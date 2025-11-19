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

Estudiante* crearEstudiante(char *nombreEstudiante ,char *apellidoEstudiante , int edadEstudiante ) {
    Estudiante *nuevoEstudiante = malloc(sizeof(Estudiante));
    if (strlen(nombreEstudiante) == 0 || strlen(apellidoEstudiante) == 0 || edadEstudiante < 18 ) {
        return NULL;
    } 
    strcpy(nuevoEstudiante->nombre, nombreEstudiante);
    strcpy(nuevoEstudiante->apellido, apellidoEstudiante);
    nuevoEstudiante->edad = edadEstudiante;
    nuevoEstudiante->materiasInscriptas = nuevaListaMaterias();
    nuevoEstudiante->materiasAprobadas = nuevaListaMateriasAprobadas();
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
        while (nodoIterador->siguiente != NULL ){
            nodoIterador = nodoIterador->siguiente;
        }
        nodoIterador->siguiente = nodoMateria;
    }
};
//void agregarMateriaAprobada(Estudiante *estudiante , Materia *materia , char aprobo ) {};