## 1. Teoría: ¿Qué es una variable estática en C?
---
En C, la palabra clave `static` sirve para mantener el valor de una variable entre llamadas a funciones, o para limitar su visibilidad dentro de un archivo o función.
Hay **dos contextos principales**:

### A. Variable estática dentro de una función
* Se declara con: `static tipo nombre;`
* Se inicializa solo una vez.
* Mantiene su valor entre ejecuciones de la función.
Es como si la variable “recordara” lo que tenía guardado la última vez.

```c
#include <stdio.h>

void contador() {
    static int num = 0;  // Solo se inicializa una vez
    num++;
    printf("El contador vale: %d\n", num);
}

int main() {
    contador();
    contador();
    contador();
    return 0;
}
```
#### Salida:
```
El contador vale: 1
El contador vale: 2
El contador vale: 3
```
Si `num` no fuera estática (solo `int num = 0;`), el resultado sería siempre 1, porque la variable se reinicia cada vez que se llama la función.

### B. Variable o función estática a nivel de archivo
* Si declaras una variable o función **fuera de cualquier función** con `static`, **solo será visible dentro del mismo archivo (.c)**.
* Sirve para **encapsular** datos o funciones internas que no deberían usarse desde otros archivos (modularidad).

```c
// archivo1.c
static int secreto = 42;  // Solo visible aquí

void mostrar() {
    printf("El secreto es %d\n", secreto);
}
```
En otro archivo `(archivo2.c)`, aunque intentes hacer:
```c
extern int secreto;  // ❌ Error
```
No funcionará, porque `secreto` es solo visible en **archivo1.c**.

## 2. Cómo funciona en memoria

| Tipo de variable | Dónde se guarda   | Cuánto vive                            | Cuándo se borra         |
| ---------------- | ----------------- | -------------------------------------- | ----------------------- |
| Local normal     | Pila (stack)      | Mientras la función se ejecuta         | Al salir de la función  |
| `static` local   | Segmento estático | Durante toda la ejecución del programa | Al terminar el programa |
| Global           | Segmento estático | Durante toda la ejecución              | Al terminar el programa |
