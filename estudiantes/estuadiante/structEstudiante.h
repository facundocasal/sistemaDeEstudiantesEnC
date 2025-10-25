#ifndef STRUCT_ESTUDIANTE_H
#define STRUCT_ESTUDIANTE_H
#include "../materias/structListaMaterias.h"
typedef struct
{
    char nombre[20];
    char apellido[20];
    int edad;
    struct ListaMaterias *materiasInscriptas;
    struct ListaMaterias *materiasAprobadas;
} Estudiante;
#endif