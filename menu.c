    #include <stdio.h>
    #include <stdlib.h>
    #include "lib.h"
 //   #include "libAutos.h"
 //   #include "altaMovie.h"
 //   #include "modificarMovie.h"
 //   #include "bajaMovie.h"
    #include "listadoMovie.h"
    #include "altaMovie.h"
 //   #include "ingresoAuto.h"
 //   #include "ingresoAutoPanta.h"
  //  #include "egresoAuto.h"


    int menu(eMovie* movie, int tammovies) {

        int opcion;
        int id;
        do{
            int min=1;
            int max=9;
            system("cls");
            printf("\t --------------------------------------------------------------\n");
            printf("\t|              Sistema de Peliculas - version 1.0.0            |\n");
            printf("\t --------------------------------------------------------------");
            printf("\n\n\n\t\t\t1- Alta pelicula");
            printf("\n\n\t\t\t2- Baja de pelicula");
            printf("\n\n\t\t\t3- Modificacion de pelicula");
            printf("\n\n\t\t\t4- Generar pagina web");
            printf("\n\n\t\t\t5- Listado de peliculas");
            printf("\n\n\t\t\t6- Salir");
            opcion=opcionesMenu("Ingrese una opcion ==> ");
            if (opcion< min || opcion>max){
                printf("\n\n\t\t\tError - Debe ingresar entre %d y %d", min, max);
                system("pause");
            }
            switch( opcion ) {
                case  1 :
                    cargarBinario(movie, tammovies);
                    id=movieLibre(movie,tammovies);
                    if(id!=-1){
                        altaMovie(movie, tammovies, id);
                    }else{
                        printf("\n\tERROR - No hay mas espacio para agregar movie\n");
                        system("pause");
                    }
                    break;
                case 2 :
 //                   bajaMovie(movie, tammovies);
 //                   opcion=1;
                   break;
                case 3 :
 //                   modificarMovie(movie, tammovies);
 //                   opcion=1;
                  break;
  //                  ingresoAuto(movie, tammovies, autos, tamautos);
  //                  opcion=-1;

                case 4 :
                   break;
                case 5 :
//                binarioVacio();
                  eMovieVacio(movie, tammovies);
                  listadoMovie(movie, tammovies);
                   opcion=-1;
                   break;
                case 6 :
  //                  id=autoLibre(autos,tamautos);
 //                   if(id!=-1){
  //                      ingresoAutoPanta(movie, tammovies, autos, tamautos);
  //                  }else{
  //                      printf("\n\tERROR - No hay mas espacio para agregar autos\n");
  //                      system("pause");
 //                   }
 //                   opcion=-1;
                    break;
                case 7 :
 //                   mostrarListaAutos(autos, tamautos);
 //                   opcion=-1;
                    break;
                case 8 :
 //                   bajaPropAutos(movie, tammovies, autos, tamautos);
 //                   opcion=0;
                    break;
                case 9 :
 //                   egresoAuto(movie, tammovies, autos, tamautos, factura, tamfactura);
 //                   opcion=0;
                    break;
               case 10 :
 //                   opcion=0;
                    break;
            }
        } while( opcion!=0 );
        return 0;
    }
