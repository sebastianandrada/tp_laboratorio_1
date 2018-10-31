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
    if(pFile == NULL)
    {
        printf("esta re moco");
    }
    int flagOnce=1;
    int retorno = -1;
    Employee* auxEmployee;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];

    //hacer con un do-while, si conviene y poner un break, que termine el programa
    while(!feof(pFile))
    {
        if(flagOnce)
        {
            fscanf(pFile,"%s\n",bufferId);
            flagOnce = 0;
        }
        printf("esta andadndo");
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

    return 1;
}
