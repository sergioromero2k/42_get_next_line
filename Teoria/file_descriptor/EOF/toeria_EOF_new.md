# EOF

### 1. Qué significa EOF
* `EOF` = `End Of File` → “Fin de archivo”
* Es un `marcador especial` que indica que no hay más datos para leer de una fuente de entrada.
En C, cuando usas funciones como `read()`, `getchar()` o `fgetc()`:
```c
int c = getchar();
```
* Si el usuario escribe texto y presiona Enter, `getchar()` devuelve ese carácter.
* Si el usuario presiona **Ctrl+D** en Linux/Unix (o Ctrl+Z en Windows), `getchar()` devuelve `EOF`, que es un valor especial (-1).

### 2. Cómo EOF se usa en la práctica
##### Ejemplo 1: Leer caracteres hasta EOF
```c
#include <stdio.h>

int main() {
    int c;
    printf("Escribe algo (Ctrl+D para terminar):\n");

    while ((c = getchar()) != EOF) {
        putchar(c); // Imprime lo que escribiste
    }

    printf("\n¡Fin de la entrada!\n");
    return 0;
}
```
Lo que pasa:
* El programa lee carácter por carácter desde stdin.
* Mientras no sea EOF (Ctrl+D), sigue leyendo.
* Cuando el usuario presiona Ctrl+D, getchar() devuelve -1 → se rompe el bucle.

##### Ejemplo 2: Leer líneas completas con fgets
```c
#include <stdio.h>

int main() {
    char buffer[100];

    printf("Escribe líneas (Ctrl+D para terminar):\n");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        printf("Leído: %s", buffer);
    }

    printf("\n¡Fin de la entrada!\n");
    return 0;
}
```
#### Explicación:
* fgets() devuelve NULL cuando llega EOF.
* Ctrl+D en Linux envía EOF al programa.
* El bucle termina.

### 3. Cómo funciona Ctrl+D en la terminal

* Linux/Unix: Ctrl+D indica “EOF” en la terminal.
* Si lo presionas al principio de la línea, envía EOF inmediatamente.
* Si lo presionas después de escribir texto y Enter, envía EOF después del buffer actual.
* Windows: se usa Ctrl+Z seguido de Enter para EOF.

### 4. Relación con `read()`
Si usas `read()`:
```c
#include <unistd.h>

char buffer[100];
ssize_t n;

while ((n = read(0, buffer, sizeof(buffer))) > 0) {
    write(1, buffer, n); // eco
}
```
* `read()` devuelve 0 cuando detecta `EOF` → fin del bucle.
* `0` es equivalente a “ya no hay más datos que leer”.

| Concepto            | Qué significa               | Cómo se activa                      |
| ------------------- | --------------------------- | ----------------------------------- |
| EOF                 | End Of File, fin de archivo | Ctrl+D en Linux / Ctrl+Z en Windows |
| getchar() / fgetc() | Devuelve EOF (-1)           | Cuando el usuario presiona Ctrl+D   |
| fgets()             | Devuelve NULL               | Cuando llega EOF                    |
| read()              | Devuelve 0                  | Cuando llega EOF                    |
