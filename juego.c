#include "juego.h"

Juego* nuevoJuegoGenerico(){
    Juego* j= malloc(sizeof(Juego));

    strcpy(j->titulo, "por resolver");
    j->horas = 0;
    return j;
}
char* toStringJuego(Juego j){
    char* cadena=malloc(30*sizeof(char));
    
    strcat(cadena,"Titulo:");
    strcat(cadena,j.titulo);
    strcat(cadena,"\n");
    strcat(cadena,"horas:");
    strcat(cadena,"\n");

    sprintf(cadena,"Titulo:%s\nhoras:%d\n"
                ,j.titulo,j.horas);
    
    return cadena;
}
Juego* nuevoJuego(char *tit, int h){
    Juego *j=malloc(sizeof(Juego));

    strcpy(j->titulo, tit);
    j->horas=h;
}

void leerJugador(Jugador *j){
    int puntos=0;

    printf("Nombre:");
    scanf("%s",j->nombre);
    printf("Puntos: ");
    scanf("%d",&puntos);
    j->numero = puntos;
}
int compararJugador(Jugador a, Jugador b){
    if(a.numero==b.numero)
        return 0;
    else
        if(a.numero<b.numero)
        return -1;
    else
        return 1;
}