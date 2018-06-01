    typedef struct{
        int idPersona;
        char nombre[25];
        int dni;
        int edad;
        int estado;
    }ePersona;

    /** \brief  intercala los datos cuando se ordenan
      *  \param  Estructura ePersona
      *  \param  Tamaño de la estructura
      *  \return datos reubicados
    */
     void burbujeo(ePersona[], int, int);

    /** \brief  Inicializa estructura ePersona
     *  \param  Estructura ePersona
     *  \return estructura inicializada (todos los estados en 0)
    */
    void inicializarEstadoPersona(ePersona[], int);

    /** \brief  Carga en la estructura datos para prueba
     *  \param  Estructura ePersona
     *  \return estructura con datos cargados
    */
    void HardCodePersona(ePersona[],int i);

    /** \brief  ingreso de datos tipo char
      *  \param  char()
      *  \return dato ingresado
    */
    int  ingresoDatoInt(char[]);

    /** \brief  ingreso de datos tipo int
      *  \param  int
      *  \return dato ingresado
    */
    void *ingresoDatoChar(char[], char[]);

    /** \brief  buscar si hay lugar para agregar un registro
      *  \param  Estructura ePersona
      *  \param  Tamaño de la estructura
     *  \return id del registro (posicion=1) o si esta lleno(posicion=-1)
    */
    int personaLibre(ePersona[],int);

    /** \brief  buscar si hay lugar para agregar un registro
     *  \return id del registro (posicion=1) o si esta lleno(posicion=-1)
    */
    int personaExiste(ePersona[],int, int);

    /** \brief  verifica si la estructura no contiene datos
      *  \param  Estructura ePersona
      *  \param  Tamaño de la estructura
      *  \return estado de la estructura (0 vacio) o (1 si hay datos)
    */
    int ePersonaVacio(ePersona[], int);

    /** \brief  ordena estructura por ID
      *  \param  Estructura ePersona
      *  \param  Tamaño de la estructura
      *  \return estructura ordenada
    */
    void ordenarPersonaId(ePersona[], int);

     /** \brief  ordena estructura por nombre
      *  \param  Estructura ePersona
      *  \param  Tamaño de la estructura
      *  \return estructura ordenada
    */
    void ordenarPersonaNombre(ePersona[], int tampersona);

     /** \brief  Lista los datos de la estructura
      *  \param  Estructura ePersona
      *  \param  Tamaño de la estructura
      *  \return salida por pantalla
    */
    void mostrarListaPersonas(ePersona[], int);

    /** \brief  ingreso de datos de opciones de menú
      *  \param  mensaje a mostrar
      *  \return dato ingresado
    */
     int  opcionesMenu(char[]);
