#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int flagOnce=1;
    int retorno = -1;
    Employee* auxEmployee;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];

    while(!feof(pFile))
    {
        if(flagOnce)
        {
            fscanf(pFile,"%s\n",bufferId);
            flagOnce = 0;
        }
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                  bufferId,
                  bufferNombre,
                  bufferHorasTrabajadas,
                  bufferSueldo)
                == 4)
        {
            auxEmployee = employee_newParametros(
                              bufferId,
                              bufferNombre,
                              bufferHorasTrabajadas,
                              bufferSueldo);

            if(auxEmployee != NULL)
            {
                 ll_add(pArrayListEmployee, auxEmployee);
                 retorno = 0;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
   // int flagOnce = 1;
    do
    {
        /*if(flagOnce)
        {
            fread(pEmpleado, sizeof(Employee), 1, pFile);
            flagOnce = 0;
        }*/
        pEmpleado = employee_new();
        fread(pEmpleado, sizeof(Employee), 1, pFile);
        ll_add(pArrayListEmployee, pEmpleado);
    }while(!feof(pFile));
    return 1;
}
