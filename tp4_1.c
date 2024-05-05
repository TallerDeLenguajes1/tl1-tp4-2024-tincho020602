#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}typedef Tarea;

struct{
Tarea T;
Nodo *Siguiente;
}typedef Nodo;

Nodo *CrearListaVacia();
Nodo *CrearListaVacia(){
    return NULL;
}

int generarID(Nodo *inicio);
int generarID(Nodo *inicio){
    if (inicio==NULL)//si el inicio es NULL,no hay nodos en la lista aun
    {
        return 1000;
    }
    Nodo *aux=inicio;
    if (aux->Siguiente==NULL)//verifico si es el unico nodo
    {
        return 1000;
    }else
    {
        //recorro hasta que llegue al final de la lista
        while (aux->Siguiente!=NULL)
        {
            aux=aux->Siguiente;
        }
        
        return aux->T.TareaID+1;
    }
    
    
    
}

Tarea CrearTarea(Nodo *inicio);
Tarea CrearTarea(Nodo *inicio){
    srand(time(NULL));
    char arreglo[100];
    Tarea Taux;
    Taux.TareaID=generarID(inicio);
    printf("\nAgregue una descripcion: ");
    fflush(stdin);
    gets(arreglo);
    Taux.Descripcion=(char *)malloc(sizeof(char)*strlen(arreglo)+1);
    strcpy(Taux.Descripcion,arreglo);
    Taux.Duracion=rand()% 91+10;
}
Nodo *CrearNodo();
Nodo *CrearNodo(){
    Nodo *aux=(Nodo *)malloc(sizeof(Nodo));
    aux->T=CrearTarea(aux);
}


int main(){
    Nodo *pendietes;
    pendietes=CrearListaVacia();

    return 0;
}