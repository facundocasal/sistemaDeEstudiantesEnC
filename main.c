#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct
#include "estudiantes/estudiante/structEstudiante.h"
#include "estudiantes/Lista/structListaEstudiantes.h"
#include "materias/listaMateriasAprobadas/structListaMateriasAprobadas.h"
#include "materias/materia/structMateria.h"
// crud
#include "estudiantes/estudiante/crudEstudiante.h"
#include "estudiantes/Lista/crudListaEstudiantes.h"
#include "materias/listaMaterias/crudListaMaterias.h"
#include "materias/listaMateriasAprobadas/crudListaMateriasAprobadas.h"
#include "materias/materia/crudMateria.h"
// mock
#include "estudiantes/Lista/mockListaEstudiantes/mockEstudiantes.h"

int main()
{
    int opcion = 0;
    char buffer[100];

    ListaEstudiantes *listaEstudiantes = nuevaListaEstudiantes();
    ListaMaterias *listaMaterias = nuevaListaMaterias();
    ListaMateriasAprobadas *ListaMateriasAprobadas = nuevaListaMateriasAprobadas();

    while (opcion != 3)
    {
        printf("---------------------\n");
        printf("MENU\n");
        printf("1. Menu Estudiante\n");
        printf("2. Menu Materias\n");
        printf("3. Salir\n");
        printf("---------------------\n");
        printf("Opcion: ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &opcion) != 1)
            {
                printf("Debe ingresar un número!\n");
                opcion = 0;
                continue;
            }
        }

        switch (opcion)
        {
        // ---------------------- MENU ESTUDIANTE ----------------------
        case 1:
        {
            int OpcionDeMenuAlumno = 0;

            while (OpcionDeMenuAlumno != 7)
            {
                printf("---------------------\n");
                printf("Menu Alumno\n");
                printf("1. Crear Estudiante\n");
                printf("2. Modificar Nombre\n");
                printf("3. Modificar Apellido\n");
                printf("4. Modificar Edad\n");
                printf("5. Mostrar Datos\n");
                printf("6. Inscribir a Materia\n");
                printf("7. Salir\n");
                printf("Elegir opcion: ");

                scanf("%d", &OpcionDeMenuAlumno);
                while (getchar() != '\n')
                    ;

                switch (OpcionDeMenuAlumno)
                {
                case 1:
                {
                    char nombre[50], apellido[50];
                    int edad;

                    printf("Nombre del estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Apellido del estudiante: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    printf("Edad del estudiante: ");
                    scanf("%d", &edad);
                    while (getchar() != '\n')
                        ;

                    Estudiante *estudiante = crearEstudiante(nombre, apellido, edad);
                    if (estudiante == NULL)
                    {
                        printf("Datos inválidos.\n");
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
                    char nombre[50], apellido[50], nuevoNombre[50];

                    printf("Ingrese el nombre del estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Ingrese el apellido del estudiante: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);

                    if (!nodo)
                    {
                        printf("No se encontro el estudiante.\n");
                    }
                    else
                    {
                        printf("Nuevo nombre: ");
                        fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
                        nuevoNombre[strcspn(nuevoNombre, "\n")] = 0;

                        modificarNombreEstudiante(nodo->estudiante, nuevoNombre);
                        printf("Nombre modificado.\n");
                    }
                    break;
                }

                case 3:
                {
                    char nombre[50], apellido[50], nuevoApellido[50];

                    printf("Ingrese el nombre: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Ingrese el apellido: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);

                    if (!nodo)
                    {
                        printf("No se encontró el estudiante.\n");
                    }
                    else
                    {
                        printf("Nuevo apellido: ");
                        fgets(nuevoApellido, sizeof(nuevoApellido), stdin);
                        nuevoApellido[strcspn(nuevoApellido, "\n")] = 0;

                        modificarApellidoEstudiante(nodo->estudiante, nuevoApellido);
                        printf("Apellido modificado.\n");
                    }
                    break;
                }

                case 4:
                {
                    char nombre[50], apellido[50];
                    int nuevaEdad;

                    printf("Ingrese el nombre: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Ingrese el apellido: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);
                    if (!nodo)
                    {
                        printf("No se encontró el estudiante.\n");
                    }
                    else
                    {
                        printf("Nueva edad: ");
                        scanf("%d", &nuevaEdad);
                        while (getchar() != '\n')
                            ;

                        modificarEdad(nodo->estudiante, nuevaEdad);
                        printf("Edad modificada.\n");
                    }
                    break;
                }

                case 5:
                {
                    char nombre[50], apellido[50];

                    printf("Ingrese el nombre: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Ingrese el apellido: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);
                    if (!nodo)
                    {
                        printf("No se encontró el estudiante.\n");
                    }
                    else
                    {
                        mostrarDatos(nodo->estudiante);
                    }
                    break;
                }

                case 6:
                {
                    char nombre[50], apellido[50], nombreMateria[50];

                    printf("Ingrese nombre estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Ingrese apellido: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);
                    if (!nodo)
                    {
                        printf("No se encontró el estudiante.\n");
                        break;
                    }

                    printf("Ingrese materia: ");
                    fgets(nombreMateria, sizeof(nombreMateria), stdin);
                    nombreMateria[strcspn(nombreMateria, "\n")] = 0;

                    NodoMateria *mat = buscarMateria(nombreMateria, listaMaterias);
                    if (!mat)
                    {
                        printf("No se encontró la materia.\n");
                        break;
                    }

                    inscribirEstudianteAMateria(nodo->estudiante, mat->materia);
                    printf("Inscripción correcta.\n");
                    break;
                }

                case 7:
                    printf("Saliendo del menu alumno...\n");
                    break;

                default:
                    printf("Opción incorrecta.\n");
                }
            }
            break;
        }

        // ---------------------- MENU MATERIAS ----------------------
        case 2:
        {
            int OpcionDeMenuMateria = 0;

            while (OpcionDeMenuMateria != 6)
            {
                printf("---------------------\n");
                printf("Menu Materias\n");
                printf("1. Crear Materia\n");
                printf("2. Modificar Materia\n");
                printf("3. Eliminar Alumno De Materia\n");
                printf("4. Buscar Estudiante Por Nombre\n");
                printf("5. Buscar Estudiantes Por Edad\n");
                printf("6. Salir\n");
                printf("Elegir opcion: ");

                scanf("%d", &OpcionDeMenuMateria);
                while (getchar() != '\n')
                    ;

                switch (OpcionDeMenuMateria)
                {
                case 1:
                {
                    char nombreMateria[50];
                    printf("Nombre de la materia: ");
                    fgets(nombreMateria, sizeof(nombreMateria), stdin);
                    nombreMateria[strcspn(nombreMateria, "\n")] = 0;

                    Materia *nueva = crearMateria(nombreMateria);
                    agregarNuevaMateria(nueva, listaMaterias);

                    printf("Materia creada.\n");
                    break;
                }

                case 2:
                {
                    char nombreMateria[50], nuevoNombre[50];

                    printf("Nombre actual: ");
                    fgets(nombreMateria, sizeof(nombreMateria), stdin);
                    nombreMateria[strcspn(nombreMateria, "\n")] = 0;

                    NodoMateria *mat = buscarMateria(nombreMateria, listaMaterias);
                    if (!mat)
                    {
                        printf("No se encontró la materia.\n");
                        break;
                    }

                    printf("Nuevo nombre: ");
                    fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
                    nuevoNombre[strcspn(nuevoNombre, "\n")] = 0;

                    modificarMateria(mat->materia, nuevoNombre);
                    printf("Materia modificada.\n");
                    break;
                }

                case 3:
                {
                    char nombre[50], apellido[50], materiaBorrar[50];

                    printf("Nombre estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Apellido estudiante: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    printf("Materia: ");
                    fgets(materiaBorrar, sizeof(materiaBorrar), stdin);
                    materiaBorrar[strcspn(materiaBorrar, "\n")] = 0;

                    NodoMateria *mat = buscarMateria(materiaBorrar, listaMaterias);
                    eliminarAlumnoDeMateria(nombre, apellido, mat->materia);

                    printf("Estudiante eliminado de la materia.\n");
                    break;
                }

                case 4:
                {
                    printf("Buscar alumno por nombre");
                    char nombre[50], apellido[50], nombreMateria[50];

                    printf("Nombre estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Apellido estudiante: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    printf("Materia: ");
                    fgets(nombreMateria, sizeof(nombreMateria), stdin);
                    nombreMateria[strcspn(nombreMateria, "\n")] = 0;

                    NodoMateria *mat = buscarMateria(nombreMateria, listaMaterias);
                    NodoEstudiante *nodoEstudiante = buscarEstudiante(nombre, apellido, listaEstudiantes);
                    printf("PRUEBA TAMAÑO: %d\n",mat->materia->estudiantesInscriptos->tamanio);
                    //buscarEstudiantePorNombre(nodoEstudiante->estudiante, mat->materia);
                    break;
                }

                case 5:
                    printf("Buscar Estudiantes por Edad (falta implementar)\n");
                    break;

                case 6:
                    printf("Saliendo del menú materias...\n");
                    break;

                default:
                    printf("Opción incorrecta.\n");
                }
            }
            break;
        }

        // ---------------------- SALIR ----------------------
        case 3:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opción incorrecta!\n");
        }
    }

    return 0;
}
