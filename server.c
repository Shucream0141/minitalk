#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
volatile sig_atomic_t bits = 0;

//移植性が必要なときはsignalよりもsigactionを使えman siganlより
//sigactionで移植性の混乱を解決できる
//http://linuxc.info/signal/signal3.htmlこれおすすめ

void signal_handler(int signal, siginfo_t *info, void *context)
{
    static int i;
    char c;

    bits = bits << 1;
    if(signal == SIGUSR1)
        bits |= 1;    
    i++;
    // printf("\n受け取った%lu、%d回目\n\n",clock(),i);
    if(i == 8)
    {
        c = bits;
        write(1,&c,1);
        i = 0;
        // printf("\n復号完了%lu\n\n",clock());
    }
}

void    receiver()
{
    struct sigaction    act1;
    struct sigaction    act2;

    memset(&act1,0,sizeof(act1));
    memset(&act2,0,sizeof(act2));
    act1.sa_sigaction = signal_handler;
    act2.sa_sigaction = signal_handler;
    sigemptyset(&act1.sa_mask);
    sigemptyset(&act2.sa_mask);
    act1.sa_flags = SA_SIGINFO;
    act2.sa_flags = SA_SIGINFO;
    sigaddset(&act1.sa_mask, SIGUSR2);
    sigaddset(&act2.sa_mask, SIGUSR1);
    sigaction(SIGUSR1, &act1, NULL);
    sigaction(SIGUSR2, &act2, NULL);
}

    // sigaddset(&act.sa_mask,SIGUSR12);をどこで使うか迷う

int main()
{
    printf("pid =%d\n",getpid());
    receiver();
    while(1)
        pause();
}

/*
今回必要なのはserver側でserver側で復号すること
もらった信号ではSIGUSR1と2の二種類しかないため、向こうで意味づけたあるUSR1、ないUSR2を使っていく、

*/