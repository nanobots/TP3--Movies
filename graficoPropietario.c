    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "lib.h"
    #include "grafico.h"

    void graficoPropietario(ePropietario persona[],int tampersonas) {
        eGrafico grafico[tampersonas];
        inicializarGrafico(grafico, tampersonas);
        int i;
//        int flag=0;
        for(i=0; i<20; i++){
 //           if (persona[i].nroTarjeta<18 &&persona[i].estado==1){
 //               strcpy(grafico[flag].menor18,"*");
 //               flag++;
 //           }
        }
//        flag=0;
        for(i=0; i<20; i++){
 //           if ((persona[i].nroTarjeta>18 && persona[i].nroTarjeta<=35)&&persona[i].estado==1){
 //               strcpy(grafico[flag].entre19y35,"*");
 //                flag++;
 //           }
        }
//        flag=0;
        for(i=0; i<20; i++){
   //         if (persona[i].nroTarjeta>35 && persona[i].estado==1){
    //            strcpy(grafico[flag].mayora35,"*");
     //            flag++;
     //       }
        }
        system("cls");
        printf("\t -----------------------------------------------------------------");
        printf("\n\t|                Grafico de personas por nroTarjeta                     |");
        printf("\n\t -----------------------------------------------------------------");
        for (i=20;i>=0;i--){
                if (persona[i].estado==1){
                    printf("\t\t\t%s\t\t%s\t\t%s   \n",grafico[i].menor18,grafico[i].entre19y35,grafico[i].mayora35);
                }
        }
        printf("\n\t\t Menores de 18    entre 19 y 35     mayores de 35 \n\n\n\n\n");
        system("pause");
    }
