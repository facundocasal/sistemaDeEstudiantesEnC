#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---- STRUCTS ----
#include "estudiantes/estudiante/structEstudiante.h"
#include "estudiantes/Lista/structListaEstudiantes.h"
#include "materias/listaMaterias/structListaMaterias.h"
#include "materias/listaMateriasAprobadas/structListaMateriasAprobadas.h"
#include "materias/materia/structMateria.h"

// ---- CRUD ----
#include "estudiantes/estudiante/crudEstudiante.h"
#include "estudiantes/Lista/crudListaEstudiantes.h"
#include "materias/listaMaterias/crudListaMaterias.h"
#include "materias/listaMateriasAprobadas/crudListaMateriasAprobadas.h"
#include "materias/materia/crudMateria.h"


#include "estudiantes/Lista/mockListaEstudiantes/mockEstudiantes.h"

// ===================== Helpers generales =====================

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void leerCadena(const char *mensaje, char *dest, int tam)
{
    printf("%s", mensaje);
    if (fgets(dest, tam, stdin) != NULL)
    {
        dest[strcspn(dest, "\n")] = 0; 
    }
}

int leerEntero(const char *mensaje)
{
    char buffer[64];
    int valor;
    while (1)
    {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            return 0;
        }
        if (sscanf(buffer, "%d", &valor) == 1)
        {
            return valor;
        }
        printf("Entrada inválida. Intente de nuevo.\n");
    }
}

// ===================== Prototipos de menús =====================

void menuEstudiante(ListaEstudiantes *listaEstudiantes, ListaMaterias *listaMaterias);
void submenuEstudianteMaterias(Estudiante *estudiante, ListaMaterias *listaMaterias);
void menuDocente(ListaEstudiantes *listaEstudiantes, ListaMaterias *listaMaterias);
void submenuDocenteGestionEstudiantes(ListaEstudiantes *listaEstudiantes);
void submenuDocenteGestionMaterias(ListaMaterias *listaMaterias);
void submenuDocenteGestionMateriasAprobadas(ListaEstudiantes *listaEstudiantes);

// ===================== MAIN =====================

int main()
{
    int opcion = 0;

    ListaEstudiantes *listaEstudiantes = nuevaListaEstudiantes();
    ListaMaterias *listaMaterias = nuevaListaMaterias();



    while (opcion != 3)
    {
        printf("\n====================\n");
        printf("MENU GENERAL\n");
        printf("1. Menu Estudiante\n");
        printf("2. Menu Docente\n");
        printf("3. Salir\n");
        printf("====================\n");

        opcion = leerEntero("Opcion: ");

        switch (opcion)
        {
        case 1:
            menuEstudiante(listaEstudiantes, listaMaterias);
            break;
        case 2:
            menuDocente(listaEstudiantes, listaMaterias);
            break;
        case 3:
            printf("Saliendo del sistema...\n");
            break;
        default:
            printf("Opcion incorrecta.\n");
        }
    }

    return 0;
}

// ===================== MENU ESTUDIANTE =====================

