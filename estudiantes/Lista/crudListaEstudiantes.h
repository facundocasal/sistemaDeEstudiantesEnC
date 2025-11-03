#include "structListaEstudiantes.h"

ListaEstudiantes *nuevaListaEstudiantes();
void agregarEstudiante(Estudiante *estudiante, ListaEstudiantes *listaEstudiantes);
NodoEstudiante *buscarEstudiante(char nombre, char apellido, ListaEstudiantes *listaEstudiantes);
void eliminarEstudiante(char nombre, char apellido, ListaEstudiantes *listaEstudiantes);
int cantidadDeAlumnos (ListaEstudiantes *ListaEstudiantes);
void modificarEstudiante (char nombre , char apellido , int edad  , Estudiante *estudiante);
Estudiante *obtenerListaEstudiantes(ListaEstudiantes *lista, int *cantidad);
Estudiante *obtenerListaEstudiantesPorRangoDeEdad(int comienzo , int fin , ListaEstudiantes *lista,  int *cantidad);
void mostrarEstudiantesPaginado(Estudiante *array, int cantidad);