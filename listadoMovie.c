    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lib.h"
    #include "listadoMovie.h"

    void listadoMovie(eMovie* movie, int tammovies) {
        system("cls");
        printf("\t --------------------------------------------------------------\n");
        printf("\t|             Sistema Movie - Listado  -version 1.0            |\n");
        printf("\t --------------------------------------------------------------\n");
        leerPeliculas(movie, tammovies);
        int leidos=0;
        char ResultString[4];
        int i=0;
        eMovie letra;
        FILE* archivo;
        archivo = fopen("peliculas.dat","rb");
        if(archivo==NULL){
            printf("error, no se puede abrir fichero");
        }else{
            fread(&letra, sizeof(letra), 1, archivo);
            while(!feof(archivo)&&letra.estado!=0){
                fread(&letra, sizeof(letra), 1, archivo);
                printf("%d----%d---%s---%s--\n",leidos,letra.idMovie, letra.titulo, letra.genero);
                leidos+=1;
            }
            printf("%d---",leidos);
            system ("pause");
        fread(movie, sizeof(eMovie), 1, archivo);
        char buffer[5000]= {};
        strcat(buffer,"<html>"
        "<head>"
        "<table style='width: 900px;background-color: #00ffff;'>"
        "<tbody>"
        "<tr>"
        "<td style='width: 366px; text-align: center;'>"
        "<h2><span style='color: #ff0000;'>listado de peliculas</span></h2>"
        "</td>"
        "</tr>"
        "</tbody>"
        "</table>");
        for(i=0; i<leidos; i++){
            strcat(buffer,"<table border='1' style='border-collapse: collapse; width: 100%'>"
            "<table style='height: 53px;' width='600'>"
            "<tbody>"
            "<tr>"
            "<td style='width: 180px;'>"
            "<a href='#'>"
            "<img class='img-responsive img-rounded' src='");
            strcat(buffer,(movie+i)->LinkDeImagen);
            strcat(buffer,"' alt=''></a>"
            "</td>"
            "<td>"
            "<ul>"
            "<h3>"
            "<a href='#'>");
            strcat(buffer,(movie+i)->titulo);
            strcat(buffer,"</a>"
            "</h3>"
            "<li>G�nero : ");
            strcat(buffer,(movie+i)->genero);
            strcat(buffer,"</li><li>Puntaje : ");
            sprintf(ResultString,"%d",(movie+i)->puntaje);
            strcat(buffer,ResultString);
            strcat(buffer,"</li><li>Duraci�n:");
            sprintf(ResultString,"%d",(movie+i)->duracion);
            strcat(buffer,ResultString);
            strcat(buffer,"</li>"
            "</ul>"
            "<li>The presidencies of Kennedy and Johnson, Vietnam, Watergate, and other history unfold through the perspective of an Alabama man with an IQ of 75</li>"
            "</ul>"
            "</td>"
            "</tr>"
            "</tbody>"
            "</table>");
        }
        strcat(buffer,"</body></html>");
        archivo = fopen("prueba.html","w");
        fprintf(archivo,buffer);
        fclose(archivo);
        printf("\n\n\n\n\n.");
        system("pause");
    }
}



