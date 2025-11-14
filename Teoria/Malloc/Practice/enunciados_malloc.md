## Problemas de malloc (Asignación)

Estos ejercicios se centran en el uso correcto de malloc y, fundamentalmente, en la liberación de memoria con free.

### 1. Fácil: Array de enteros variable

* Escribe un programa que solicite por consola al usuario la cantidad N de números enteros que desea almacenar. 
* Utiliza malloc para asignar dinámicamente el espacio exacto para este array de N enteros. 
* Luego, utiliza un bucle para solicitar al usuario que ingrese cada uno de esos N valores y, finalmente, imprime todos los valores almacenados. 
* Asegúrate de manejar el posible fallo de asignación (NULL) y de liberar la memoria antes de terminar.

### 2. Intermedio: Estructura de datos dinámica

Define una estructura llamada Libro con dos campos:

* `titulo` (puntero a `char`).
* `num_paginas` (entero).

Escribe una función que tome el título y el número de páginas como argumentos. Dentro de esta función, utiliza dos llamadas a malloc: una para asignar memoria para la estructura Libro misma, y otra para asignar memoria para el campo titulo (suficiente para almacenar la cadena del título). Asigna los valores a los campos y, fuera de la función principal, no olvides liberar ambas porciones de memoria.

### 3. Intermedio: Array de punteros

Crea un programa que use malloc para asignar un array de 5 punteros a enteros (int *). A continuación, dentro de un bucle, usa otra llamada a malloc para hacer que cada uno de esos 5 punteros apunte a un nuevo entero individual. Asigna el valor del índice del bucle a cada uno de esos enteros. Imprime los valores y, crucialmente, diseña la lógica para liberar correctamente las 5 porciones de memoria individuales y luego el array de punteros principal.