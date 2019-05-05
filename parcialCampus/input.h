/**
* \brief Solicita un número entero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita un número real al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga la cadena ingresada
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita una caracter para el sexo al usuario y valida que sea f o m.
* \param input Carga el char ingresado.
* \param message Es el mensaje a ser mostrado.
* \param eMessage Es el mensaje a ser mostrado en caso de error.
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getCharGenre(char* input,char message[],char eMessage[]);

/**
* \brief Permite el ingreso de una fecha. Valida si el año es bisiesto y el número de días de cada mes.
* \param inputY Carga el año ingresado.
* \param inputM Carga el número del mes ingresado.
* \param inputD Carga el número del día ingresado.
* \param message Es el mensaje a ser mostrado concatenado con "Ingrese la fecha de ".
* \param yLowLimit Limite inferior a validar para los años.
* \param yHiLimit Limite superior a validar para los años.
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getDate(int* inputY, int* inputM, int* inputD, char message[], int yLowLimit, int yHiLimit);
