#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include "funciones.h"
#include <string.h>
#define aa 	160
#define ee 130
#define ii 161
#define oo 162
#define uu 163
#define nn 167
#define enie 164

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
    while (lisProp[i].estado == 1 && i<T_CLIENTES)
        {
            i++;
            if (i==T_CLIENTES){return -1;}
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
        printf("\n\t\t\tNO SE PUEDEN AGREGAR MAS RESGISTROS A LA BASE DE PERSONAS");
        system("pause");
    }
    else
    {
        lisProp[indice].idPropietario = indice;

        printf("\nIngrese nombre del propietario: ");
        fgets(dato,100,stdin);
        ArreglarErrorFget(dato);

        while(!ValidarNombre(dato,100))
        {
            printf("\nIngrese nombre del propietario: ");
            fgets(dato,100,stdin);
            ArreglarErrorFget(dato);
        }

        strcpy(lisProp[indice].nom_ape,dato);

        printf("\nIngrese direccion: ");
        fgets(dato,100,stdin);
        ArreglarErrorFget(dato);

        strcpy(lisProp[indice].direc,dato);

        printf("\nIngrese n%c tarjeta de cr%cdito: ",nn,ee);
        fgets(dato,100,stdin);
        ArreglarErrorFget(dato);

        strcpy(lisProp[indice].tarjCred,dato);

        lisProp[indice].estado =1;

        Mostrar_Propietario_Cargado(lisProp, indice);

    }

}

