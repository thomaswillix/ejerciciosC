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
Juego* nuevoJuego(char *tit, double h){
    Juego *j=malloc(sizeof(Juego));

    strcpy(j->titulo, tit);
    j->horas=h;
}

void leerJuego(Juego *j){
    int horas=0;

    printf("Nombre:");
    scanf("%s",j->titulo);
    printf("Puntos: ");
    scanf("%d",&horas);
    j->horas = horas;
}
int compararJuego(Juego a, Juego b){
    if(a.horas==b.horas)
        return 0;
    else
        if(a.horas<b.horas)
        return -1;
    else
        return 1;
}
