#include "structListaEstudiantes.h"
#include "structEstudiante.h"
#include "crudEstudiante.h"
#include "mockListaEstudiantes/mockEstudiantes.c"
#include <string.h>
#include <stdlib.h>


ListaEstudiantes *nuevaListaEstudiantes()
{
    ListaEstudiantes *nuevaLista = malloc(sizeof(ListaEstudiantes));
    if (nuevaLista == NULL) return NULL;
    
    nuevaLista->head = NULL;
    nuevaLista->tamanio = 0;
    return nuevaLista;
}

void agregarEstudiante(Estudiante *estudiante, ListaEstudiantes *lista)
{
    if (estudiante == NULL || lista == NULL)
    {
        return;
    }
    NodoEstudiante *nuevoEstudiante = malloc(sizeof(NodoEstudiante));
    nuevoEstudiante->estudiante = estudiante;

    nuevoEstudiante->siguiente = NULL;



    if (lista -> head == NULL){
        lista -> head = nuevoEstudiante;
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
  
}

NodoEstudiante *buscarEstudiante(char nombre, char apellido, ListaEstudiantes *lista)
{
    if (strlen(nombre) == 0 || srtlen(apellido) == 0  || lista->head == NULL || lista == NULL) 
    {
        printf("Error: datos invalidos o lista vacia.\n");
        return NULL;
    }
    NodoEstudiante *iteradorEstudiante = lista->head;
    
    while (iteradorEstudiante != NULL)
    {
        if (strcmp(iteradorEstudiante->estudiante->nombre, nombre) == 0 && strcmp(iteradorEstudiante->estudiante->apellido, apellido == 0))
        {
            printf("Estudiante encontrado!!\n");
            return iteradorEstudiante;
        }
        iteradorEstudiante = iteradorEstudiante->siguiente;
    }
    printf("Error: el estudiante no existe.\n");
    return NULL;
}

void eliminarEstudiante(char nombre, char apellido, ListaEstudiantes *lista)
{
    if (strlen(nombre) == 0 || srtlen(apellido) == 0 || lista->head == NULL || lista == NULL)
    {
        printf("Error: datos invalidos o lista vacia.\n");
        return NULL;
    }
    NodoEstudiante *actual = lista -> head;
    NodoEstudiante *anterior = NULL;

    while (actual != NULL){
        if (strcmp(actual -> estudiante -> nombre, nombre) == 0 && 
        strcmp(actual -> estudiante -> apellido, apellido)== 0){
            break;
        }
        anterior = actual;
        actual = actual -> siguiente;
    }

    if(actual == NULL){
        printf("Error: el estudiante no existe. \n");
        return;
    }

    if(anterior == NULL){
        lista -> head = actual -> siguiente;
    }else{
        anterior -> siguiente = actual -> siguiente;
    }

    printf("Estudiante \n Nombre: %s\n Apellido: %s\n Edad: %d\n Eliminado!!\n", actual -> estudiante -> nombre,
    actual -> estudiante -> apellido, actual ->estudiante -> edad);
    
    free(actual -> estudiante);
    free(actual);

    lista -> tamanio--;
}
    


int cantidadDeAlumnos(ListaEstudiantes *lista)
{
    return lista->tamanio;
}

void modificarEstudiante(char nombre, char apellido, int edad, Estudiante *estudiante)
{
    if (strlen(nombre) > 0 && strcmp(nombre, estudiante->nombre) != 0)
    {
        modificarNombreEstudiante(estudiante, nombre);
    }
    if (strlen(apellido) > 0 && strcmp(apellido, estudiante->apellido) != 0)
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
    
    while ( iterador != NULL){
        array[i] = iterador -> estudiante;
        iterador = iterador->siguiente;
        i++;
    }
    *cantidad = i ;
    return array;
}

void cargarDatosPrueba (ListaEstudiantes *lista) {
    int cantidad = sizeof(datos) / sizeof(datos[0]);
    for (int i = 0 ; i < cantidad ; i++) {
        Estudiante *nuevoEstudiante = crearEstudiante(datos[i].nombre , datos[i].apellido , datos[i].edad);
        agregarEstudiante(nuevoEstudiante , lista);
    }
    printf("Datos de prueba cargados correctamente.\n");
}  