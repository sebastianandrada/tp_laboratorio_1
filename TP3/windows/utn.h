/**
    utn_getInt : pide un entero al usuario
    @param pInt: puntero al entero destino
    @param reintentos: cantidad de reintentos
    @param msg: mensaje que se mostrara al usuario al pedir el dato
    @param msgError: mensaje que se mostrara al usuario en caso de ingresar un dato incorrecto
    @return : 0 OK, -1 error.
*/
int utn_getInt(int* pInt, int reintentos, char* msg, char* msgError, int min, int max);
/**
    utn_getFloat : pide un entero al usuario
    @param pFloat: puntero al float destino
    @param reintentos: cantidad de reintentos
    @param msg: mensaje que se mostrara al usuario al pedir el dato
    @param msgError: mensaje que se mostrara al usuario en caso de ingresar un dato incorrecto
    @return : 0 OK, -1 error.
*/
int utn_getFloat(float* pFloat, int reintentos, char* msg, char msgError[], float min, float max);

/**
    utn_getString : pide un entero al usuario
    @param pString: puntero al string destino
    @param reintentos: cantidad de reintentos
    @param msg: mensaje que se mostrara al usuario al pedir el dato
    @param msgError: mensaje que se mostrara al usuario en caso de ingresar un dato incorrecto
    @return : 0 OK, -1 error.
*/
int utn_getString(char* pBuffer, int reintentos, char* msg, char* msgError, int limite);

int isFloat(char* pBuffer);
/**
    isInt:valida si la cadena de caracteres solo tiene numeros
    @param pBuffer: cadena de caracteres que recibe para validar
    @return : 0 OK, -1 error
*/
int isInt(char* pBuffer);
/**
    isLetter:valida si la cadena de caracteres solo letras y convierte la primera letra en mayuscula
    @param pBuffer: cadena de caracteres que recibe para validar
    @return : 0 OK, -1 error
*/
int isLetter(char* pBuffer);
/**
    getString:permite ingresar una cadena de caracteres recibieno un array
    @param pBuffer: cadena de caracteres que recibe
    @param limite: guarda el int del limite del array
    @return : 0 OK, -1 error
*/