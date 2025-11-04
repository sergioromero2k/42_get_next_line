### Nivel 1 – Entender el tamaño
---
Para reservar memoria para un texto de tamaño desconocido en tiempo de ejecución sin usar un array fijo, se utiliza la asignación dinámica de memoria.

* **Función Clave:** La función principal para esto en C es malloc() o realloc().
* **Proceso:**
    1. Comienzas reservando una pequeña cantidad inicial de memoria (ej. 10 caracteres) usando `malloc()`.
    2. A medida que el usuario escribe, si la variable se llena, usas realloc() para duplicar o aumentar el tamaño de la memoria reservada.
    3. Esto te permite crecer la memoria justo a medida que se necesita, evitando el desperdicio (como en `char texto[1000]`) o el desbordamiento.

### Nivel 2 – Simular un buffer
---
* Para el texto: `Hola mundo\nEsto es 42\n`, leyendo de 5 en 5 caracteres:

| Paso | Trozo leído | Contenido del Buffer | ¿Línea completa?                  |
|------|-------------|----------------------|-----------------------------------|
| 1    | Lectura 1   | Hola                 | No (Falta \n)                     |
| 2    | Lectura 2   | mundo                | No (Falta \n)                     |
| 3    | Lectura 3   | \nEst               | Sí (\n encontrado)                |

* **Acumulación**: La primera línea completa se forma uniendo los datos acumulados: "`Hola` " + "`mundo`" + "`\n`".
* **Resultado**: La primera línea es: "`Hola mundo\n`".
* **Buffer Residual**: Después de devolver la línea, el buffer de la Lectura 3 todavía tiene material para la siguiente línea: "`Est`".