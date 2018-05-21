
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define T_AUTOS 20
#define T_CLIENTES 20
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

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
    int costo;



}EAuto;

int devolverHorasEstadia(void); // FUNCION QUE CALCULA UN TIEMPO RANDOM, USADAD PARA CALCULAR ESTACIONAMIENTO
int obtenerEspacioLibre(EProp lisProp[]); // BUSCA ESPACIO LIBRE DENTRO DE LA ESTRUCTURA DE PROPIETARIOS
void AltaPropietario(EProp lisProp[]); // REALIZA ALTA DE PROPIETARIOS
void Mod_Tarj_Cre (EProp lisProp[]); // MODIFICAR TARJETA DE CREDITO NGRESANDO UN ID
void BajaProp (EProp lisProp[], EAuto lisAuto[]); // BAJA DE PROPIETARIO INGRESANDO EL ID
void IngresoAuto(EAuto lisAuto[], EProp lisProp[]); // ALTA DE AUTO
void EgresoAuto(EAuto listAuto[],EProp lisProp[]); // BORRA AUTO DE LA ESTRUCTURA
int Ver_Estacionamiento_Vacio(EAuto lisAuto[],int); // VERIFICA QUE LA ESTRUCTURA DE AUTOS ESTE VACIA (PARA NO DEJAR BORRAR)
int Ver_BaseCliente_Vacio(EProp lisAuto[],int); // VERIFICA QUE LA BASE DE CLINETES ESTE VACIA (PARA NO DEJAR BORRAR)
void Mostrar_Propietario_Cargado(EProp lisprop[],int); // MUESTRA POR PANTALLA UN REGISTRO ESPECIFICO DE PROPIETARIO
int ValidarNombre(char[],int);
void inicilizar_Prop(EProp lisProp[]);
void inicializar_Autos(EAuto lisAuto[]);
void Mostrar_Base_Propietarios(EProp lisProp[]);
void HardCode_Prop(EProp lisProp[]);
int validarInt (char[]);
void ArreglarErrorFget(char[]);
int obtenerEspacioLibre_Auto(EAuto lisAuto[]);
void listarProp(EProp lisProp[]);
void listarAuto(EAuto lisAuto[], EProp lisProp[]);
//listar

void RecaudacionTotal(EAuto lisAuto[]);
void RecaudacionTotal_Marca(EAuto lisAuto[]);
void Autosde1id(EProp lisProp[], EAuto lisAuto[]);
void ListarPropAudi(EProp lisProp[], EAuto lisAuto[]);
void ListadoOrdenadoAutos(EProp lisProp[], EAuto lisAuto[]);
void HardCode_Autos(EAuto lisAuto[]);











#endif // FUNCIONES_H_INCLUDED