void menuEstudiante(ListaEstudiantes *listaEstudiantes, ListaMaterias *listaMaterias)
{
    int opcion = 0;

    while (opcion != 8)
    {
        printf("\n---------------------\n");
        printf("MENU ESTUDIANTE\n");
        printf("1. Crear Estudiante\n");
        printf("2. Modificar Nombre\n");
        printf("3. Modificar Apellido\n");
        printf("4. Modificar Edad\n");
        printf("5. Mostrar Datos\n");
        printf("6. Gestionar Materias\n");
        printf("7. Mostrar Promedio\n");
        printf("8. Volver al menu general\n");
        printf("---------------------\n");

        opcion = leerEntero("Elegir opcion: ");

        char nombre[50], apellido[50];

        switch (opcion)
        {
        case 1:
        {
            char nombreNuevo[50], apellidoNuevo[50];
            int edad;

            leerCadena("Nombre del estudiante: ", nombreNuevo, sizeof(nombreNuevo));
            leerCadena("Apellido del estudiante: ", apellidoNuevo, sizeof(apellidoNuevo));
            edad = leerEntero("Edad del estudiante: ");

            Estudiante *estudiante = crearEstudiante(nombreNuevo, apellidoNuevo, edad);
            if (estudiante == NULL)
            {
                printf("Datos inválidos. Debe tener nombre, apellido y ser mayor de 18.\n");
            }
            else
            {
                agregarEstudiante(estudiante, listaEstudiantes);
                printf("Estudiante creado correctamente.\n");
            }
            break;
        }

        case 2:
        {
            leerCadena("Nombre actual: ", nombre, sizeof(nombre));
            leerCadena("Apellido actual: ", apellido, sizeof(apellido));

            NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);
            if (!nodo)
            {
                printf("No se encontro el estudiante.\n");
                break;
            }

            char nuevoNombre[50];
            leerCadena("Nuevo nombre: ", nuevoNombre, sizeof(nuevoNombre));
            modificarNombreEstudiante(nodo->estudiante, nuevoNombre);
            printf("Nombre modificado.\n");
            break;
        }

        case 3:
        {
            leerCadena("Nombre actual: ", nombre, sizeof(nombre));
            leerCadena("Apellido actual: ", apellido, sizeof(apellido));

            NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);
            if (!nodo)
            {
                printf("No se encontro el estudiante.\n");
                break;
            }

            char nuevoApellido[50];
            leerCadena("Nuevo apellido: ", nuevoApellido, sizeof(nuevoApellido));
            modificarApellidoEstudiante(nodo->estudiante, nuevoApellido);
            printf("Apellido modificado.\n");
            break;
        }

        case 4:
        {
            leerCadena("Nombre: ", nombre, sizeof(nombre));
            leerCadena("Apellido: ", apellido, sizeof(apellido));

            NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);
            if (!nodo)
            {
                printf("No se encontro el estudiante.\n");
                break;
            }

            int nuevaEdad = leerEntero("Nueva edad: ");
            modificarEdad(nodo->estudiante, nuevaEdad);
            printf("Edad modificada.\n");
            break;
        }

        case 5:
        {
            leerCadena("Nombre: ", nombre, sizeof(nombre));
            leerCadena("Apellido: ", apellido, sizeof(apellido));

            NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);
            if (!nodo)
            {
                printf("No se encontro el estudiante.\n");
                break;
            }

            mostrarDatos(nodo->estudiante);
            break;
        }

        case 6:
        {
            // Gestionar materias del estudiante (submenú)
            leerCadena("Nombre del estudiante: ", nombre, sizeof(nombre));
            leerCadena("Apellido del estudiante: ", apellido, sizeof(apellido));

            NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);
            if (!nodo)
            {
                printf("No se encontro el estudiante.\n");
                break;
            }

            submenuEstudianteMaterias(nodo->estudiante, listaMaterias);
            break;
        }

        case 7:
        {
            // Mostrar promedio de materias aprobadas
            leerCadena("Nombre del estudiante: ", nombre, sizeof(nombre));
            leerCadena("Apellido del estudiante: ", apellido, sizeof(apellido));

            NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);
            if (!nodo)
            {
                printf("No se encontro el estudiante.\n");
                break;
            }

            ListaMateriasAprobadas *listaAprobadas = nodo->estudiante->materiasAprobadas;
            if (listaAprobadas == NULL || listaAprobadas->head == NULL)
            {
                printf("El estudiante no tiene materias aprobadas aun.\n");
                break;
            }

            obtenerPromedio(listaAprobadas);
            break;
        }

        case 8:
            printf("Volviendo al menu general...\n");
            break;

        default:
            printf("Opcion incorrecta.\n");
        }
    }
}

// ===================== SUBMENU ESTUDIANTE: GESTIONAR MATERIAS =====================

