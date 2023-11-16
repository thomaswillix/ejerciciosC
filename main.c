#include <stdio.h>
#include <stdlib.h>
#include "juego.h"
#define NUM_JUEGOS 3

int main (int argc, char** argv){
    
    if(1==3)
        printf("Funciona\n");
    else
        printf("No funciona\n");
    
    Juego *juegos[NUM_JUEGOS];
    int i = 0;

    for(i = 0;i<=NUM_JUEGOS; i++)
    {
        //leer jugador
        juegos[i] = nuevoJuegoGenerico();
        leerJuego(juegos[i]);
    }
    //ordenar el array

    for(i = 0;i<=NUM_JUEGOS; i++)
    {
        //mostrar jugador
        printf("%s",toStringJuego(*juegos[i]));
        
        //Lo de abajo es a lo que me dio tiempo hacer
        
        /*Jugador* j1 = nuevoJugador(participantes[i]->nombre, 
            participantes[i]->numero);
        if (participantes[i]>participantes[i-1])
        {
            participantes[i-1]
        }*/

        int cambios = 1;
        Juego *auxiliar;
        while (cambios>0)
        {
            cambios =0;
            for (i = 0; i < NUM_JUEGOS; i++)
            {
                if (compararJuego(*juegos[i], *juegos[i+1])>0)
                {
                    //intercambiar
                    juegos[i] = juegos[i+1] ;
                    auxiliar=juegos[i];
                    juegos[i]=juegos[i+1];
                    juegos[i+1]=auxiliar;
                    cambios++;
                }
                
            }
            
        }
        
    }


    /*Jugador *uno, *dos;

    uno = nuevoJugadorGenerico();
    dos=nuevoJugador("Thomas", 21);
    leerJugador(uno);
    leerJugador(dos);

    if(compararJugador(*uno,*dos)>0)
        printf("ganador:%s\n",toStringJugador(*uno));
    else
        if(compararJugador(*uno,*dos)<0)
        printf("ganador:%s\n",toStringJugador(*dos));
    else
        printf("Empate");
    

    printf("%s\n", toStringJugador(*uno));
    leerJugador(uno);

    printf("%s\n", toStringJugador(*uno));
    printf("%s\n", toStringJugador(*dos));*/

    return(EXIT_SUCCESS);
}
