#include <stdio.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include <string.h>

static int getIndiceVacio(Employee *e, int length);
static int generarID(void);
static void printEmployee(Employee e);

int initEmployees(Employee *list, int len)
{
  int i;
  int retorno = -1;
  if (len > 0)
  {
    for (i = 0; i < len; i++)
    {
      list[i].isEmpty = 1;
      retorno = 0;
    }
  }
  return retorno;
}

int addEmployee(Employee *list, int len, char name[], char lastName[], float salary, int sector)
{
  int retorno = -1;
  char auxName[51];
  char auxLastName[51];
  float auxSalary;
  int auxSector;
  int index = getIndiceVacio(list, len);
  if (len >= 0 && utn_getString(auxName, 5, "Ingrese nombre: \n", "Dato invalido\n", 51) == 0)
  {
    if (utn_getString(auxLastName, 5, "Ingrese un apellido: \n", "Dato invalido\n", 51) == 0)
    {
      if (utn_getFloat(&auxSalary, 5, "Ingrese el salario: \n", "Dato invalido\n", 0.0, 1000000.0) == 0)
      {
        if (utn_getInt(&auxSector, 5, "Ingrese el sector\n", "Dato invalido\n", 0, 50) == 0)
        {
          // int nuevoID = generarID();
          // printf("id : %d\n", nuevoID);
          list[index].id = generarID();
          //printf("El id es: %d", list[index].id);
          list[index].isEmpty = 0;
          list[index].salary = auxSalary;
          list[index].sector = auxSector;
          strncpy(list[index].name, auxName, 51);
          strncpy(list[index].lastName, auxLastName, 51);
          //printf("Esto ocurre luego\n");
          retorno = 0;
        }
      }
    }
  }
  return retorno;
}

int printEmployees(Employee *list, int length)
{
  int i;
  int retorno = -1;
    for (i = 0; i < length; i++)
    {
      //printf("numero %d, is empty?: %d\n", i, list[i].isEmpty);
      if (list[i].isEmpty == 0)
      {
        printf("\nEmpleado n° %d\n", i);
        printEmployee(list[i]);
      }
    }
    retorno = 0;
  return retorno;
}

/**********staticas*****************/
static int getIndiceVacio(Employee *e, int length)
{
  int i;
  int retorno = -1;
  for (i = 0; i < length; i++)
  {
    if (e[i].isEmpty == 1)
    {
      retorno = i;
      break;
    }
  }
  return retorno;
}

static int generarID(void)
{
  static int contID = 0;
  return contID++;
}

static void printEmployee(Employee e)
{
  printf("id: %d\n", e.id);
  printf("isEmpty (0 false, 1 true): %d\n", e.isEmpty);
  printf("nombre: %s\n", e.name);
  printf("last name: %s\n", e.lastName);
  printf("salario: %.2f\n", e.salary);
  printf("sector: %d\n\n", e.sector);
}
