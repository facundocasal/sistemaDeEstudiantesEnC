#include <stdlib.h>
#include "structListaMaterias.h"
#include "materias/materia/crudMateria.h"
#include "crudListaMaterias.h"
#include "materias/listaMaterias/structListaMaterias.h"
#include <stdio.h>
#include <string.h>
ListaMaterias *nuevaListaMaterias()
{
    ListaMaterias *nuevaLista = malloc(sizeof(ListaMaterias));
    nuevaLista->head = NULL;
    nuevaLista->tamanio = 0;
    return nuevaLista;
}

void agregarNuevaMateria(Materia *materia, ListaMaterias *lista)
{
    if (materia == NULL)
    {
        return;
    }
    NodoMateria *nueavaMateria = malloc(sizeof(NodoMateria));
    nueavaMateria->materia = materia;
    nueavaMateria->siguiente = NULL;
    NodoMateria *iteradorMateria = lista->head;
    if (iteradorMateria == NULL)
    {
        lista->head = nueavaMateria;
    }
    else
    {
        while (iteradorMateria->siguiente != NULL)
        {
            iteradorMateria = iteradorMateria->siguiente;
        }
        iteradorMateria->siguiente = nueavaMateria;
    }
    lista->tamanio++;
}

NodoMateria *buscarMateria(char *nombreDeMateria, ListaMaterias *lista)
{
    if (lista->tamanio == 0 || strlen(nombreDeMateria) == 0)
    {
        printf("Error: datos invalidos o lista vacia.\n");
        return NULL;
    }
    NodoMateria *iteradorMateria = malloc(sizeof(NodoMateria));
    iteradorMateria = lista->head;
    while (iteradorMateria != NULL)
    {
        if (strcmp(iteradorMateria->materia->nombre, nombreDeMateria) == 0)
        {
            printf("Materia encontrada!!\n");
            return iteradorMateria;
        }
        iteradorMateria = iteradorMateria->siguiente;
    }
    printf("Error: La materia no existe.\n");
    return NULL;
}
Materia *ModificarMateriaLista(char *nuevoNombre, Materia *materia)
{
    if (strlen(nuevoNombre) == 0 || materia == NULL)
    {
        printf("Error al modificar la materia");
        return NULL;
    }
    modificarMateria(materia, nuevoNombre);
    return materia;
}

void eliminarMateria(char *nombreDeMateria, ListaMaterias *lista)
{
    if (lista->tamanio == 0 || strlen(nombreDeMateria) == 0)
    {
        printf("Error: datos invalidos o lista vacia.\n");
        return ;
    }
    NodoMateria *materiaAEliminar = buscarMateria(nombreDeMateria, lista);
    if (materiaAEliminar == NULL)
    {
        return ;
    }
    NodoMateria *iteradorMateria = malloc(sizeof(NodoMateria));
    iteradorMateria = lista->head;
    if (iteradorMateria == materiaAEliminar)
    {
        lista->head = materiaAEliminar->siguiente;
    }
    else
    {
        while (iteradorMateria->siguiente != materiaAEliminar)
        {
            iteradorMateria = iteradorMateria->siguiente;
        }
        iteradorMateria->siguiente = materiaAEliminar->siguiente;
    }
    printf("Materia \n %s\n Eliminada!!\n", materiaAEliminar->materia->nombre);
    lista->tamanio--;
}

int cantidadMaterias(ListaMaterias *lista)
{
    return lista->tamanio;
}

Materia *obtenerListaMaterias(ListaMaterias *lista, int *cantidad)
{
    if (lista == NULL || lista->head == NULL)
    {
        *cantidad = 0;
        return NULL;
    }
    Materia *array = malloc(sizeof(Materia) * lista->tamanio);
    if (array == NULL)
    {
        *cantidad = 0;
        return NULL;
    }
    int i = 0;
    NodoMateria *iterador = lista->head;
    while (iterador != NULL)
    {
        array[i] = *(iterador->materia);
        iterador = iterador->siguiente;
        i++;
    }
    *cantidad = i;
    return array;
}

void cargarDatosDePruebaMateria(ListaMaterias *lista)
{
    const char *nombresDeMaterias[] = {
        "Matematica",
        "Programacion",
        "Fisica",
        "Informatica",
        "Redes"};
    int cantidad = sizeof(nombresDeMaterias) / sizeof(nombresDeMaterias[0]);
    for (int i = 0; i < cantidad; i++)
    {
        Materia *nuevoMateria = crearMateria(nombresDeMaterias[i]);
        agregarNuevaMateria(nuevoMateria, lista);
    }
    printf("Datos de prueba cargados correctamente.\n");
}

void mostrarMateriasPaginado(Materia *array, int cantidad) {
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
            printf("%d) Nombre de la materia: %s \n", 
                i + 1, array[i].nombre);
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