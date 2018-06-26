#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Estructura.h"
#include "genericas.h"

#define TAMLista 10
#define PAGINADO 5

int main()
{
    ArrayList *ListUrg;
    ArrayList *ListAtendidosUrg;
    ArrayList *ListReg;
    ArrayList *ListAtendidosReg;
    ArrayList *ListTemporal;

    ListUrg= al_newArrayList();
    ListAtendidosUrg= al_newArrayList();
    ListReg= al_newArrayList();
    ListAtendidosReg= al_newArrayList();
    ListTemporal= al_newArrayList();

    char seguir='s';
    int opcion=0;
    int Error=-9;

    if(ListUrg!=NULL && ListAtendidosUrg!=NULL && ListReg!=NULL && ListAtendidosReg!=NULL && ListTemporal!=NULL)
    {
        Error=0;
    }

    if(Error==0)
    {
        do
        {
            menu(   "\n 1. TRAMITE URGENTE"
                    "\n 2. TRAMITE REGULAR"
                    "\n 3. PROXIMO CLIENTE"
                    "\n 4. LISTAR"
                    "\n 5. INFORMAR:"
                );

            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    Error=AltaTramite(ListUrg,ListAtendidosUrg);
                    break;
                case 2:
                    Error=AltaTramite(ListReg,ListAtendidosReg);
                    break;
                case 3://PROXIMO CLIENTE
                    Error=ListUrg->isEmpty(ListUrg);
                    if(Error!=-1)
                    {
                        if(Error==0)
                        {//hay Urgentes
                            Error=ProxCliente(ListUrg,ListAtendidosUrg,"TURNO URGENTE");
                        }
                        else
                        {//No hay Urgentes a atender
                            Error=ListReg->isEmpty(ListReg);
                            if(Error!=-1)
                            {
                                if(Error==0)
                                {
                                    Error=ProxCliente(ListReg,ListAtendidosReg,"TURNO REGULAR");
                                }
                                else
                                {
                                    Error=Error*100;
                                    //Ya no hay mas turnos que atender.
                                }
                            }
                            else
                            {
                                Error=Error*10;
                            }
                        }
                    }

                    break;
                case 4:
                    //Error=MuestraClientes(ListUrg,"Turnos Urgentes por Atender");
                    //Error=MuestraClientes(ListReg,"Turnos Regulares por Atender");

                    Error=al_MuestraElemento_desde_hasta(ListUrg,"Turnos Urgentes por Atender",MuestraCliente ,0,al_len(ListUrg),PAGINADO);
                    if(Error!=0)
                    {
                        sms_error(opcion,Error);
                        Error=0;
                    }
                    Error=al_MuestraElemento_desde_hasta(ListReg,"Turnos Regulares por Atender",MuestraCliente ,0,ListReg->len(ListReg),PAGINADO);
                    /*
                    Error=al_MuestraElemento_desde_hasta(ListAtendidosUrg,"ATENDIDOS URG",MuestraCliente ,0,ListAtendidosUrg->len(ListAtendidosUrg),PAGINADO);
                    */
                    break;
                case 5:
                    ListTemporal= clonaOrdenado(ListAtendidosUrg,compara_elementos_Estructura,1);
                    if(ListTemporal!=NULL)
                    {
                        Error=al_MuestraElemento_desde_hasta(ListTemporal,"Turnos Urgentes Atendidos",MuestraCliente ,0,ListTemporal->len(ListTemporal),PAGINADO);
                    }
                    else
                    {
                        Error=-1;
                    }
                    ListTemporal=NULL;
                    ListTemporal= clonaOrdenado(ListAtendidosReg,compara_elementos_Estructura,1);
                    if(ListTemporal!=NULL)
                    {
                        Error=al_MuestraElemento_desde_hasta(ListTemporal,"Turnos Urgentes Atendidos",MuestraCliente ,0,ListTemporal->len(ListTemporal),PAGINADO);
                    }
                    else
                    {
                        Error=-1;
                    }

                    break;
                case 0:
                    seguir = 'n';
                    Error=0;
                    break;
                default:
                    Error=-1;
                    opcion=-2;
                    break;
            }//FIN switch(opcion)
            if(Error!=0)
            {
                sms_error(opcion,Error);
                Error=0;
            }
        }while(seguir=='s');
    }
    else
    {
        sms_error(-1,Error);
    }//FIN if(Error==0)

    return Error;
}//int main()
