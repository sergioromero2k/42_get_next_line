### Nivel 1 – Entender el tamaño

#### Ejercicio
Tienes una función que debe leer un texto del usuario (por teclado) y guardarlo en una variable.
No sabes cuántos caracteres escribirá.
¿Cómo podrías reservar memoria sin usar un array fijo como `char texto[1000]`?
(**Idea**: el objetivo es que empieces a pensar en cuándo necesitas reservar memoria en tiempo de ejecución.)

### Nivel 2 – Simular un buffer

#### Ejercicio
Imagina que tienes un archivo con este texto:
```
Hola mundo\nEsto es 42\n
```
y decides leerlo de 5 en 5 caracteres.
Haz una lista de qué trozos leerías (buffers) en cada paso hasta formar la primera línea completa.
(El objetivo es entrenar cómo se “acumula” lo leído antes de encontrar \n.)