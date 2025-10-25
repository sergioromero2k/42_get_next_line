# EOF old
---
### 1. Usando getchar()
Esta es probablemente la forma más clásica
```c
#include <stdio.h>

int main() {
    int c;

    printf("Escribe texto (Ctrl+D para terminar):\n");

    while ((c = getchar()) != EOF) {  // getchar() devuelve EOF cuando Ctrl+D
        putchar(c); // imprime el carácter leído
    }

    printf("\n¡Fin de la entrada!\n");
    return 0;
}
```
* `getchar()` lee un carácter a la vez de stdin.
* Devuelve EOF cuando el usuario presiona Ctrl+D.
* Esta técnica se usaba mucho antes de que existieran buffers grandes y funciones como fgets().

### 2. Usando scanf() (menos recomendable, pero clásico)
```c
#include <stdio.h>

int main() {
    char palabra[100];

    printf("Escribe palabras (Ctrl+D para terminar):\n");

    while (scanf("%99s", palabra) != EOF) {  // scanf devuelve EOF al final
        printf("Leíste: %s\n", palabra);
    }

    printf("¡Fin de la entrada!\n");
    return 0;
}
```
* `scanf()` devuelve el número de elementos leídos, y EOF cuando llega al final de la entrada.
* Útil para leer palabras o números sin usar buffers de líneas.

### 3. Usando fgetc() con un archivo
Si quieres leer **desde un archivo en lugar de stdin**, la técnica clásica es:
```c
#include <stdio.h>

int main() {
    FILE *f = fopen("archivo.txt", "r");
    int c;

    if (!f) return 1;

    while ((c = fgetc(f)) != EOF) {  // fgetc devuelve EOF al final del archivo
        putchar(c);
    }

    fclose(f);
    return 0;
}
```
* `fgetc()` lee un carácter a la vez.
* EOF indica que ya no hay más caracteres en el archivo.
* Este patrón se usaba mucho en programas antiguos tipo cat o more.