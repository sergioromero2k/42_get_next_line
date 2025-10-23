## Ejercicios de práctica de Neovim
Archivo sugerido para todos: **prueba.txt**
Llena el archivo con varias líneas de texto, números y palabras repetidas para poder practicar movimientos, búsquedas y reemplazos.

### 1. Movimiento básico

Abre prueba.txt y mueve el cursor:

* Al inicio de la primera línea
* Al final de la última línea
* A la tercera palabra de la segunda línea
* Al paréntesis o corchete más cercano

### 2. Borrar y pegar

En prueba.txt:

* Borra la primera línea
* Borra la tercera palabra de la segunda línea
* Copia la segunda línea y pégala después de la última línea

### 3. Insertar y reemplazar

* Inserta texto al principio de la primera línea
* Inserta texto al final de la última línea
* Cambia una palabra seleccionada usando el modo visual y c

### 4. Selección y manipulación

* Selcciona la segunda línea completa y cámbiala a mayúsculas (usa visual + U)
* Selecciona un bloque rectangular de 3x3 caracteres y reemplázalo por otra palabra
* Indenta tres líneas consecutivas usando >

### 5. Buscar y reemplazar

* Busca la palabra “test” y navega entre todas las coincidencias (n / N)
* Reemplaza todas las apariciones de “error” por “correcto” en el archivo

### 6. Split y navegación

* Abre prueba.txt en un split horizontal
* Abre otro archivo otro.txt en split vertical
* Cambia entre splits usando los atajos de movimiento de ventana

### 7. Buffer y tabs

* Abre prueba.txt y otro.txt
* Cambia entre archivos usando buffers (:bnext, :bprev)
* Abre un nuevo tab y abre tercer.txt dentro

### 8. Guardar y salir

* Modifica prueba.txt y guárdalo sin salir
* Abre otro.txt, haz cambios y sal sin guardar
* Guarda y sal de tercer.txt

### 9. Combinación de movimientos y edición

* Ve al final de la cuarta línea
* Borra las dos últimas palabras
* Mueve la línea actual debajo de la segunda línea usando :m

### 10. Terminal y comandos

* Abre un terminal integrado (:term)
* Navega por el historial del terminal (Ctrl+P / Ctrl+N)
* Cierra el terminal y vuelve al archivo usando splits