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
        limpiarConsola();
        mostrarMenu(op1, op2);
        opcion = getInt("Ingrese una opcion\n");
        switch (opcion)
        {
        case 1:
            limpiarConsola();
            op1 = getFloat("Ingrese un numero\n");
            break;
        case 2:
            limpiarConsola();
            op2 = getFloat("Ingrese un numero\n");
            break;
        case 3:
            limpiarConsola();
            resSuma = suma(op1, op2);
            resResta = resta(op1, op2);
            resDivision = dividir(op1, op2);
            resMultiplicacion = multiplicar(op1, op2);
            resFactorialA = factorial(op1);
            resFactorialB = factorial(op2);
            continuar = getChar("Se han realizado las operaciones.\n");
            break;
        case 4:
            limpiarConsola();
            mostrarResultados(resSuma, resResta, resDivision, resMultiplicacion, resFactorialA, resFactorialB);
            continuar = getChar("Los resultados.\n");
            break;
        case 5:
            continuar = 0;
            break;
        default:
            limpiarConsola();
            opcion = getInt("Ingrese una opcion valida (1-5)");
            break;
        }
    }

    return 0;
}

