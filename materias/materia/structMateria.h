#ifndef STRUCT_MATERIA_H
#define STRUCT_MATERIA_H
#include "estudiantes/lista/structListaEstudiantes.h"
typedef struct
{
    char nombre[20];
    struct ListaEstudiantes *estudiantesInscriptos;
} Materia;

#endif