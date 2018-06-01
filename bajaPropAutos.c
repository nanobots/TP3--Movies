    #include <stdio.h>
    #include <stdlib.h>
    #include "lib.h"
    #include "libAutos.h"
    #include "bajaPropietario.h"

    void bajaPropAutos(ePropietario propietario[],int tampropietarios, eAutos autos[], int tamautos) {
        int i;
        int id;
        int salir;
        do{
            salir=0;
            system("cls");
            printf("\t-------------------------------------------------------\n");
            printf("\t|                    Baja de propietario                  |\n");
            printf("\t-------------------------------------------------------\n");
            ordenarPropietarioId(propietario, tampropietarios);
            mostrarListaPropietario(propietario, tampropietarios);
            printf("\n\n\n\t\t Selecione un propietario a dar de baja - 0 salir : ");
            scanf("%d", &id);
            if(id!=0){
                for(i=0; i<tampropietarios; i++){
                    if(propietario[i].idPropietario == id && propietario[i].estado==1){
                        confirmaBajas(propietario, i, autos, tamautos);
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

       void confirmaBajas(ePropietario propietario[], int id, eAutos autos[], int tamautos ){
        int salir=0;
        do{
            int opcion=0;
            system("cls");
            printf("\t-------------------------------------------------------\n");
            printf("\t|                 Baja de propietario                     |\n");
            printf("\t-------------------------------------------------------\n");
            printf("\n\t\tPropietario :\n");
            printf("\n\t\t\tNro.: %d - Nombre: %s\n",propietario[id].idPropietario,propietario[id].nombre);
            printf("\n\t\tAutos estacionados:\n");
            for (int i=0;i<tamautos;i++){
                if (autos[i].idPropietario==propietario[id].idPropietario){
                printf("\n\t\t\t%s           %s", autos[i].patente ,autos[i].marca);
                }
            }
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
                    for (int i=0;i<tamautos;i++){
                        if (autos[i].idPropietario==propietario[id].idPropietario){
                            autos[i].estado=0;
                        }
                    }
                    propietario[id].estado=0;
                    salir=-1;
                    break;
            }
    }while(salir!=-1);
  }
