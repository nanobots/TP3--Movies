    typedef struct{
        int idMovie;
        char titulo[25];
        char genero[25];
        int duracion;
        int puntaje;
        char LinkDeImagen[160];
        int estado;
    }eMovie;


    int binarioVacio();

    void cargarBinario(eMovie*, int);

    int contareBinario(eMovie*, int);

    int contareeMovie(eMovie*);

    /** \brief  verifica si la estructura no contiene datos
      *  \param  Estructura eMovie
      *  \param  Tama�o de la estructura
      *  \return estado de la estructura (0 vacio) o (1 si hay datos)
    */
    int eMovieVacio(eMovie*, int);

    /** \brief  Carga en la estructura datos para prueba
     *  \param  Estructura eMovie
     *  \return estructura con datos cargados
    */
    void HardCodeMovie(eMovie*, int);

    int guardarArchivo(eMovie*);

    void grabarBinario(eMovie*, int);

    /** \brief  ingreso de datos tipo char
      *  \param  int
      *  \return dato ingresado
    */
    void *ingresoDatoChar(char[], char[]);

    /** \brief  ingreso de datos tipo int
      *  \param  char()
      *  \return dato ingresado
    */
    int  ingresoDatoInt(char[]);

    /** \brief  mostrar datos de estructur eMovie solo activos
     *  \return salida por pantalla
    */
    int ingresoNumero(char[]);

    /** \brief  ingreso de datos tipo int
      *  \param  char()
      *  \return dato ingresado
    */
    void mostrarListaMovie(eMovie*, int);

    /** \brief  buscar si hay lugar para agregar un registro
     *  \return id del registro (posicion=1) o si esta lleno(posicion=-1)
    */
    int movieExiste(eMovie[],int, int);


     /** \brief  buscar si hay lugar para agregar un registro
      *  \param  Estructura eMovie
      *  \param  Tama�o de la estructura
     *  \return id del registro (posicion=1) o si esta lleno(posicion=-1)
    */
    int movieLibre(eMovie[],int);

    int leerPeliculas(eMovie*, int);


//int eMovie_init(eMovie* listadoMovies, int limiteMovies);
//int eMovie_buscarLugarLibre(eMovie* listadoMovies, int limiteMovies);
int eMovie_siguienteId(eMovie* listadoMovies, int limiteMovies);
int eMovie_buscarPorId(eMovie* listadoMovies, int limiteMovies, int idMovie);
int eMovie_pedirIdYBuscar(eMovie* listadoMovies, int limiteMovies);
int eMovie_estaVacio(eMovie* listadoMovies, int limiteMovies);
int eMovie_informarListadoVacio(eMovie* listadoMovies, int limiteMovies);

void eMovie_pedirNombre(char* retorno);
void eMovie_pedirPais(char* retorno);
eMovie eMovie_pedirIngreso(eMovie* listadoMovies, int limiteMovies);
int eMovie_mostrarUno(eMovie* propietario);
int eMovie_mostrarListado(eMovie* listadoMovies, int limiteMovies);
int eMovie_alta(eMovie* listadoMovies, int limiteMovies);
int eMovie_modificacion(eMovie* listadoMovies, int limiteMovies);
int eMovie_baja(eMovie* listadoMovies, int limiteMovies);
int eMovie_ordenar(eMovie* listado, int limiteMovies, char* orden);

    int buscoMovie(eMovie[], int, int);;
    /** \brief  intercala los datos cuando se ordenan
      *  \param  Estructura eMovie
      *  \param  Tama�o de la estructura
      *  \return datos reubicados
    */
     void burbujeo(eMovie[], int, int);

    /** \brief  Inicializa estructura eMovie
     *  \param  Estructura eMovie
     *  \return estructura inicializada (todos los estados en 0)
    */
    void inicializarEstadoMovie(eMovie[], int);


//    void HardCodeMovie(eMovie[],int i);









    /** \brief  ordena estructura por ID
      *  \param  Estructura eMovie
      *  \param  Tama�o de la estructura
      *  \return estructura ordenada
    */
    void ordenarMovieId(eMovie[], int);

     /** \brief  ordena estructura por nombre
      *  \param  Estructura eMovie
      *  \param  Tama�o de la estructura
      *  \return estructura ordenada
    */
    void ordenarMovieNombre(eMovie[], int tammovie);

     /** \brief  Lista los datos de la estructura
      *  \param  Estructura eMovie
      *  \param  Tama�o de la estructura
      *  \return salida por pantalla
    */
    void mostrarListaMovie(eMovie[], int);

    /** \brief  ingreso de datos de opciones de men�
      *  \param  mensaje a mostrar
      *  \return dato ingresado
    */
     int  opcionesMenu(char[]);
