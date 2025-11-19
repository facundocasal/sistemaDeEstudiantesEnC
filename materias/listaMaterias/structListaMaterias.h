#ifndef STRUCT_LISTAMATERIA_H
#define STRUCT_LISTAMATERIA_H
#include <stdbool.h>


struct Materia;   
typedef struct Materia Materia;
typedef struct NodoMateria {
    Materia *materia;
    struct NodoMateria *siguiente;
} NodoMateria;



typedef struct ListaMaterias
{
    NodoMateria *head;
    int tamanio;
} ListaMaterias;

#endif