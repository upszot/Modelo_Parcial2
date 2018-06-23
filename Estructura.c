#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructura.h"


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

int MuestraCliente(ECliente * Cliente)
{
    int retorno=-1;
    if(Cliente !=NULL)
    {
        retorno=0;
        printf("Turno: %d ",Cliente->NroTurno);
        printf("DNI: %s \n",Cliente->DNI);
    }
    return retorno;
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
        printf("\n\n-------- %s --------\n",sms);
        if(this->isEmpty(this)==0)
        {//No esta vacio
            void *pElement;
            for(int index=0;index<this->len(this);index++)
            {
                pElement=this->get(this,index);
                MuestraCliente(pElement);
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


int al_MuestraElemento_desde_hasta(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado)
{
    int retorno=-1;
    int cont=0;
    system("cls");
    if(this!=NULL && Titulo!=NULL)
    {
        retorno=0;
        printf("\n\n-------- %s --------\n",Titulo);
        if(this->isEmpty(this)==0)
        {//No esta vacio
            //void *pElement;
            for(int index=desde;index<hasta;index++)
            {
                if(cont!=0 && cont %paginado==0)
                {
                    system("pause");
                    system("cls");
                    printf("\n\n-------- %s --------\n",Titulo);
                }
                //pElement=this->get(this,index);
                pFunc(al_get(this,index));
                //MuestraCliente(pElement);
                cont++;
            }

            if(cont!=0)
            {//pausa la ultima tanda de elementos mostrados
                system("pause");
            }
        }//if(this->isEmpty(this)==0)
    }//if(this!=NULL && Titulo!=NULL)
    return retorno;
}
