    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include "lib.h"
    #include "libAutos.h"
    #define MARCAAUTO(defAuto) a, b, c

      void ingresoAuto(ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos, eFactura factura[], int tamfactura) {
        eAutos auxAutos;
        int posicion;
        char patente[20];
        char marca[20];
        int existe;
        int opcion=0;
        int flag=1;
        int flagPatente=0;
        int flagMarca=0;
        int flagIdPropietario=0;

        do{
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|                 Alta  de autos                  |\n");
            printf("\t -------------------------------------------------------\n");

            if (flagPatente==0){
                printf("\n\n\t\tPatente Nro. :");
            }else{
                printf("\n\n\t\tPatente Nro. : %s",auxAutos.patente);
            }
            if (flagMarca==0){
                printf("\n\n\t\tMarca auto   :");
            }else{
                printf("\n\n\t\tMarca auto   : %s",auxAutos.marca);
            }
            if (flagIdPropietario==0){
                printf("\n\n\t\tPropietario  :");
            }else{
                printf("\n\n\t\tPropietario  : %d",auxAutos.idPropietario);
            }
            switch(flag){
                case 0:
                    printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                    system("\n\n\t\tpause");
                case 1:
                    strcpy(auxAutos.patente, ingresoDatoChar("Ingrese patente : ",patente));
                    existe=patenteExiste(autos, tamautos, auxAutos.patente);
                    if (existe!=0){
                        flagPatente = 1;
                        flag=2;
                        posicion=autoLibre(autos,tamautos);
                    }else{
                        printf("\n\n\t\t\tError - El autos con patente %s ya existe\n",auxAutos.patente);
                        system("\n\n\t\tpause");
                    }
                    break;
                case 2:
                    strcpy(auxAutos.marca, ingresoDatoChar("Ingrese marca : ",marca));
                    flagMarca=1;
                    flag=3;
                    break;
                case 3:
                    auxAutos.idPropietario=ingresoDatoInt("Ingrese propietario : ");
                    existe=propietarioExiste(propietario, tampropietarios, auxAutos.idPropietario);
                    if (existe==-1){
                       printf("%d",existe);
                        flagIdPropietario = 1;
                        flag=4;
                    }else{
                        printf("\n\n\t\t\tError - El propietario %d no existe\n",auxAutos.idPropietario);
                        system("\n\n\t\tpause");
                        flag=3;
                    }
                    break;
               case 4:
                   flag=5;
                   break;
               case 5:
                    flag=6;
                    opcion=opcionesMenu("\n\n\t\tConfirma cambios ?    1-grabar 0-Salir :");
                    if(opcion<0 || opcion>1){
                        printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                        system("\n\n\t\tpause");
                        flag=5;
                    }else if (opcion==1){
                        strcpy(autos[posicion].patente, auxAutos.patente);
                        strcpy(autos[posicion].marca, auxAutos.marca);
      //                  strcpy(autos[posicion].patente, auxAutos.patente);
                        flag=7;
                    }else{
                        flag=7;
                        break;
                    }
                }
            }while(flag!=7);
       }
