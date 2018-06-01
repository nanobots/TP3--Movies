    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include "lib.h"
    #include "libAutos.h"
    #include "ingresoAutoPanta.h"

    void ingresoAutoPanta(ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos) {
        eAutos auxAutos;
        char patente[20];
        int existe;
        int flag=1;
 //       int flagPatente=0;
        do{
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|                 Alta  de autos      patente            |\n");
            printf("\t -------------------------------------------------------\n");
            printf("\n\n\t\tPatente Nro. :");
            printf("\n\n\t\tMarca auto   :");
            printf("\n\n\t\tPropietario  :");
            switch(flag){
                case 0:
                    printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                    system("\n\n\t\tpause");
                case 1:
                    strcpy(auxAutos.patente, ingresoDatoChar("Ingrese patente : ",patente));
                    existe=patenteExiste(autos, tamautos, auxAutos.patente);
                    if (existe!=-1){
                         ingresoMarcaAutos(auxAutos, propietario, tampropietarios, autos, tamautos);
                        flag=7;
                    }else{
                        printf("\n\n\t\t\tError - El autos con patente %s ya existe\n",auxAutos.patente);
                        system("\n\n\t\tpause");
                    }
                    break;
                }
            }while(flag!=7);
    }

    void ingresoMarcaAutos(eAutos auxAutos, ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos) {
        char marca[20];
        int flag=1;
        do{
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|                 Alta  de autos     2222             |\n");
            printf("\t -------------------------------------------------------\n");
            printf("\n\n\t\tPatente Nro. : %s\n",auxAutos.patente);
            strcpy(auxAutos.marca, ingresoDatoChar1("Ingrese marca : ",marca));
            if(strcmp(auxAutos.marca,"NULL")!=0){
                strcpy(auxAutos.marca, marca);
                ingresoClienteAutos(auxAutos, propietario, tampropietarios, autos, tamautos);
                flag=7;
            }else{
                printf("\n\n\t\t\tError - El la marca ingresda no existe\n");
                system("\n\n\t\tpause");
            }
        }while(flag!=7);
    }
    void ingresoClienteAutos(eAutos auxAutos, ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos) {
        int existe;
         int flag=1;
         do{
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|                 Alta  de autos     2222             |\n");
            printf("\t -------------------------------------------------------\n");
            printf("\n\t\tPatente Nro. : %s",auxAutos.patente);
            printf("\n\n\t\tMarca auto   : %s\n",auxAutos.marca);
            printf("\n\t -------------------------------------------------------");
            ordenarPropietarioNombre(propietario, tampropietarios);
            mostrarListaPropietario(propietario, tampropietarios);
            printf("\n\t -------------------------------------------------------\n");
            switch(flag){
                case 0:
                    printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                    system("\n\n\t\tpause");
                case 1:
                    auxAutos.idPropietario=ingresoDatoInt("Ingrese propietario : ");
                    existe=propietarioExiste(propietario, tampropietarios, auxAutos.idPropietario);
                    if (existe!=-1){
                        grabarClienteAutos(auxAutos, propietario, tampropietarios, autos, tamautos);
                        flag=7;
                    }else{
                        printf("\n\n\t\t\tError - El propietario %d no existe\n",auxAutos.idPropietario);
                        system("\n\n\t\tpause");
                        flag=1;
                    }
                break;
            }
        }while(flag!=7);
    }

   void grabarClienteAutos(eAutos auxAutos, ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos) {
        int opcion=0;
        int flag=1;
        int posicion;
        do{
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|                 Alta  de autos     2222             |\n");
            printf("\t -------------------------------------------------------\n");
            printf("\n\t\tPatente Nro. : %s",auxAutos.patente);
            printf("\n\n\t\tMarca auto   : %s",auxAutos.marca);
            printf("\n\n\t\tPropietario   : %d",auxAutos.idPropietario);
            opcion=opcionesMenu("\n\n\t\tConfirma cambios ?    1-grabar 0-Salir :");

            if(opcion<0 || opcion>1){
                printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                system("\n\n\t\tpause");
                flag=3;
            }else if (opcion==1){
                posicion=autoLibre(autos,tamautos);
                strcpy(autos[posicion].patente, auxAutos.patente);
                strcpy(autos[posicion].marca, auxAutos.marca);
                autos[posicion].idPropietario=auxAutos.idPropietario;
                autos[posicion].estado=1;
                flag=7;
                break;
            }
        }while(flag!=7);
    }
