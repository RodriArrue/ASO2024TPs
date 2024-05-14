#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

#define NUMBER_OF_THREADS 2
#define CANTIDAD_INICIAL_HAMBURGUESAS 20

int cantidad_restante_hamburguesas = CANTIDAD_INICIAL_HAMBURGUESAS;
pthread_mutex_t lock; 
int turno = 0; 

void *comer_hamburguesa(void *tid)
{
    int id = (intptr_t) tid;
    while (1)
    {
        
        while (turno != id)
        {
            
            sched_yield();
        }

        pthread_mutex_lock(&lock); 
        if (cantidad_restante_hamburguesas > 0)
        {
            printf("Hola! soy el hilo (comensal) %d , me voy a comer una hamburguesa ! ya que todavia queda/n %d \n", id, cantidad_restante_hamburguesas);
            cantidad_restante_hamburguesas--; 
        }
        else
        {
            printf("SE TERMINARON LAS HAMBURGUESAS :( \n");
            pthread_mutex_unlock(&lock);
            pthread_exit(NULL); 
        }
        turno = (turno + 1) % NUMBER_OF_THREADS; 
        pthread_mutex_unlock(&lock); 
    }
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status, ret;
    pthread_mutex_init(&lock, NULL); 
    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf("Hola!, soy el hilo principal. Estoy creando el hilo %d \n", i);
        status = pthread_create(&threads[i], NULL, comer_hamburguesa, (void *)(intptr_t)i);
        if (status != 0)
        {
            printf("Algo salio mal, al crear el hilo recibi el codigo de error %d \n", status);
            exit(-1);
        }
    }

    for (int i = 0; i < NUMBER_OF_THREADS; i++)
    {
        ret = pthread_join(threads[i], NULL); 
        if (ret != 0)
        {
            printf("Error al esperar la terminación del hilo %d, código de error %d \n", i, ret);
        }
    }

    pthread_mutex_destroy(&lock); 
    printf("Todos los hilos han terminado. Adios!\n");
    return 0; 
}