#include <structMateria.h>
#include <structListaMaterias.h>
#include <stdlib.h>
#include "../../estudiante/structEstudiante.h"
#include "../../estudiantes/Lista/crudListaEstudiantes.h"
#include "crudMateria.h"
#include <stdio.h>
#include <string.h>
Materia* crearMateria(const char *nombreDeMateria);
Materia* crearMateria(const char *nombreDeMateria)
{
    Materia *nuevaMateria = malloc(sizeof(Materia));
    if (nombreDeMateria == NULL)
    {
        return NULL;
    }
    strcpy(nuevaMateria->nombre, nombreDeMateria);
    nuevaMateria->estudiantesInscriptos = nuevaListaEstudiantes();
    return nuevaMateria;
}

void modificarMateria(Materia *materia, char *nombre)
{
   strcpy(materia->nombre, nombre);
}

void eliminarAlumnoDeMateria(char *nombre, char *apellido, Materia *materia)
{
    if (nombre == NULL || apellido == NULL || materia == NULL || materia->estudiantesInscriptos->tamanio == 0)
    {
        printf("Error: datos invalidos o lista vacia.\n");
        return;
    }
    eliminarEstudiante(nombre, apellido, materia->estudiantesInscriptos);
}

void anotarseEnUnaMateria(Estudiante *estudiante, Materia *materia)
{
    if (estudiante == NULL)
    {
        return;
    }
    agregarEstudiante(estudiante, materia->estudiantesInscriptos);
}

Estudiante *buscarEstudiantePorNombre(Estudiante *estudiante, Materia *materia)
{
    if (estudiante == NULL)
    {
        return NULL;
    }

    printf("PRUEBA %d\n", materia->estudiantesInscriptos->tamanio);

    NodoEstudiante *estudianteEncontrado =
        buscarEstudiante(estudiante->nombre, estudiante->apellido, materia->estudiantesInscriptos);

    if (estudianteEncontrado == NULL) return NULL;

    return estudianteEncontrado->estudiante;
};

// void rendirMateria();
