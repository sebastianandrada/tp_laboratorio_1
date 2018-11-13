#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int isValidId(char* id);
static int isValidNombre(char* nombre);
static int isValidHorasTrabajadas(int horasTrabajadas);
static int isValidSueldo(int sueldo);

Employee* employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void employee_delete(Employee* this)
{
    free(this);
}

Employee* employee_newParametros(char* idStr,char* nombreStr, char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    this=employee_new();

    if(
    isValidId(idStr) &&
    !employee_setId(this,atoi(idStr))&&
    !employee_setNombre(this,nombreStr)&&
    !employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))&&
    !employee_setSueldo(this,atoi(sueldoStr)))
        return this;

    employee_delete(this);
    return NULL;
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && isValidHorasTrabajadas(horasTrabajadas))
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && isValidSueldo(sueldo))
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

static int isValidId(char* id)
{
    return !isInt(id);
}
static int isValidNombre(char* nombre)
{
    return !isLetter(nombre);
}
static int isValidHorasTrabajadas(int horasTrabajadas)
{
    return horasTrabajadas<1000 && horasTrabajadas > 0;
}
static int isValidSueldo(int sueldo)
{
    return sueldo > 0 && sueldo < 5000000;
}

int employee_compareBySueldo(void* pEmp1,void* pEmp2)
{

    if(((Employee*)pEmp1)->sueldo > ((Employee*)pEmp2)->sueldo)
    {
        return 1;
    }
    if(((Employee*)pEmp1)->sueldo < ((Employee*)pEmp2)->sueldo)
    {
        return -1;
    }
    return 0;
}

