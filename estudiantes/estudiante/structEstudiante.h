#ifndef STRUCT_ESTUDIANTE_H
#define STRUCT_ESTUDIANTE_H

#include "materias/listaMaterias/structListaMaterias.h"
#include "materias/listaMateriasAprobadas/structListaMateriasAprobadas.h"


typedef struct {
    char nombre[20];
    char apellido[20];
    int edad;
    ListaMateriasAprobadas *materiasAprobadas;
    ListaMaterias *materiasInscriptas;
} Estudiante;

#endif