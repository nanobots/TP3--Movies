    typedef struct{
        int idAutos;
        char patente[25];
        char marca[25];
        int idPropietario;
        char estado;
    }eAutos;


    int buscoAutos(eAutos[], int, int);;
    /** \brief  intercala los datos cuando se ordenan
      *  \param  Estructura eAutos
      *  \param  Tamaño de la estructura
      *  \return datos reubicados
    */
     void burbujeoAutos(eAutos[], int, int);

    /** \brief  Inicializa estructura eAutos
     *  \param  Estructura eAutos
     *  \return estructura inicializada (todos los estados en 0)
    */
    void inicializarEstadoAutos(eAutos[], int);

    /** \brief  Carga en la estructura datos para prueba
     *  \param  Estructura eAutos
     *  \return estructura con datos cargados
    */
    void HardCodeAutos(eAutos[],int i);

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
      *  \param  Estructura eAutos
      *  \param  Tamaño de la estructura
     *  \return id del registro (posicion=1) o si esta lleno(posicion=-1)
    */
    int autosLibre(eAutos[],int);

    /** \brief  buscar si hay lugar para agregar un registro
     *  \return id del registro (posicion=1) o si esta lleno(posicion=-1)
    */
    int autosExiste(eAutos[],int, int);

    /** \brief  verifica si la estructura no contiene datos
      *  \param  Estructura eAutos
      *  \param  Tamaño de la estructura
      *  \return estado de la estructura (0 vacio) o (1 si hay datos)
    */
    int eAutosVacio(eAutos[], int);

    /** \brief  ordena estructura por ID
      *  \param  Estructura eAutos
      *  \param  Tamaño de la estructura
      *  \return estructura ordenada
    */
    void ordenarAutosId(eAutos[], int);

     /** \brief  ordena estructura por nombre
      *  \param  Estructura eAutos
      *  \param  Tamaño de la estructura
      *  \return estructura ordenada
    */
    void ordenarAutosNombre(eAutos[], int tamautos);

     /** \brief  Lista los datos de la estructura
      *  \param  Estructura eAutos
      *  \param  Tamaño de la estructura
      *  \return salida por pantalla
    */
    void mostrarListaAutos(eAutos[], intePropietario[], int);

    /** \brief  ingreso de datos de opciones de menú
      *  \param  mensaje a mostrar
      *  \return dato ingresado
    */
     int  opcionesMenu(char[]);
