#include <structMateria.h>
#include <structListaMaterias.h>
#include <stdlib.h>
#include "estudiantes/Lista/crudListaEstudiantes.h"

Materia* crearMateria(char *nombreDeMateria)
{
    Materia *nuevaMateria = malloc(sizeof(Materia));
    if (nombreDeMateria == "")
    {
        return NULL;
    }
    strcpy(nuevaMateria->nombre, nombreDeMateria);
    nuevaMateria->estudiantesInscriptos = nuevaListaEstudiantes();
    return nuevaMateria;
}

void modificarMateria(Materia *materia, char *nombre)
{
    strcpy(*materia->nombre, nombre);
}

void eliminarAlumnoDeMateria(char nombre, char apellido, Materia *materia)
{
    if (nombre == "" || apellido == "" || materia == NULL || materia->estudiantesInscriptos->tamanio == 0)
    {
        printf("Error: datos invalidos o lista vacia.\n");
        return NULL;
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

void buscarEstudiantePorNombre(Estudiante *estudiante, Materia *materia)
{
    if (estudiante == NULL)
    {
        return;
    }
    Estudiante *estudianteEncontrado = buscarEstudiante(estudiante->nombre, estudiante->apellido, materia->estudiantesInscriptos);
    return estudianteEncontrado;
}

void buscarEstudiantesPorEdad(int edad, Materia *materia){
    if (materia == NULL || edad < 0 || edad > 100){
        return;
    }
    
}

// void rendirMateria();
