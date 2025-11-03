#ifndef STRUCT_LISTAESTUDIANTES_H
#define STRUCT_LISTAESTUDIANTES_H
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

#endif