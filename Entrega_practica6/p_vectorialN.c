#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

struct datos
{
int dato1, dato2;
};


// Variable compartida
int resultado = 0;
sem_t semaforo1;


// Declaración de threads
pthread_t th1, th2,suma;
pthread_attr_t atributos;

// Definición de funciones
void producto (void *arg)
{
    struct datos *p;
    p = (struct datos *)arg;
    sem_wait(&semaforo1);
    resultado = resultado +( p->dato1 * p->dato2); 
    sem_post(&semaforo1);
    pthread_exit(0);
}
void  total (void *arg)
{
    printf("\nEl resultado es : %d\n", resultado);
    pthread_exit(0);
}
int main(){
   
	pthread_attr_init(&atributos);
    int n;
    //introduccion de datos
    printf("Introduce el valor de N\n");
    scanf("%d",&n);
    struct datos u[n];
    pthread_t thread_id[n];
    sem_init(&semaforo1,0,1);
    for(int i = 0; i < n; i++){
        printf("introduce los dos valores\n");
        printf("primer valor: ");
        scanf("%d",&u[i].dato1);
        printf("segundo valor: ");
        scanf("%d",&u[i].dato2);
       
    }

   for(int i = 0; i < n; i++){
         pthread_create(&thread_id[i], &atributos, producto,(void*)&u[i]);
    }

     //inicio semaforo
   
    //creo hilos
    pthread_create(&suma, &atributos,total,(void*)&u); 

    
    for(int i = 0; i < n; i++){
        pthread_join(thread_id[i],NULL);
    }
    
    pthread_join(suma,NULL);
    sem_destroy(&semaforo1);
    return 0;

}