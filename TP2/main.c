#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define CANT_EMPLADOS 1000

int main()
{

  Employee empleados[CANT_EMPLADOS];
  initEmployees(empleados, CANT_EMPLADOS);
  cargaForzadaEmployee(empleados, CANT_EMPLADOS, "Mariana", "Siri", 14000.12, 3);
  cargaForzadaEmployee(empleados, CANT_EMPLADOS, "Rosario", "De Pedro", 45431.51, 1);
  cargaForzadaEmployee(empleados, CANT_EMPLADOS, "Marcos", "Presley", 10000.50, 14);
  cargaForzadaEmployee(empleados, CANT_EMPLADOS, "Juliana", "Aguad", 45666.4, 12);
  cargaForzadaEmployee(empleados, CANT_EMPLADOS, "Pedro", "Buley", 17566.3, 12);

  int opcion;
  int id;
  int opcionInforme;

  do
  {
    utn_getInt(&opcion, 5, "\n1)Alta empleado\n2)Modificar empleado\n3)Baja de empleado\n4)Informar\nElija una opcion ",
               "Elige una opcion valida ", 0, 6);
    switch (opcion)
    {
    case 1:
      if (addEmployee(empleados, CANT_EMPLADOS) == 0)
      {
        printf("\nCarga exitosa!\n");
      }
      else
      {
        printf("Ocurrio un error en la carga de usuario");
      }
      break;
    case 2:
      utn_getInt(&id, 10, "Ingrese id de empleado a Modificar ", "Id invalido", 0, CANT_EMPLADOS);
      modifyEmployee(empleados, CANT_EMPLADOS, id);
      break;
    case 3:
      utn_getInt(&id, 10, "Ingrese id de empleado a Modificar ", "Id invalido", 0, CANT_EMPLADOS);
      removeEmployee(empleados, CANT_EMPLADOS, id);
      break;
    case 4:
      utn_getInt(&opcionInforme, 5, "\n1)Listar empleados alfabeticamente por apellido y sector\n2)Total y promedio de salarios, cantidad de empleados que superan el salario promedio\nElija una opcion ",
                 "Elija una opcion valida (1,2)\n", 1, 2);
      //imformeEmployees(empleados, CANT_EMPLADOS, opcionInforme);
      printf("\nTu vieja");
      break;
    case 5:
      printEmployees(empleados, CANT_EMPLADOS);
    }

  } while (opcion != 0);

  return 0;
}
