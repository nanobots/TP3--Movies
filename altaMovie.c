    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include "lib.h"

     void altaMovie(eMovie* movie, int tammovies, int id) {
        eMovie auxMovie;
        char titulo[20];
        char genero[20];
        int opcion=0;
        int flag=1;
        int flagTitulo=0;
        long int flagGenero=0;
        int flagDuracion=0;
        int flagPuntaje=0;

        do{
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|                 Alta de peliculas                  |\n");
            printf("\t -------------------------------------------------------\n");
            printf("\n\n\n\n\t\tid       : %d",id);
            if (flagTitulo==0){
                printf("\n\n\t\tTitulo   :");
            }else{
                printf("\n\n\t\tTitulo   : %s",auxMovie.titulo);
            }
            if (flagGenero==0){
                printf("\n\n\t\tGenero   :");
            }else{
                printf("\n\n\t\tGenero   : %s",auxMovie.genero);
            }
           if (flagDuracion==0){
                printf("\n\n\t\tDuracion :");
            }else{
                printf("\n\n\t\tDuracion : %d",auxMovie.duracion);
            }
            if (flagPuntaje==0){
                printf("\n\n\t\tPuntaje  :");
            }else{
                printf("\n\n\t\tPuntaje  : %d",auxMovie.puntaje);
            }

            switch(flag){
                case 0:
                    printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                    system("\n\n\t\tpause");
 //               case 1:
 //                   auxMovie.idMovie=ingresoDatoInt("Ingrese movie : ");
 //                   existe=movieExiste(movie, tammovies, auxMovie.idMovie);
 //                   if (existe!=-1){
 //                       printf("\n\n\t\t\tError - El movie %d ya existe\n",auxMovie.idMovie);
 //                       system("\n\n\t\tpause");
 //                    }else{
 //                       flagLegajo = 1;
 //                       flag=2;
 //                   }
 //                   break;
                case 1:
 //                   strcpy(&((auxMovie+id)->titulo),ingresoDatoChar("Ingrese nombre : ",titulo));
//                    strcpy(titulo, ingresoDatoChar("Ingrese nombre : ",titulo));
                    strcpy(auxMovie.titulo, ingresoDatoChar("Ingrese titulo : ",titulo));
                    flagTitulo = 1;
                    flag=2;
                    break;
                case 2:
                    strcpy(auxMovie.genero, ingresoDatoChar("Ingrese genero : ",genero));
                    flagGenero=1;
                    flag=3;
                    break;
                case 3:
                    auxMovie.duracion=ingresoDatoInt("Ingrese duracion : ");
                    flagDuracion=1;
                    flag=4;
                    break;
                case 4:
                    auxMovie.puntaje=ingresoDatoInt("Ingrese puntaje : ");
                    flagPuntaje=1;
                    flag=5;
                    break;
               case 5:
                    flag=6;
                    opcion=opcionesMenu("\n\n\t\tConfirma cambios ?    1-grabar 0-Salir :");
                    if(opcion<0 || opcion>1){
                        printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                        system("pause");
                        flag=5;
                    }else if (opcion==1){
                        (movie+id)->idMovie = id;
                        strcpy((char*)&((movie+id)->titulo),titulo);
                        strcpy((char*)&((movie+id)->genero),genero);
                        (movie+id)->estado = 1;
//                        movie[posicion].idMovie=auxMovie.idMovie;
//                       strcpy(movie[id].titulo, auxMovie.titulo);
//                       strcpy(movie[id].genero, auxMovie.genero);
//                       strcpy(movie[id].duracion, auxMovie.duracion);
//                       movie[id].estado=1;
                        flag=7;
                        break;
                    }else{
                        flag=7;
                        break;
                    }
                }
            }while(flag!=7);
       }
