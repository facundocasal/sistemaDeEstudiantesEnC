#include "structMateria.h"
#include <stdbool.h>

typedef struct NodoMateria {
    Materia *materia;
    struct NodoMateria *siguiente;
} NodoMateria;


typedef struct ListaMaterias
{
    NodoMateria *head;
    int tamanio;
} ListaMaterias;

