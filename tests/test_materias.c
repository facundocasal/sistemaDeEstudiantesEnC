#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#include "../materias/materia/structMateria.h"
#include "../materias/materia/crudMateria.h"
#include "../materias/listaMaterias/structListaMaterias.h"
#include "../materias/listaMaterias/crudListaMaterias.h"
#include "../estudiantes/estudiante/structEstudiante.h"
#include "../estudiantes/estudiante/crudEstudiante.h"
#include "../estudiantes/lista/structListaEstudiantes.h"
#include "../estudiantes/lista/crudListaEstudiantes.h"



// =========================
//    TESTS UNITARIOS
// =========================

void test_crear_materia() {
    Materia *m = crearMateria("Programacion");

    assert(m != NULL);
    assert(strcmp(m->nombre, "Programacion") == 0);
    assert(m->estudiantesInscriptos != NULL);

    free(m->estudiantesInscriptos);
    free(m);
    printf("test_crear_materia OK\n");
}

void test_agregar_materia_lista() {
    ListaMaterias *lista = nuevaListaMaterias();
    Materia *m = crearMateria("Matematica");

    agregarNuevaMateria(m, lista);

    assert(lista->tamanio == 1);
    assert(strcmp(lista->head->materia->nombre, "Matematica") == 0);

    free(lista);
    free(m->estudiantesInscriptos);
    free(m);
    printf("test_crear_materia_lista OK\n");
}

void test_buscar_materia() {
    ListaMaterias *lista = nuevaListaMaterias();

    agregarNuevaMateria(crearMateria("Fisica"), lista);
    agregarNuevaMateria(crearMateria("Quimica"), lista);

    NodoMateria *n = buscarMateria("Quimica", lista);

    assert(n != NULL);
    assert(strcmp(n->materia->nombre, "Quimica") == 0);

    free(lista);
    printf("test_buscar_materia OK\n");
}

void test_modificar_materia() {
    Materia *m = crearMateria("Redes");

    ModificarMateriaLista("RedesII", m);

    assert(strcmp(m->nombre, "RedesII") == 0);

    free(m->estudiantesInscriptos);
    free(m);
    printf("test_modificar_materia OK\n");
}

void test_eliminar_materia() {
    ListaMaterias *lista = nuevaListaMaterias();

    agregarNuevaMateria(crearMateria("BD1"), lista);
    agregarNuevaMateria(crearMateria("SO"), lista);

    eliminarMateria("BD1", lista);

    assert(lista->tamanio == 1);
    assert(strcmp(lista->head->materia->nombre, "SO") == 0);

    free(lista);
    printf("test_eliminar_materia OK\n");
}

void test_obtener_lista_materias() {
    ListaMaterias *lista = nuevaListaMaterias();
    agregarNuevaMateria(crearMateria("A"), lista);
    agregarNuevaMateria(crearMateria("B"), lista);
    agregarNuevaMateria(crearMateria("C"), lista);

    int cantidad = 0;
    Materia *array = obtenerListaMaterias(lista, &cantidad);

    assert(cantidad == 3);
    assert(strcmp(array[0].nombre, "A") == 0);
    assert(strcmp(array[1].nombre, "B") == 0);
    assert(strcmp(array[2].nombre, "C") == 0);

    free(array);
    free(lista);
    printf("test_obtener_lista_materia OK\n");
}


// =========================
//     TEST RUNNER
// =========================

int main() {
    printf("=== TESTS LISTA DE MATERIAS ===\n");

    test_crear_materia();
    test_agregar_materia_lista();
    test_buscar_materia();
    test_modificar_materia();
    test_eliminar_materia();
    test_obtener_lista_materias();

    printf("Todos los tests pasaron correctamente.\n");

    return 0;
}
