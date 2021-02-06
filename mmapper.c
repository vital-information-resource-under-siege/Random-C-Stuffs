#include<stdio.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
void main()
{
	struct stat sb;
	int fd = open("/home/ajay/format.c",O_RDONLY);
	fstat(fd,&sb);
	char *file_memory = mmap(NULL,sb.st_size,PROT_READ,MAP_PRIVATE,fd,0);
	for(int i = 0;i<sb.st_size;i++)
	{
		printf("%c",file_memory[i]);
	}
	printf("\n");
	close(fd);
}

