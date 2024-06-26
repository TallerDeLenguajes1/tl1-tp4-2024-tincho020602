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
Nodo *CrearNodo(Tarea datos);
Nodo *CrearNodo(Tarea datos){
    Nodo *nuevoNodo=(Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->T=datos;//guardo los datos cargados
    nuevoNodo->Siguiente=NULL;
    return nuevoNodo;
}

void insertarUltimo(Nodo **inicio,Nodo *nuevoNodo);
void insertarUltimo(Nodo **inicio,Nodo *nuevoNodo){
    nuevoNodo->Siguiente=*inicio;
    *inicio=nuevoNodo;
}

void cargarTarea(Nodo **inicio);
void cargarTarea(Nodo **inicio){
    int bandera;
    do{
        Tarea Tnueva=CrearTarea(*inicio);
        Nodo *nuevoNodo=CrearNodo(Tnueva);
        if (*inicio==NULL)//compruebo que inicio no este vacio
        {
            *inicio=nuevoNodo;//si es null, apunto al nuevo nodo
        }else
        {
            insertarUltimo(*inicio,nuevoNodo);
        }
        printf("\nDesea cargar otra tarea? Ingrese 1:si o 0:no");
        scanf("%d",&bandera);//se repetira el bucle siempre que si quiera cargar mas datos
    }while (bandera!=1);
}


int main(){
    Nodo *pendientes;
    pendientes=CrearListaVacia();
    cargarTarea(&pendientes);
    return 0;
}