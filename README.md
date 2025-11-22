# sistemaDeEstudiantesEnC

Consigna del TP final:


Desarrollar un sistema de estudiantes en C. Debe permitir:


CRUD: Create Read Update Delete List

ABM: Alta Baja Modificación


-Dar de alta, modificar, eliminar y listar estudiantes

-Buscar estudiantes por nombre

-Buscar estudiantes por rango de edad


Además cada estudiante puede anotarse en N materias.

-Dar de alta, modificar, eliminar y listar materias

-Anotarse en una materia

-Rendir una materia


El sistema debe poder soportar un gran listado de estudiantes y materias. Utilizar estructuras de datos para almacenar los listados. Decidir si se utiliza ordenamiento de los datos.


El diseño del sistema y los modelos son libres. Utilizar la creatividad para que el manejo del sistema sea lo más práctico posible.


La única limitación respecto al uso de librerías es que la estructura de datos que usen sea de desarrollo propio.


Si los requerimientos planteados son cumplidos, el ejercicio está aprobado (nota 4). Puede pasar que en situaciones en la que la cantidad de datos sea muy grande, el sistema sea inmanejable. En ese caso, detallar las limitaciones de la solución propuesta (si las limitaciones son reconocidas no se considera desaprobado el punto). Agregar en el README del repositorio.


Hasta este punto, todos los estudiantes deben presentar este trabajo para poder aprobar la materia.


Ideas no-obligatorias de implementar pero que suman puntos: 

utilizar paginado

poder elegir el estudiante/materia de un listado reducido

generar estudiantes de prueba y materias aleatorias de forma masiva

estadísticas de los estudiantes y materias, etc.

árboles de correlatividad de materias

qué pasa si una materia anterior está desaprobada? Puede anotarse? 

cálculo de promedios. 

archivo de configuración general donde se especifican las variables del sistema.

mejoras en la interfaz de usuario

tests unitarios

Persistencia en CSV

(cualquier otra feature que quieran agregar)


En el repositorio hacer un README con los integrantes, las consignas implementadas y los puntos extras que hayan desarrollado.


El trabajo se puede hacer de a cinco, cuatro o tres personas.

Si el equipo tiene 4 personas deben hacer obligatoriamente un punto extra más para la nota 4.

Si el equipo tiene 5 personas deben hacer obligatoriamente dos puntos extra más para la nota 4.


Alternativa 2, TP alternativo: individualmente hacer una aplicación de funcionalidad libre desarrollada en C. La idea debe ser enviada y posteriormente validada por el docente. Al igual que el trabajo principal, se deben justificar las funcionalidades (features) para calcular la nota. Quien opte por esta alternativa debe realizar la primera parte del TP general y la app libre individualmente.


Grabar un video de máximo 10 minutos (puede ser menos) mostrando el funcionamiento del sistema y los puntos implementados. En esta oportunidad no es necesario enfocarse tanto en el código, ya que se puede ver en el repositorio. Concéntrese en presentar el proyecto funcionando. Quienes presenten dos trabajos (alternativa 2) deberán presentar también dos videos.

# 📘 Sistema de Gestión de Estudiantes y Materias en C

## 👥 Integrantes

- **Rodrigo Bitti**
- **Facundo Casal**
- **Nazareno Pereyra**

---

## 📋 Descripción del Proyecto

Este proyecto implementa un **sistema de gestión de estudiantes y materias (CRUD/ABM)** desarrollado íntegramente en **C**, utilizando estructuras de datos implementadas manualmente (sin uso de librerías externas).

El sistema permite manejar:
- Estudiantes  
- Materias  
- Materias aprobadas  
- Inscripciones  
- Búsquedas  
- Filtros  
- Listados con paginado  

---

## ✔️ Funcionalidades Implementadas

### 🧑‍🎓 Estudiantes
- Alta, baja, modificación y listado
- Búsqueda por nombre y apellido
- Búsqueda por rango de edad
- Inscripción del estudiante a materias
- Listado paginado
- Datos de prueba

### 📚 Materias
- Alta, baja y modificación
- Búsqueda por nombre
- Listado paginado
- Inscripción de estudiantes
- Eliminación de alumnos de una materia
- Datos de prueba

### 🏆 Materias Aprobadas
- Alta con nota
- Baja
- Modificación de la nota
- Cálculo de promedio de notas
- Listado paginado
- Datos de prueba

---

## 🧱 Estructuras de Datos Implementadas

Todas las estructuras fueron desarrolladas manualmente.

### Listas
- `ListaEstudiantes`
- `ListaMaterias`
- `ListaMateriasAprobadas`

Cada una utiliza **listas enlazadas simples** con sus nodos correspondientes:

- `NodoEstudiante`
- `NodoMateria`
- `NodoMateriaAprobada`

Se incluyen funciones para convertir las listas en arrays dinámicos cuando se requiere paginado u operaciones adicionales.

---

