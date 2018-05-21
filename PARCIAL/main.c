#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
     EProp lisProp[T_CLIENTES];
     EAuto lisAuto[T_AUTOS];

     inicilizar_Prop(lisProp);
     inicializar_Autos(lisAuto);
     //HardCode_Prop(lisProp);
     //HardCode_Autos(lisAuto);
     char dato[100];
     char opcion;
     char seguir='s';


     while(seguir=='s')
    {
        system("cls");
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
        printf("10-\t LISTADO DE AUTOS ESTACIONADOS ORDENADOS POR PATENTE\n");
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
                if (!Ver_BaseCliente_Vacio(lisProp,T_CLIENTES)){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{Mod_Tarj_Cre(lisProp);}

                // MODIFICACION DE PROPIETARI (TARJ DE CREDITO)
                break;
            case 3:
                if (!Ver_BaseCliente_Vacio(lisProp,T_CLIENTES)){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{BajaProp (lisProp,lisAuto);}

                // BAJA DE PROPIETARIO
                break;
            case 4:
                if (!Ver_BaseCliente_Vacio(lisProp,T_CLIENTES)){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{IngresoAuto(lisAuto,lisProp);}


                // INGRESO DE AUTOMOVIL
                break;
            case 5:
                if (!Ver_Estacionamiento_Vacio(lisAuto,T_AUTOS)){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{EgresoAuto(lisAuto,lisProp);}
                // EGRESO DE AUTOMOVIL
                break;
            case 6:
                if (!Ver_Estacionamiento_Vacio(lisAuto,T_AUTOS)){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{RecaudacionTotal(lisAuto);}
                //RECAUDACION TOTAL
                break;
            case 7:
                if (!Ver_Estacionamiento_Vacio(lisAuto,T_AUTOS)){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{RecaudacionTotal_Marca(lisAuto);}
                //RECAUDACION POR MARCA
                break;
            case 8:
                if (!Ver_BaseCliente_Vacio(lisProp,T_CLIENTES)){printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{Autosde1id(lisProp,lisAuto);}
                //LISTAR AUTOS DE UN PROPIETARIO
                break;
            case 9:
                if ((!Ver_Estacionamiento_Vacio(lisAuto,T_AUTOS)) && (!Ver_BaseCliente_Vacio(lisProp,T_CLIENTES))) {printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{ListarPropAudi(lisProp,lisAuto);}
                //LISTAR DATOS DE PROPIETARIO QUE TENGA AUDI
                break;
            case 10:
                if ((!Ver_Estacionamiento_Vacio(lisAuto,T_AUTOS)) && (!Ver_BaseCliente_Vacio(lisProp,T_CLIENTES))) {printf("\n\tDebe realizar la carga de datos en primer lugar. La base de datos del sistema esta vacia.\n\n"); system("pause");}
                else{ListadoOrdenadoAutos(lisProp,lisAuto);}
                //LISTARDO DE AUTOS ESTACIONADOS ORDENADOS POR PATENTE
                break;
            case 11:
                seguir = 'n';
                break;
        }
    }
}