void submenuEstudianteMaterias(Estudiante *estudiante, ListaMaterias *listaMaterias)
{
    int opcion = 0;

    while (opcion != 4)
    {
        printf("\n---- Gestionar Materias (Estudiante: %s %s) ----\n",
               estudiante->nombre, estudiante->apellido);
        printf("1. Inscribirse a una materia\n");
        printf("2. Buscar materia inscripta\n");
        printf("3. Mostrar sus materias inscriptas\n");
        printf("4. Volver\n");

        opcion = leerEntero("Elegir opcion: ");

        char nombreMateria[50];

        switch (opcion)
        {
        case 1:
        {
            leerCadena("Nombre de la materia a inscribirse: ",
                       nombreMateria, sizeof(nombreMateria));

            NodoMateria *nodoMat = buscarMateria(nombreMateria, listaMaterias);
            if (!nodoMat)
            {
                printf("La materia no existe en el sistema.\n");
                break;
            }

            inscribirEstudianteAMateria(estudiante, nodoMat->materia);
            printf("Inscripcion correcta.\n");
            break;
        }

        case 2:
        {
            leerCadena("Nombre de la materia a buscar en sus inscripciones: ",
                       nombreMateria, sizeof(nombreMateria));

            ListaMaterias *listaInscripto = estudiante->materiasInscriptas;
            NodoMateria *nodoMat = buscarMateria(nombreMateria, listaInscripto);
            if (!nodoMat)
            {
                printf("El estudiante NO esta inscripto en esa materia.\n");
            }
            else
            {
                printf("El estudiante esta inscripto en la materia %s.\n",
                       nodoMat->materia->nombre);
            }
            break;
        }

        case 3:
            mostrarMateriasInscriptas(estudiante);
            break;

        case 4:
            printf("Volviendo al menu estudiante...\n");
            break;

        default:
            printf("Opcion incorrecta.\n");
        }
    }
}

// ===================== MENU DOCENTE =====================

void menuDocente(ListaEstudiantes *listaEstudiantes, ListaMaterias *listaMaterias)
{
    int opcion = 0;

    while (opcion != 4)
    {
        printf("\n---------------------\n");
        printf("MENU DOCENTE\n");
        printf("1. Gestion de estudiantes\n");
        printf("2. Gestion de materias\n");
        printf("3. Gestion de materias aprobadas\n");
        printf("4. Volver al menu general\n");
        printf("---------------------\n");

        opcion = leerEntero("Elegir opcion: ");

        switch (opcion)
        {
        case 1:
            submenuDocenteGestionEstudiantes(listaEstudiantes);
            break;
        case 2:
            submenuDocenteGestionMaterias(listaMaterias);
            break;
        case 3:
            submenuDocenteGestionMateriasAprobadas(listaEstudiantes);
            break;
        case 4:
            printf("Volviendo al menu general...\n");
            break;
        default:
            printf("Opcion incorrecta.\n");
        }
    }
}

// ===================== DOCENTE: GESTION ESTUDIANTES =====================

void submenuDocenteGestionEstudiantes(ListaEstudiantes *listaEstudiantes)
{
    int opcion = 0;

    while (opcion != 4)
    {
        printf("\n---- Gestion de Estudiantes ----\n");
        printf("1. Ver todos los estudiantes (paginado)\n");
        printf("2. Buscar estudiantes por rango de edad\n");
        printf("3. Eliminar estudiante\n");
        printf("4. Volver\n");

        opcion = leerEntero("Elegir opcion: ");

        char nombre[50], apellido[50];

        switch (opcion)
        {
        case 1:
        {
            int cantidad = 0;
            Estudiante *array = obtenerListaEstudiantes(listaEstudiantes, &cantidad);
            if (cantidad == 0 || array == NULL)
            {
                printf("No hay estudiantes cargados.\n");
                break;
            }
            mostrarEstudiantesPaginado(array, cantidad);
            free(array);
            break;
        }

        case 2:
        {
            int desde = leerEntero("Edad desde: ");
            int hasta = leerEntero("Edad hasta: ");

            int cantidad = 0;
            Estudiante *array = obtenerListaEstudiantesPorRangoDeEdad(desde, hasta,
                                                                       listaEstudiantes, &cantidad);
            if (cantidad == 0 || array == NULL)
            {
                printf("No se encontraron estudiantes en ese rango.\n");
                break;
            }

            mostrarEstudiantesPaginado(array, cantidad);
            free(array);
            break;
        }

        case 3:
        {
            leerCadena("Nombre del estudiante a eliminar: ", nombre, sizeof(nombre));
            leerCadena("Apellido del estudiante a eliminar: ", apellido, sizeof(apellido));

            eliminarEstudiante(nombre, apellido, listaEstudiantes);
            break;
        }

        case 4:
            printf("Volviendo al menu docente...\n");
            break;

        default:
            printf("Opcion incorrecta.\n");
        }
    }
}

