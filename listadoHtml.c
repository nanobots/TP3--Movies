#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listadoHtml()
{
    FILE* archivo;
    char variable[50]="los pelos verdes de agustin!";
    char buffer[1080]= {};

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
        "</table>"
        "<table border='1' style='border-collapse: collapse; width: 100%'>"
        "<tbody>"
        "</tbody>"
        "</table>"
        "<table style='height: 53px;' width='377'>"
        "<tbody>"
        "<tr>"
        "<td style='width: 180px;'>"
        "<a href='#'>"
//        "<img class='img-responsive img-rounded' src='http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg' alt=''>"
        "<img class='img-responsive img-rounded' src='thumbnails//Mind-and-Machine.jpg' alt=''>"
        "</a>"
        "</td>"
        "<td style='width: 50%;'>"
        "<ul>"
        "<li>Género:Aventura</li>"
        "<li>Puntaje:86</li>"
        "<li>Duración:116</li>"
        "</ul>"
        "</td>"
        "</tr>"
        "</tbody>"
        "</table>"
        "</body></html>");
        archivo = fopen("prueba.html","w");
        fprintf(archivo,buffer);
        fclose(archivo);
    return 0;
}
