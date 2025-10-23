### 1. Modos principales de Neovim
| Modo    | Cómo entrar                                      | Qué se hace                                 |
| ------- | ------------------------------------------------ | ------------------------------------------- |
| Normal  | `Esc`                                            | Navegación, borrar, copiar, pegar, comandos |
| Insert  | `i` / `I` / `a` / `A`                            | Escribir texto                              |
| Visual  | `v` (caracter) / `V` (línea) / `Ctrl+v` (bloque) | Seleccionar texto                           |
| Command | `:`                                              | Ejecutar comandos (`:w`, `:q`, etc.)        |

### 2. Movimientos (modo normal)
| Acción                      | Comando                                            | Modo   |
| --------------------------- | -------------------------------------------------- | ------ |
| Moverse por palabras        | `w` (inicio) / `e` (fin) / `b` (atrás)             | Normal |
| Moverse por líneas          | `0` (inicio) / `^` (primer carácter) / `$` (final) | Normal |
| Saltar a inicio/fin archivo | `gg` / `G`                                         | Normal |
| Buscar                      | `/palabra` → `n` siguiente / `N` anterior          | Normal |
| Saltar paréntesis o bloques | `%`                                                | Normal |

### 3. Edición Básica
| Acción                | Comando                                         | Modo            |
| --------------------- | ----------------------------------------------- | --------------- |
| Borrar                | `x` (carácter) / `dd` (línea) / `daw` (palabra) | Normal          |
| Copiar                | `yy` (línea) / `yaw` (palabra)                  | Normal          |
| Pegar                 | `p` (después) / `P` (antes)                     | Normal          |
| Deshacer / rehacer    | `u` / `Ctrl+r`                                  | Normal          |
| Repetir última acción | `.`                                             | Normal          |
| Insertar texto        | `i` / `I` / `a` / `A`                           | Normal → Insert |

### 4. Selección y manipulación
| Acción             | Comando              | Modo            |
| ------------------ | -------------------- | --------------- |
| Seleccionar        | `v` / `V` / `Ctrl+v` | Normal → Visual |
| Cortar selección   | `d`                  | Visual          |
| Copiar selección   | `y`                  | Visual          |
| Cambiar selección  | `c`                  | Visual → Insert |
| Indentar selección | `>` / `<`            | Visual          |

### 5. Trucos (modo normal / command)
| Acción              | Comando                     | Modo    |
| ------------------- | --------------------------- | ------- |
| Mover línea         | `:m .+1` / `:m .-2`         | Command |
| Duplicar línea      | `yyp`                       | Normal  |
| Buscar y reemplazar | `:%s/antiguo/nuevo/g`       | Command |
| Abrir archivo       | `:e archivo`                | Command |
| Abrir tab           | `:tabnew archivo`           | Command |
| Cambiar buffer      | `:bnext` / `:bprev`         | Command |
| Guardar / salir     | `:w` / `:q` / `:wq` / `:q!` | Command |

### 6. Atajos útiles (modo normal)
| Acción                    | Comando              | Modo    |
| ------------------------- | -------------------- | ------- |
| Abrir terminal integrada  | `:term`              | Command |
| Split                     | `:split` / `:vsplit` | Command |
| Saltar entre splits       | `Ctrl+w h/j/k/l`     | Normal  |
| Cerrar split              | `:close`             | Command |
| Mover cursor al centro    | `zz`                 | Normal  |
| Mover cursor arriba/abajo | `zt` / `zb`          | Normal  |
