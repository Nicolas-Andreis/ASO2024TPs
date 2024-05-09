#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 2
#define CANTIDAD_INICIAL_HAMBURGUESAS 20

int cantidad_restante_hamburguesas = CANTIDAD_INICIAL_HAMBURGUESAS;
int turno = 0; // coloque el codigo aqui
void *comer_hamburguesa(void *tid)
{
    while (1 == 1)
    {
        
        while (turno != (int)tid) //coloque el codigo aqui
            ; 

        // INICIO DE LA ZONA CRÍTICA
        if (cantidad_restante_hamburguesas > 0)
        {
            printf("Hola! Soy el hilo(comensal) %d, me voy a comer una hamburguesa! Todavía quedan %d \n", (int)tid, cantidad_restante_hamburguesas);
            cantidad_restante_hamburguesas--; // Me como una hamburguesa
            
        }
        else
        {
            printf("SE TERMINARON LAS HAMBURGUESAS :( \n");
            turno = (turno + 1)% NUMBER_OF_THREADS;
            pthread_exit(NULL); // Forzar terminación del hilo
        }
        turno = (turno + 1) % NUMBER_OF_THREADS; // coloque el codigo aqui
         
        // SALIDA DE LA ZONA CRÍTICA
    }
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i, ret;

    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Hola!, soy el hilo principal. Estoy creando el hilo %d \n", i);
        status = pthread_create(&threads[i], NULL, comer_hamburguesa, (void *)i);
        if (status != 0)
        {
            printf("Algo salió mal, al crear el hilo recibí el código de error %d \n", status);
            exit(-1);
        }
    }

    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        void *retval;
        ret = pthread_join(threads[i], &retval); // Esperar por la terminación de los hilos que creé
    }

    pthread_exit(NULL); // Terminar el programa
}