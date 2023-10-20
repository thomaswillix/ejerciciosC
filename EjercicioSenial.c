#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "cosillas.h"
#include <stdbool.h>

pid_t pid_hijo;


void manejador (int segnal)
{
    printf("Por esta vez te has salvado, no te fíes de los extraños\n");
    kill(pid_hijo,SIGKILL); 
    exit(0);
}
bool comprobacion ()
{
    int anio;
    scanf("%d",&anio);
	while(anio != 1989){
        printf("error\n");
        scanf("%d",&anio);        
    }
    printf("correcto\n");
    return true;
}

int main(){
	int num;
    signal(SIGUSR1, manejador);    

	pid_hijo=fork();
    switch(pid_hijo){
		case -1:
			printf("error al crear el proceso\n");
			exit(-1);
		case 0:
        printf("¿En qué año ganó la vuelta a España Pedro Delgado por primera vez?\n¡Si no aciertas en 30 segundos destruiré todos tus datos!\n");

            if (comprobacion())
            {
                kill(getppid() ,SIGUSR1);    
            }
		default:
            sleep(30);
            destruir();
            kill(pid_hijo,SIGKILL);
	}
	exit(0);
}
