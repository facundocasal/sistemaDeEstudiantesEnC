#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structListaMateriasAprobadas.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "crudListaMateriasAprobadas.h"

ListaMateriasAprobadas* nuevaListaMateriasAprobadas()
{
    ListaMateriasAprobadas *nuevaLista = malloc(sizeof(ListaMateriasAprobadas));
    nuevaLista->head = NULL;
    nuevaLista->tamanio = 0;
    return nuevaLista;
};

void agregarNuevaMateriaAprobada(const char *nombre, int nota, ListaMateriasAprobadas *lista)
{
    if (strlen(nombre) == 0 || nota < 4 || nota > 10)
    {
        printf("Error al agregar nueva materia aprobada");
        return;
    }
    NodoMateriaAprobada *nuevaMateriaAprobada = malloc(sizeof(NodoMateriaAprobada));
    strcpy(nuevaMateriaAprobada->nombreMateria, nombre);
    nuevaMateriaAprobada->nota = nota;
    nuevaMateriaAprobada->condicion = 1;
    nuevaMateriaAprobada->siguiente = NULL;
    if (lista->tamanio == 0)
    {
        lista->head = nuevaMateriaAprobada;
    }
    else
    {
        NodoMateriaAprobada *iterador = lista->head;
        while (iterador->siguiente != NULL)
        {
            iterador = iterador->siguiente;
        }
        iterador->siguiente = nuevaMateriaAprobada;
    }
    lista->tamanio++;
    printf("Se agrego nueva materia aprobada");
}

NodoMateriaAprobada *obtenerListaMateriasAprobadas(ListaMateriasAprobadas *lista, int *cantidad)
{
    if (lista == NULL || lista->head == NULL)
    {
        *cantidad = 0;
        return NULL;
    }
    NodoMateriaAprobada *array = malloc(sizeof(NodoMateriaAprobada) * lista->tamanio);
    if (array == NULL)
    {
        *cantidad = 0;
        return NULL;
    }
    int i = 0;
    NodoMateriaAprobada *iterador = lista->head;
    while (iterador != NULL)
    {
        array[i] = *(iterador);
        iterador = iterador->siguiente;
        i++;
    }
    *cantidad = i;
    return array;
}

NodoMateriaAprobada *buscarMateriaAprobada(char *nombreMateria, ListaMateriasAprobadas *lista)
{
    if (strlen(nombreMateria) == 0 || lista->head == NULL)
    {
        printf("Error al buscar materia aprobada ");
        return NULL;
    }
    NodoMateriaAprobada *iterador = lista->head;
    while (iterador != NULL)
    {

        if (strcmp(nombreMateria , iterador->nombreMateria ) == 0)
        {
            printf("Materia encontrada");
            return iterador;
        }
        iterador = iterador->siguiente;
    }
    printf("No pudimos encontrar esa materia");
    return NULL;
}

void eliminarMateriaAprobada(char *nombreMateria, ListaMateriasAprobadas *lista)
{
    if (strlen(nombreMateria) == 0  || lista->head == NULL)
    {
        printf("Error al eliminar materia aprobada ");
        return;
    }
    NodoMateriaAprobada *materiaAEliminar = buscarMateriaAprobada(nombreMateria, lista);
    if (materiaAEliminar != NULL)
    {
        NodoMateriaAprobada *iterador = malloc(sizeof(NodoMateriaAprobada));
        iterador = lista->head;
        if (iterador == materiaAEliminar)
        {
            lista->head = materiaAEliminar->siguiente;
        }
        else
        {
            while (iterador->siguiente == materiaAEliminar)
            {
                iterador = iterador->siguiente;
            }
            iterador->siguiente = materiaAEliminar->siguiente;
        }
        lista->tamanio--;
        printf("Error al eliminar materia aprobada.");
        return;
    }
}

bool modificarNotaDeMateriaAprobada(int nota, char *nombreMateria, ListaMateriasAprobadas *lista){
    NodoMateriaAprobada *materiaAModificar = buscarMateriaAprobada(nombreMateria, lista);
    if (nota >= 4){
        materiaAModificar->nota = nota;
    }else{
        eliminarMateriaAprobada(nombreMateria , lista);
    }
    return 1;
}
int obternerCantidadMateriasArpobadas ( ListaMateriasAprobadas *lista){
    return lista->tamanio;
}

float obternerPromedio (ListaMateriasAprobadas *lista) {
    if (obternerCantidadMateriasArpobadas(lista) == 0){
        return 0.0;
    }
    int suma = 0;
    NodoMateriaAprobada *iterador = malloc(sizeof(NodoMateriaAprobada));
    iterador = lista->head;
    while (iterador != NULL)
    {
        suma += iterador->nota;
    }
    printf("Promedio: %.2f\n", (float)suma / obternerCantidadMateriasArpobadas(lista));
    return (float)suma / obternerCantidadMateriasArpobadas(lista);
}

void mostrarMateriasAprobadasPaginado(NodoMateriaAprobada *array, int cantidad) {
    int cantidadMateriasPorPagina = 10;
    int paginaActual = 0;
    int totalPaginas = (cantidad + cantidadMateriasPorPagina - 1) / cantidadMateriasPorPagina;
    char opcion;
    do {
        printf("=== Página %d de %d ===\n", paginaActual + 1, totalPaginas);
        int inicio = paginaActual * cantidadMateriasPorPagina;
        int fin = inicio + cantidadMateriasPorPagina;
        if (fin > cantidad) fin = cantidad;
        for (int i = inicio; i < fin; i++) {
            printf("%d) Nombre de la materia: %s Condición: %s (Nota: %d)\n", 
                i + 1, array[i].nombreMateria, "Aprobada" , array[i].nota);
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
void cargarDatosDePruebaMateriasAprobadas(ListaMateriasAprobadas *lista) {
    const char *materias[] = {"Matematica", "Fisica", "Programacion", "Informatica"};
    int notas[] = {8, 6, 9, 7};
    int cantidad = sizeof(materias) / sizeof(materias[0]);
    for (int i = 0; i < cantidad; i++) {
        agregarNuevaMateriaAprobada(materias[i], notas[i], lista);
    }
}