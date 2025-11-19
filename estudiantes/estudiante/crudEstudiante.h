#include "structEstudiante.h"
#include "../../materias/materia/structMateria.h"

Estudiante* crearEstudiante(char *nombreEstudiante ,char *apellidoEstudiante , int edadEstudiante ) ;
void modificarNombreEstudiante(Estudiante *estudiante , char *nombre );
void modificarApellidoEstudiante(Estudiante *estudiante , char *apellido );
void modificarEdad (Estudiante *estudiante , int edad);
void mostrarDatos (Estudiante *estudiante);
void inscribirEstudianteAMateria(Estudiante *estudiante , Materia *materia );
//void agregarMateriaAprobada(Estudiante *estudiante , Materia *materia , char aprobo );