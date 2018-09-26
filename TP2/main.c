#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define CANT_EMPLADOS 200

int main()
{
  /*   int enen;
    utn_getInt(&enen, 5, "Ingrese un entero: ", "no!\n", 0, 5000);
    printf("El entero es %d\n", enen);
    float flflo;
    utn_getFloat(&flflo, 5, "Ingrese un flotante: ", "no!\n", 0.0, 5000.0);
    printf("El flotante es %.2f", flflo);
    char cadena[1250];
    utn_getString(&cadena, 5, "Ingrese su nombre papu", "no!", 1250);
    printf("Su nombre es: %s", cadena); */

    int rdoInit;
    int rdoAdd;
    int rdoPrint;

    Employee empleados[CANT_EMPLADOS];
    rdoInit = initEmployees(empleados, CANT_EMPLADOS);
    printf("Rdo initEmployees:  %d\n", rdoInit);

    rdoAdd = addEmployee(empleados, CANT_EMPLADOS, "as","df", 2220.2, 1);
    printf("Rdo addEmployees: %d\n", rdoAdd);

    rdoPrint = printEmployees(empleados, CANT_EMPLADOS);
    printf("Rdo print: %d\n", rdoPrint);

    return 0;
}
