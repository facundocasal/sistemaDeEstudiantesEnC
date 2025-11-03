#include "materias/listaMateriasAprobadas/structListaMateriasAprobadas.h"

ListaMateriasAprobadas *nuevaListaMateriasAprobadas();
void agregarNuevaMateriaAprobada(char nombre, int nota, ListaMateriasAprobadas *lista);
NodoMateriaAprobada *obtenerListaMaterias(ListaMateriasAprobadas *lista, int *cantidad);
NodoMateriaAprobada *buscarMateriaAprobada(char nombreMateria, ListaMateriasAprobadas *lista);
void eliminarMateriaAprobada(char nombreMateria, ListaMateriasAprobadas *lista);
bool modificarNotaDeMateriaAprobada ( int nota , char nombreMateria  , ListaMateriasAprobadas *lista);
int obternerCantidadMateriasArpobadas ( ListaMateriasAprobadas *lista);
int obternerPromedio (ListaMateriasAprobadas *lista);
void mostrarMateriasAprobadasPaginado(NodoMateriaAprobada *array, int cantidad);
void cargarDatosDePruebaMateriasAprobadas(ListaMateriasAprobadas *lista);