// ===================== DOCENTE: GESTION MATERIAS =====================

void submenuDocenteGestionMaterias(ListaMaterias *listaMaterias)
{
    int opcion = 0;

    while (opcion != 9)
    {
        printf("\n---- Gestion de Materias ----\n");
        printf("1. Agregar nueva materia\n");
        printf("2. Buscar materia\n");
        printf("3. Modificar materia\n");
        printf("4. Eliminar materia\n");
        printf("5. Ver cantidad de materias\n");
        printf("6. Obtener lista de materias (paginado)\n");
        printf("7. Cargar datos de prueba\n");
        printf("8. Mostrar materias paginado\n");
        printf("9. Volver\n");

        opcion = leerEntero("Elegir opcion: ");

        char nombreMateria[50], nuevoNombre[50];

        switch (opcion)
        {


        case 1:
        {
            leerCadena("Nombre de la nueva materia: ", nombreMateria, sizeof(nombreMateria));
            Materia *nueva = crearMateria(nombreMateria);
            if (!nueva)
            {
                printf("No se pudo crear la materia.\n");
                break;
            }
            agregarNuevaMateria(nueva, listaMaterias);
            printf("Materia agregada.\n");
            break;
        }

        case 2:
        {
            leerCadena("Nombre de la materia a buscar: ", nombreMateria, sizeof(nombreMateria));
            NodoMateria *nodo = buscarMateria(nombreMateria, listaMaterias);
            if (!nodo)
            {
                printf("La materia no existe.\n");
            }
            else
            {
                printf("Materia encontrada: %s\n", nodo->materia->nombre);
            }
            break;
        }

        case 3:
        {
            leerCadena("Nombre actual de la materia: ", nombreMateria, sizeof(nombreMateria));
            NodoMateria *nodo = buscarMateria(nombreMateria, listaMaterias);
            if (!nodo)
            {
                printf("La materia no existe.\n");
                break;
            }

            leerCadena("Nuevo nombre: ", nuevoNombre, sizeof(nuevoNombre));
            modificarMateria(nodo->materia, nuevoNombre);
            printf("Materia modificada.\n");
            break;
        }

        case 4:
        {
            leerCadena("Nombre de la materia a eliminar: ", nombreMateria, sizeof(nombreMateria));
            eliminarMateria(nombreMateria, listaMaterias);
            break;
        }

        case 5:
            printf("Cantidad de materias: %d\n", cantidadMaterias(listaMaterias));
            break;

        case 6:
        {
            int cantidad = 0;
            Materia *array = obtenerListaMaterias(listaMaterias, &cantidad);
            if (cantidad == 0 || array == NULL)
            {
                printf("No hay materias cargadas.\n");
                break;
            }
            mostrarMateriasPaginado(array, cantidad);
            free(array);
            break;
        }

        case 7:
            cargarDatosDePruebaMateria(listaMaterias);
            break;

        case 8:
        {
            int cantidad = 0;
            Materia *array = obtenerListaMaterias(listaMaterias, &cantidad);
            if (cantidad == 0 || array == NULL)
            {
                printf("No hay materias cargadas.\n");
                break;
            }
            mostrarMateriasPaginado(array, cantidad);
            free(array);
            break;
        }

        case 9:
            printf("Volviendo al menu docente...\n");
            break;

        default:
            printf("Opcion incorrecta.\n");
        }
    }
}

