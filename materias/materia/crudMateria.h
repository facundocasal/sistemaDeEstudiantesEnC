#include "structMateria.h"

Materia* crearMateria(char *nombreDeMateria);
void modificarMateria(Materia *materia, char *nombre);
void eliminarAlumnoDeMateria(char nombre, char apellido, Materia *materia);
void anotarseEnUnaMateria(Estudiante *estudiante, Materia *materia);
void buscarEstudiantePorNombre(Estudiante *estudiante, Materia *materia);
void buscarEstudiantesPorEdad(int edad, Materia *materia);
