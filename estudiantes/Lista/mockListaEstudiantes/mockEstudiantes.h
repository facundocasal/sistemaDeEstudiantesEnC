#ifndef MOCK_ESTUDIANTES_H
#define MOCK_ESTUDIANTES_H

typedef struct {
    char *nombre;
    char *apellido;
    int edad;
} MockEstudiante;

#define MOCK_CANTIDAD 20  
extern MockEstudiante datos[];

#endif
