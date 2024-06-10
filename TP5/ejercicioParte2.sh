#!/bin/bash

# Ciudad predeterminada
ciudad="Carhue"

# Clave de la API
clave_api="457a941649bb476aa4d135624241006"

# Hacer la solicitud a la API
datos_clima=$(curl -s "http://api.weatherapi.com/v1/current.json?key=$clave_api&q=$ciudad")

# Extraer la información relevante del JSON de respuesta
clima=$(echo "$datos_clima" | jq '.current.condition.text' -r)
temperatura=$(echo "$datos_clima" | jq '.current.temp_c')
sensacion_termica=$(echo "$datos_clima" | jq '.current.feelslike_c')

# Mostrar el resultado al usuario
echo "El clima actual en $ciudad es: $clima"
echo "Temperatura: $temperatura °C"
echo "Sensación térmica: $sensacion_termica °C"

