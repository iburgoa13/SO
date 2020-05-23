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
    struct datos u,v;
	pthread_attr_init(&atributos);
    
    //introduccion de datos
    printf("Introduce los valores de a y b\n");
    printf("Valor de a: ");
    scanf("%d",&u.dato1);
    printf("Valor de b: ");
    scanf("%d",&v.dato1);
    printf("Introduce los valores de c y d\n");
    printf("Valor de c: ");
    scanf("%d",&u.dato2);
    printf("Valor de d: ");
    scanf("%d",&v.dato2);

     //inicio semaforo
    sem_init(&semaforo1,0,1);
    //creo hilos
	pthread_create(&th1, &atributos, producto,(void*)&u);    
    pthread_create(&th2, &atributos,producto,(void*)&v); 
    pthread_create(&suma, &atributos,total,(void*)&v); 
    //duermo por un segundo el principal
    //leo el rsleep(1);esultadosleep(1);

    
    
    //finalizo los hilos
    pthread_join(th1, NULL);
    pthread_join(th2,NULL);
    pthread_join(suma,NULL);
    sem_destroy(&semaforo1);
    return 0;

}