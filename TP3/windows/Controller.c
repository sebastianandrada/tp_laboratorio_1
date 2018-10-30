#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
{
    int retorno = -1;
    FILE *pFile;
    if (pFile = fopen("data.csv", "r") == NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        retorno = -1;
    }
    if (parser_EmployeeFromText(pFile, pArrayListEmployee) == 1)
    {
        retorno = 1;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee)
{
    /*Employee* auxEmployee1 = employee_newParametros("-1", "Pedro", "1255", "40000");
    ll_add(pArrayListEmployee, auxEmployee1);*/
    int retorno = -1;
    char auxName[128];
    char auxHorasTrabajadas[40];
    char auxSueldo[40];
    Employee *auxEmployee;

    if (pArrayListEmployee != NULL &&
        (utn_getString(auxName, 5, "Ingrese un nombre: \n", "Dato invalido\n", 128) == 0) &&
        (utn_getString(auxHorasTrabajadas, 5, "Ingrese las horas trabajadas\n", "Dato invalido\n", 40) == 0) &&
        (utn_getString(auxSueldo, 5, "Ingrese el sueldo\n", "Dato invalido\n", 40) == 0))
    {
        retorno = 0;
        auxEmployee = employee_newParametros("-1", auxName, auxHorasTrabajadas, auxSueldo);
        ll_add(pArrayListEmployee, auxEmployee);
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee)
{
    int retorno = -1;
    char auxName[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    int index;
    int id;
    utn_getInt(&id, 3, "Ingrese id del empleado a editar", "Id invalido", 0, 40000);
    index = findEmployeeById(pArrayListEmployee, id);
    Employee *auxEmployee = ll_get(pArrayListEmployee, index);
    if (auxEmployee != NULL &&
        utn_getString(auxName, 5, "Edit empleado", "Invalido", 128) &&
        utn_getInt(&auxHorasTrabajadas, 5, "Editar horas trabajadas", "Cantidad invalida", 0, 900) &&
        utn_getInt(&auxSueldo, 5, "Editar sueldo", "Cantidad invalida", 0, 4000000))
    {
        employee_setNombre(auxEmployee, auxName);
        employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
        employee_setSueldo(auxEmployee, auxSueldo);
        retorno = 0;
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee)
{
    //get posicion del emp
    //free a eso
    // y luego remove espacion en memoria
    int retorno = -1;
    int id;
    int index = findEmployeeById(pArrayListEmployee, id);
    if ((utn_getInt(&id, 3, "Ingrese id del empleado a editar", "Id invalido", 0, 40000) == 0) &&
        index != -1 && pArrayListEmployee != NULL)
    {
        Employee *auxEmployee = ll_get(pArrayListEmployee, index);
        employee_delete(auxEmployee);
        ll_remove(pArrayListEmployee, index);
        retorno = 0;
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee)
{
    int i;
    Employee *auxEmployee;
    int auxId;
    char auxNombre[1024];
    int auxHoras;
    int auxSueldo;

    int len = ll_len(pArrayListEmployee);
    for (i = 0; i < len; i++)
    {
        auxEmployee = ll_get(pArrayListEmployee, i);
        employee_getId(auxEmployee, &auxId);
        employee_getNombre(auxEmployee, auxNombre);
        employee_getHorasTrabajadas(auxEmployee, &auxHoras);
        employee_getSueldo(auxEmployee, &auxSueldo);

        printf("\n%d - %s - %d - %d",
               auxId,
               auxNombre,
               auxHoras,
               auxSueldo);
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee)
{
    //ll_sort()
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee)
{
    return 1;
}

int findEmployeeById(LinkedList *pArrayListEmployee, int id)
{
    int i;
    int index = -1;
    Employee *auxE;
    int auxId;
    int len = ll_len(pArrayListEmployee);
    if (len > 0 && pArrayListEmployee != NULL)
    {
        for (i = 0; i < len; i++)
        {
            auxE = ll_get(pArrayListEmployee, i);
            employee_getId(auxE, auxId);
            if (auxId == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

int compararEmpleados(void* pEmp1, void* pEmp2)
{
    Employee* auxEmp1 = pEmp1;
    Employee* auxEmp2 = pEmp2;
    int auxSueldoEmp1 = employee_getSueldo(pEmp1, auxSueldoEmp1);
    int auxSueldoEmp2 = employee_getSueldo(pEmp1, auxSueldoEmp2);

    if(auxSueldoEmp1 > auxSueldoEmp2)
    {
        return 1;
    }
    if(auxSueldoEmp1 < auxSueldoEmp2)
    {
        return -1;
    }
    return 0;
}

/* int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;


} */
