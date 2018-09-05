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
    float resFactorial;

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
            op1 = getFloat("Ingrese un numero\n");
            //mostrarMenu();
            break;
        case 3:
            // calcularOperaciones(op1, op2);
            resSuma = op1 + op2;                //suma(op1, op2);
            resResta = op1 - op2        ;    //resta(op1, op2);
            resDivision = op1 / op2      ;      //dividir(op1, op2);
            resMultiplicacion =  op1 * op2;                 //multiplicar(op1, op2);
            resFactorial =    0;      //factorial(op1, op2);
            break;
        case 4:
            //mostrarResultados(resSuma, resResta, resDivision, resMultiplicacion, resFactorial);
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



/*void mostrarResultados(float resSuma, float resResta, float resMultiplicacion, float resDivision, float resFactorial)
{
    printf("a) El resultado de A+B es: r \n
           b) El resultado de A-B es: r\n
           c) El resultado de A/B es: r\n o No es posible dividir por cero
           d) El resultado de A*B es: r\n
           e) El factorial de A es: r1 y El factorial de B es: r2\n");
}*/


