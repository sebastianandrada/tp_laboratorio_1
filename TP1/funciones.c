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

/**
 * \brief Realiza la suma entre dos operandos
 * \param op1 Es el primer operando
 * \param op2 Es el segundo operando
 * \return El resultado de la suma entre los dos operandos
 *
*/
float suma(float op1, float op2){
  return op1 + op2;
}

/**
 * \brief Realiza la resta entre dos operandos
 * \param op1 Es el primer operando
 * \param op2 Es el segundo operando
 * \return El resultado de la resta entre los dos operandos
 *
*/
float resta(float op1, float op2){
  return op1 - op2;
}

/**
 * \brief Realiza la division entre dos operandos
 * \param op1 Es el primer operando
 * \param op2 Es el segundo operando
 * \return El resultado de la division entre los dos operandos
 *
*/
float dividir(float op1, float op2){
  return op1 / op2;

}

/**
 * \brief Realiza la multiplicacion entre dos operandos
 * \param op1 Es el primer operando
 * \param op2 Es el segundo operando
 * \return El resultado de la multiplicacion entre los dos operandos
 *
*/
float multiplicar(float op1, float op2){
  return op1 * op2;
}

/**
 * \brief Realiza el factorial de un numero
 * \param op1 Es el primer operando
 * \param op2 Es el segundo operando
 * \return El resultado de el factorial de un numero
 *
*/
float factorial(float op){
    int factorial = 1;
    int i;
      for(i = 1; i <= op; i++){
        factorial = factorial * i;
      }
      return factorial;
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

void mostrarResultados(float resSuma, float resResta, float resDivision, float resMultiplicacion, float resFactorialA, float resFactorialB){
  printf("El resultado de A + B es: %.1f", resSuma);
  printf("El resultado de A - B es: %.1f", resResta);
  printf("El resultado de A / B es: %.1f", resDivision);
  printf("El resultado de A * B es: %.1f", resMultiplicacion);
  printf("El factorial de A es: %.1f y El factorial de B es: %.1f",resFactorialA, resFactorialB);
}
