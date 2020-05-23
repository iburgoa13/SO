#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 10

void funcion(void)  {
	printf("Thread %d \n", (int) pthread_self());	
	pthread_exit(0);
}

int main() {
  int j;	
  pthread_attr_t atributos;	
  pthread_t thread_id[MAX_THREADS];
	pthread_attr_init(&atributos);	
	pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_DETACHED);
	for(j = 0; j < MAX_THREADS; j ++)    		
	   pthread_create(&thread_id[j], &atributos,  (void *) funcion, NULL);
 	sleep(1);
}
