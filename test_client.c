#include <signal.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    pid_t pid;
    
    pid = atoi(argv[1]);
    kill(pid,SIGUSR1);
}