void Mod_Tarj_Cre (EProp lisProp[])
{
    Mostrar_Base_Propietarios(lisProp);
    char dato[100];
    int ID;
    int a;
    printf("\nIngrese ID de la persona que modifico su tarjeta: ");
    fgets(dato,100,stdin);
    ArreglarErrorFget(dato);
    ID = validarInt(dato);
    while(ID==-1)
    {
        printf("\n ID incorrecto, ingrese nuevamente el ID");
        fgets(dato,100,stdin);
        ArreglarErrorFget(dato);
        ID = validarInt(dato);
    }

    for(a=0;a<20;a++)
    {
        if(lisProp[a].idPropietario==ID && lisProp[a].estado==1)
            {
               printf("\nIngrese nueva tarjeta de credito: ");
               fgets(dato,100,stdin);
               ArreglarErrorFget(dato);
               strcpy(lisProp[a].tarjCred,dato);
               break;
            }else if(a==19){printf("\nNo existe la persona ingresada");}
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

void IngresoAuto(EAuto lisAuto[], EProp lisProp[])
{
    char dato[100];
    char seguirCarga=0;
    int indice;
    int idprop;
    int marca;
    indice = obtenerEspacioLibre_Auto(lisAuto);
    if (indice == -1)
    {
        system("cls");
        printf("\t\t\t ESTACIONAMIENTO LLENO - NO SE PUEDEN INGRESAR AUTOS");
        system("pause");
    }
    else
    {
        listarProp(lisProp);
        printf("\nIngrese Id de propietario: ");
        scanf("%d",&idprop);
        fflush(stdin);


        for(int b=0;b<20;b++)
        {
            if(lisProp[b].idPropietario==idprop){seguirCarga=1;}

        }

        if (seguirCarga==1)
        {
            lisAuto[indice].idPropietario = idprop;

            printf("\nIngrese Patente: ");
            fgets(dato,100,stdin);
            ArreglarErrorFget(dato);
            strcpy(lisAuto[indice].patente,dato);

            printf("\nIngrese Marca: \n");
            printf("1-ALFA ROMEO\n2-FERRARI\n3-AUDI\n4-OTRO\n");
            scanf("%d",&marca);
            fflush(stdin);
            lisAuto[indice].marca=marca;

            lisAuto[indice].estado =1;

        }else {printf("\n El ID no corresponde a un cliente de nuestra base\n\n");system("pause");}


    }
}

void EgresoAuto(EAuto lisAuto[], EProp lisProp[])
{
    char patente[100];
    int a=0;
    char condicion=0;
    int costo=0;
    char dato[100];
    listarAuto(lisAuto,lisProp);
    printf("Ingrese Patente: ");
    fgets(dato,100,stdin);
    ArreglarErrorFget(dato);

    while (a<T_AUTOS && condicion ==0)
    {
        if ((strcmp(lisAuto[a].patente,dato)==0) && (lisAuto[a].estado==1))
            {
                condicion=1;
                switch(lisAuto[a].marca)
                {
                    case 1:
                        costo=devolverHorasEstadia()*150;
                    break;
                    case 2:
                        costo=devolverHorasEstadia()*175;
                    break;
                    case 3:
                        costo=devolverHorasEstadia()*200;
                    break;
                    case 4:
                        costo=devolverHorasEstadia()*250;
                    break;
                }
            }
        a++;


    } /*if (a==T_AUTOS-1){printf("\n Patente invalida, por favor ingresar patente correcta proxima vez");}
        else
        {  */ a=a-1;
            int id_ap;
            int ID_prop=-1;
                          //buscar prop por id
            id_ap = lisAuto[a].idPropietario; printf("id: %d\n",id_ap);system("pause");
                           for(int prop=0;prop<T_CLIENTES;prop++)
                           {
                               if(lisProp[prop].idPropietario==id_ap){ID_prop=prop;}
                           }

                            printf("Propietario: %s\n",lisProp[ID_prop].nom_ape);
                            printf("Patente: %s\n",lisAuto[a].patente);
                            printf("Marca: %d\n", lisAuto[a].marca);
                            printf("Costo de la estadia: %d\n\n\n\n\n",costo);
                            lisAuto[a].costo=costo;
                            lisAuto[a].estado=2; // ESTADO A COBRAR
                            system("pause");
        }




int Ver_Estacionamiento_Vacio(EAuto lisAuto[], int cantidad) // devuelve 0 si esta vacio, 1 si tiene al menos un elemento
{
    int i=0;
    while(i<cantidad)
    {
        if(lisAuto[i].estado)
        {
            return 1;
        }
        else return 0;
    i++;
    }
}

int Ver_BaseCliente_Vacio(EProp lisProp[],int cantidad) // devuelve 0 si esta vacio, 1 si tiene al menos un elemento
{
    int i=0;
    while(i<cantidad)
    {
        if(lisProp[i].estado)
        {
            return 1;
        }
        else return 0;
    i++;
    }
}


void Mostrar_Propietario_Cargado(EProp lisProp[],int ind)
{
        system("cls");
        printf("PROPIETARO INGRESADO:\n\n\n");
        printf(" Nombre: %s\n Direcci%cn: %s\n N%c Tarjeta: %s\n ID: %d\n",lisProp[ind].nom_ape,oo,lisProp[ind].direc,nn,lisProp[ind].tarjCred,lisProp[ind].idPropietario);
        printf("\n\n");
        system("pause");
        system("cls");
}

int ValidarNombre(char entrada[],int largo)
{
    if(strlen(entrada)<largo+1)
    {
            int j=0;
            while(entrada[j]!= '\0')
            {
                if(isdigit(entrada[j])==0)
                   {
                       j++;
                       if(entrada[j]=='\0'){return 1;}
                   }
                else
                    {
                        printf("\n\n No se pueden ingresar digitos num%cricos en este campo",ee);
                        return 0;

                    }

            }
    }
    else
    {
        printf("\n DATO INGRESADO SOBREPASA LOS %d CARACTERES ADMITIDOS\n\n",largo);
        return 0;
    }

}

void inicilizar_Prop(EProp lisProp[])
{
    for(int a=0;a<T_CLIENTES;a++)
    {
        lisProp[a].estado =0;
        lisProp[a].idPropietario=-1;
    }
}
void inicializar_Autos(EAuto lisAuto[])
{
    char patentenull[] = {NULL};
    for(int a=0;a<T_AUTOS;a++)
    {
        lisAuto[a].estado =0;
        lisAuto[a].idPropietario=-1;
        strcpy(lisAuto[a].patente,patentenull);
    }
}


void Mostrar_Base_Propietarios(EProp lisProp[])
{
    int i=0;
    system("cls");
    printf("\nNombre\t\tDirecci%cn\t\tTarjeta\t\t\tID\n",oo);
    printf("============================================================================\n\n");
     while (lisProp[i].estado == 1 && i<T_CLIENTES)
     {

         printf("%s\t\t%s\t\t\t%s\t\t\t%d\n",lisProp[i].nom_ape,lisProp[i].direc,lisProp[i].tarjCred,lisProp[i].idPropietario);
         i++;
     }

}
void HardCode_Prop(EProp lisProp[])
    {
        int id[]= {0,1,2,3};
        char nombre[][20]= {"Juan","Luis","Maria","Jose"};
        char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
        char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};

        for(int a=0;a<4;a++)
        {
            strcpy(lisProp[a].nom_ape,nombre[a]);
            strcpy(lisProp[a].tarjCred,tarjeta[a]);
            strcpy(lisProp[a].direc,direccion[a]);
            lisProp[a].idPropietario = id[a];
            lisProp[a].estado=1;


        }


    }
void HardCode_Autos(EAuto lisAuto[])
{
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,0,1,0,2,2,3,0,3,2};
    for(int a=0;a<10;a++)
        {
            strcpy(lisAuto[a].patente,patente[a]);
            lisAuto[a].marca=marca[a];
            lisAuto[a].idPropietario=propietario[a];
            lisAuto[a].estado=1;

        }

}




    int validarInt (char dato[])
{
   int i=0;
   //printf("estoy dentro de validar int, muestro dato %s",dato);
   while(dato[i] != '\0' && (dato[i]=='0' || dato[i]=='1' || dato[i]=='2' || dato[i]=='3' || dato[i]=='4' || dato[i]=='5' || dato[i]=='6' || dato[i]=='7' || dato[i]=='8' || dato[i]=='9')){i++;}
   if(dato[i+1]=='\0') {return atoi(dato);}
   else return -1;


}

