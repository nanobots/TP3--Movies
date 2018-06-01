    #include <stdio.h>
    #include <stdlib.h>
    #include "lib.h"
    #include "bajaPropietario.h"

    void bajaPropietario(ePropietario propietario[],int tampropietarios) {
        int i;
        int id;
        int salir;
        do{
            salir=0;
            system("cls");
            printf("\t-------------------------------------------------------\n");
            printf("\t|                    Baja de propietario                  |");
            printf("\t-------------------------------------------------------\n");
            ordenarPropietarioId(propietario, tampropietarios);
            mostrarListaPropietario(propietario, tampropietarios);
            printf("\n\n\n\t\t Selecione un propietario a dar de baja - 0 salir : ");
            scanf("%d", &id);
            if(id!=0){
                for(i=0; i<tampropietarios; i++){
                    if(propietario[i].idPropietario == id && propietario[i].estado==1){
                        confirmaBaja(propietario, i);
                        salir=2;
                        break;
                    }else{
                        salir=3;
                    }
                }
                if (salir==3){
                    printf("\n\tPropietario %d no exsiste - ",id);
                    system("pause");
                }
            }
         }while(salir!=0);
       }

       void confirmaBaja(ePropietario propietario[], int id){
        int salir=0;
        do{
            int opcion=0;
            system("cls");
            printf("\t-------------------------------------------------------\n");
            printf("\t|                 Baja de propietario                     |\n");
            printf("\t-------------------------------------------------------\n");
            printf("\n\n\t\t\tPropietario Nro. : %d",propietario[id].idPropietario);
            printf("\n\n\t\t\tNombre           : %s",propietario[id].nombre);
            printf("\n\n\t\t\tDomicilio        : %s",propietario[id].domicilio);
            printf("\n\n\t\t\tNroTarjeta       : %s",propietario[id].nroTarjeta);
            printf("\n\n\n\n\n\n\t\tElija una opcion  1 Confirma baja - 0 Salir :--> ");
            scanf("%d",&opcion);
            if (opcion<0 || opcion>1){
               printf("\n\n\t\t\tError - Debe ingresar entre %d y %d\n",0,1);
               system("\n\n\t\tpause");
            }
            switch(opcion) {
                case  0 :
                    salir=-1;
                    break;
                case 1 :
                   propietario[id].estado=0;
                   salir=-1;
                   break;
            }
    }while(salir!=-1);
  }
