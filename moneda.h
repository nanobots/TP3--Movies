
    typedef struct{
        int idMovie;
        char titulo[10];
        char genero[10];
        int duracion;
        int puntaje;
        char LinkDeImagen[25];
        int estado;
    }eMovie;

    /** \brief  Carga en la estructura datos para prueba
     *  \param  Estructura eMovie
     *  \return estructura con datos cargados
    */
    void HardCodeMovie(eMovie* movie, int tammovies);


    void mostrarListaMovie(eMovie* movie, int tammovie);
