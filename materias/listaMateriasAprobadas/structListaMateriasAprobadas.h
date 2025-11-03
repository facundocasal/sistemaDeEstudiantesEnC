#ifndef STRUCT_LISTAMATERIASAPROBADAS_H
#define STRUCT_LISTAMATERIASAPROBADAS_H

#include <stdbool.h>

typedef struct NodoMateriaAprobada {
    char nombreMateria[50];
    int nota;
    bool condicion;
    struct NodoMateriaAprobada *siguiente;
} NodoMateriaAprobada;


typedef struct ListaMateriasAprobadas
{
    NodoMateriaAprobada *head;
    int tamanio;
} ListaMateriasAprobadas;

#endif