## 🔧 Headers y Funcionalidades

### 🧑‍🎓 Estudiante
```c
Estudiante* crearEstudiante(char *nombre, char *apellido, int edad);
void modificarNombreEstudiante(Estudiante*, char*);
void modificarApellidoEstudiante(Estudiante*, char*);
void modificarEdad(Estudiante*, int);
void mostrarDatos(Estudiante*);
void inscribirEstudianteAMateria(Estudiante*, Materia*);
```
## 🔧 Headers y Funcionalidades

### 🧑‍🎓 ListaEstudiantes
```c
ListaEstudiantes* nuevaListaEstudiantes();
void agregarEstudiante(Estudiante*, ListaEstudiantes*);
NodoEstudiante* buscarEstudiante(char *nombre, char *apellido, ListaEstudiantes*);
void eliminarEstudiante(char*, char*, ListaEstudiantes*);
int cantidadDeAlumnos(ListaEstudiantes*);
void modificarEstudiante(char*, char*, int, Estudiante*);
Estudiante* obtenerListaEstudiantes(ListaEstudiantes*, int*);
Estudiante* obtenerListaEstudiantesPorRangoDeEdad(int comienzo, int fin, ListaEstudiantes*, int*);
void mostrarEstudiantesPaginado(Estudiante*, int);
void cargarDatosDePruebaEstudiantes(ListaEstudiantes*);
```

### 📘 Materia
```c
Materia* crearMateria(const char *nombre);
void modificarMateria(Materia*, char*);
void eliminarAlumnoDeMateria(char *nombre, char *apellido, Materia*);
void anotarseEnUnaMateria(Estudiante*, Materia*);
Estudiante* buscarEstudiantePorNombre(Estudiante*, Materia*);
void buscarEstudiantesPorEdad(int edad, Materia*);
```

### 📚 ListaMaterias
```c
ListaMaterias* nuevaListaMaterias();
void agregarNuevaMateria(Materia*, ListaMaterias*);
NodoMateria* buscarMateria(char*, ListaMaterias*);
Materia* ModificarMateriaLista(char *nuevoNombre, Materia*);
void eliminarMateria(char*, ListaMaterias*);
int cantidadMaterias(ListaMaterias*);
Materia* obtenerListaMaterias(ListaMaterias*, int*);
void cargarDatosDePruebaMateria(ListaMaterias*);
void mostrarMateriasPaginado(Materia*, int);
```

### 🏆 ListaMateriasAprobadas
```c
ListaMateriasAprobadas* nuevaListaMateriasAprobadas();
void agregarNuevaMateriaAprobada(const char *nombre, int nota, ListaMateriasAprobadas*);
NodoMateriaAprobada* obtenerListaMateriasAprobadas(ListaMateriasAprobadas*, int*);
NodoMateriaAprobada* buscarMateriaAprobada(char*, ListaMateriasAprobadas*);
void eliminarMateriaAprobada(char*, ListaMateriasAprobadas*);
bool modificarNotaDeMateriaAprobada(int nota, char *nombreMateria, ListaMateriasAprobadas*);
int obternerCantidadMateriasArpobadas(ListaMateriasAprobadas*);
float obternerPromedio(ListaMateriasAprobadas*);
void mostrarMateriasAprobadasPaginado(NodoMateriaAprobada*, int);
void cargarDatosDePruebaMateriasAprobadas(ListaMateriasAprobadas*);

```
## 🧠 Decisiones de Diseño

- Se utilizan **listas enlazadas** para permitir alta y baja sin realocación.
- Para paginado y ordenamientos se transforma la lista en un **array dinámico**.
- Separación modular por entidades (**Estudiante**, **Materia**, **Listas**).
- Se permite que cada estudiante pueda inscribirse en **N materias**.
- Diseño escalable dentro de los límites del **lenguaje C estándar**.

---

## ⚠️ Limitaciones del Sistema

Según la consigna, se reconocen las siguientes limitaciones:

- Las búsquedas son **lineales (O(n))**, debido al uso de listas enlazadas.
- No se aplica **ordenamiento automático** de los datos (aunque podría añadirse).
- No se implementa **persistencia**, por lo que los datos se pierden al cerrar el programa.
- Con miles de elementos en memoria, el **rendimiento puede degradarse**.
- No hay garantía de unicidad en nombres duplicados (no existen claves únicas formales).

Estas limitaciones están documentadas y cumplen con las exigencias del enunciado.

---

## 🚀 Puntos Extra Implementados

- **Paginado** de estudiantes, materias y materias aprobadas.
- **Cálculo automático del promedio** de materias aprobadas.
- **Filtrado por rango de edad**.
- **Datos de prueba** para facilitar el testing y validación.
- **Conversión de listas enlazadas a arrays dinámicos**.
- Diseño **modular y escalable**.
- * Test Unitarios *

---

## 💻 Compilación y Ejecución

```bash
gcc -o sistema main.c estudiantes/
```
