#include <string.h>
#include <stdlib.h>
#include "materias/listaMateriasAprobadas/structListaMateriasAprobadas.h"


ListaMateriasAprobadas *nuevaListaMateriasArobadas () {
    ListaMateriasAprobadas *nuevaLista = malloc(sizeof(ListaMateriasAprobadas));
    nuevaLista->head = NULL;
    nuevaLista->tamanio = 0;
    return nuevaLista;
};

void agregarNuevaMateriaAprobada( char nombre , int nota  ) {
    if (nombre == "" || nota <= 0 || nota > 10  ){
        printf("Error al agregar nueva materia aprobada");
        return;
    }
    NodoMateriaAprobada *nuevaMateriaAprobada = malloc(sizeof(NodoMateriaAprobada));
    nuevaMateriaAprobada->nombreMateria = nombre;
    nuevaMateriaAprobada->nota = nota;
    nuevaMateriaAprobada->siguiente = NULL;
    
}