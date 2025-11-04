## Malloc (Memory Allocation)
---
`malloc` se usa para asignar un bloque de memoria del tamaño especificado en bytes y devuelve un puntero al inicio de ese bloque.

### ¿Para qué sirve?
Cuando necesitas una cantidad de memoria que no conoces hasta que el programa se está ejecutando (por ejemplo, para almacenar una lista cuyo tamaño el usuario introduce).

#### Sintaxis
```c
void *malloc(size_t size);
```
#### Ejemplo
Para asignar memoria para 50 enteros (int):
```c
int *ptr_array;
int num_elements = 50;

// sizeof(int) devuelve el tamaño de un entero en bytes (típicamente 4)
ptr_array = (int *)malloc(num_elements * sizeof(int));

if (ptr_array == NULL) {
    // Manejar el error de asignación de memoria
    printf("Error al asignar memoria.\n");
}
```
* **Devuelve**: Un puntero genérico (void *) al bloque asignado. Debes hacer un cast (conversión de tipo) al tipo de puntero que necesitas (ej: (int *)).
* **Fallo**: Si no hay suficiente memoria disponible, devuelve NULL.