void ArreglarErrorFget(char dato[])
{
    int largo=0;
    while (dato[largo]!='\n')
            {
                largo++;
            }
            dato[largo]='\0';

}

int obtenerEspacioLibre_Auto(EAuto lisAuto[])
{
    int i=0;
    while (lisAuto[i].estado == 1 && i<T_AUTOS)
        {
            i++;
            if (i==T_AUTOS){return -1;}
        }
    return i;
}

void listarProp(EProp lisProp[])
{
    system("cls");
    printf("\n\nLISTADO DE PROPIETARIOS EN LA BASE\n");
    printf("====================================\n\n");
    for (int a=0;a<T_CLIENTES;a++)
    {
        if(lisProp[a].estado==1)
        {
            printf("Propietario: %s\t\t ID: %d\t\n",lisProp[a].nom_ape,lisProp[a].idPropietario);
        }

    }
}

void listarAuto(EAuto lisAuto[], EProp lisProp[])
{
    printf("\n AUTOS EN EL GARAGE:\n\n");

    printf("Patente:\t\tPropietario:\n\n");

    for(int a=0;a<T_AUTOS;a++)
    {
        if(lisAuto[a].estado==1)
        {       int k=0;
                while(lisAuto[a].idPropietario!=lisProp[k].idPropietario)
                {
                    k++;

                }
                printf("%s\t\t\t%s\n",lisAuto[a].patente,lisProp[k].nom_ape);}
        }
}

void RecaudacionTotal(EAuto lisAuto[])
{

    system("cls");
    int a;
    int costo=0;

    for(a=0;a<T_AUTOS;a++)
    {
        if(lisAuto[a].estado==2)
        {
            costo = costo+lisAuto[a].costo;
        }
    }

    lisAuto[a].estado=0;
    printf("\nRECAUDACION TOTAL DEL ESTACIONAMIENTO: %d\n\n",costo);
    system("pause");

}

void RecaudacionTotal_Marca(EAuto lisAuto[])
{
    system("cls");
    int costoA=0;
    int costoB=0;
    int costoC=0;
    int costoD=0;

    for(int a=0;a<T_AUTOS;a++)
    {
        if (lisAuto[a].estado==2)
        {
            switch(lisAuto[a].marca)
                {
                    case 1:
                        costoA=costoA+lisAuto[a].costo;
                    break;
                    case 2:
                        costoB=costoB+lisAuto[a].costo;
                    break;
                    case 3:
                        costoC=costoC+lisAuto[a].costo;
                    break;
                    case 4:
                        costoD=costoD+lisAuto[a].costo;
                    break;
                }

        }
    }

    printf("\nRECAUDACON TOTAL POR ALFA ROMEO: %d\n",costoA);
    printf("RECAUDACON TOTAL POR FERRARI: %d\n",costoB);
    printf("RECAUDACON TOTAL POR AUDI: %d\n",costoC);
    printf("RECAUDACON TOTAL POR OTROS: %d\n",costoD);
    printf("RECAUDACION TOTAL %d\n\n",costoA+costoB+costoC+costoD);
    system("pause");
}


