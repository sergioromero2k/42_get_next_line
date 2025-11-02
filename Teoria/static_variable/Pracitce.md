### Enunciados
---
##### 1. Contador de llamadas

Crea una función llamada `saludar()` que imprima "Hola!" y además muestre cuántas veces ha sido llamada desde main().
Usa una variable estática dentro de la función.

##### 2. Número acumulado

Haz una función acumular(int n) que sume el número recibido a un acumulador estático y muestre el total acumulado cada vez que se llama.
Ejemplo de uso:
```c
acumular(5);
acumular(3);
acumular(2);
```

Debe mostrar el total actualizado cada vez (usa static).

##### 3. Alternar mensaje

Escribe una función `alternar_mensaje()` que imprima “Encendido” la primera vez que se llama, “Apagado” la segunda, “Encendido” la tercera, y así sucesivamente.
(Usa una variable estática para recordar el estado.)

##### 4. Generador de ID

Crea una función nuevo_id() que devuelva un número de identificación que aumente en 1 cada vez que se llama.
Ejemplo:
```c
printf("%d", nuevo_id()); // 1
printf("%d", nuevo_id()); // 2
printf("%d", nuevo_id()); // 3
```

Usa una variable estática dentro de la función para llevar el conteo.

##### 5. Control de acceso

Haz una función int acceso_correcto() que permita el acceso solo 3 veces.
Después de la tercera llamada, muestra “Acceso denegado” y no permita más accesos.
Usa una variable estática para contar los intentos.

##### 6. Variable estática global

Crea dos funciones (`incrementar()` y `mostrar()`) que usen una variable estática global (declarada fuera de main, con static int valor;).

* `incrementar()` debe sumar 1 al valor.
* `mostrar()` debe imprimir el valor actual.
Prueba llamarlas varias veces desde `main()`.