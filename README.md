# Trabajo práctico número 4

## Uso del repositorio

Este repositorio utiliza `pre-commit` para validaciones de formato. Para trabajar con el mismo usted debe tener instalado: `pre-commit` (https://pre-commit.com/#install).

Después de clonar el repositorio se debe ejecutar el comando:

```
pre-commit install
```

Para generar la documentación del proyecto se utiliza el comando:

```
make doc
```

Para compilar el proyecto se utiliza el comando:

```
make all
```

Para limpiar el proyecto se utiliza el comando:

```
make clean
```
## Consideraciones

Se ha documentado los archivo `.h` y `.c`, se consideró esta opción debido a que se puede documentar un `.h` para interfaces públicas que otros desarrolladores usarán. y el `.c` para detalles internos, algoritmos y funciones privadas que otros desarrolladores no necesitan conocer a menos que trabajen en la implementación.

Se ha decido usar la opción de definir la licencia desde github.

## Licencia

Este trabajo se distribuye bajo la licencia XXXX.
