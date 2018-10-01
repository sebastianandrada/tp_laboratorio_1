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

int addEmployee(Employee *list, int len)
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

int findEmployeeById(Employee *list, int len, int id)
{
  int retorno = -1;
  int i;
  for (i = 0; i < len; i++)
  {
    if (list[i].id == id && list[i].isEmpty == 0)
    {
      retorno = i;
      break;
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

int removeEmployee(Employee *list, int len, int id)
{
  int retorno = -1;
  int index = findEmployeeById(list, len, id);
  if (index != -1)
  {
    list[index].isEmpty = 1;
    retorno = 0;
  }
  return retorno;
}

/*int printEmployees(Employee* list, int length)
{
  int retorno = -1;
  int i;

  for (i = 0; i < length; i++)
  {
    if (list[i].isEmpty == 0)
    {
      printEmployee(list[i]);
    }
    retorno = 0;
  }
  return retorno;
}*/

int modifyEmployee(Employee *list, int len, int id)
{
  int retorno = -1;
  int index = findEmployeeById(list, len, id);
  int opcion;
  char auxString[51];
  float auxSalary;
  int auxSector;
  if (index != -1)
  {
    do
    {
      utn_getInt(&opcion, 5, "Campo a modificar\n1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n0)Volver a menu principal\n",
                 "Opciones validas (0,4)\n", 0, 4);

      switch (opcion)
      {
      case 1:
        if (utn_getString(auxString, 5, "Ingrese el nuevo nombre: ", "No!", 51) == 0)
        {
          strncpy(list[index].name, auxString, 51);
          retorno = 0;
          printf("\nModificacion exitosa!\n");
        }
        break;
      case 2:
        if (utn_getString(auxString, 5, "Ingrese el nuevo apellido: ", "No!", 51) == 0)
        {
          strncpy(list[index].lastName, auxString, 51);
          retorno = 0;
          printf("\nModificacion exitosa!\n");
        }
        break;
      case 3:
        if(utn_getFloat(&auxSalary, 5, "Ingrese salario $", "no!", 0.0, 50000000000.0) == 0)
        {
          list[index].salary = auxSalary;
          retorno = 0;
          printf("\nModificacion exitosa!\n");
        }
        break;
      case 4:
        if(utn_getInt(&auxSector, 5, "Ingrese sector ", "no!", 0, 9999) == 0)
        {
          list[index].sector = auxSector;
          retorno = 0;
          printf("\nModificacion exitosa!\n");
        }
        break;
      }
    } while (opcion != 0);
  }
  else
  {
    printf("\nNo existe un empleado con ese id!\n");
  }
  return retorno;
}

void cargaForzadaEmployee(Employee *list, int len, char *name, char *lastName, float salary, int sector)
{
  int index = getIndiceVacio(list, len);
  if (index != -1)
  {
    list[index].id = generarID();
    list[index].salary = salary;
    list[index].sector = sector;
    strncpy(list[index].name, name, 51);
    strncpy(list[index].lastName, lastName, 51);
    list[index].isEmpty = 0;
  }
}

/*9 7 6 15 16 5 10 11
temp = 7
j = 0
7 < 9

data[1] = 9

7*/

int sortEmployees(Employee* list, int len, int order)
{
  int i,j;
  Employee temp;
  for( i = 0; i < len; i++)
  {
    temp = list[i];
    j= i-1;
    while(j>=0 && (order == 0 && temp.sector < list[j].sector)){
      list[j+1] = list[j];
      j--;
    }
    list[j+1] = temp;
  }
}

/**********estaticas*****************/
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
