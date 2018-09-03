#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
//#include "funciones.h"

int main()
{
    int opcion;
    float op1;
    float op2;

    printf("Calculadora!!\n");
    printf("1. Ingresar 1er operando\n");
    printf("2. Ingresar 2do operando\n");
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
    //scanf("%d", &opcion);
    opcion = getInt("Ingrese una opcion\n");

    switch (opcion)
    {
        case 1:
            //op1 = getFloat("Ingrese un numero");
            printf("La opcion es: %d", opcion);
            //printf("EL numero ingresado es : %f", op1);
            break;
        case 2:
            printf("La opcion es: %d", opcion);
            break;
        case 3:
            printf("La opcion es: %d", opcion);
            break;
        case 4:
            printf("La opcion es: %d", opcion);
            break;
        case 5:
            printf("La opcion es: %d", opcion);
            break;

        default:
        printf("no hay opcion");
            break;
    }

    return 0;
}
