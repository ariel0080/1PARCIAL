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
        printf("1- ALTA DE PROPIETARIO\n");
        printf("2- MODIFICACION DE TARJETA DE CREDITO DE PROPIETARIO\n");
        printf("3- BAJA DE PROPIETARIO\n");
        printf("4- INGRESO DE AUTOMOVIL\n");
        printf("5- EGRESO DE AUTOMOVIL\n");
        printf("6- RECAUDACION TOTAL\n");
        printf("7- RECAUDACION POR MARCA\n");
        printf("8- LISTAR AUTOS DE UN PROPIETARIO\n");
        printf("9- LISTAR DATOS DE PROPIETARIO QUE TENGA AUDI\n");
        printf("10- LISTARDO DE AUTOS ESTACIONADOS ORDENADOS POR PATENTE\n");
        printf("11- Salir\n");


        scanf("%d",&opcion);
        fflush(stdin);

     switch(opcion)
        {
            case 1:
                AltaPropietario(lisProp);
                // ALTA DE PROPIETARIO
                break;
            case 2:
                Mod_Tarj_Cre (lisProp);
                // MODIFICACION DE PROPIETARI (TARJ DE CREDITO)
                break;
            case 3:
                BajaProp (lisProp,lisAuto);
                // BAJA DE PROPIETARIO
                break;
            case 4:
                IngresoAuto(lisAuto);
                // INGRESO DE AUTOMOVIL
                break;
            case 5:
                // EGRESO DE AUTOMOVIL
                break;
            case 6:
                //RECAUDACION TOTAL
                break;
            case 7:
                //RECAUDACION POR MARCA
                break;
            case 8:
                //LISTAR AUTOS DE UN PROPIETARIO
                break;
            case 9:
                //LISTAR DATOS DE PROPIETARIO QUE TENGA AUDI
                break;
            case 10:
                //LISTARDO DE AUTOS ESTACIONADOS ORDENADOS POR PATENTE
                break;
            case 11:
                seguir = 'n';
                break;
        }
    }
}
