#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

void main(int argc, char *argv[]){
    pid_t  hijo; //Proceso genérico (padre e hijos).  
    int i;       //Autoincremental del bucle for
    char c;      //Char para la lectura del archivo
    int pi[2];   //Pipe para el flujo de los datos entre los extremos
    FILE *fd;    //Archivo que leeremos
    
    if(argc<2){  //Comprobación de los argumentos
        printf("faltan argumentos\n");
        exit(-1);
    }

	fd=fopen(argv[1],"r"); //abrimos el fichero para lectura
    
	if (fd == NULL){  //Comprobación de la lectura correcta
		printf("ERROR DE APERTURA DEL FICHERO ....\n");
		exit(-1);
	}
	printf("Contenido del fichero:\n");
    
    pipe(pi);
    int contador = 0;
    char letras[] = "aeiou";

    for(i=0;i<=4;i++) //Bucle en el que realizamos los 5 fork()
    {                  // (Procesos hijos)
       
       hijo = fork();
        if(hijo==0){
        

        while(fscanf(fd,"%c",&c)>0)
            {
                printf("%c", c);                 
                if(c == letras[i])
                {
                    contador++;
                }
            }
            close(pi[0]);
            break;
        }
        
        
    }
    
    
    if (hijo == 0)
    {
        printf("Hijo: %d con PID: %d y Padre %d\n", i,getpid() ,getppid());
        printf("El número de veces que ha aparecido la vocal: %c es de %d veces (Proceso %d)\n", toupper(letras[i]) , contador, i);
        sleep(10);
        printf("Fin del hijo %d \n", i);
    } else{
        sleep(5);
        printf("Este es el proceso padre y su id es: %d\n",getpid());
    }
}