/*
Iker Burgoa Muñoz
Ejercicio entregable
Apartado A
Sacar el producto escalar por un semaforo sin nombre y dos thread
*/
#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
//numero de hilos
#define MAX_THREADS 2

//estructura del vector
struct vectores
{
    float uno;
    float dos;
};
//variables para guardar los valores
float E = 0;
//semaforo
sem_t sem;




// funcion que calcula el producto escalar
void producto_escalar(void *arg){
    struct vectores *p;
    p = (struct vectores *)arg;
    sem_wait(&sem);
    E = E +( p->uno * p->dos);  
    sem_post(&sem);
    pthread_exit(0);
}


//funcion que pinta el resultado
void pintar_resultado(){
    printf("El producto escalar de los vectores U y V es: %f\n", E);
}

int main()
{
    struct vectores u,v;
	pthread_t thread_id[MAX_THREADS];
    pthread_attr_t atributos;
	pthread_attr_init(&atributos);
    
    //introduccion de datos
    printf("Introduce los valores del vector U\n");
    printf("Valor de u1: ");
    scanf("%f",&u.uno);
    printf("Valor de u2: ");
    scanf("%f",&v.uno);
    printf("Introduce los valores del vector V\n");
    printf("Valor de v1: ");
    scanf("%f",&u.dos);
    printf("Valor de v2: ");
    scanf("%f",&v.dos);

    //inicio semaforo
    sem_init(&sem,0,1);
    //creo hilos
	pthread_create(&thread_id[0], &atributos, producto_escalar,(void*)&u);    
    pthread_create(&thread_id[1], &atributos,producto_escalar,(void*)&v); 
    //duermo por un segundo el principal
    sleep(1);
    //leo el resultado
    pintar_resultado();
    //finalizo los hilos
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1],NULL);
    sem_destroy(&sem);
    return 0;
}