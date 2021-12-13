#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  // Imprime las páginas libres:
  printf (1, "Paginas libres: %d\n", freemem(F_PAGES));
  
  // Imprime los bytes libres
  printf (1, "Bytes libres: %d\n", freemem(F_BYTES));

  exit(0);
}
