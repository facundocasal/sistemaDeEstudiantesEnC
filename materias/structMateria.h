#ifndef STRUCT_Materia_H
#define STRUCT_Materia_H
typedef struct
{
    char nombre[20];
    struct ListaEstudiantes *estudiantesInscriptos;
} Materia;
#endif