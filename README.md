# TP Final Taller de Programacion 1

| Integrantes    | Padron |
|----------------|--------|
| Blanco Joaquin |        |
| Bravo Victor   | 98882  |
| Rack Lucas     |        |

## Uso de CMake (info para el grupo)

Para la compilacion de cliente y servidor se recomienda utilizar CMakeLists.txt. Para su utilizacion se debe copiar el siguiente codigo en un terminal.

~~~
mkdir build
cd build
cmake ..
make
~~~

El codigo anterior crea una carpeta `build` y con `cmake ..` se crea un Makefile para la compilacion del `client` y `server`. Para no agregar al repo archivos innecesarios `build` es ignorado (ver `.gitignore`).

