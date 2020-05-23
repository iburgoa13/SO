#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
pid_t pid_hijo;
char buf[1];

void proc_adios_padre() {
    char resp[1];
    write(1, "¿Quieres que terminar? (s/n):", 30);
    read(0,resp,1);
    if (resp[0]=='s') {
        kill(pid_hijo, SIGUSR1);
        wait(&pid_hijo);
        write(1, "ADIOS\n", 6);
    }
}

int main() {
    pid_hijo = fork();
    if (pid_hijo == 0)
        if (execlp("./adios_hijo","hijo", NULL) == -1) {
            write(2, "Error en exec\n", 14);
            exit(1);
    }
    write(1, "Hola hijo\n", 11);
    while (read(0, buf, 1) == 1) {
	  	if (buf[0] == '\n') kill(pid_hijo, SIGUSR1);
          signal(SIGUSR2, proc_adios_padre);
	} 
    
  
   
    
    
    
}