#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "genericas.h"

typedef struct{
    int id;
    int NroTurno;
    char DNI[20];
}ECliente;

ECliente* nuevoTramite(void);
int compara_elementos_Estructura(void* pElementA,void* pElementB);
int ProxCliente(ArrayList *ListPendientes,ArrayList *ListAtendidos,char *sms);
int AltaTramite(ArrayList *ListPendientes,ArrayList *ListAtendidos);
int MuestraCliente(ECliente * Cliente);
int Mayor(ArrayList *this);
int getNextTurno(ArrayList *ListPendientes,ArrayList *ListAtendidos);
//int MuestraClientes(ArrayList *this,char *sms);
int al_MuestraElemento_desde_hasta(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado);
ArrayList* clonaOrdenado(ArrayList *this,int (*pFunc)(void* ,void*),int orden);
