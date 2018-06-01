    #include <stdio.h>
    #include <string.h>
    #include "lib.h"
    #include "grafico.h"

    void burbujeo(ePropietario propietario[], int i,int j){
        int auxId=propietario[i].idPropietario;
        propietario[i].idPropietario=propietario[j].idPropietario;
        propietario[j].idPropietario=auxId;
        char auxnombre[50];
        strcpy(auxnombre,propietario[i].nombre);
        strcpy(propietario[i].nombre,propietario[j].nombre);
        strcpy(propietario[j].nombre,auxnombre);
        int auxDni=propietario[i].dni;
        propietario[i].dni=propietario[j].dni;
        propietario[j].dni=auxDni;
        int auxEdad=propietario[i].edad;
        propietario[i].edad=propietario[j].edad;
        propietario[j].edad=auxEdad;
        int auxEstado=propietario[i].estado;
        propietario[i].estado=propietario[j].estado;
        propietario[j].estado=auxEstado;
    }
    void HardCodePropietario(ePropietario propietario[], int tampropietarios){
        int id[20] = {1015,1014,1004,1003,1006,1005,1008,1007,1009,1010,1011,1012,1013,1001,1002};
        char nombre[][50]= {"Mariana","Mauro","Laura","Vanesa","Gustavo","Alexandra","Marcelo","Natalia","Victoria","Gisela","Antonela","Patricia","Santiago","Pedro","Romualdo"};
        int dni[20] = {2809454,25978654,2287466,12941598,9619629,93864644,20458689,309459850,24665454,317910522,19262912,31854965,28226657,30867155,94769558};
        int edad[20] = {17,40,45,64,24,26,68,16,19,15,39,17,23,14,15};
        int estado[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        int i;
         for(i=0; i<tampropietarios; i++){
            propietario[i].estado = 0;
        }
        for(i=0; i<20; i++){
            propietario[i].idPropietario = id[i];
            strcpy(propietario[i].nombre, nombre[i]);
            propietario[i].dni = dni[i];
            propietario[i].edad = edad[i];
            propietario[i].estado = estado[i];
        }
    }
    int ePropietarioVacio(ePropietario propietario[], int tampropietario){
        int vacio = 0;
        int i;
        for(i=0; i<tampropietario; i++){
             if (propietario[i].estado != 0){
                vacio = 1;
                break;
            }
        }
        return vacio;
    }
    int ingresoDatoInt(char txt[]){
        int dato;
        printf("\n\n\n\n\n\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        return dato;
    }
    void *ingresoDatoChar(char *txt, char *nombre){
        printf("\n\n\n\n\n\n\n\n\t\t%s ",txt);
        fflush(stdin);
        gets(nombre);
 //        nombre=substring(nombre, 30);
        return nombre;
    }
    int propietarioExiste(ePropietario propietario[], int tampropietario, int id){
        int existe = 0;
        int i;
        for(i=0; i<tampropietario; i++){
             if (propietario[i].idPropietario == id){
                existe = -1;
                break;
            }
        }
        return existe;
    }
    int propietarioLibre(ePropietario buscar[], int registros){
        int posicion = -1;
        int i;
        for(i=0; i<registros; i++){
            if (buscar[i].estado == 0){
                 posicion = 1;
            break;
            }
        }
        return posicion;
    }
    void mostrarListaPropietario(ePropietario propietario[], int tampropietario) {
        int i;
        printf("\n\t\tpropietario            nombre\n");
        for(i=0; i<tampropietario; i++){
            if(propietario[i].estado == 1){
                 printf("\n\t\t%1d          %1s", propietario[i].idPropietario, propietario[i].nombre);
            }
        }
    }
    void ordenarPropietarioId(ePropietario propietario[], int tampropietario){
        for(int i=0;i<tampropietario-1; i++){
            for(int j=i+1;j<tampropietario; j++){
                if(propietario[i].idPropietario > propietario[j].idPropietario){
                    burbujeo(propietario, i,j);
                }
            }
        }
    }
    void ordenarPropietarioNombre(ePropietario propietario[], int tampropietario){
        for(int i=0;i<tampropietario-1; i++){
            for(int j=i+1;j<tampropietario; j++){
                if(strcmp(propietario[j].nombre,propietario[i].nombre)<0){
                   burbujeo(propietario, i, j);
                }
            }
        }
    }
    int opcionesMenu(char txt[]){
        int dato;
        printf("\n\n\n\t\t%s ",txt);
        scanf("%d", &dato);
        return dato;
    }

