#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include <limits.h>

static int	over(long *num, const char *str, int count)
{
	if (count == 0 && ((*num > LONG_MAX / 10) || (*num == LONG_MAX / 10 && *str
				- '0' > LONG_MAX % 10)))
	{
		*num = LONG_MAX;
		return (1);
	}
	else if (count == 1 && ((*num > LONG_MIN / 10 * -1) || (*num == LONG_MIN
				/ 10 * -1 && *str - '0' > LONG_MIN % 10 * -1)))
	{
		*num = LONG_MIN;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		count;
	long	num;

	num = 0;
	count = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (over(&num, str, count))
			return (num);
		num = num * 10 + *str - '0';
		str++;
	}
    if(*str < '0' || *str > '9' )
        return 0;
	if (count == 1)
		num *= -1;
	else if (count > 1)
		num = 0;
	return (num);
}
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if(argc!=2)
        return 1;
    
    printf("%d\n",ft_atoi(argv[1]));    
    printf("%d\n",atoi(argv[1]));
}
// int main()
// {
//     printf("%d",SIGINT);//整数が割り振られていることがわかる
//     return 0;
// }

// int main()
// {
//     printf("%d",8 | 9);//かつとまたはの演算子
//     printf("%d",8 & 9);
// }

// int main()
// {
//     printf("%d\n",getpid());//自分のプロセスを取得する
//     printf("%d",getppid());//親の
// }

// int main()
// {

// }

/*
方針は、まずは送って受け取るをしたい。
どう送るかはkill、受け取るのはsignalっぽい
killは指定したプロセスやシステムの全プロセスにシグナルを送ることができる。
int kill(pid_t pid, int sig);sigの部分を送れる。
 

SIGUSR1とSIGUSR2があるから、それぞれを0と1に対応させて
bitとして毎回送る。送ったやつを複合させる。
*/
