#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int n = 1;


void proc_adios_hijo() {
    write(1, "HASTA PRONTO\n", 13);
    exit(0);
}

void proc() {
     write(1, "Hola padre\n", 11);
     kill(getppid(), SIGUSR2);
    return;
}
int main() {
    signal(SIGUSR1, proc);
    pause();
    signal(SIGUSR1, proc_adios_hijo);


}