    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lib.h"
    #include "libAutos.h"

    void egresoAuto(ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos, eFactura factura[], int tamfactura) {
        eFactura auxFactura;
        char patente[20];
        int flag=1;
         do{
            system("cls");
            printf("\t -------------------------------------------------------\n");
            printf("\t|                 Egreso de autos                       |\n");
            printf("\t -------------------------------------------------------\n");
            mostrarAutosEstacionados(autos, tamautos, factura, tamfactura);
            switch(flag){
                case 0:
                    printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
                    system("\n\n\t\tpause");
                case 1:
                    strcpy(auxFactura.patente, ingresoDatoChar("Ingrese patente : ",patente));
                    auxFactura.posAuto=patenteExiste(autos, tamautos, auxFactura.patente);
                    if (auxFactura.posAuto!=-1){
                        grabarFacturaAutos(auxFactura, propietario, tampropietarios, autos, tamautos, factura, tamfactura);
                        flag=7;
                    }else{
                        printf("\n\n\t\t\tError - El autos con patente %s no existe\n",auxFactura.patente);
                        system("\n\n\t\tpause");
                    }
                    break;
                }
            }while(flag!=7);
    }
   void grabarFacturaAutos(eFactura auxFactura, ePropietario propietario[], int tampropietarios, eAutos autos[], int tamautos,eFactura factura[], int tamfactura) {
        int opcion=0;
        int flag=1;
        int estadia;
        int total;
        int valorHora;
        do{
            system("cls");
            printf("\t -------------------------------------------------------");
            printf("\n\t|                    TICKETS                            |");
            printf("\n\t -------------------------------------------------------");
            estadia=devolverHorasEstadia();
            valorHora=devolverValorHora(autos[auxFactura.posAuto].marca);
            total=valorHora*estadia;
            printf("\n\n\n\t      Propietario   : %s",propietario[auxFactura.posAuto].nombre);
            printf("\n\n\n\t      Patente Nro.: %s       Marca auto : %s", auxFactura.patente, autos[auxFactura.posAuto].marca);
            printf("\n\n\n\t      Tiempo estacionado : %d Hs.  Valor Hora %d", estadia, valorHora);
            printf("\n\n\n\t\t          Total a Pagar %c%d",36,total);
            printf("\n\n\t -------------------------------------------------------");
            opcion=opcionesMenu("\n\n\t\t\t\t1- Emitir tickets   0- Salir :");
            if(opcion<0 || opcion>1){
                printf("\n\n\t\tError - Debe ingresar entre %d y %d\n",0,1);
                system("\n\n\t\tpause");
                flag=3;
            }else if (opcion==1){
                factura[auxFactura.posAuto].estadia=estadia;
                factura[auxFactura.posAuto].valorHora=valorHora;
                factura[auxFactura.posAuto].total=total;
                factura[auxFactura.posAuto].estado=2;
                flag=7;
                break;
            }
        }while(flag!=7);
    }
