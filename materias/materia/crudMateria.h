#include "structMateria.h"

Materia* crearMateria(const char *nombreDeMateria);
void modificarMateria(Materia *materia, char *nombre);
void eliminarAlumnoDeMateria(char *nombre, char *apellido, Materia *materia);
void anotarseEnUnaMateria(Estudiante *estudiante, Materia *materia);
Estudiante *buscarEstudiantePorNombre(Estudiante *estudiante, Materia *materia);
void buscarEstudiantesPorEdad(int edad, Materia *materia);
