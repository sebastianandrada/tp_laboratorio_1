#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

static int findEmployeeById(LinkedList *pArrayListEmployee, int id);

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
    pFile = fopen("data.csv", "r");
    if (pFile == NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        return -1;
    }
    retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
    fclose(pFile);
    printf("Carga exitosa\n");
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
    int retorno = -1;
    FILE *pFile;
    pFile = fopen(path, "r");
    if (pFile == NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        return -1;
    }
    retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    fclose(pFile);
    printf("\nCarga exitosa!\n");
    return retorno;
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
    int retorno = -1;
    char auxName[128];
    char auxHorasTrabajadas[40];
    char auxSueldo[40];
    Employee *auxEmployee;

    if (pArrayListEmployee != NULL &&
        utn_getString(auxName, 5, "Ingrese un nombre: \n", "Dato invalido\n", 128) == 0 &&
        utn_getString(auxHorasTrabajadas, 5, "Ingrese las horas trabajadas\n", "Dato invalido\n", 40) == 0 &&
        utn_getString(auxSueldo, 5, "Ingrese el sueldo\n", "Dato invalido\n", 40) == 0)
    {
        retorno = 0;
        auxEmployee = employee_newParametros("-1", auxName, auxHorasTrabajadas, auxSueldo);
        ll_add(pArrayListEmployee, auxEmployee);
        printf("Carga exitosa!");
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
    utn_getInt(&id, 3, "Ingrese id del empleado a editar: ", "Id invalido", 0, 40000);
    index = findEmployeeById(pArrayListEmployee, id);
    Employee *auxEmployee = ll_get(pArrayListEmployee, index);
    if (auxEmployee != NULL &&
        utn_getString(auxName, 5, "Edit nombre: ", "Invalido", 128) == 0 &&
        utn_getInt(&auxHorasTrabajadas, 5, "Editar horas trabajadas: ", "Cantidad invalida", 0, 900) == 0 &&
        utn_getInt(&auxSueldo, 5, "Editar sueldo: ", "Cantidad invalida", 0, 4000000) == 0)
    {
        employee_setNombre(auxEmployee, auxName);
        employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
        employee_setSueldo(auxEmployee, auxSueldo);
        printf("Empleado editado con exito");
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
    int retorno = -1;
    int id;
    utn_getInt(&id, 3, "Ingrese id del empleado a eliminar: ", "Id invalido", 0, 40000);
    int index = findEmployeeById(pArrayListEmployee, id);
    if (index != -1 && pArrayListEmployee != NULL)
    {
        Employee *auxEmployee = ll_get(pArrayListEmployee, index);
        employee_delete(auxEmployee);
        ll_remove(pArrayListEmployee, index);
        printf("Baja exitosa\n");
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
    if(len > 0)
    {
        printf("\n----------Empleados---------");
        for (i = 0; i < len; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &auxId);
            employee_getNombre(auxEmployee, auxNombre);
            employee_getHorasTrabajadas(auxEmployee, &auxHoras);
            employee_getSueldo(auxEmployee, &auxSueldo);

            printf("\nID: %d - Nombre: %s - Horas: %d - Sueldo: %d",
                   auxId,
                   auxNombre,
                   auxHoras,
                   auxSueldo);
        }
        printf("\n-----------------------------\n");
    } else
    {
        printf("\nNo hay empleados\n");
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
    ll_sort(pArrayListEmployee, employee_compareBySueldo,0);
    printf("\nOrdenados\n");
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
    FILE* pArchivo = fopen(path, "w");
    int retorno = -1;
    Employee* pEmpleado;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    int i;
    int len = ll_len(pArrayListEmployee);
    if(pArchivo != NULL)
    {
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<len;i++)
        {
            pEmpleado = ll_get(pArrayListEmployee, i);
            employee_getNombre(pEmpleado, auxNombre);
            employee_getId(pEmpleado, &auxId);
            employee_getHorasTrabajadas(pEmpleado, &auxHoras);
            employee_getSueldo(pEmpleado, &auxSueldo);
            fprintf(pArchivo, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
        }
        retorno = 1;
    }
    fclose(pArchivo);
    return retorno;
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
    FILE* pArchivo = fopen(path, "wb");
    int retorno = -1;
    Employee* pEmpleado;
    int i;
    int len = ll_len(pArrayListEmployee);
    if(pArchivo != NULL)
    {
        for(i=0;i<len;i++)
        {
            pEmpleado = ll_get(pArrayListEmployee, i);
            fwrite(pEmpleado, sizeof(Employee), 1,pArchivo);
        }
        retorno = 1;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief find an Employee by Id en returns the index position in LinkedList.
*
* \param list LinkedList*
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
static int findEmployeeById(LinkedList *pArrayListEmployee, int id)
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
            employee_getId(auxE, &auxId);
            if (auxId == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

