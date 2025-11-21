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
        printf("2. Menu Docente\n");
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

            while (OpcionDeMenuAlumno != 8)
            {
                printf("---------------------\n");
                printf("Menu Estudiante\n");
                printf("1. Crear Estudiante\n");
                printf("2. Modificar Nombre\n");
                printf("3. Modificar Apellido\n");
                printf("4. Modificar Edad\n");
                printf("5. Mostrar Datos\n");
                printf("6. Gestionar Materias\n");
                printf("7. Mostrar Promedios\n");
                printf("8. Salir\n");
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

                    int opcionGestionMateriasDeEstudiantes = 0;
                    while (opcionGestionMateriasDeEstudiantes != 4)
                    {
                        printf("---------------------\n");
                        printf("Gestion de Materias\n");
                        printf("---------------------\n");
                        printf("Elegi la opcion:\n");
                        printf("1.Inscribirse a una materia existente\n");
                        printf("2.Buscar materia inscripta\n");
                        printf("3.Mostrar sus materias inscriptas\n");
                        printf("4.Salir\n")

                            scanf("%d", &opcionGestionMateriasDeEstudiantes);
                        while (getchar() != '\n')
                            ;

                        switch (opcionGestionMateriasDeEstudiantes)
                        {
                        case 1:
                        {

                            char nombre[50], apellido[50], nombreMateria[50];
                            printf("Inscribirse a una materia existente\n");

                            printf("Ingrese nombre estudiante: \n");
                            fgets(nombre, sizeof(nombre), stdin);
                            nombre[strcspn(nombre, "\n")] = 0;

                            printf("Ingrese apellido: \n");
                            fgets(apellido, sizeof(apellido), stdin);
                            apellido[strcspn(apellido, "\n")] = 0;

                            NodoEstudiante *nodo = buscarEstudiante(nombre, apellido, listaEstudiantes);

                            printf("Materias:\n");
                            int cantidadMaterias = 0;
                            Materia *materiasArray = obtenerListaMaterias(listaMaterias, &cantidadMaterias);
                            for (int i = 0; i < cantidadMaterias; i++)
                            {
                                printf("- %s (ID: %d)\n", materiasArray[i].nombre);
                                // Ajustalo según los campos de tu struct Materia
                            }
                            free(materiasArray);
                            printf("Ingrese la materia a anotarse:\n ");
                            fgets(nombreMateria, sizeof(nombreMateria), stdin);
                            nombreMateria[strcspn(nombreMateria, "\n")] = 0;

                            NodoMateria *mat = buscarMateria(nombreMateria, listaMaterias);
                            inscribirEstudianteAMateria(nodo->estudiante, mat->materia);
                            printf("Inscripcion concretada");
                            break;
                        }
                        case 2:
                        {
                            printf("Buscar materia inscripta\n");
                            char nombre[50], apellido[50], nombreMateria[50];

                            printf("Ingrese nombre estudiante:\n ");
                            fgets(nombre, sizeof(nombre), stdin);
                            nombre[strcspn(nombre, "\n")] = 0;

                            printf("Ingrese apellido: \n");
                            fgets(apellido, sizeof(apellido), stdin);
                            apellido[strcspn(apellido, "\n")] = 0;

                            printf("Ingrese materia: \n");
                            fgets(nombreMateria, sizeof(nombreMateria), stdin);
                            nombreMateria[strcspn(nombreMateria, "\n")] = 0;

                            NodoEstudiante *nodoEstudiante = buscarEstudiante(nombre, apellido, listaEstudiantes);
                            buscarMateria(nombreMateria, nodoEstudiante->estudiante->materiasInscriptas);
                            break;
                        }

                        case 3:
                        {
                            printf("Mostrar materias inscriptas\n");

                            printf("Ingrese nombre estudiante:\n ");
                            fgets(nombre, sizeof(nombre), stdin);
                            nombre[strcspn(nombre, "\n")] = 0;

                            printf("Ingrese apellido: \n");
                            fgets(apellido, sizeof(apellido), stdin);
                            apellido[strcspn(apellido, "\n")] = 0;

                            NodoEstudiante *NodoEstudiante = buscarEstudiante(nombre, apellido, listaEstudiantes);
                            mostrarMateriasInscriptas(NodoEstudiante->estudiante);
                            break;
                        }

                        case 4:
                        {
                            break;
                        }

                        default:
                            printf("Opcion incorrecta.\n");
                            break;
                        }
                    }

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
                    anotarseEnUnaMateria(nodo->estudiante, mat->materia);
                    printf("Inscripción correcta.\n");
                    break;
                }

                case 7:
                    printf("Mostrar Promedio\n");

                    break;

                case 8:
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
                printf("Menu Docente\n");
                printf("---------------------\n");
                printf("1.Gestion de Materias");
                printf("2.Gestion de Estudiantes");

                printf("6. Salir\n");
                printf("Elegir opcion: ");

                scanf("%d", &OpcionDeMenuMateria);
                while (getchar() != '\n')
                    ;

                switch (OpcionDeMenuMateria)
                {
                case 1:
                {
                    int opcionDeMenuDocenteGestionEstudiantes = 0;

                    while (opcionDeMenuDocenteGestionEstudiantes)
                    {
                        printf("Gestion de Materias\n");
                        printf("1.Crear Materia");
                        printf("2. Modificar Materia\n");
                        printf("3. Eliminar Alumno De Materia\n");
                        printf("Salir");
                        scanf("%d", &opcionDeMenuDocenteGestionEstudiantes);
                        while (getchar() != '\n')
                            ;

                        switch (opcionDeMenuDocenteGestionEstudiantes)
                        {
                        case 1:
                        {
                            char nombreMateria[50];
                            printf("Nombre de la materia: \n");
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

                            printf("Nombre actual: \n");
                            fgets(nombreMateria, sizeof(nombreMateria), stdin);
                            nombreMateria[strcspn(nombreMateria, "\n")] = 0;

                            NodoMateria *mat = buscarMateria(nombreMateria, listaMaterias);

                            printf("Nuevo nombre: \n");
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
                        default:
                        printf("Opcion incorrecta");
                            break;
                        }
                    }

                case 2:
                {
                    int opcionDeMenuDocenteGestionMaterias = 0;

                    while (opcionDeMenuDocenteGestionMaterias)
                    {
                        printf("Gestion de Estudiantes\n");
                        printf("1. Buscar Estudiante Por Nombre\n");
                        printf("2. Buscar Estudiantes Por Edad\n");
                        scanf("%d", &opcionDeMenuDocenteGestionEstudiantes);
                        while (getchar() != '\n')
                            ;

                        switch (opcionDeMenuDocenteGestionMaterias)
                        {
                        case 1:
                        {
                            printf("Buscar Estudiante Por Nombre\n");
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
                            printf("PRUEBA TAMAÑO: %d\n", mat->materia->estudiantesInscriptos->tamanio);
                            // buscarEstudiantePorNombre(nodoEstudiante->estudiante, mat->materia);
                            break;
                        }

                        case 2:
                        {
                            printf("Buscar Estudiantes Por Edad\n");

                            char nombre[50];
                            char apellido[50];

                            printf("Ingresa Nombre estudiante: ");
                            fgets(nombre, sizeof(nombre), stdin);
                            nombre[strcspn(nombre, "\n")] = 0;

                            printf("Ingresa Apellido estudiante: ");
                            fgets(apellido, sizeof(apellido), stdin);
                            apellido[strcspn(apellido, "\n")] = 0;

                            NodoEstudiante *nodoEstudiante = buscarEstudiante(nombre, apellido, listaEstudiantes);
                            obtenerPromedio(nodoEstudiante->estudiante->materiasAprobadas);

                            break;
                        }

                        default:
                            printf("Opcion incorrecta");
                            break;
                        }
                    }
                }
                }


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
