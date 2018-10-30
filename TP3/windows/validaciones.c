#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include <ctype.h>

int isLetter(char* pBuffer)
{
    int i=0;
    int retorno=0;
    int flag=0;
    while(pBuffer[i] != '\0')
    {
        if(flag==0)
        {
            pBuffer[i]=toupper(pBuffer[i]);
            flag=1;
        }else if ((pBuffer[i]< 'A' || pBuffer[i] > 'Z') &&
                (pBuffer[i]< 'a' || pBuffer[i] > 'z') &&
                (pBuffer[i]!= ' ') && ( pBuffer[i] != '.'))
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int isFloat(char* pBuffer)
{
    int i=0;
    int retorno=0;
    int contadorPuntos=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] == '.' && contadorPuntos==0)
        {
            contadorPuntos++;
            i++;
            continue;
        }
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int isInt(char* pBuffer)
{
    int i=0;
    int retorno=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

