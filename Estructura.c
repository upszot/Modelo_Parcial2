#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructura.h"
#include "ArrayList.h"

ECliente* nuevoTramite(void)
{
    ECliente* returnAux;
    returnAux = (ECliente*)malloc(sizeof(ECliente));
    return returnAux;
}

int ProxCliente(ArrayList *ListPendientes,ArrayList *ListAtendidos)
{
    int retorno=-1;
    if(ListPendientes!=NULL && ListAtendidos!=NULL)
    {

        ECliente *Cliente;
        Cliente=al_pop(ListPendientes,0);
        ListAtendidos->add(ListAtendidos,Cliente);
        MuestraCliente(Cliente);
        retorno=0;
    }
    return retorno;
}


int AltaTramite(ArrayList *ListPendientes,ArrayList *ListAtendidos)
{
    int retorno=-1;
    ECliente *Cliente;
    if(ListPendientes !=NULL && ListAtendidos !=NULL)
    {
        ECliente *Cliente;
        Cliente=nuevoTramite();
        Cliente->NroTurno=getNextTurno(ListPendientes,ListAtendidos);

        strcpy(Cliente->DNI,get_char("\n Ingrese DNI: ",20));
        ListPendientes->add(ListPendientes,Cliente);
        retorno=0;
    }
    return retorno;
}

void MuestraCliente(ECliente * Cliente)
{
    if(Cliente !=NULL)
    {
        printf("\nTurno: %d ",Cliente->NroTurno);
        printf("DNI: %s",Cliente->DNI);
    }
}


int Mayor(ArrayList *this)
{
    int Mayor;
    ECliente *Cliente;
    if(this!=NULL)
    {
        for(int i=0;i<this->len(this);i++)
        {
            Cliente=this->get(this,i);
            if(i==0 || Mayor<Cliente->NroTurno)
            {
                Mayor=Cliente->NroTurno;
            }
        }
    }
    return Mayor;
}

int getNextTurno(ArrayList *this,ArrayList *this2)
{
    int retorno;
    if(this!=NULL && this2!=NULL)
    {
        if( this->isEmpty(this)==1 )
        {
            retorno=Mayor(this2);
        }
        else
        {
            retorno=Mayor(this);
        }
    }
    return retorno;
}


