### Ejercicio 1: Escritor de archivos
1. Crea un programa que abra un archivo llamado "salida.txt" en modo de escritura (`O_WRONLY` | `O_CREAT`).
2. Escribe el mensaje "Hola, mundo con fd!" en ese archivo.
3. Cierra el descriptor de archivo.
4. Compila y ejecuta el programa. Luego, usa `cat` en la terminal para verificar que el archivo contiene el mensaje correcto. 

### Ejercicio 2: Copiador de archivos

1. Crea un programa que reciba dos argumentos en la línea de comandos: el nombre de un archivo de origen y el de un archivo de destino.
2. Abre el archivo de origen en modo de solo lectura (`O_RDONLY`).
3. Abre (o crea) el archivo de destino en modo de solo escritura (`O_WRONLY` | `O_CREAT`).
4. Crea un bucle que lea datos del archivo de origen en un búfer y los escriba en el archivo de destino. El bucle debe continuar hasta que `read()` devuelva 0 (final del archivo).

### Ejercicio 3: Lector de entrada estándar
1. Escribe un programa que lea desde la entrada estándar `(fd=0)` en un bucle.
2. En cada iteración, lee una pequeña cantidad de bytes (por ejemplo, 10 bytes) y escríbelos en la salida estándar `(fd=1)`.
3. El programa debe dejar de leer cuando el usuario presione Ctrl+D (lo que envía un `EOF`). 

### Ejercicio 4: Manejo de errores detallado
1. Modifica uno de los ejercicios anteriores para usar `perror()` cuando ocurra un error con `open()`, `read()` o `write()`.
2. Esto te ayudará a entender por qué fallan las llamadas al sistema. 

### Ejercicio 5: Redirección de salida
1. Escribe un programa que simplemente imprima un mensaje usando `write()` en la salida estándar `(fd=1)`.
2. Compila y ejecuta el programa.
3. Ejecútalo de nuevo, pero esta vez redirige la salida a un archivo usando el operador `>` de la terminal: `./tu_programa > archivo.txt`.
4. Verifica que el mensaje se ha escrito en `archivo.txt` y no en la pantalla. 
