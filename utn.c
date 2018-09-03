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