// ===================== DOCENTE: GESTION MATERIAS APROBADAS =====================

void submenuDocenteGestionMateriasAprobadas(ListaEstudiantes *listaEstudiantes)
{
    int opcion = 0;

    while (opcion != 11)
    {
        printf("\n---- Gestion de Materias Aprobadas (por alumno) ----\n");
        printf("1. Crear lista de materias aprobadas\n");
        printf("2. Agregar nueva materia aprobada\n");
        printf("3. Obtener lista de materias aprobadas\n");
        printf("4. Buscar materia aprobada\n");
        printf("5. Eliminar materia aprobada\n");
        printf("6. Modificar nota de materia aprobada\n");
        printf("7. Obtener cantidad de materias aprobadas\n");
        printf("8. Obtener promedio\n");
        printf("9. Mostrar materias aprobadas paginado\n");
        printf("10. Cargar datos de prueba\n");
        printf("11. Volver\n");

        opcion = leerEntero("Elegir opcion: ");

        char nombre[50], apellido[50], nombreMateria[50];
        int nota;

        if (opcion >= 1 && opcion <= 10)
        {
            leerCadena("Nombre del estudiante: ", nombre, sizeof(nombre));
            leerCadena("Apellido del estudiante: ", apellido, sizeof(apellido));

            NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);
            if (!nodo)
            {
                printf("No se encontro el estudiante.\n");
                continue;
            }

            ListaMateriasAprobadas *listaAprobadas = nodo->estudiante->materiasAprobadas;

            switch (opcion)
            {
            case 1:
                listaAprobadas->head = NULL;
                listaAprobadas->tamanio = 0;
                printf("Lista de materias aprobadas reiniciada para el alumno.\n");
                break;

            case 2:
                leerCadena("Nombre de la materia aprobada: ",
                           nombreMateria, sizeof(nombreMateria));
                nota = leerEntero("Nota (4-10): ");
                agregarNuevaMateriaAprobada(nombreMateria, nota, listaAprobadas);
                break;

            case 3:
            {
                int cantidad = 0;
                NodoMateriaAprobada *array = obtenerListaMateriasAprobadas(listaAprobadas, &cantidad);
                if (cantidad == 0 || array == NULL)
                {
                    printf("No hay materias aprobadas.\n");
                    break;
                }
                mostrarMateriasAprobadasPaginado(array, cantidad);
                free(array);
                break;
            }

            case 4:
                leerCadena("Nombre de la materia aprobada a buscar: ",
                           nombreMateria, sizeof(nombreMateria));
                buscarMateriaAprobada(nombreMateria, listaAprobadas);
                break;

            case 5:
                leerCadena("Nombre de la materia aprobada a eliminar: ",
                           nombreMateria, sizeof(nombreMateria));
                eliminarMateriaAprobada(nombreMateria, listaAprobadas);
                break;

            case 6:
                leerCadena("Nombre de la materia aprobada: ",
                           nombreMateria, sizeof(nombreMateria));
                nota = leerEntero("Nueva nota: ");
                modificarNotaDeMateriaAprobada(nota, nombreMateria, listaAprobadas);
                break;

            case 7:
                printf("Cantidad de materias aprobadas: %d\n",
                       obtenerCantidadMateriasArprobadas(listaAprobadas));
                break;

            case 8:
                obtenerPromedio(listaAprobadas);
                break;

            case 9:
            {
                int cantidad = 0;
                NodoMateriaAprobada *array = obtenerListaMateriasAprobadas(listaAprobadas, &cantidad);
                if (cantidad == 0 || array == NULL)
                {
                    printf("No hay materias aprobadas.\n");
                    break;
                }
                mostrarMateriasAprobadasPaginado(array, cantidad);
                free(array);
                break;
            }

            case 10:
                cargarDatosDePruebaMateriasAprobadas(listaAprobadas);
                break;

            default:
                break;
            }
        }
        else if (opcion == 11)
        {
            printf("Volviendo al menu docente...\n");
        }
        else
        {
            printf("Opcion incorrecta.\n");
        }
    }
}
