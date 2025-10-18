## Función `get_next_line`
---
La función `get_next_line` es una implementación personalizada en C que lee un archivo descriptor y devuelve una línea completa del archivo. Su propósito es leer archivos línea por línea, **independientemente de su tamaño**, y está diseñada para ser utilizada en proyectos de programación, como en la escuela de informática 42. 

Las características clave de `get_next_line` incluyen:

**Lectura incremental:** En lugar de leer todo el archivo a la vez, lo lee en fragmentos pequeños (a menudo definidos por **BUFFER_SIZE**). Esto es más eficiente para archivos grandes y evita el uso excesivo de memoria.
**Gestión de estados:** Para saber dónde continuar la lectura en la siguiente llamada, la función utiliza una variable estática. Esta variable conserva su valor entre llamadas sucesivas a la función, lo que le permite almacenar los datos sobrantes del último fragmento leído y continuar desde ese punto.
**Manejo de múltiples descriptores de archivo:** Una implementación más avanzada (a menudo parte del "bonus" en los proyectos de la escuela 42) permite que la función gestione varios descriptores de archivo a la vez, utilizando una estructura de datos para mantener el estado de cada uno de ellos.
**Devolución de una línea:** La función busca **el carácter de nueva línea (\n)** o **el fin del archivo (EOF)**. Una vez que lo encuentra, devuelve la línea completa como una cadena de caracteres asignada dinámicamente.
**Manejo de errores:** Si ocurre un error al leer el archivo o si no hay más líneas, la función devuelve **NULL**. 

### ¿Para qué se usa get_next_line?
**Procesamiento de archivos:** Es muy útil para procesar archivos de texto línea por línea, sin importar lo grandes que sean o lo variables que sean las longitudes de las líneas.
**Entrada estándar:** También puede leer de la entrada estándar, como lo haría un programa de línea de comandos que procesa la entrada del usuario.
**Manejo de la memoria:** El proyecto detrás de esta función se enfoca en el manejo de la asignación y liberación de memoria para evitar fugas de memoria