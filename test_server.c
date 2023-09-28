#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// void signal_handler(int signum)
// {
//     if(signum == SIGUSR1)
//         printf("12345\n");
// }
// int main()
// {
//     printf("pid = %d\n", getpid());
//     signal(SIGINT,signal_handler);
//     while(1)
//     {
//     }
// }

#include <signal.h>
#include <stdio.h>

volatile sig_atomic_t g_flag = 0;

void signal_handler(int signum) {
    g_flag = 1;
}

int main(void)
{
    printf("pid = %d\n",getpid());
    signal(SIGUSR1, signal_handler);

    while (!g_flag) {
    }

    puts("exit");
}