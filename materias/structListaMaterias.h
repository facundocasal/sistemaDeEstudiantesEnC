#include "structMateria.h"
#include <stdbool.h>

typedef struct NodoMateria {
    Materia *materia;
    int nota;
    bool aprobada;
    struct NodoMateria *siguiente;
} NodoMateria;


typedef struct ListaMaterias
{
    NodoMateria *head;
    int tamanio;
} ListaMaterias;