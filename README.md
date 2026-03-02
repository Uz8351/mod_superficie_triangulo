# Módulo de Apache: mod_superficie_triangulo

Este es un módulo de bajo nivel escrito en **C** para el servidor web **Apache2**. 

## Funcionalidad
El módulo registra un manejador (*handler*) específico que intercepta peticiones web para calcular la superficie de un triángulo de forma extremadamente eficiente, procesando los datos directamente en la memoria del servidor.

##  Instalación y Compilación
Para compilar este módulo binario, se requiere el paquete de desarrollo de Apache (`apache2-dev`):

```bash
sudo apxs -i -a -c mod_superficie_triangulo.c
