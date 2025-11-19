#ifndef STRUCT_ESTUDIANTE_H
#define STRUCT_ESTUDIANTE_H

typedef struct ListaMateriasAprobadas ListaMateriasAprobadas;
typedef struct ListaMaterias ListaMaterias;

typedef struct Estudiante{
    char nombre[20];
    char apellido[20];
    int edad;
    ListaMateriasAprobadas *materiasAprobadas;
    ListaMaterias *materiasInscriptas;
} Estudiante;

#endif

