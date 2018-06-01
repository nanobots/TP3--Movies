    #include <stdio.h>
    #include <stdlib.h>
    #include "lib.h"
    #include "listadoPropietario.h"

    void listadoPropietario(ePropietario propietario[], int tampropietarios) {
        system("cls");
        printf("\t --------------------------------------------------------------\n");
        printf("\t|        Sistema Propietario - Listado  -version 1.0           |\n");
        printf("\t --------------------------------------------------------------\n");
        mostrarListaPropietario(propietario, tampropietarios);
        printf("\n\n\n\n\n.");
        system("pause");
    }



