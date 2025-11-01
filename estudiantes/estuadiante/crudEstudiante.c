#include "structEstudiante.h"
#include "../materias/structListaMaterias.h"
#include <string.h>
#include <stdlib.h>

Estudiante* crearEstudiante(char *nombreEstudiante ,char *apellidoEstudiante , int edadEstudiante ) {
    Estudiante *nuevoEstudiante = malloc(sizeof(Estudiante));
    if (nombreEstudiante == "" || apellidoEstudiante == "" || edadEstudiante <= 18 ) {
        return NULL;
    }
    
    strcpy(nuevoEstudiante->nombre, nombreEstudiante);
    
    strcpy(nuevoEstudiante->apellido, apellidoEstudiante);
    nuevoEstudiante->edad = edadEstudiante;

    ListaMaterias *nuevaListaMateriasInscriptas = malloc(sizeof(ListaMaterias));
    nuevaListaMateriasInscriptas->head = NULL;
    nuevoEstudiante->materiasInscriptas = nuevaListaMateriasInscriptas;

    ListaMaterias *nuevaListaMateriasAprobadas = malloc(sizeof(ListaMaterias));
    nuevaListaMateriasAprobadas->head = NULL;
    nuevoEstudiante->materiasAprobadas = nuevaListaMateriasAprobadas;
    return nuevoEstudiante;
};
void modificarNombreEstudiante(Estudiante *estudiante , char *nombre ){
    strcpy(estudiante->nombre, nombre);
};
void modificarApellidoEstudiante(Estudiante *estudiante , char *apellido ){
    strcpy(estudiante->apellido, apellido);
};
void modificarEdad (Estudiante *estudiante , int edad){
    estudiante->edad = edad;
};

void mostrarDatos (Estudiante *estudiante){
    if (estudiante == NULL) {
        printf("Error: el estudiante no existe.\n");
        return;
    }
    printf("Nombre: %s\n Apellido: %s\n Edad: %d\n" , estudiante->nombre , estudiante->apellido , estudiante->edad);
};

void inscribirEstudianteAMateria(Estudiante *estudiante , Materia *materia ){
    if (materia == NULL || estudiante == NULL ) {
        return;
    }  
    NodoMateria *nodoMateria = malloc(sizeof(NodoMateria));
    nodoMateria->materia = materia;
    nodoMateria->siguiente = NULL;
    
    if (estudiante->materiasInscriptas->head == NULL){
        estudiante->materiasInscriptas->head = nodoMateria;
    }else {
        NodoMateria *nodoIterador = estudiante->materiasInscriptas->head;
        while (nodoIterador != NULL ){
            nodoIterador = nodoIterador->siguiente;
        }
        nodoIterador->siguiente = nodoMateria;
    }
};

void agregarMateriaAprobada(Estudiante *estudiante , Materia *materia , char aprobo ) {
    if (aprobo == "Aprobo"){

    }
};