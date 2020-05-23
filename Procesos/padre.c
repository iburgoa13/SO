#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

pid_t pid_hijo;
char buf[1];
void esPar(){
    printf("El numero introducido es par\n");
    exit(0);
}
void esImpar(){
    printf("El numero introducido es Impar\n");
    exit(0);
}
int main() {
    pid_hijo = fork();
    if (pid_hijo == 0)
        if (execlp("./hijo","hijo", NULL) == -1) {
            write(2, "Error en exec\n", 14);
            exit(1);
        }

    printf("Yo soy el padre %d\n",getpid());
    while (read(0, buf, 1) == 1) {
          if (buf[0] == '\n') kill(pid_hijo, SIGUSR1);
          signal(SIGUSR1,esPar);
          signal(SIGUSR2,esImpar);
          wait(&pid_hijo);

    } 
    

   


}
