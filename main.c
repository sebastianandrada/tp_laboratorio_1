#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
//#include "funciones.h"

int main()
{
    int opcion;
    float op1;
    float op2;
    float resSuma;
    float resResta;
    float resDivision;
    float resMultiplicacion;
    float resFactorial;

    while(opcion != 5)
    {
    mostrarMenu();
    opcion = getInt("Ingrese una opcion\n");
    switch (opcion)
    {
        case 1:
            op1 = getFloat("Ingrese un numero");
            mostrarMenu();
            break;
        case 2:
            op1 = getFloat("Ingrese un numero");
            mostrarMenu();
            break;
        case 3:
            // calcularOperaciones(op1, op2);
            resSuma = suma(op1, op2);
            resResta = resta(op1, op2);
            resDivision = dividir(op1, op2);
            resMultiplicacion = multiplicar(op1, op2);
            resFactorial = factorial(op1, op2);
            break;
        case 4:
            mostrarResultados(resSuma, resResta, resDivision, resMultiplicacion, resFactorial);
            break;
        case 5:
            break;
        default:
        printf("Ingrese una opcion valida");
            break;
    }
    }

    return 0;
}

    void mostrarMenu(){
        printf("Calculadora!!\n");
        printf("1. Ingresar 1er operando\n");
        printf("2. Ingresar 2do operando\n");
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
    }

    void mostrarResultados(float, float, float, float, float){
        printf("a) El resultado de A+B es: r \n
            b) El resultado de A-B es: r\n
            c) El resultado de A/B es: r\n” o “No es posible dividir por cero”
            d) El resultado de A*B es: r\n”
            e) El factorial de A es: r1 y El factorial de B es: r2\n”");
    }
