#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int n = 7;
void proc(){
     
    write(1,"yo soy el proceso hijo: \n",25);
    write(1,"inserta un numero: \n",20);
    scanf("%d", &n);
    if(n%2==0){
        kill(getppid(),SIGUSR1);
            exit(0);
    }
    else kill(getppid(),SIGUSR2);
    exit(0);
}

int main() {
  
   signal(SIGUSR1,proc);
   pause();
   
}


