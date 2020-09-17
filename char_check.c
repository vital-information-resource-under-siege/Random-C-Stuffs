#include<unistd.h>
void _start()
{
	char a;
	write(0,"Enter the input from 1 to 9\n",28);
	read(1,&a,1);
	char spaces;
	char count = '\x31';
	while(count <= a)
	{
		spaces = a - count + '\x31';
		while(spaces > '\x30')
		{
			write(0," ",1);
			spaces-=1;
		}
		while(spaces < count)
		{
			write(0,&count,1);
			write(0," ",1);
			spaces+=1;
		}
		write(0,"\n",1);
		count+=1;
	}
	_exit(0);
}