void Autosde1id(EProp lisProp[], EAuto lisAuto[])
{
    char dato[100];
    int id;
    system("cls");
    Mostrar_Base_Propietarios(lisProp);
    printf("\nIngrese ID de la persona: ");
    fgets(dato,100,stdin);
    ArreglarErrorFget(dato);
    id=validarInt(dato);

    Mostrar_Propietario_Cargado(lisProp,id);

    for(int a=0;a<T_AUTOS;a++)
    {
        if(lisAuto[a].idPropietario==id && lisAuto[a].estado==1)
        {
            printf("\nPATENTE: %s\n",lisAuto[a].patente);
            switch(lisAuto[a].marca)
                {
                    case 1:
                        printf("MARCA: ALFA ROMEO\n");
                    break;
                    case 2:
                        printf("MARCA: FERRARI\n");
                    break;
                    case 3:
                        printf("MARCA: AUDI\n");
                    break;
                    case 4:
                        printf("MARCA: OTRO\n");
                    break;
                }
        }
    }
    printf("\n\n\n\n");
    system("pause");
}

void ListarPropAudi(EProp lisProp[], EAuto lisAuto[])
{
    for (int a=0;a<T_AUTOS;a++)
    {
        if (lisAuto[a].marca==3 && lisAuto[a].estado==1)
        {
         for(int j=0;j<T_CLIENTES;j++)
         {
             if(lisAuto[a].idPropietario==lisProp[j].idPropietario)
             {
                 printf("\n\nNombre: %s\n Direcci%cn: %s\n N%c Tarjeta: %s\n ID: %d Coche: Audi \n",lisProp[j].nom_ape,oo,lisProp[j].direc,nn,lisProp[j].tarjCred,lisProp[j].idPropietario);

             }
         }


        }


    }
    system("pause");
}

void ListadoOrdenadoAutos(EProp lisProp[], EAuto lisAuto[])
{
 // EAuto aux;
  int c, d,marca,estado,idp;
  char paten[20];
  char marca_letras[20];

  for (c = 0 ; c < ( T_AUTOS - 1 ); c++)
  {
    for (d = 0 ; d < T_AUTOS - c - 1; d++)
    {

      if (strcmp(lisAuto[d].patente,lisAuto[d+1].patente)>0)
      {
        strcpy(paten,lisAuto[d].patente);
        marca = lisAuto[d].marca;
        estado = lisAuto[d].estado;
        idp = lisAuto[d].idPropietario;

        strcpy(lisAuto[d].patente,lisAuto[d+1].patente);
        lisAuto[d].idPropietario = lisAuto[d+1].idPropietario;
        lisAuto[d].marca = lisAuto[d+1].marca;
        lisAuto[d].estado = lisAuto[d+1].estado;

        strcpy(lisAuto[d+1].patente,paten);
        lisAuto[d+1].idPropietario = idp;
        lisAuto[d+1].marca =marca;
        lisAuto[d+1].estado=estado;

      }
    }
  }
        printf("LISTADO DE AUTOS ORDENADOS POR PATENTE\n");
        printf("=======================================\n\n");

        printf("Patente\t\tMarca\t\tID\n");

  for(int j=0;j<T_AUTOS;j++)
  {
      if(lisAuto[j].estado==1)
      {
          switch(lisAuto[j].marca)
      {
      case 1:
        strcpy(marca_letras,"ALFA ROMEO");
        break;
      case 2:
        strcpy(marca_letras,"FERRARI");
        break;
      case 3:
        strcpy(marca_letras,"AUDI");
        break;
      case 4:
        strcpy(marca_letras,"OTRO");
        break;
      }


          for(int jj=0;jj<T_CLIENTES;jj++)
          {
              if(lisProp[jj].idPropietario==lisAuto[j].idPropietario) /*{printf("Propietario: %s",lisProp[jj].nom_ape);}*/
              {
                  printf("%s\t\t%s\t\t%d\n",lisAuto[j].patente,marca_letras,lisAuto[j].idPropietario);
              }
          }
      }


  }
system("pause");
}
