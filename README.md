# ASO2024TPs
## TP3
### a ¿Qué se puede notar con respecto al tiempo de ejecución? ¿Es
predecible?

Los tiempos de ejecución difieren entre utilizar hilos (paralelismo) y 
no utilizarlos (secuencialmente). Con hilos, las tareas pueden ejecutarse 
simultáneamente, lo que resulta en un tiempo total de ejecución más corto 
en comparación con la ejecución secuencial sin hilos. En promedio, 
en 10 ejecuciones, los tiempos fueron de aproximadamente 
4.0262633 segundos con hilos  
5.1820766 segundos sin hilos.

La diferencia de tiempo se debe a que, con hilos, mientras una tarea
 (como la tarea 2) está en espera, otras tareas pueden continuar ejecutándose.
 Esto optimiza el uso del tiempo de CPU y reduce el tiempo total de ejecución.


### b Comparar con un campañero el tiempo de ejecución. ¿Son iguales?

Comparando con otro estudiante, sus tiempos fueron consistentes con esta 
observación: alrededor de 
4.07101 segundos con hilos 
5.17174 segundos sin hilos. 
Estos resultados corroboran la ventaja del enfoque de hilos para
 tareas que pueden ejecutarse en paralelo, lo que lleva a una menor duración 
total del proceso.

### c-Cuando ejecuté el archivo suma_rasta.py unas 10 veces, todo parecía estar
 bien. Pero luego me pidieron que descomentara esas líneas específicas en 
el código y lo ejecutara otras 10 veces más.

Después de hacer eso, noté que el tiempo que tomaba completar el programa 
era más largo. ¿Por qué? Bueno, resulta que cuando descomenté esas líneas,
 agregué dos bucles adicionales que no estaban haciendo nada útil,
 solo estaban pasando el tiempo con un pequeño retraso.

Estos bucles estaban dentro de las funciones sumador y restador, y cada 
uno se ejecutaba mil veces. Aunque cada iteración de estos bucles no hacía 
nada relevante, sumaba tiempo total de ejecución del programa.

Entonces, en resumen, el tiempo de ejecución aumentó porque añadí estas 
iteraciones adicionales que no eran necesarias para la lógica principal 
del programa.
Ahora, respecto al cambio en el valor final, ocurrió debido a este 
tiempo adicional de ejecución. Al introducir los bucles adicionales, 
aumenté el tiempo en el que acumulador estaba siendo modificado. 
Esto significaba que entre cada incremento y decremento de acumulador, 
había mil iteraciones adicionales que estaban ocurriendo. Durante este 
tiempo, el valor de acumulador estaba siendo afectado por la lógica dentro 
de esos bucles adicionales, lo que resultó en un valor final diferente al 
que obtendría sin ellos.

### 2-b Viendo la figura como sería para el problema de las hamburguesas con 2 comensales y 8 hamburgesas.

![punto2b](./TP3/WhatsApp%20Image%202024-05-07%20at%206.40.21%20PM.jpeg) 