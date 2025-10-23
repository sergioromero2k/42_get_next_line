## File Descriptor
---
Un **descriptor de archivo** (File Descriptor o fd) es un entero no negativo que el sistema operativo asigna a un archivo abierto o a otro recurso de entrada/salida (como un socket de red o una tubería). En lugar de trabajar directamente con el archivo por su nombre, el programa utiliza este entero como una "llave" para interactuar con él. 

Cuando un programa se ejecuta, el sistema operativo le asigna automáticamente tres descriptores de archivo estándar: 

* **0**: **Entrada Estándar (STDIN_FILENO)**, típicamente el teclado.
* **1**: **Salida Estándar (STDOUT_FILENO)**, típicamente la pantalla o terminal.
* **2**: **Error Estándar (STDERR_FILENO)**, para mensajes de error, también en la terminal. 

### Cómo se usan los descriptores de archivo
El flujo de trabajo básico para usar un **descriptor de archivo** es el siguiente:

1. **Abrir:** Utilizas la función **open()** para abrir un archivo. Si la llamada es exitosa, open() devuelve un entero que es el descriptor de archivo para ese archivo específico. Si falla, devuelve -1.
2. **Leer/Escribir:** Una vez que tienes el fd, lo pasas a las funciones read() o write() para interactuar con el archivo. Le dices a la función cuántos bytes leer o escribir, y dónde colocar o tomar esos datos (un búfer).
3. **Cerrar:** Cuando terminas de usar el archivo, llamas a la función close() para liberar el descriptor de archivo, indicando que ya no necesitas el recurso. 