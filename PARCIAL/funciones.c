#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "funciones.h"
#include <string.h>
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4
#define T_AUTOS 20


int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

int obtenerEspacioLibre(EProp lisProp[])
{

    int i=0;
    while (lisProp[i].estado == 1 && i<T_AUTOS)
        {
            i++;
            if (i==T_AUTOS){return -1;}
        }
    return i;

}

void AltaPropietario(EProp lisProp[])
{
    char dato[100];
    int indice;
    indice = obtenerEspacioLibre(lisProp);
    if (indice == -1)
    {
        system("cls");
        printf("\t\t\t NO SE PUEDEN AGREGAR MAS RESGISTROS A LA BASE DE PERSONAS");
        system("pause");
    }
    else
    {
        lisProp[indice].idPropietario = indice+100;

        printf("\nIngrese nombre: ");
        fgets(dato,100,stdin);
        strcpy(lisProp[indice].nom_ape,dato);

        printf("\nIngrese direccion: ");
        fgets(dato,100,stdin);
        strcpy(lisProp[indice].direc,dato);

        printf("\nIngrese n%c tarjeta de credito: ",167);
        fgets(dato,100,stdin);
        strcpy(lisProp[indice].tarjCred,dato);

        lisProp[indice].estado =1;
    }

}

void Mod_Tarj_Cre (EProp lisProp[])
{
    char dato[100];
    int a=0;
    printf("\nIngrese nombre de la persona que modifico su tarjeta: ");
    fgets(dato,100,stdin);

    while(strcmp(lisProp[a].nom_ape,dato)!=0 && a<20)
    {
        a++;
    }

    if(a==20){printf("\nNo existe la persona ingresada");}

    else
    {
        printf("\nIngrese nueva tarjeta de credito: ");
        fgets(dato,100,stdin);
        strcpy(lisProp[a].tarjCred,dato);
    }


}

void BajaProp (EProp lisProp[] ,EAuto lisAuto[])
{
    int id;
    int a=0;
    char resp;
    int costoAudi=0;
    int costoAlpha=0;
    int costoFerrari =0;
    int costoOtros=0;

    printf("\nIngrese Id de propietario a dar de baja: ");
    scanf("%d",&id);
    fflush(stdin);

    while(lisProp[a].idPropietario != id && a<20)
    {
        a++;
    }

    if(a==20){printf("\nNo existe la persona ingresada\n\n");system("pause");}

    else
    {
        printf("\nDesea dar de baja a: %s %s %s]???", lisProp[a].nom_ape, lisProp[a].direc, lisProp[a].tarjCred);
        printf("\ns para borrar, cualquier otro caracter para desistir\n");
        scanf("%c",&resp);
        fflush(stdin);
        if (resp=='s'){lisProp[a].estado =0;}

        for(int x;x<20;x++)
        {
            if(lisAuto[x].idPropietario == lisProp[a].idPropietario && lisAuto[x].idPropietario != -1)
            {
                if(lisAuto[x].marca == 1){costoAlpha=costoAlpha*devolverHorasEstadia()*150;}
                if(lisAuto[x].marca == 2){costoFerrari=costoFerrari*devolverHorasEstadia()*175;}
                if(lisAuto[x].marca == 3){costoAudi=costoAudi*devolverHorasEstadia()*200;}
                if(lisAuto[x].marca == 4){costoOtros=costoOtros*devolverHorasEstadia()*250;}

                lisAuto[x].estado =0;

                printf("\nValor a cobrar por autos estacionados: %d\n",costoAlpha+costoAudi+costoFerrari+costoOtros);
                system("pause");

            }
        }
    }
}

void IngresoAuto(EAuto lisAuto[])
{
    char dato[100];
    int indice;
    int idprop;
    int marca;
    indice = obtenerEspacioLibre(lisAuto);
    if (indice == -1)
    {
        system("cls");
        printf("\t\t\t ESTACIONAMIENTO LLENO - NO SE PUEDEN INGRESAR AUTOS");
        system("pause");
    }
    else
    {
        lisAuto[indice].estado =1;

        printf("\nIngrese Id de propietario: ");
        scanf("%d",&idprop);
        fflush(stdin);
        lisAuto[indice].idPropietario = idprop;

        printf("\Ingrese Patente: ");
        fgets(dato,100,stdin);
        strcpy(lisAuto[indice].patente,dato);

        printf("\Ingrese Marca: ");
        scanf("%d",&marca);
        fflush(stdin);
        lisAuto[indice].marca=marca;
    }


}

void EgresoAuto(EAuto lisAuto[], EProp lisProp[])
{
    char patente[100];
    int costo;
    int costoAudi=0;
    int costoAlpha=0;
    int costoFerrari =0;
    int costoOtros=0;
    char dato[100];
    printf("Ingrese Patente: ");
    fgets(dato,100,stdin);

    for(int a=0;a<20;a++)
    {
        if (strcmp(lisAuto[a].patente,dato)==0)
            {

                if(lisAuto[a].marca == 1){costoAlpha=costoAlpha*devolverHorasEstadia()*150;}
                if(lisAuto[a].marca == 2){costoFerrari=costoFerrari*devolverHorasEstadia()*175;}
                if(lisAuto[a].marca == 3){costoAudi=costoAudi*devolverHorasEstadia()*200;}
                if(lisAuto[a].marca == 4){costoOtros=costoOtros*devolverHorasEstadia()*250;}

                costo = costoAlpha+costoAudi+costoFerrari+costoOtros;

                for (int b=0;b<20;b++)
                {
                            if (lisAuto[a].idPropietario==lisProp[b].idPropietario)
                            printf("Propietario: %s\n",lisProp[b].nom_ape);
                            printf("Patente: %s\n",lisAuto[a]);
                            printf("Marca: %d\n", lisAuto[a].marca);
                            printf("Costo de la estadia: %d\n",costo);

                }


                lisAuto[a].estado=0;
            }
    }

}








