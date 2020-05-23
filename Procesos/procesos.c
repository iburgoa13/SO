#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void parOimpar (int signum);

int main(){
    pid_t pid_hijo;
    int n;
    int s;
    pid_hijo = fork();
    if(pid_hijo ==0){
        //soyhijo
        printf("Soy el hijo con el pid %d, inserta un numero: \n", pid_hijo);
        scanf("%d", &n);
        if(n%2==0){
            signal(SIGUSR1,parOimpar);
           kill(getpid(),SIGUSR1);
        }
        else{
         signal(SIGUSR2,parOimpar);
            kill(getpid(),SIGUSR2);
        } 
    }
    else if(pid_hijo >0){
        printf("Soy el padre %d\n",getpid());
       wait(&s);


    }
    exit(0);

}
void parOimpar (int signum){
 //Si la señal es SIGUSR1 entonces
 if(signum==SIGUSR1){
 printf("El numero es par\n");
 }
 //Si es SIGUSR2 entonces
 else
 {
 printf("EL numero es impar\n");
 }

}