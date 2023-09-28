#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>
#include <stdio.h>
int	ft_atoi(const char *str);

// void send_char(pid_t pid,char c)
// {
//     int i;
//     int bit;

//     bit = 1;
//     i = 0;
//     while(i < 8)
//     {
//         bit = c % 2;
//         c /= 2;
//         if(bit == 1)
//             kill(pid,SIGUSR1);//USR1
//         else
//             kill(pid,SIGUSR2);//USR2
//         i++;
//         usleep(100);
//     }
// }

void send_char(pid_t pid, char c)
{
    int digit;

    digit = 7;
    while(digit >= 0)
    {
        if(c & (1 << digit))
            kill(pid,SIGUSR1);
        else
            kill(pid,SIGUSR2);
        digit--;
        usleep(100);
        // printf("\n送りました%lu\n\n",clock());
    }
}

/*
どういう時にSIGUSR1と２を送りたいかっていうと、2で割ったときにあるかないかを二進数で送りたいだけ、あるをUSR1として、ないを逆にする。
//この方法では50 = 1*32 + 1*16 + 0*8 +0*4 + 1*2 + 0*1　110010を　010011の順で送っている
安定させるためにunsigned char にすべきか？けど試してみたら変な値が出てきた
*/

void str_to_char(pid_t pid, char *str)
{
    while(*str)
    {
        send_char(pid, *str);
        str++;
    }
}

int main(int argc, char *argv[])
{
    int pid;
    // printf("\n始めます%lu\n\n",clock());
    if(argc != 3)
        return 1;
    pid = ft_atoi(argv[1]);
    if(pid < 0)
        return 1;
    if(pid <= 1000 || pid >= 99999)
    {
        write(1,"argment pid is error",20);
        return 1;
    }
    str_to_char(pid,argv[2]);
    return 0;
}


//文字のbitを送る順番は、向こうの復号の順番を考えるかこちらのやつを考えるのにたく、
//手っ取り早くビット演算使うか、自分でアルゴリズム考えるかのどちらか
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
    if((*str < '0' || *str > '9') && *str != '\0')
        return 0;   
	if (count == 1)
		num *= -1;
	else if (count > 1)
		num = 0;
	return (num);
}