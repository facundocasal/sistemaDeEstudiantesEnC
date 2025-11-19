#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// struct 
#include "estudiantes/estudiante/structEstudiante.h"
#include "estudiantes/Lista/structListaEstudiantes.h"
// crud 
#include "estudiantes/estudiante/crudEstudiante.h"
#include "estudiantes/Lista/crudListaEstudiantes.h"
// mock 
#include "estudiantes/Lista/mockListaEstudiantes/mockEstudiantes.h"




int main() {

    ListaEstudiantes *lista = nuevaListaEstudiantes();

    // Cargar datos mock
    printf("Cargando datos de prueba...\n");
    cargarDatosDePruebaEstudiantes(lista);
    printf("Cantidad de estudiantes cargados: %d\n\n", cantidadDeAlumnos(lista));

    // === MOSTRAR TODOS LOS ESTUDIANTES ===
    printf("\n==== LISTA COMPLETA DE ESTUDIANTES ====\n");
    int cantTotal = 0;
    Estudiante *todos = obtenerListaEstudiantes(lista, &cantTotal);
    for (int i = 0; i < cantTotal; i++) {
        printf("%d) %s %s (Edad: %d)\n", 
            i+1, todos[i].nombre, todos[i].apellido, todos[i].edad);
    }

    // === BUSCAR ESTUDIANTE ===
    printf("\n=== BUSCAR ESTUDIANTE ===\n");
    NodoEstudiante *buscado = buscarEstudiante("Facundo", "Casal", lista);
    if (buscado != NULL) {
        mostrarDatos(buscado->estudiante);
    }

    // === MODIFICAR ESTUDIANTE ===
    printf("\n=== MODIFICAR ESTUDIANTE (Facundo) ===\n");
    if (buscado != NULL) {
        modificarEstudiante("Facu", "Casal", 30, buscado->estudiante);
        mostrarDatos(buscado->estudiante);
    }

    // === ELIMINAR ESTUDIANTE ===
    printf("\n=== ELIMINAR ESTUDIANTE (Ariel Gomez) ===\n");
    eliminarEstudiante("Ariel", "Gomez", lista);
    printf("Cantidad total de estudiantes ahora: %d\n", cantidadDeAlumnos(lista));

    // === BUSCAR ESTUDIANTES POR RANGO DE EDAD ===
    printf("\n=== ESTUDIANTES ENTRE 20 Y 22 ANIOS ===\n");
    int cantRango = 0;
    Estudiante *rango = obtenerListaEstudiantesPorRangoDeEdad(20, 22, lista, &cantRango);
    for (int i = 0; i < cantRango; i++) {
        printf("%d) %s %s (Edad: %d)\n", 
            i+1, rango[i].nombre, rango[i].apellido, rango[i].edad);
    }

    // === PAGINADO ===
    printf("\n=== MOSTRAR PAGINADO ===\n");
    mostrarEstudiantesPaginado(todos, cantTotal);

    // === INSCRIBIR MATERIA ===
    printf("\n=== INSCRIBIR MATERIA (si tenés materias cargadas) ===\n");
    // Solo ejemplo si tenés crearMateria
    // Materia* m1 = crearMateria("Matematica", 1);
    // inscribirEstudianteAMateria(buscado->estudiante, m1);

    // === LIBERAR ===
    free(todos);
    free(rango);
    free(lista);

    return 0;
}
