#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
//#include "ArrayEmployees.h"
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
  int opcionCampoEmpleado;
  int opcionOrden;
  float auxSalarioTotal;
  float auxSalarioPromedio;
  int cantEmpleadosSuperaProm;

  do
  {
    utn_getInt(&opcion, 5, "\n1)Alta empleado\n2)Modificar empleado\n3)Baja de empleado\n4)Informar\n0)Salir\nElija una opcion ",
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
      if (utn_getInt(&opcionInforme, 5, "\n1)Listar empleados alfabeticamente por apellido y sector\n2)Total y promedio de salarios, cantidad de empleados que superan el salario promedio\nElija una opcion ",
                     "Elija una opcion valida (1,2)\n", 1, 3) == 0)
      {
        switch (opcionInforme)
        {
        case 1:
          if (utn_getInt(&opcionCampoEmpleado, 5, "\n1)Listar por apellido\n2)Listar por sector\nElija una opcion", "Elija una opcion valida (1,2)\n", 1, 3) == 0)
          {
            if (utn_getInt(&opcionOrden, 5, "Elija orden:\n1)Ascendente\n2)Descendente", "\nElija una opcion valida\n", 1, 3) == 0)
            {
              switch (opcionCampoEmpleado)
              {
              case 1:
                if (opcionOrden == 1)
                {
                  sortEmployeesByLastName(empleados, CANT_EMPLADOS, 1);
                  printEmployees(empleados, CANT_EMPLADOS);
                }
                else
                {
                  sortEmployeesByLastName(empleados, CANT_EMPLADOS, 0);
                  printEmployees(empleados, CANT_EMPLADOS);
                }
                break;

              case 2:
                if (opcionOrden == 1)
                {
                  sortEmployeesBySector(empleados, CANT_EMPLADOS, 1);
                  printEmployees(empleados, CANT_EMPLADOS);
                }
                else
                {
                  sortEmployeesBySector(empleados, CANT_EMPLADOS, 0);
                  printEmployees(empleados, CANT_EMPLADOS);
                }
                break;
              }
            }
            break;
          case 2:

            auxSalarioTotal = getSalarioTotal(empleados, CANT_EMPLADOS);
            printf("\nSalario total: $%.2f\n", auxSalarioTotal);
            auxSalarioPromedio = getSalarioPromedio(empleados, CANT_EMPLADOS);
            printf("\nSalario promedio: $%.2f\n", auxSalarioPromedio);
            for (int i = 0; i < CANT_EMPLADOS; i++)
            {
              if (empleados[i].salary > auxSalarioPromedio && empleados[i].isEmpty == 0)
              {
                cantEmpleadosSuperaProm++;
              }
            }
            printf("Cantidad de empleados que superan el promedio: %d\n", cantEmpleadosSuperaProm);
            break;
          }
        }
        break;
      case 5:
        printEmployees(empleados, CANT_EMPLADOS);
      }
    }
  } while (opcion != 0);

  return 0;
}
