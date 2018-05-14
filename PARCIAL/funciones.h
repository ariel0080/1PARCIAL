
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    int idPropietario;
    char nom_ape[100];
    char direc[100];
    char tarjCred[100];
    int estado;

}EProp;

typedef struct {


    char patente[20];
    int marca;
    int idPropietario;
    int estado;

}EAuto;

int devolverHorasEstadia(void);
int obtenerEspacioLibre(EProp lisProp[]);
void AltaPropietario(EProp lisProp[]);
void Mod_Tarj_Cre (EProp lisProp[]);
void BajaProp (EProp lisProp[], EAuto lisAuto[]);
void IngresoAuto(EAuto listAuto[]);
void EgresoAuto(EAuto listAuto[],EProp lisProp[]);
int












#endif // FUNCIONES_H_INCLUDED
