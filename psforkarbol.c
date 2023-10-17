#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main(){
    pid_t  hijo;
    int i;

    for(i=1;i<=5;i++)
    {
        hijo = fork();
        if(hijo==0){
            break;
        }
    }
    if (hijo == 0)
    {
        printf("Hijo: %d con PID: %d y Padre %d\n", i,getpid() ,getppid());
        sleep(10);
        printf("Fin del hijo %d \n", i);
    } else{
        sleep(5 );
        printf("Este es el proceso padre y su id es: %d\n",getpid());
    }
}