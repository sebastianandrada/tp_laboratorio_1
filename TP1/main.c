#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    int continuar = 1;
    float op1=0;
    float op2=0;
    float resSuma;
    float resResta;
    float resDivision;
    float resMultiplicacion;
    float resFactorialA;
    float resFactorialB;

    while(continuar)
    {
        mostrarMenu(op1, op2);
        opcion = getInt("Ingrese una opcion\n");
        switch (opcion)
        {
        case 1:
            ocultarMenu();
            op1 = getFloat("Ingrese un numero\n");
            ocultarMenu();
            //mostrarMenu();
            break;
        case 2:
            ocultarMenu();
            op1 = getFloat("Ingrese un numero\n");
            ocultarMenu();
            //mostrarMenu();
            break;
        case 3:
            // calcularOperaciones(op1, op2);
            ocultarMenu();
            resSuma = suma(op1, op2);
            resResta = resta(op1, op2);
            resDivision = dividir(op1, op2);
            resMultiplicacion = multiplicar(op1, op2);
            resFactorialA = factorial(op1);
            resFactorialB = factorial(op2);
            ocultarMenu();
            break;
        case 4:
            ocultarMenu();
            mostrarResultados(resSuma, resResta, resDivision, resMultiplicacion, resFactorialA, resFactorialB);
            ocultarMenu();
            break;
        case 5:
            continuar = 0;
            break;
        default:
            printf("Ingrese una opcion valida");
            break;
        }
    }

    return 0;
}

