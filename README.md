PROYECTO-ARBOL-GENEALOGICO-EDD2025C

Descripción General del Proyecto

Este proyecto es una aplicación en C++ que simula la estructura de un árbol genealógico de una casa real y gestiona la línea de sucesión al trono. El objetivo principal es cargar la información de los nobles desde un archivo CSV, construir el árbol, mostrar su estructura y aplicar las reglas básicas de sucesión para determinar quién debe ocupar el trono.

El funcionamiento del sistema se basa en un Árbol Dinámico (Binary Tree), donde cada nodo representa a un miembro de la familia real. El programa analiza relaciones padre–hijo, estados (vivo/muerto), antecedentes como “fue rey”, y genera automáticamente la línea de sucesión actual.

La información de los nobles se carga y se mantiene mediante un archivo CSV ubicado en la carpeta bin.

Estructura de la Aplicación

El núcleo del sistema está compuesto por la clase Tree, la clase CSVHandler, la clase Succession, y el struct Noble.

Archivos principales del proyecto

realeza.h
Contiene:

La definición del struct Noble

La clase Tree

La clase CSVHandler

La clase Succession

realeza.cpp
Implementa:

La lógica del árbol genealógico

La carga y guardado del archivo CSV

La asignación automática de rey

La generación de la línea de sucesión

Main.cpp
Maneja:

El flujo general del programa

El menú interactivo

La ejecución de las funcionalidades principales

bin/reino.csv
Archivo que almacena toda la información de la dinastía:

ID

Nombre y apellido

Género

Edad

ID del padre

Estado (vivo/muerto)

Marcas de si fue rey o es rey actualmente

Funcionalidades Implementadas

✔ Cargar la información de la familia real desde un archivo CSV

✔ Construir el árbol genealógico dinámicamente

✔ Imprimir el árbol en pantalla

✔ Generar la línea de sucesión actual según reglas internas

✔ Asignar automáticamente un nuevo rey al morir el anterior

✔ Menú interactivo para realizar todas las acciones desde consola

Reglas de Sucesión (Simplificadas)

Solo heredan descendientes directos organizados por orden de nacimiento.

Las mujeres heredan únicamente si no existen varones en su misma rama directa.

Los miembros fallecidos no participan en la línea.

Si una rama se extingue, se pasa a la siguiente.

El rey actual es siempre el miembro vivo más apto según estas reglas.

Estructura de Carpetas

KING/
│
├── bin/
│   ├── programa.exe
│   └── reino.csv
│
└── src/
    ├── Main.cpp
    ├── realeza.cpp
    └── realeza.h

Cómo Compilar el Proyecto

Desde la carpeta raíz del proyecto (donde está src):

g++ src/Main.cpp src/realeza.cpp -o bin/programa.exe

Cómo Ejecutarlo

bin\programa.exe

Autor: Oscar Torres 
