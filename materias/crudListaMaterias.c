#include <structListaMaterias.h>
#include <stdlib.h>

ListaMaterias *NuevaListaMaterias(){
    ListaMaterias *nuevaLista = malloc(sizeof(ListaMaterias));
    nuevaLista -> head = NULL;
    nuevaLista -> tamanio = 0;
    return nuevaLista;
}

void AgregarNuevaMateria(Materia *materia){

}