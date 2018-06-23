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

int ProxCliente(ArrayList *ListPendientes,ArrayList *ListAtendidos,char *sms)
{
    int retorno=-1;
    if(ListPendientes!=NULL && ListAtendidos!=NULL)
    {

        ECliente *Cliente;
        Cliente=al_pop(ListPendientes,0);
        ListAtendidos->add(ListAtendidos,Cliente);

        printf("\n\n-------- %s --------\n",sms);
        MuestraCliente(Cliente);
        printf("\n\n");
        system("pause");
        retorno=0;
    }
    return retorno;
}


int AltaTramite(ArrayList *ListPendientes,ArrayList *ListAtendidos)
{
    int retorno=-1;
    int NroTurno;
    ECliente *Cliente;
    if(ListPendientes !=NULL && ListAtendidos !=NULL)
    {
        NroTurno=getNextTurno(ListPendientes,ListAtendidos);
        if(NroTurno>0)
        {
            ECliente *Cliente;
            Cliente=nuevoTramite();
            Cliente->NroTurno=NroTurno;
            strcpy(Cliente->DNI,get_char("\n Ingrese DNI: ",20));
            ListPendientes->add(ListPendientes,Cliente);
            retorno=0;
        }
        else
        {
            retorno=NroTurno*10;//asi se que el error viene de mas adentro.
        }
    }
    return retorno;
}

void MuestraCliente(ECliente * Cliente)
{
    if(Cliente !=NULL)
    {
        printf("Turno: %d ",Cliente->NroTurno);
        printf("DNI: %s \n",Cliente->DNI);
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

int getNextTurno(ArrayList *ListPendientes,ArrayList *ListAtendidos)
{
    int retorno=-9;
    if(ListPendientes!=NULL && ListAtendidos!=NULL)
    {
        retorno=ListPendientes->isEmpty(ListPendientes);
        if( retorno!=-1 )
        {
            if(retorno==1)
            {//ListPendientes esta vacio
                retorno=ListAtendidos->isEmpty(ListAtendidos);
                if(retorno!=-1)
                {
                    if(retorno==0)
                    {//busco el Ultimo nro de turno que se atendio
                        retorno=Mayor(ListAtendidos)+1;
                    }
                    //sino Retorno es 1 y por lo tanto es la 1er persona en atenderse
                }
            }
            else
            {//tiene algo
                retorno=Mayor(ListPendientes)+1;
            }
        }
    }//if(ListPendientes!=NULL && ListAtendidos!=NULL)
    return retorno;
}

int MuestraClientes(ArrayList *this,char *sms)
{
    int retorno=-1;
    if(this!=NULL && sms!=NULL)
    {
        if(this->isEmpty(this)==0)
        {//No esta vacio
            ECliente *Cliente;
            printf("\n\n-------- %s --------\n",sms);
            for(int index=0;index<this->len(this);index++)
            {
                Cliente=this->get(this,index);
                MuestraCliente(Cliente);
            }
        }
        else
        {
            printf("\n\n NO HAY DATOS A MOSTRAR..\n");
        }
        system("pause");
        retorno=0;
    }
    return retorno;
}
