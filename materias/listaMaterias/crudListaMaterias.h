#include "materias/materia/structMateria.h"
#include "materias/listaMaterias/structListaMaterias.h"
ListaMaterias *nuevaListaMaterias();
void agregarNuevaMateria(Materia *materia, ListaMaterias *lista);
Materia *buscarMateria(char nombreDeMateria, ListaMaterias *lista);
Materia *ModificarMateriaLista(char nuevoNombre, Materia *materia);
void eliminarMateria(char nombreDeMateria, ListaMaterias *lista);
int cantidadMaterias(ListaMaterias *lista);
Materia *obtenerListaMaterias(ListaMaterias *lista, int *cantidad);
void cargarDatosDePruebaMateria(ListaMaterias *lista);
void mostrarMateriasPaginado(Materia *array, int cantidad);