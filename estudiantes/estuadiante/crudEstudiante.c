#include "structEstudiante.h"
#include "../materias/structListaMaterias.h"
#include <string.h>
#include <stdlib.h>

Estudiante* crearEstudiante(char *nombreEstudiante ,char *apellidoEstudiante , int edadEstudiante ) {
    if (strlen(nombreEstudiante) == 0 || srtlen(apellidoEstudiante) == 0 || edadEstudiante <= 18) {
        return NULL;
    }
    Estudiante *nuevoEstudiante = malloc(sizeof(Estudiante));
    if (nuevoEstudiante == NULL) return NULL;
    //comprobaciones de cadenas no vacias y edad valida

    strcpy(nuevoEstudiante->nombre, nombreEstudiante);
    strcpy(nuevoEstudiante->apellido, apellidoEstudiante);
    nuevoEstudiante->edad = edadEstudiante;
    //copiar cadenas

    nuevoEstudiante -> materiasInscriptas = malloc(sizeof(ListaMaterias));
    if (nuevoEstudiante -> materiasInscriptas != NULL){
        nuevoEstudiante -> materiasInscriptas -> head = NULL;
    }
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
    if (materia == NULL || estudiante == NULL || estudiante -> materiasInscriptas == NULL) {
        return;
    }  
    NodoMateria *nodoMateria = malloc(sizeof(NodoMateria));
    if (nodoMateria == NULL) return;
    
    nodoMateria->materia = materia;
    nodoMateria->siguiente = NULL;
    
    if (estudiante->materiasInscriptas->head == NULL){
        estudiante->materiasInscriptas->head = nodoMateria;
    }else {
        NodoMateria *nodoIterador = estudiante->materiasInscriptas->head;
        while (nodoIterador -> siguiente != NULL){
            nodoIterador = nodoIterador->siguiente;
        }
        nodoIterador->siguiente = nodoMateria;
    }
};

void agregarMateriaAprobada(Estudiante *estudiante , Materia *materia , char *aprobo ) {
    if (strcmp(aprobo, "Aprobo") == 0){

    }
};