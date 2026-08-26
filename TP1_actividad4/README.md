# TP1 — Actividad 4

Implementación en C++ del sistema de móviles (trayectoria bidimensional), a partir del
modelo UML y del código de la Actividad 3.

## Archivos

| Archivo | Contenido |
|---|---|
| `EstadoMovil.h` | Enumerado `DETENIDO` / `EN_MOVIMIENTO`. |
| `Posicion.h` / `.cpp` | Punto `(x, y)` en metros y operaciones geométricas. |
| `Velocidad.h` / `.cpp` | Vector velocidad `(vx, vy)`; módulo, ángulo, construcción polar. |
| `Movil.h` / `.cpp` | Clase principal: estado, desplazamiento, validaciones. |
| `RegistradorCSV.h` / `.cpp` | Registro opcional de estados en `estados_moviles.csv`. |
| `main.cpp` | Programa de pruebas (requerimientos del anexo). |
| `Makefile` | Compilación modular, regla `run` y regla `clean`. |
| `Movil.drawio` | Diagrama de clases UML (editable). |
| `diagrama_clases.md` | Mismo diagrama + correspondencia con el código + cambios vs. Act3. |

## Uso

```sh
make          # compila cada módulo y enlaza el ejecutable ./movil
make run      # compila (si hace falta) y ejecuta el programa
make clean    # borra los .o, el ejecutable y el .csv generado
```

## Qué demuestra la ejecución

- Creación de móviles con dos formas de inicialización (constructor por defecto y con datos).
- Estado inicial de cada móvil.
- Desplazamiento durante varios intervalos de tiempo (posición y distancia cambian).
- Cambio de velocidad (uno válido y uno rechazado por superar la velocidad máxima).
- Cambio de estado: al detener un móvil, el paso del tiempo no modifica su posición.
- Estado final y distancia total recorrida de cada móvil.
- Registro de todos los estados en `estados_moviles.csv`
  (`movil,estado,distancia_recorrida`).
