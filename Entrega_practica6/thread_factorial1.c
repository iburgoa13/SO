#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 10

int factorial(void * arg)
{
	int i;
	int n = (int) arg;
	int resultado = 1;
	for (i = 2; i <= n; i ++) {
		resultado = resultado * i;
		fprintf(stderr, "%d! : en calculo...\n", n);
	  sleep(1);
	}
	fprintf (stderr, "main(): %d! = %d\n", n, resultado);
	return resultado;
}

int main()   {
	long j;
	pthread_attr_t atributos;
	pthread_t thread_id[MAX_THREADS];
	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_DETACHED);
	for(j = 0; j < MAX_THREADS; j ++)     
	  pthread_create(&thread_id[j], &atributos, (void *) factorial, (int *)j);
	/*for(j = 0; j < MAX_THREADS; j ++)    
	  pthread_join(thread_id[j], NULL);*/
}
