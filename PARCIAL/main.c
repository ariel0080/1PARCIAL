#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
     EProp lisProp[20];
     EAuto lisAuto[20];

     char dato[100];
     char opcion;
     char seguir='s';


     while(seguir=='s')
    {
        printf("\n\tSISTEMA DE ESTACIONAMIENTO\n");
        printf("\t==========================\n\n");
        printf("\tINGRESE OPCION DESEADA\n\n");
        printf("\n\n\n1-\t ALTA DE PROPIETARIO\n");
        printf("2-\t MODIFICACION DE TARJETA DE CREDITO DE PROPIETARIO\n");
        printf("3-\t BAJA DE PROPIETARIO\n");
        printf("4-\t INGRESO DE AUTOMOVIL\n");
        printf("5-\t EGRESO DE AUTOMOVIL\n");
        printf("6-\t RECAUDACION TOTAL\n");
        printf("7-\t RECAUDACION POR MARCA\n");
        printf("8-\t LISTAR AUTOS DE UN PROPIETARIO\n");
        printf("9-\t LISTAR DATOS DE PROPIETARIO QUE TENGA AUDI\n");
        printf("10-\t LISTARDO DE AUTOS ESTACIONADOS ORDENADOS POR PATENTE\n");
        printf("11-\t SALIR\n");


        scanf("%d",&opcion);
        fflush(stdin);

     switch(opcion)
        {
            case 1:
                AltaPropietario(lisProp);


                // ALTA DE PROPIETARIO
                break;
            case 2:
                if (){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{Mod_Tarj_Cre (lisProp);}

                // MODIFICACION DE PROPIETARI (TARJ DE CREDITO)
                break;
            case 3:
                if (){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{BajaProp (lisProp,lisAuto);}

                // BAJA DE PROPIETARIO
                break;
            case 4:
                IngresoAuto(lisAuto);

                // INGRESO DE AUTOMOVIL
                break;
            case 5:
                if (){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{}
                // EGRESO DE AUTOMOVIL
                break;
            case 6:
                if (){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{}
                //RECAUDACION TOTAL
                break;
            case 7:
                if (){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{}
                //RECAUDACION POR MARCA
                break;
            case 8:
                if (){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{}
                //LISTAR AUTOS DE UN PROPIETARIO
                break;
            case 9:
                if (){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{}
                //LISTAR DATOS DE PROPIETARIO QUE TENGA AUDI
                break;
            case 10:
                if (FlagCargaA==0){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{}
                //LISTARDO DE AUTOS ESTACIONADOS ORDENADOS POR PATENTE
                break;
            case 11:
                seguir = 'n';
                break;
        }
    }
}
