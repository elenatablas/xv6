#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  int exit_status;

  if(argint(0, &exit_status) < 0)
    return -1;
  exit(exit_status);
  return 0;  // not reached
}

int
sys_wait(void)
{
  int *exit_status;
  if(argptr(0, (void**)&exit_status, sizeof(exit_status)) < 0)
    return -1;
  return wait(exit_status);
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int n, sz;
  struct proc *curproc = myproc();

  if(argint(0, &n) < 0)
    return -1;

  sz = curproc->sz;
  if(n>=0)
  {
    if((sz+n) >= KERNBASE)
      return -1;
    curproc->sz = sz+n;
  }
  else // argumento negativo
  {
    if(sz+n < myproc()->heap)
    {
      return -1;
    }
    if((curproc->sz = deallocuvm(curproc->pgdir, sz, sz + n)) == 0)
      return -1;
  }
  
  lcr3(V2P(curproc->pgdir));  // Invalidate TLB.

  //if(growproc(n) < 0)
  //   return -1;

  return sz; // retornamos el anterior tamaño
}

int 
sys_freemem (void)
{
  int type;
  if(argint(0, &type) < 0)
  {
    return -1;
  }
  if(type == 0)
  {
    return getNumFreePages();
  }
  return (getNumFreePages()*PGSIZE);
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_date(void)
{
  struct rtcdate *d;
  if(argptr(0, (void **) &d, sizeof(struct rtcdate)) < 0)
    return -1;
  cmostime(d);
  return 0;
}