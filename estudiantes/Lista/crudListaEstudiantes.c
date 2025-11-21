#include "structListaEstudiantes.h"
#include "estudiantes/estudiante/structEstudiante.h"
#include "crudListaEstudiantes.h"
#include "estudiantes/estudiante/crudEstudiante.h"
#include "mockListaEstudiantes/mockEstudiantes.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

ListaEstudiantes *nuevaListaEstudiantes()
{
    ListaEstudiantes *nuevaLista = malloc(sizeof(ListaEstudiantes));
    nuevaLista->head = NULL;
    nuevaLista->tamanio = 0;
    return nuevaLista;
}

void agregarEstudiante(Estudiante *estudiante, ListaEstudiantes *lista)
{
    if (estudiante == NULL)
    {
        return;
    }
    NodoEstudiante *nuevoEstudiante = malloc(sizeof(NodoEstudiante));
    nuevoEstudiante->estudiante = estudiante;
    nuevoEstudiante->siguiente = NULL;
    NodoEstudiante *iteradorEstudiante = lista->head;
    if (iteradorEstudiante == NULL)
    {
        lista->head = nuevoEstudiante;
    }
    else
    {
        while (iteradorEstudiante->siguiente != NULL)
        {
            iteradorEstudiante = iteradorEstudiante->siguiente;
        }
        iteradorEstudiante->siguiente = nuevoEstudiante;
    }
    lista->tamanio++;
}

NodoEstudiante *buscarEstudiante(char *nombre, char *apellido, ListaEstudiantes *lista)
{
    if (nombre == NULL || apellido == NULL || strlen(nombre) == 0 || strlen(nombre) == 0 )
    {
        printf("Error: datos invalidos o lista vacia.\n");
        return NULL;
    }

      if (lista == NULL)
    {
        printf("Error: lista vacía.\n");
        return NULL;
    }

    NodoEstudiante *iteradorEstudiante = lista->head;
    while (iteradorEstudiante != NULL)
    {
        if (strcmp(iteradorEstudiante->estudiante->nombre, nombre) == 0 &&
            strcmp(iteradorEstudiante->estudiante->apellido, apellido) == 0)
        {
            printf("Estudiante encontrado!!\n");
            return iteradorEstudiante;
        }
        iteradorEstudiante = iteradorEstudiante->siguiente;
    }
    printf("Error: el estudiante no existe.\n");
    return NULL;
}

void eliminarEstudiante(char *nombre, char *apellido, ListaEstudiantes *lista)
{
    if (strlen(nombre) == 0 || strlen(apellido) == 0 || lista->head == NULL)
    {
        printf("Error: datos invalidos o lista vacia.\n");
        return;
    }
    NodoEstudiante *estudianteAEliminar = buscarEstudiante(nombre, apellido, lista);
    if (estudianteAEliminar == NULL)
    {
        return;
    }
    NodoEstudiante *iteradorEstudiante = lista->head;
    if (iteradorEstudiante == estudianteAEliminar)
    {
        lista->head = estudianteAEliminar->siguiente;
    }
    else
    {
        while (iteradorEstudiante->siguiente != estudianteAEliminar)
        {
            iteradorEstudiante = iteradorEstudiante->siguiente;
        }
        iteradorEstudiante->siguiente = estudianteAEliminar->siguiente;
    }
    lista->tamanio--;
    printf("Estudiante \n Nombre: %s\n Apellido: %s\n Edad: %d\n Eliminado!!\n", estudianteAEliminar->estudiante->nombre, estudianteAEliminar->estudiante->apellido, estudianteAEliminar->estudiante->edad);
    free(estudianteAEliminar);
}

int cantidadDeAlumnos(ListaEstudiantes *lista)
{
    return lista->tamanio;
}

void modificarEstudiante(char *nombre , char *apellido , int edad  , Estudiante *estudiante)
{
    if (strlen(nombre) > 0 && strcmp(nombre, estudiante->nombre) != 0)
    {
        modificarNombreEstudiante(estudiante, nombre);
    }
    if (strlen(apellido) > 0 && apellido != estudiante->apellido)
    {
        modificarApellidoEstudiante(estudiante, apellido);
    }
    if (edad >= 18 && edad != estudiante->edad)
    {
        modificarEdad(estudiante, edad);
    }
}

Estudiante *obtenerListaEstudiantes(ListaEstudiantes *lista, int *cantidad)
{
    if (lista == NULL || lista->head == NULL)
    {
        *cantidad = 0;
        return NULL;
    }
    Estudiante *array = malloc(sizeof(Estudiante) * lista->tamanio);
    if (array == NULL)
    {
        *cantidad = 0;
        return NULL;
    }
    int i = 0;
    NodoEstudiante *iterador = lista->head;
    while (iterador != NULL)
    {
        array[i] = *(iterador->estudiante);
        iterador = iterador->siguiente;
        i++;
    }
    *cantidad = i;
    return array;
}
Estudiante *obtenerListaEstudiantesPorRangoDeEdad(int comienzo, int fin, ListaEstudiantes *lista, int *cantidad)
{
    if (lista == NULL || lista->head == NULL)
    {
        *cantidad = 0;
        return NULL;
    }
    Estudiante *array = malloc(sizeof(Estudiante) * lista->tamanio);
    if (array == NULL)
    {
        *cantidad = 0;
        return NULL;
    }
    int i = 0;
    NodoEstudiante *iterador = lista->head;
    while (iterador != NULL)
    {
        if (iterador->estudiante->edad >= comienzo && iterador->estudiante->edad <= fin)
        {
            array[i] = *(iterador->estudiante);
            i++;
        }
        iterador = iterador->siguiente;
    }
    *cantidad = i;
    return array;
}
void cargarDatosDePruebaEstudiantes(ListaEstudiantes *lista)
{   
    for (int i = 0; i < MOCK_CANTIDAD; i++)
    {
        Estudiante *nuevoEstudiante = crearEstudiante(
            datos[i].nombre,
            datos[i].apellido,
            datos[i].edad
        );
        agregarEstudiante(nuevoEstudiante, lista);
    }
    printf("Datos de prueba cargados correctamente.\n");
}

void mostrarEstudiantesPaginado(Estudiante *array, int cantidad) {
    int cantidadEstudiantesPorPagina = 10;
    int paginaActual = 0;
    int totalPaginas = (cantidad + cantidadEstudiantesPorPagina - 1) / cantidadEstudiantesPorPagina;
    char opcion;
    do {
        printf("=== Página %d de %d ===\n", paginaActual + 1, totalPaginas);
        int inicio = paginaActual * cantidadEstudiantesPorPagina;
        int fin = inicio + cantidadEstudiantesPorPagina;
        if (fin > cantidad) fin = cantidad;
        for (int i = inicio; i < fin; i++) {
            printf("%d) Nombre del Estudiante: %s %s (Edad:%d)  \n", 
                i + 1, array[i].nombre , array[i].apellido , array[i].edad);
        }
        printf("\n(a) anterior | (s) siguiente | (q) salir\n");
        printf("Seleccione opción: ");
        scanf(" %c", &opcion);

        if (opcion == 's' && paginaActual < totalPaginas - 1)
            paginaActual++;
        else if (opcion == 'a' && paginaActual > 0)
            paginaActual--;

    } while (opcion != 'q');
}