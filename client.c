#include "minitalk.h"

void send_char(pid_t pid, char c)
{
    int digit;
	int err;

    digit = 7;
    while(digit >= 0)
    {
        if(c & (1 << digit))
            err = kill(pid,SIGUSR1);
        else
            err = kill(pid,SIGUSR2);
        if(err == -1)
			exit(1);
		digit--;
        usleep(100);
    }
}

/*
どういう時にSIGUSR1と２を送りたいかっていうと、2で割ったときにあるかないかを二進数で送りたいだけ、あるをUSR1として、ないを逆にする。
//この方法では50 = 1*32 + 1*16 + 0*8 +0*4 + 1*2 + 0*1　110010を　010011の順で送っている
安定させるためにunsigned char にすべきか？けど試してみたら変な値が出てきた
*/

void str_to_char(pid_t pid, char *str)
{
    while(*str != '\0')
    {
        send_char(pid, *str);
        str++;
    }
}

int main(int argc, char *argv[])
{
    int pid;

    if(argc != 3)
        return 1;
    pid = ft_atoi(argv[1]);
    if(pid < 0)
        return 1;
    if(pid <= 1000 || pid >= 99999)
    {
		ft_printf("argment pid is error. pid = %d",pid);
        return 1;
    }
    str_to_char(pid,argv[2]);
    return 0;
}
//printfの後にwriteをすると、順番が逆になる


//文字のbitを送る順番は、向こうの復号の順番を考えるかこちらのやつを考えるのにたく、
//手っ取り早くビット演算使うか、自分でアルゴリズム考えるかのどちらか
static int	is_over(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	else
		return (0);
}

void exit_and_print(void)
{
	ft_printf("error\n");
	exit(1);
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
		if (is_over(num))
			exit_and_print();
		num = num * 10 + *str - '0';
		str++;
	}
    if(*str != '\0' || count > 1)
		exit_and_print();
	if (count == 1)
		num *= -1;
	return (num);
}

