#include "structListaMateriasAprobadas.h"

ListaMateriasAprobadas *nuevaListaMateriasAprobadas();
void agregarNuevaMateriaAprobada(const char *nombre, int nota, ListaMateriasAprobadas *lista);
NodoMateriaAprobada *obtenerListaMateriasAprobadas(ListaMateriasAprobadas *lista, int *cantidad);
NodoMateriaAprobada *buscarMateriaAprobada(char *nombreMateria, ListaMateriasAprobadas *lista);
void eliminarMateriaAprobada(char *nombreMateria, ListaMateriasAprobadas *lista);
bool modificarNotaDeMateriaAprobada(int nota, char *nombreMateria, ListaMateriasAprobadas *lista);
int obternerCantidadMateriasArpobadas ( ListaMateriasAprobadas *lista);
float obternerPromedio (ListaMateriasAprobadas *lista);
void mostrarMateriasAprobadasPaginado(NodoMateriaAprobada *array, int cantidad);
void cargarDatosDePruebaMateriasAprobadas(ListaMateriasAprobadas *lista);