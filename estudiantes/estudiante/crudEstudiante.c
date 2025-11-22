#include "structEstudiante.h"
#include "crudEstudiante.h"
#include "../../materias/materia/structMateria.h"
#include "../../materias/listaMaterias/structListaMaterias.h"
#include "../../materias/listaMaterias/crudListaMaterias.h"
#include "../../materias/listaMateriasAprobadas/structListaMateriasAprobadas.h"
#include "../../materias/listaMateriasAprobadas/crudListaMateriasAprobadas.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Estudiante *crearEstudiante(char *nombreEstudiante, char *apellidoEstudiante, int edadEstudiante)
{
    Estudiante *nuevoEstudiante = malloc(sizeof(Estudiante));
    if (strlen(nombreEstudiante) == 0 || strlen(apellidoEstudiante) == 0 || edadEstudiante < 18)
    {
        return NULL;
    }
    strcpy(nuevoEstudiante->nombre, nombreEstudiante);
    strcpy(nuevoEstudiante->apellido, apellidoEstudiante);
    nuevoEstudiante->edad = edadEstudiante;
    nuevoEstudiante->materiasInscriptas = nuevaListaMaterias();
    nuevoEstudiante->materiasAprobadas = nuevaListaMateriasAprobadas();
    return nuevoEstudiante;
};
void modificarNombreEstudiante(Estudiante *estudiante, char *nombre)
{
    strcpy(estudiante->nombre, nombre);
};
void modificarApellidoEstudiante(Estudiante *estudiante, char *apellido)
{
    strcpy(estudiante->apellido, apellido);
};
void modificarEdad(Estudiante *estudiante, int edad)
{
    estudiante->edad = edad;
};
void mostrarDatos(Estudiante *estudiante)
{
    if (estudiante == NULL)
    {
        return;
    }

    printf("Nombre: %s\n", estudiante->nombre);
    printf("Apellido: %s\n", estudiante->apellido);
    printf("Edad: %d\n", estudiante->edad);

    printf("Materias inscriptas: %d\n", estudiante->materiasInscriptas->tamanio);

    NodoMateria *actual = estudiante->materiasInscriptas->head;

    if (actual == NULL)
    {
        printf(" - No tiene materias inscriptas.\n");
        return;
    }

    printf("Lista de materias inscriptas:\n");
    while (actual != NULL)
    {
        printf(" - %s\n", actual->materia->nombre);
        actual = actual->siguiente;
    }
};
void inscribirEstudianteAMateria(Estudiante *estudiante, Materia *materia)
{
    if (materia == NULL || estudiante == NULL)
    {
        return;
    }

    NodoMateria *iterador = estudiante->materiasInscriptas->head;
    while (iterador != NULL)
    {
        if (strcmp(iterador->materia->nombre, materia->nombre) == 0)
        {
            printf("Ya estas inscripto a la materia\n");
            return;
        }
        iterador = iterador->siguiente;
    }

    NodoMateria *nodoMateria = malloc(sizeof(NodoMateria));
    nodoMateria->materia = materia;
    nodoMateria->siguiente = NULL;

    if (estudiante->materiasInscriptas->head == NULL)
    {
        estudiante->materiasInscriptas->head = nodoMateria;
    }
    else
    {
        NodoMateria *nodoIterador = estudiante->materiasInscriptas->head;
        while (nodoIterador->siguiente != NULL)
        {
            nodoIterador = nodoIterador->siguiente;
        }
        nodoIterador->siguiente = nodoMateria;
        printf("Inscripcion correcta");
    }
};

void mostrarMateriasInscriptas(Estudiante *estudiante)
{
    if (estudiante == NULL || estudiante->materiasInscriptas == NULL)
    {
        printf("Error: estudiante o lista de materias vacia.\n");
        return;
    }

    NodoMateria *actual = estudiante->materiasInscriptas->head;

    if (actual == NULL)
    {
        printf("El estudiante no esta inscripto en ninguna materia.\n");
        return;
    }

    printf("Materias inscriptas de %s %s:\n", estudiante->nombre, estudiante->apellido);

    while (actual != NULL)
    {
        printf(" - %s\n", actual->materia->nombre);
        actual = actual->siguiente;
    }
}

