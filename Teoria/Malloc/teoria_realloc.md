## realloc (Re-allocation)
`realloc` se usa para cambiar el tamaño de un bloque de memoria que ya ha sido asignado previamente por `malloc`, `calloc` (similar a malloc pero inicializa la memoria a cero), o `realloc` mismo.

### ¿Para qué sirve?
* Expandir o reducir el tamaño de un bloque de memoria sin perder los datos que ya contiene.
* Es muy útil cuando una estructura de datos (como una matriz o array) necesita crecer o encoger dinámicamente.

### Sintaxis
```c
void *realloc(void *ptr, size_t new_size);
```
#### Ejemplo

Suponiendo que ya has asignado memoria con ptr_array, ahora quieres aumentar su tamaño para 100 enteros:
```c
// ... (código anterior donde ptr_array ya tiene memoria para 50 enteros)
int new_num_elements = 100;
int *temp_ptr;

temp_ptr = (int *)realloc(ptr_array, new_num_elements * sizeof(int));

if (temp_ptr == NULL) {
    // Si falla, el bloque original (ptr_array) NO se libera,
    // y aún puedes usar los 50 elementos originales.
    printf("Error al reasignar memoria, el bloque original sigue intacto.\n");
} else {
    // Si tiene éxito, actualizamos el puntero para usar el nuevo bloque
    ptr_array = temp_ptr;
}
```
#### Comportamiento:
* Si el nuevo tamaño es mayor, `realloc` intenta expandir el bloque actual. Si no puede, asigna un nuevo bloque más grande, **copia los datos antiguos** al nuevo bloque y libera el antiguo.
* Si el nuevo tamaño es **menor**, reduce el tamaño del bloque.
* Si el nuevo tamaño es **cero**, es equivalente a llamar a `free(ptr)`.