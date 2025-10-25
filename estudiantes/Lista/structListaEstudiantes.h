#include "structEstudiante.h"


typedef struct NodoEstudiante {
    Estudiante *estudiante;
    struct NodoEstudiante *siguiente;
} NodoEstudiante;


typedef struct ListaEstudiantes
{
    NodoEstudiante *head;
    int tamanio;
} ListaEstudiantes;