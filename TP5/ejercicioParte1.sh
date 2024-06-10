#!/bin/bash

# Generar un número aleatorio entre 1 y 100
numero_aleatorio=$(( (RANDOM % 100) + 1 ))

echo "¡Bienvenido al juego Adivina el Número!"
echo "Estoy pensando en un número entre 1 y 100. ¡Adivina cuál es!"

# Comienza el bucle para permitir múltiples intentos
while true; do
    read -p "Ingresa tu intento: " intento

    if [[ $intento -eq $numero_aleatorio ]]; then
        echo "¡Felicidades! Has adivinado el número correcto."
        break
    elif [[ $intento -lt $numero_aleatorio ]]; then
        echo "El número es mayor que $intento. ¡Inténtalo de nuevo!"
    else
        echo "El número es menor que $intento. ¡Inténtalo de nuevo!"
    fi
done
