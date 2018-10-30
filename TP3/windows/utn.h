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