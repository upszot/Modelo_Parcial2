#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

typedef struct{
    int id;
    int NroTurno;
    char DNI[20];
}ECliente;

ECliente* nuevoTramite(void);
int ProxCliente(ArrayList *ListPendientes,ArrayList *ListAtendidos,char *sms);
int AltaTramite(ArrayList *ListPendientes,ArrayList *ListAtendidos);
void MuestraCliente(ECliente * Cliente);
int Mayor(ArrayList *this);
int getNextTurno(ArrayList *ListPendientes,ArrayList *ListAtendidos);
int MuestraClientes(ArrayList *this,char *sms);
