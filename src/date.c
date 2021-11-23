#include "types.h"
#include "user.h"
#include "date.h"

int 
main(int argc, char *argv[])
{
    struct rtcdate r;

    if(date(&r))
    {
        printf(2, "date failed\n");
        exit(0);
    }
    // Código para imprimir la fecha
    printf(1, "Chiquillo, vaya cabeza que tienes. Hoy estamos a %d/%d/%d\n", r.day, r.month, r.year);

    exit(0);
}