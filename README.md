# 42_get_next_line

Commen core 42 - project 2.1

### Get next line (Parte Obligatoria)

| **Elemento**              | **Descripción**                                                |
| ------------------------- | -------------------------------------------------------------- |
| **Nombre de función**     | `get_next_line`                                                |
| **Prototipo**             | `char *get_next_line(int fd);`                                 |
| **Descripción**           | Lee una línea de un file descriptor especificado.              |
| **Parámetros**            | - `fd`: Descriptor de archivo desde el cual se leerá la línea. |
| **Valor devuelto**        | - **Éxito**: Devuelve un puntero a la línea leída.             |
|                           | - **Fallo o fin de lectura**: Devuelve `NULL`.                 |
| **Funciones autorizadas** | - `read`, `malloc`, `free`                                     |

`get_next_line` es una función en C que lee una línea de un descriptor de archivo(fd) y la devuelve como una cadena de caracteres.
La función está diseñada para ser llamada reptidamente en un bucle para leer un arhcivo línea por línea hasta que se alcance el final del archivo o se produzca un error.
