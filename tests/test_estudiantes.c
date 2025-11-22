#include <stdio.h>
#include <assert.h>
#include <string.h>



#include "../estudiantes/estudiante/crudEstudiante.h"
#include "../materias/materia/crudMateria.h"
#include "../materias/listaMaterias/crudListaMaterias.h"
#include "../materias/listaMateriasAprobadas/crudListaMateriasAprobadas.h"

void test_crear_estudiante_valido() {
    Estudiante *e = crearEstudiante("Juan", "Perez", 20);

    assert(e != NULL);
    assert(strcmp(e->nombre, "Juan") == 0);
    assert(strcmp(e->apellido, "Perez") == 0);
    assert(e->edad == 20);
    assert(e->materiasInscriptas != NULL);
    assert(e->materiasInscriptas->tamanio == 0);
    assert(e->materiasAprobadas != NULL);

    printf("test_crear_estudiante_valido OK\n");
}

void test_crear_estudiante_invalido() {
    Estudiante *e1 = crearEstudiante("", "Perez", 20);
    Estudiante *e2 = crearEstudiante("Juan", "", 20);
    Estudiante *e3 = crearEstudiante("Juan", "Perez", 15);

    assert(e1 == NULL);
    assert(e2 == NULL);
    assert(e3 == NULL);

    printf("test_crear_estudiante_invalido OK\n");
}

void test_modificar_datos_estudiante() {
    Estudiante *e = crearEstudiante("Juan", "Perez", 20);

    modificarNombreEstudiante(e, "Carlos");
    modificarApellidoEstudiante(e, "Gomez");
    modificarEdad(e, 25);

    assert(strcmp(e->nombre, "Carlos") == 0);
    assert(strcmp(e->apellido, "Gomez") == 0);
    assert(e->edad == 25);

    printf("test_modificar_datos_estudiante OK\n");
}

void test_inscribir_estudiante_en_materia() {
    Estudiante *e = crearEstudiante("Ana", "Lopez", 22);

    Materia *m1 = crearMateria("Algebra");
    Materia *m2 = crearMateria("Programacion");

    inscribirEstudianteAMateria(e, m1);
    inscribirEstudianteAMateria(e, m2);

    assert(e->materiasInscriptas->head != NULL);
    assert(strcmp(e->materiasInscriptas->head->materia->nombre, "Algebra") == 0);
    assert(strcmp(e->materiasInscriptas->head->siguiente->materia->nombre, "Programacion") == 0);

    printf("test_inscribir_estudiante_en_materia OK\n");
}

void test_inscribir

int main() {
    printf("== INICIANDO TESTS DE ESTUDIANTE ==\n\n");

    test_crear_estudiante_valido();
    test_crear_estudiante_invalido();
    test_modificar_datos_estudiante();
    test_inscribir_estudiante_en_materia();

    printf("\n== TODOS LOS TESTS DE ESTUDIANTE PASARON OK ==\n");
    return 0;
}
