    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lib.h"
    #include "altaMovie.h"


    int binarioVacio(){
        int registros;
        FILE *archivo;
        archivo=fopen("peliculas.dat", "rb"); //abro modo lectura
        if(archivo==NULL){
            printf("\n\tERROR - No archivo peliculas.dat no existe\n");
            system("pause");
      //      archivo= fopen("peliculas.dat", "wb"); // creo un archivo nuevo
        }
        fread(&registros, sizeof(int), 1, archivo);
        printf("\n\tERROR - %d\n",registros);
        system("pause");
        fclose(archivo);
        return registros;
    }

    void cargarBinario(eMovie *movie, int tammovie){
        FILE *archivo;
        archivo=fopen("peliculas.dat", "rb");
        if(archivo==NULL){
            HardCodeMovie(movie, tammovie);
            archivo=fopen("peliculas.dat", "rb");
            if(archivo==NULL){
                printf("\n\tERROR - No archivo peliculas.dat no existe\n");
            }else{
                fread(movie,sizeof(movie),6,archivo);
                fclose(archivo);
            }
        }
    }

    int contareBinario(eMovie* movies, int tammovie){
        int i;
        int cantMovie;
        for(i=0; i<tammovie; i++){
            cantMovie+=1;
        }
        return cantMovie;
     }


    int contareMovie(eMovie* movies, int tammovie){
        int i;
        int cantMovie;
        for(i=0; i<tammovie; i++){
            cantMovie+=1;
        }
        return cantMovie;
     }

    int eMovieVacio(eMovie* movies, int tammovies){
        int vacio = 0;
        if(movies== NULL){
            vacio = 1;
        }
        return vacio;
    }

    void HardCodeMovie(eMovie* movie, int tammovies){
        int id[6] = {0,1,2,3,4,5};
        char titulo[6][25] = {"Back to the future","The Secret Life of Pets","Assassins Creed","maria cuire","Mind and Machine","The Land of Stealth"};
        char genero[6][16] = {"Aventura","Animacion","Accion","Biografica","Ciencia ficcion","Romance"};
        int duracion[6] = {116,89,120,100,130,116};
        int puntaje[6] = {86,87,92,88,75,68};
        char LinkDeImagen[6][160] = {"http://image.tmdb.org/t/p/w185/xS3k4YTyt5DdaLmbDGxdioi2v3w.jpg","http://image.tmdb.org/t/p/w185/q2icKmDXoj8FSc2IZU3sOIB2EAG.jpg","thumbnails//AssassinsCreed.jpg","http://image.tmdb.org/t/p/w185/7WsyChQLEftFiDOVTGkv3hFpyyt.jpg","thumbnails//Mind-and-Machine.jpg","thumbnails//TheLandofStealth.jpg"};

        for(int i = 0; i<tammovies ; i++){
            (movie+i)->idMovie = 0;
            (movie+i)->estado = 0;
        }
        for(int i = 0; i<6 ; i++){
            (movie+i)->idMovie = id[i];
            strcpy((char*)&((movie+i)->titulo),titulo[i]);
            strcpy((char*)&((movie+i)->genero),genero[i]);
            (movie+i)->duracion = duracion[i];
            (movie+i)->puntaje = puntaje[i];
            strcpy((char*)&((movie+i)->LinkDeImagen),LinkDeImagen[i]);
            (movie+i)->estado = 1;
        }

        grabarBinario(movie, tammovies);
        FILE* miArchivo;
        miArchivo = fopen("peliculas.dat","rb");
        fread(movie, sizeof(eMovie), 6, miArchivo);
        for(int i=0; i<6; i++){
            printf("hardcordeo - - - %d--%s\n", movie[i].idMovie, movie[i].titulo);
        }
        system("pause");
    }

    void grabarBinario(eMovie* movie, int tammovie){
        int i;
        int registros = 0;
        FILE* archivo;
        archivo = fopen("peliculas.dat", "wb");
        if(archivo == NULL){
            printf("\n\tERROR - No archivo peliculas.dat no existe\n");
            system("pause");
        }else{
            for(i=0 ; i<tammovie ; i++){
                if((movie+i)->estado == 1){
                    registros++;
                }
            }
            for(i=0; i<tammovie ; i++){
                if((movie+i)->estado == 1){
                    fwrite((movie+i), sizeof(eMovie), 1, archivo);
                }
            }
            fclose(archivo);
        }
    }

    int guardarArchivo(eMovie* movie){
        FILE *archivo;
        archivo=fopen("peliculas.dat","wb");
        if(archivo == NULL){
            printf("\n\tERROR - No archivo eMovie.bin no existe\n");
            system("pause");
        }
        fwrite(movie,sizeof(movie),1,archivo);
        fclose(archivo);
        return 0;
    }

    void *ingresoDatoChar(char *txt, char *nombre){
        printf("\n\n\n\n\n\t\t%s ",txt);
        fflush(stdin);
        gets(nombre);
        return nombre;
    }

     int ingresoDatoInt(char txt[]){
        int dato;
        printf("\n\n\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        return dato;
    }
    int ingresoNumero(char txt[]){
        char sNum[20];
        int num;
        printf("\n\n\n\n\n\t\t%s ",txt);
        scanf("%s",sNum);
        num=atoi(sNum); /* atoi convierte el numero ingresado como cadena en entero
        en caso de ser posible, de lo contrario retorna 0*/
        if(num!=0 )
            printf("El numero es: %d\n",num);
        else
            printf("No es un numero\n");
        return 0;
   }


    void mostrarListaMovie(eMovie* movie, int tammovie) {

       int i;
        FILE* archivo;
        archivo = fopen("peliculas.dat","rb");
        fread(movie, sizeof(eMovie), 3, archivo);

        for(i=0; i<tammovie; i++){
            if((movie+i)->estado == 1){
                    printf("\n\t\t%-10s  %-10s  %-10d  %-5d", (movie+i)->titulo, (movie+i)->genero, (movie+i)->estado,(movie+i)->idMovie);
            }
        }
    }

     int movieExiste(eMovie movie[], int tammovie, int id){
        int existe = -1;
        int i;
        for(i=0; i<tammovie; i++){
            printf("\n\tERROR %d\n",i);
            system("pause");
             if (movie[i].idMovie == id){
                existe = i;
                break;
            }
        }
        return existe;
    }

   int movieLibre(eMovie* movie, int tammovie){
        int posicion = -1;
        int i;
        for(i=0; i<tammovie; i++){
            printf("xxxx1--%d--%s\n", movie[i].idMovie, (movie+i)->titulo);
            system("pause");
            if ((movie+i)->estado == 0){
                 posicion = i;
            break;
            }
        }
        return posicion;
    }



    int leerPeliculas(eMovie *movie,int tammovie){
        int i;
        int leidos=0;
        eMovie letra;
        FILE* archivo;
        archivo = fopen("peliculas.dat","rb");
        if(archivo==NULL){
            printf("error, no se puede abrir fichero");
        }else{
            fread(&letra, sizeof(letra), 1, archivo);
//            while(!feof(archivo)&&letra.estado!=0){
                for (i=0;i<tammovie;i++){
                leidos+=1;
                printf("%d----%d---%d---%s--\n",leidos,letra.idMovie, letra.estado, letra.titulo);
                fread(&letra, sizeof(letra), 1, archivo);
 //           }
 }
            printf("%d---",leidos);
            system ("pause");
        fread(movie, sizeof(eMovie), 1, archivo);
        fclose(archivo);
      }
	return leidos;
}


//    if((listadoMovies+i)->estado == 1)
 //               {
 //                   eMovie_mostrarUno(listadoMovies+i);
 //               }

/*
int eMovie_init(eMovie* listadoMovies, int limiteMovies)
{
    int retorno = -1;
    int i;

    if(listadoMovies != NULL && limiteMovies > 0)
    {
        retorno = 0;
        for(i=0 ; i<limiteMovies ; i++)
        {
            (listadoMovies+i)->estado= 0;
            (listadoMovies+i)->idMovie= 0;
        }
    }
    return retorno;
}
*/

/*

*/

/*
int eMovie_siguienteId(eMovie* listadoMovies, int limiteMovies)
{
    int retorno = -1;
    int i;

    if(listadoMovies != NULL && limiteMovies > 0)
    {
        retorno = 0;
        for(i=0; i<limiteMovies; i++)
        {
            if((listadoMovies+i)->estado == 1)
            {
                if((listadoMovies+i)->idMovie > retorno)
                {
                     retorno = (listadoMovies+i)->idMovie + 1;
                }
            }
        }
    }
    return retorno;
}

*/

/*

int eMovie_estaVacio(eMovie* listadoMovies, int limiteMovies)
{
    int retorno = -1;
    int i;

    if(listadoMovies != NULL && limiteMovies > 0)
    {
        retorno = 1;
        for(i=0 ; i<limiteMovies ; i++)
        {
            if((listadoMovies+i)->estado == 1)
            {
                retorno = 0;
                break;//con el primer ocupado ya se que no esta vacio
            }
        }
    }
    return retorno;
}


*/


/*

int eMovie_buscarPorId(eMovie* listadoMovies, int limiteMovies, int idMovie)
{
    int retorno = -1;
    int i;

    if(listadoMovies != NULL && limiteMovies > 0)
    {
        retorno = -2;
        for(i=0 ; i<limiteMovies ; i++)
        {
            if((listadoMovies+i)->estado == 1 && (listadoMovies+i)->idMovie == idMovie)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

*/
/*
void eMovie_pedirNombre(char* retorno)
{
//    pedirStringValido(retorno, MONEDA_MSJ_INGRESE_NOMBRE, MONEDA_MSJ_REINGRESE_NOMBRE, MONEDA_LARGO_NOMBRE);
}

void eMovie_pedirPais(char* retorno)
{
//    pedirStringValido(retorno, MONEDA_MSJ_INGRESE_PAIS, MONEDA_MSJ_REINGRESE_PAIS, MONEDA_LARGO_PAIS);
}
*/

/*
eMovie eMovie_pedirIngreso(eMovie* listadoMovies, int limiteMovies)
{
    eMovie retorno;

    retorno.idMovie = eMovie_siguienteId(listadoMovies, limiteMovies);

//    eMovie_pedirNombre((char *)&(retorno.nombre));

//    eMovie_pedirPais((char *)&(retorno.pais));

    retorno.estado = 1;

    return retorno;
}


int eMovie_mostrarUno(eMovie* propietario)
{
     int retorno = -1;

     if(propietario != NULL)
     {
        retorno = 0;
//        printf(MONEDA_MOSTRAR_UNO_MASCARA, propietario->idMovie, propietario->nombre, propietario->pais);
     }
     return retorno;
}

int eMovie_mostrarListado(eMovie* listadoMovies, int limiteMovies)
{
    int retorno = -1;
//    int i;

    if(listadoMovies != NULL && limiteMovies > 0)
    {
        retorno = 0;
//        if(eMovie_informarListadoVacio(listadoMovies, limiteMovies) == 0)
//        {
//            imprimirEnPantalla(MONEDA_MOSTRAR_UNO_CABECERA);

 //           for(i=0 ; i<limiteMovies ; i++)
 //           {
 //               if((listadoMovies+i)->estado == 1)
 //               {
 //                   eMovie_mostrarUno(listadoMovies+i);
 //               }
  //          }
     //   }
    }
    return retorno;
}
*/


/*
int eMovie_alta(eMovie* listadoMovies, int limiteMovies)
{
    int retorno = -1;
    eMovie registro;
    char confirmacion;
//    int posicion;

    if(listadoMovies != NULL && limiteMovies > 0)
    {
        retorno = 0;
//        limpiarPantalla();
//        imprimirTitulo(MONEDA_ALTA_TITULO);

//        posicion = eMovie_buscarLugarLibre(listadoMovies, limiteMovies);
//        if(posicion < -1)
//        {
////            imprimirEnPantalla(MONEDA_MSJ_NO_MAS_LUGAR);
//        }
//        else if(posicion < 0)
//        {
 //           retorno = posicion;
 //       }
 //       else
 //       {
  //          registro = eMovie_pedirIngreso(listadoMovies, limiteMovies);

//            imprimirEnPantalla(MONEDA_MOSTRAR_UNO_CABECERA);
 //           eMovie_mostrarUno(&registro);

//            confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

//            if(confirmacion == 'S')
//            {
//                *(listadoMovies+posicion) = registro;
//                eMovie_ordenar(listadoMovies, limiteMovies, MONEDA_ORDEN_NOMBRE);
//                imprimirEnPantalla(MONEDA_MSJ_ALTA_OK);
 //           }
//            else
//            {
//                imprimirEnPantalla(MSJ_CANCELO_GESTION);
//            }
 //       }
//        pausa();
    }
    return retorno;
}
*/
/*
int eMovie_ordenar(eMovie* listadoMovies, int limiteMovies, char* orden)
{
    int retorno = -1;
    int i;
    int j;
    eMovie aux;

    if(listadoMovies != NULL && limiteMovies > 0)
    {
        retorno = 0;
        if(strcmp(orden, "idAsc") == 0)
        {
            for(i=0 ; i<limiteMovies-1 ; i++)
            {
                for(j=i+1 ; j<limiteMovies ; j++)
                {
                    if((listadoMovies+i)->idMovie > (listadoMovies+j)->idMovie)
                    {
                        aux = *(listadoMovies+i);
                        *(listadoMovies+i) = *(listadoMovies+j);
                        *(listadoMovies+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "idDesc") == 0)
        {
            for(i=0 ; i<limiteMovies-1 ; i++)
            {
                for(j=i+1 ; j<limiteMovies ; j++)
                {
                    if((listadoMovies+i)->idMovie < (listadoMovies+j)->idMovie)
                    {
                        aux = *(listadoMovies+i);
                        *(listadoMovies+i) = *(listadoMovies+j);
                        *(listadoMovies+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "nombreAsc") == 0)
        {
            for(i=0 ; i<limiteMovies-1 ; i++)
            {
                for(j=i+1 ; j<limiteMovies ; j++)
                {
//                    if(strcmpi((listadoMovies+i)->nombre, (listadoMovies+j)->nombre) > 0)
                    {
                        aux = *(listadoMovies+i);
                        *(listadoMovies+i) = *(listadoMovies+j);
                        *(listadoMovies+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "nombreDesc") == 0)
        {
            for(i=0 ; i<limiteMovies-1 ; i++)
            {
                for(j=i+1 ; j<limiteMovies ; j++)
                {
//                    if(strcmpi((listadoMovies+i)->nombre, (listadoMovies+j)->nombre) < 0)
                    {
                        aux = *(listadoMovies+i);
                        *(listadoMovies+i) = *(listadoMovies+j);
                        *(listadoMovies+j) = aux;
                    }
                }
            }
        }
    }
    return retorno;
}
*/

/*
int eMovie_modificarUno(eMovie* registro)
{
    int retorno = -1;
//    eMenu menuModificar = {cantidad de opciones MONEDA_MENU_MODIFICAR_UNO_CANT,
//                            codigos{1,2,0},
 //                           descripciones{MONEDA_MENU_MODIFICAR_UNO_DETALLE1,MONEDA_MENU_MODIFICAR_UNO_DETALLE2,MONEDA_MENU_MODIFICAR_UNO_DETALLE0},
 //                           titulo del menu{MONEDA_MENU_MODIFICAR_UNO_TITULO}};
//    int opcion;

    if(registro != NULL)
    {
        retorno = 1;
//        ejecutarEnConsola(LIMPIAR_PANTALLA);
//        imprimirTitulo(MSJ_MODIFICANDO_REGISTRO);
//        imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);
 //       imprimirEnPantalla(MONEDA_MOSTRAR_UNO_CABECERA);

        eMovie_mostrarUno(registro);

//        opcion = pedirOpcion(&menuModificar);
//        switch(opcion)
//        {
//            case 1:
//                eMovie_pedirNombre((char *)&registro->nombre);
//                break;
//            case 2:
//                eMovie_pedirPais((char *)&registro->pais);
//                break;
//            case 0:
//                retorno = 0;
//                break;
//        }
    }
    return retorno;
}
*/

/*
int eMovie_pedirIdYBuscar(eMovie* listadoMovies, int limiteMovies)
{
    int retorno=0;
//    int idMovie;

//    do
//    {
//        eMovie_mostrarListado(listadoMovies, limiteMovies);
//        idMovie = pedirIntValido(MONEDA_MSJ_INGRESE_ID, MONEDA_MSJ_REINGRESE_ID, MONEDA_ID_MIN, MONEDA_ID_MAX);
//        retorno = eMovie_buscarPorId(listadoMovies, limiteMovies, idMovie);
//        if(retorno < 0)
//        {
//            imprimirEnPantalla(MONEDA_MSJ_ID_NO_EXISTE);
//            pausa();
 //       }
 //   }
//    while(retorno < 0);

    return retorno;
}
*/

/*
int eMovie_modificacion(eMovie* listadoMovies, int limiteMovies)
{
    eMovie registro;
    char confirmacion;
    int posicion;
    int huboCambios;

//    ejecutarEnConsola(LIMPIAR_PANTALLA);
//    imprimirTitulo(MONEDA_MODIFICACION_TITULO);

    if(eMovie_estaVacio(listadoMovies, limiteMovies) == 1)
    {
//        imprimirEnPantalla(MONEDA_MSJ_LISTA_VACIA);
    }
    else
    {
        posicion = eMovie_pedirIdYBuscar(listadoMovies, limiteMovies);
        //traigo el registro del id elegido para no pisar directo sobre el listadoMovies
        registro = listadoMovies[posicion];

        huboCambios = eMovie_modificarUno(&registro);
        if(huboCambios == 1)
        {
            //if(aca se pregunta si hubo cambios que requieran reprocesar)
         //   {
          //      se recalcularian promedios por ej->
         //   }

//            ejecutarEnConsola(LIMPIAR_PANTALLA);
//            imprimirTitulo(MONEDA_MODIFICACION_TITULO);

 //           imprimirEnPantalla(MONEDA_MSJ_REGISTRO_ACTUAL);
 //           eMovie_mostrarUno(listadoMovies+posicion);

   //         imprimirEnPantalla(MONEDA_MSJ_REGISTRO_MODIFICADO);
    //        eMovie_mostrarUno(&registro);

     //       confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);
        }
        else
        {
            confirmacion = 'N';
        }

        if(confirmacion == 'S')
        {
            listadoMovies[posicion] = registro;
//            eMovie_ordenar(listadoMovies, limiteMovies, MONEDA_ORDEN_ID);


//            imprimirEnPantalla(MONEDA_MSJ_MODIFICACION_OK);
        }
        else
        {
//            imprimirEnPantalla(MSJ_CANCELO_GESTION);
        }
    }

//    ejecutarEnConsola(HACER_PAUSA);
}
*/
/*

int eMovie_baja(eMovie* listadoMovies, int limiteMovies)
{
//    char confirmacion;
    int posicion;
    int idMovie=0;

//    ejecutarEnConsola(LIMPIAR_PANTALLA);
//    imprimirTitulo(MONEDA_BAJA_TITULO);

    if(eMovie_estaVacio(listadoMovies, limiteMovies) == 1)
    {
//        imprimirEnPantalla(MONEDA_MSJ_LISTA_VACIA);
    }
    else
    {
//        ejecutarEnConsola(LIMPIAR_PANTALLA);
//        imprimirTitulo(MONEDA_BAJA_TITULO);

        posicion = eMovie_pedirIdYBuscar(listadoMovies, limiteMovies);

//        imprimirEnPantalla(MONEDA_MOSTRAR_UNO_CABECERA);
        eMovie_mostrarUno(listadoMovies+posicion);

//        confirmacion = pedirConfirmacion(MONEDA_MSJ_CONFIRMAR_BAJA);

//        if(confirmacion == 'S')
//        {
//            idMovie = (listadoMovies+posicion)->idMovie;
//            (listadoMovies+posicion)->estado = LIBRE;
//            imprimirEnPantalla(MONEDA_MSJ_BAJA_OK);
//        }
//        else
//        {
//            imprimirEnPantalla(MSJ_CANCELO_GESTION);
//        }
    }

//    ejecutarEnConsola(HACER_PAUSA);
    return idMovie;
}
*/


/*
    void burbujeo(eMovie movie[], int i,int j){
        int idMovieAux=movie[i].idMovie;
        movie[i].idMovie=movie[j].idMovie;
        movie[j].idMovie=idMovieAux;

        char nombreAux[25];
        strcpy(nombreAux,movie[i].nombre);
        strcpy(movie[i].nombre,movie[j].nombre);
        strcpy(movie[j].nombre,nombreAux);

        char domicilioAux[25];
        strcpy(domicilioAux,movie[i].domicilio);
        strcpy(movie[i].domicilio,movie[j].domicilio);
        strcpy(movie[j].domicilio,domicilioAux);

        char nroTarjetaAux[25];
        strcpy(nroTarjetaAux,movie[i].nroTarjeta);
        strcpy(movie[i].nroTarjeta,movie[j].nroTarjeta);
        strcpy(movie[j].nroTarjeta,nroTarjetaAux);

        int auxEstado=movie[i].estado;
        movie[i].estado=movie[j].estado;
        movie[j].estado=auxEstado;
    }
    void HardCodeMovie(eMovie movie[], int tammovies){
        int id[20] = {1015,1014,1004,1003,1006};
        char nombre[][25]= {"Mariana","Mauro  ","Laura  ","Vanesa ","Gustavo"};
        char domicilio[][25] = {"2809454","25978654","2287466","12941598","9619629"};
        char nroTarjeta[][25] = {"1700 1700","4000 4000","4500 4500","6400 6400","2400 2400"};
        int estado[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        int i;
         for(i=0; i<tammovies; i++){
            movie[i].estado = 0;
            movie[i].idMovie = 0;
        }
        for(i=0; i<5; i++){
            movie[i].idMovie = id[i];
            strcpy(movie[i].nombre, nombre[i]);
            strcpy(movie[i].domicilio, domicilio[i]);
            strcpy(movie[i].nroTarjeta, nroTarjeta[i]);
            movie[i].estado = estado[i];
        }
    }


    int movieExiste(eMovie movie[], int tammovie, int id){
        int existe = -1;
        int i;
        for(i=0; i<tammovie; i++){
             if (movie[i].idMovie == id){
                existe = i;
                break;
            }
        }
        return existe;
    }

    void ordenarMovieId(eMovie movie[], int tammovie){
        for(int i=0;i<tammovie-1; i++){
            for(int j=i+1;j<tammovie; j++){
                if(movie[i].idMovie > movie[j].idMovie){
                    burbujeo(movie, i,j);
                }
            }
        }
    }
    void ordenarMovieNombre(eMovie movie[], int tammovie){
        for(int i=0;i<tammovie-1; i++){
            for(int j=i+1;j<tammovie; j++){
                if(strcmp(movie[j].nombre,movie[i].nombre)<0){
                   burbujeo(movie, i, j);
                }
            }
        }
    }
 */
    int opcionesMenu(char txt[]){
        int dato;
        printf("\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        return dato;
    }


