#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "genericas.h"



char seguir='s';
    int opcion=0;
    int Error=-9;
    EMovie peliculas[TAMPelis];
    Error=inicializaVector(peliculas,TAMPelis);

    char Archivo[30]="Peliculas.txt";
    //char web[50]="Web\\index_peliculas.html";
    char web[50]="Web\\index.html";
    char Path_Template[20]="Temp_Web\\";

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
