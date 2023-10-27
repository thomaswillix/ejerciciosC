#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

void main(int argc, char *argv[])
{
    pid_t hijo;
    int pi[2], contador, suma = 0;
    FILE *fd;
    char c;

    if (argc < 2)
    {
        printf("faltan argumentos\n");
        exit(-1);
    }

    if (fd == NULL)
    {
        printf("ERROR DE APERTURA DEL FICHERO ....\n");
        exit(-1);
    }
    printf("Contenido del fichero:\n");

    pipe(pi);
    contador = 0;
    char letras[5] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i <= 4; i++)
    {
        hijo = fork();
        fd = fopen(argv[1], "r");

        if (hijo == 0)
        {
            while (fscanf(fd, "%c", &c) > 0)
            {
                printf("%c", c);
                if (tolower(c) == letras[i])
                {
                    contador++;
                }
            }

            printf("Hijo: %d con PID: %d y Padre %d\n", i, getpid(), getppid());
            printf("El número de veces que ha aparecido la vocal: %c es de %d veces (Proceso %d)\n", toupper(letras[i]), contador, i);

            write(pi[1], &contador, sizeof contador);
            close(pi[1]);
            exit(EXIT_SUCCESS);
        }
    }

    close(pi[1]);

    for (int i = 0; i < 5; i++)
    {
        read(pi[0], &contador, sizeof contador);
        suma += contador;
    }

    printf("Este es el proceso padre y su id es: %d\n", getpid());
    printf("En total hay %d vocales\n", suma);
}
