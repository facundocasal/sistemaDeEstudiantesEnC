#include "structListaEstudiantes.h"
#include "structEstudiante.h"
#include "crudEstudiante.h"
#include "mockListaEstudiantes/mockEstudiantes.c"
#include <string.h>
#include <stdlib.h>


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
        iteradorEstudiante = nuevoEstudiante;
    }
    else
    {
        NodoEstudiante *iteradorEstudiante = lista->head;
        while (iteradorEstudiante->siguiente != NULL)
        {
            iteradorEstudiante = iteradorEstudiante->siguiente;
        }
        iteradorEstudiante->siguiente = nuevoEstudiante;
    }
    lista->tamanio++;
    free(nuevoEstudiante);
    free(iteradorEstudiante);
}

NodoEstudiante *buscarEstudiante(char nombre, char apellido, ListaEstudiantes *lista)
{
    if (nombre == "" || apellido == "" || lista->head == NULL)
    {
        printf("Error: datos invalidos o lista vacia.\n");
        return NULL;
    }
    NodoEstudiante *iteradorEstudiante = lista->head;
    while (iteradorEstudiante->siguiente != NULL)
    {
        if (iteradorEstudiante->estudiante->nombre == nombre && iteradorEstudiante->estudiante->apellido == apellido)
        {
            printf("Estudiante encontrado!!\n");
            return iteradorEstudiante;
        }
        iteradorEstudiante = iteradorEstudiante->siguiente;
    }
    printf("Error: el estudiante no existe.\n");
    free(iteradorEstudiante);
    return NULL;
}

void eliminarEstudiante(char nombre, char apellido, ListaEstudiantes *lista)
{
    if (nombre == "" || apellido == "" || lista->head == NULL)
    {
        printf("Error: datos invalidos o lista vacia.\n");
        return NULL;
    }
    NodoEstudiante *estudianteAEliminar = buscarEstudiante(nombre, apellido, lista);
    if (estudianteAEliminar == NULL)
    {
        printf("Error: el estudiante no existe.\n");
        return NULL;
    }
    NodoEstudiante *iteradorEstudiante = lista->head;
    if (iteradorEstudiante == estudianteAEliminar)
    {
        lista->head = estudianteAEliminar->siguiente;
    }
    else
    {
        while (iteradorEstudiante->siguiente == estudianteAEliminar)
        {
            iteradorEstudiante = iteradorEstudiante->siguiente;
        }
        iteradorEstudiante->siguiente = estudianteAEliminar->siguiente;
    }
    lista->tamanio--;
    printf("Estudiante \n Nombre: %s\n Apellido: %s\n Edad: %d\n Eliminado!!\n", estudianteAEliminar->estudiante->nombre, estudianteAEliminar->estudiante->apellido, estudianteAEliminar->estudiante->edad);
    free(iteradorEstudiante);
    free(estudianteAEliminar);
}

int cantidadDeAlumnos(ListaEstudiantes *lista)
{
    return lista->tamanio;
}

void modificarEstudiante(char nombre, char apellido, int edad, Estudiante *estudiante)
{
    if (nombre != "" && nombre != estudiante->nombre)
    {
        modificarNombreEstudiante(estudiante, nombre);
    }
    if (apellido != "" && apellido != estudiante->apellido)
    {
        modificarApellidoEstudiante(estudiante, apellido);
    }
    if (edad >= 18 && edad != estudiante->edad)
    {
        modificarEdad(estudiante, edad);
    }
}


Estudiante **obtenerListaEstudiantes(ListaEstudiantes *lista, int *cantidad) {
    if (lista == NULL || lista->head == NULL) {
        *cantidad = 0;
        return NULL;
    }
    Estudiante **array = malloc(sizeof(Estudiante *) * lista->tamanio);
    if (array == NULL){
        *cantidad = 0;
        return NULL;
    }
    int i = 0 ; 
    NodoEstudiante *iterador = lista->head;
    while ( iterador == NULL){
        array[i] = iterador;
        iterador = iterador->siguiente;
        i++;
    }
    free(iterador);
    *cantidad = i ;
    return array;
}

void cargarDatosPrueba (ListaEstudiantes *lista) {
    int cantidad = sizeof(datos) / sizeof(datos[0]);
    for (int i = 0 ; i < cantidad ; i++) {
        Estudiante *nuevoEstudiante = crearEstudiante(datos[i].nombre , datos[i].apellido , datos[i].edad);
        agregarEstudiante(nuevoEstudiante , lista);
        free(nuevoEstudiante);
    }
    printf("Datos de prueba cargados correctamente.\n");
    free(cantidad);
}  