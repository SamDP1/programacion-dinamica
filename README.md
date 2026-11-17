# Programación Dinámica en C++

Dos problemas resueltos con Programación Dinámica (PD):

1. **Escaleras** (`escaleras.cpp`): se calcula de cuántas formas se llega al escalón N subiendo 1 o 2 escalones por paso, usando `dp[i] = dp[i-1] + dp[i-2]`.
2. **Cambio mínimo de monedas** (`monedas.cpp`): se calcula la menor cantidad de monedas para formar una cantidad, probando cada moneda en cada monto con `dp[i] = min(dp[i - c] + 1)`.

## Cómo ejecutar el proyecto

Se necesita un programa para compilar C++, por ejemplo Code::Blocks o Dev-C++.

1. Descargar los archivos del repositorio.
2. Abrir el archivo `.cpp` que se quiere probar:
- Code::Blocks: menú File > Open.
- Dev-C++: menú Archivo > Abrir.
3. Compilar y ejecutar:
- Code::Blocks: presionar F9 (Build and run).
- Dev-C++: presionar F11 (Compilar y ejecutar).
4. Escribir los datos que pide el programa en la ventana negra.

Si se usa la terminal: `g++ archivo.cpp -o programa` y luego ejecutar `programa`.

## Escaleras

Datos que pide el programa: el número de escalones (N).

Ejemplo de entrada:

    5

Salida esperada:

    Formas posibles: 8
    Tabla DP: [1, 1, 2, 3, 5, 8]

- Estado DP: `dp[i]` = formas de llegar al escalón i.
- Casos base: `dp[0] = 1` y `dp[1] = 1`.

## Cambio mínimo de monedas

Datos que pide el programa: la cantidad de tipos de monedas, el valor de cada moneda y la cantidad a formar.

Ejemplo de entrada:

    3
    1 3 4
    6

Salida esperada:

    Cantidad minima de monedas: 2
    Combinacion: 3 + 3
    Tabla DP: [0, 1, 2, 1, 1, 2, 2]

- Estado DP: `dp[i]` = mínimo de monedas para formar la cantidad i.
- Casos base: `dp[0] = 0` y el resto de montos empieza en infinito.
- Si la cantidad no se puede formar con esas monedas, el programa lo indica.

## Complejidad

| Problema | Tiempo | Espacio |
|---|---|---|
| Escaleras | O(N) | O(N) |
| Cambio de monedas | O(M · n) | O(M) |

En monedas, M es la cantidad a formar y n es el número de tipos de monedas.
