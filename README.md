![logo](./markdown/logo_umu.svg) 

# XV6

Proyecto de Ampliación de Sistemas Operativos para 3º de Ingenieria Informática.

Se parte de la implementación del Sistema Operativo XV6 incompleta y se pide realizar ciertas tareas para completarlo.

Este proyecto ha sido realizado por Enrique Rodriguez Lopez y Elena Peréz Gonzalez Tablas.

# Requisitos

Para poder usar el proyecto, necesitaremos el emulador QEMU.

```console
enrique@pc:~$ sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils
```

# Compilación

```console
enrique@pc:~$ make
```

# Uso
```console
enrique@pc:~$ make qemu
```

Una vez ejecutes este comando te aparecerá el emulador QEMU con el sistema operativo XV6.

# Tareas realizadas

- Creación de llamada al sistema date()
- Creación de llamada al sistema dup2()
- Modifica las llamadas exit() y wait() para que sigan la signatura de las funciones de POSIX, es decir: int wait(int* status) y void exit(int
status).
- Implementación de reserva de páginas de memoria bajo demanda
- Modifica el código de la función exec() para que asigne a cada proceso
un número de páginas de pila igual al número de páginas de código+datos de ese
proceso.
- Creación de llamada al sistema freemem con la siguiente signatura: int freemem(int type).
- Modifica bmap() para que implemente un bloque doblemente indirecto.
No puedes cambiar el tamaño del nodo-i en disco, por lo que sacrificaremos un
bloque directo para implementar el doblemente indirecto
- Modifica xv6 para manejar el borrado de ficheros con bloques doble-
mente indirectos.

## Licence
This project is licensed under the [MIT]() Licence - see the [LICENSE]() file for details.