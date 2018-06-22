#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Estructura.h"
#include "genericas.h"

#define TAMLista 10

int main()
{

    ArrayList *ListUrg;
    ArrayList *ListReg;

    ListUrg= al_newArrayList();
    ListReg= al_newArrayList();

    ECliente  AuxCliente;

    char seguir='s';
    int opcion=0;
    int Error=-9;

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

                    Error= al_add(ListUrg, AuxCliente);
                    break;
                case 2:
                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

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
