#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// struct 
#include "estudiantes/estudiante/structEstudiante.h"
#include "estudiantes/Lista/structListaEstudiantes.h"
// crud 
#include "estudiantes/estudiante/crudEstudiante.h"
#include "estudiantes/Lista/crudListaEstudiantes.h"
#include "estudiantes/estudiante/crudEstudiante.h"
#include "materias/listaMaterias/crudListaMaterias.h"
// mock 
#include "estudiantes/Lista/mockListaEstudiantes/mockEstudiantes.h"




int main() {
    int opcion = 0;
    char buffer[100];
    ListaEstudiantes* listaEstudiantes = nuevaListaEstudiantes();
    ListaMaterias* listaMaterias = nuevaListaMaterias();

    while (opcion != 3) {
        printf("---------------------\n");
        printf("MENU\n");
        printf("Elegir Opcion\n");
        printf("1. Menu Estudiante\n");
        printf("2. Menu Materias\n");
        printf("3. Salir\n");
        printf("---------------------\n");
        printf("Opcion: ");

      if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &opcion) != 1) {
                printf("Debe ingresar un número!\n");
                opcion = 0;
                continue;
            }
        }    

        switch (opcion) {
            case 1:
            int OpcionDeMenuAlumno = 0;
            while (OpcionDeMenuAlumno != 7)
            {
                    printf("---------------------\n");
                    printf("Menu Alumno\n");
                    printf("---------------------\n");
                    printf("1. Crear Estudiante\n");
                    printf("2. Modificar Nombre\n");
                    printf("3. Modificar Apellido\n");
                    printf("4. Modificar Edad\n");
                    printf("5. Mostrar Datos\n");
                    printf("6. Inscribir a Materia\n");
                    printf("7. Salir\n");

                    printf("Elegir opcion: \n");
                    scanf("%d", &OpcionDeMenuAlumno);
                    while(getchar() != '\n'); // limpiar buffer

                switch (OpcionDeMenuAlumno)
                {
                case 1:
                    printf("crearEstudiante\n");
                    char nombre[50];
                    char apellido[50];
                    int edad;

                    printf("Nombre del estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;
                    
                    printf("Apellido del estudiante: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    printf("Edad del estudiante: ");
                    scanf("%d", &edad);
                    while(getchar() != '\n');

                    Estudiante* estudiante = crearEstudiante(nombre, apellido, edad);

                    if(estudiante == NULL){
                        printf("Datos inválidos. El estudiante no se pudo crear.\n");
                    } else {
                        printf("Estudiante creado correctamente:\n");
                        printf("Nombre: %s\n", estudiante->nombre);
                        printf("Apellido: %s\n", estudiante->apellido);
                        printf("Edad: %d\n", estudiante->edad);
                        agregarEstudiante(estudiante, listaEstudiantes);
                    }
                    break;
                case 2: {
                    printf("Modificar nombre de estudiante\n");
                    
                    char nombre[50];
                    char apellido[50];

                    printf("Ingrese el nombre del estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;
                    
                    printf("Ingrese el apellido del estudiante: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                   NodoEstudiante* nodoSeleccionado = buscarEstudiante(nombre, apellido, listaEstudiantes);
                    if (nodoSeleccionado == NULL) {
                        
                        printf("No se encontró el estudiante.\n");
                    } else 
                    {
                        char nuevoNombre[50];
                        printf("Ingrese el nuevo nombre: ");
                        fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
                        nuevoNombre[strcspn(nuevoNombre, "\n")] = 0; // quitar salto de línea

                        modificarNombreEstudiante(nodoSeleccionado->estudiante, nuevoNombre);
                        printf("Nombre modificado correctamente: %s\n",nodoSeleccionado->estudiante->nombre);
                    }
                    break;
                    }
                case 3:{
                    printf("Modificar apellido del estudiante\n");
                    char nombre[50];
                    char apellido[50];

                    printf("Ingrese el nombre del estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;
                    
                    printf("Ingrese el apellido del estudiante: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                     NodoEstudiante* nodoSeleccionado = buscarEstudiante(nombre, apellido, listaEstudiantes);
                    if (nodoSeleccionado == NULL) {
                        
                        printf("No se encontró el estudiante.\n");
                    } else 
                    {
                        char nuevoApellido[50];
                        printf("Ingrese el nuevo Apellido: ");
                        fgets(nuevoApellido, sizeof(nuevoApellido), stdin);
                        nuevoApellido[strcspn(nuevoApellido, "\n")] = 0; // quitar salto de línea

                        modificarApellidoEstudiante(nodoSeleccionado->estudiante, nuevoApellido);
                        printf("Apellido modificado correctamente: %s\n",nodoSeleccionado->estudiante->apellido);
                    }
                    printf("Apellido: %s", estudiante->apellido);
                    break;
                }
                case 4:{
                    printf("Modificar edad del estudiante\n");
                    char nombre[50];
                    char apellido[50];

                    printf("Ingrese el nombre del estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;
                    
                    printf("Ingrese el apellido del estudiante: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                     NodoEstudiante* nodoSeleccionado = buscarEstudiante(nombre, apellido, listaEstudiantes);
                    if (nodoSeleccionado == NULL) {
                        
                        printf("No se encontró el estudiante.\n");
                    } else 
                    {
                        int nuevaEdad;
                        printf("Ingrese la nueva edad: ");
                        scanf("%d", &nuevaEdad);
                        while(getchar() != '\n');

                        modificarEdad(nodoSeleccionado->estudiante, nuevaEdad);
                        printf("Edad modificada correctamente: %d\n",nodoSeleccionado->estudiante->edad);
                    }
                    break;
                }
                case 5:{
                    printf("Mostrar Datos\n");
                    char nombre[50];
                    char apellido[50];

                    printf("Ingrese el nombre del estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Ingrese el apellido del estudiante: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    NodoEstudiante* nodoSeleccionado = buscarEstudiante(nombre, apellido, listaEstudiantes);

                    if (nodoSeleccionado == NULL)
                    {
                        printf("No se encontró el estudiante.\n");
                    } else {
                        mostrarDatos(nodoSeleccionado->estudiante);
                    }
                    break;
                }
                    
                case 6:{
                    printf("Inscribir estudiante a materia\n");
                    char nombre[50];
                    char apellido[50];
                    char nombreMateria[50];

                    printf("Ingrese el nombre del estudiante: ");
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = 0;

                    printf("Ingrese el apellido del estudiante: ");
                    fgets(apellido, sizeof(apellido), stdin);
                    apellido[strcspn(apellido, "\n")] = 0;

                    NodoEstudiante* nodoSeleccionado = buscarEstudiante(nombre, apellido, listaEstudiantes);

                    if (nodoSeleccionado == NULL) {
                        printf("No se encontró el estudiante.\n");
                        break;
                    }

                    printf("Ingrese el nombre de la materia: ");
                    fgets(nombreMateria, sizeof(nombreMateria), stdin);
                    nombreMateria[strcspn(nombreMateria, "\n")] = 0;

                    NodoMateria* nodoMateria = buscarMateria(nombreMateria, listaMaterias);
                    if (nodoMateria == NULL) {
                        printf("No se encontró la materia.\n");
                        break;
                    }

                    inscribirEstudianteAMateria(nodoSeleccionado->estudiante, nodoMateria->materia);
                    printf("Estudiante %s %s inscripto en la materia %s correctamente.\n",
                        nodoSeleccionado->estudiante->nombre,
                        nodoSeleccionado->estudiante->apellido,
                        nodoMateria->materia->nombre
                    );


                    break;
                }
                  
                case 7:
                printf("Saliendo del Menu de Alumnos.\n");
                break;

                default:
                printf("Opcion incorrecta\n");
                
                }
            }
             
            break;
            case 2:
            printf("---------------------\n");
            printf("Menu Materias\n");
            printf("---------------------\n");
            
            break;

            case 3:
            printf("Saliendo...\n");
            break;

            default:
            printf("Opcion Incorrecta\n");
        }
    }

    return 0;
}
