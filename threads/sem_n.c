/*
Iker Burgoa Muñoz
Ejercicio entregable
Apartado B
Sacar el producto escalar por un semaforo con nombre y dos thread
*/
#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
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





void producto_escalar(void *arg){
    struct vectores *p;
    p = (struct vectores *)arg;
    sem_trywait(&sem);
    E = E +( p->uno * p->dos); 
    sem_post(&sem);
    pthread_exit(0);

}


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
    sem_open("semaforo",O_CREAT, 0644, 1);
    //creo hilos
	pthread_create(&thread_id[0], &atributos, producto_escalar,(void*)&u); 
    sem_wait(&sem);   
    pthread_create(&thread_id[1], &atributos,producto_escalar,(void*)&v); 
    //duermo por un segundo el principal
    sleep(1);
    //leo el resultado
    pintar_resultado();
    //finalizo los hilos
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1],NULL);
    sem_close(&sem);
    sem_unlink(&sem);
    return 0;
}