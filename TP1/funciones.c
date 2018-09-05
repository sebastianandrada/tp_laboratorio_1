#include <stdio_ext.h>
#include <stdlib.h>

/**
 * \brief Solicita un numero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser retornado
 * \return El numero ingresado por el usuario
 *
*/
float getFloat(char mensaje[]){
  float aux;
  printf("%s", mensaje);
  scanf("%f", &aux);
  return aux;
}

/**
 * \brief Solicita un numero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser retornado
 * \return El numero ingresado por el usuario
 *
*/
int getInt(char mensaje[]){
  int aux;
  printf("%s", mensaje);
  scanf("%d", &aux);
  return aux;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser retornado
 * \return El caracter ingresado por el usuario
 *
*/
char getChar(char mensaje[]){
  char aux;
  printf("%s", mensaje);
  __fpurge(stdin);
  scanf("%c", &aux);
  return aux;
}

void mostrarMenu(op1, op2)
{
    printf("Calculadora!!\n");
    printf("1. Ingresar 1er operando (A=%.2f)\n", op1);
    printf("2. Ingresar 2do operando (B=%.2f)\n", op2);
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
}

void ocultarMenu(){
    system("clear");
}
