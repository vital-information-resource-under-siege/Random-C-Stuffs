#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdint.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int i = 0;
	int fd = open("/home/ajay/random.txt",O_RDONLY);                                         // File opened to read 
	int fd2 = open("/home/ajay/Desktop/random_copy.txt",O_CREAT,S_IWUSR);                   // File open to create 
	close(fd2);
	int fd3 = open("/home/ajay/Desktop/random_copy.txt",O_WRONLY);                         // File open to write contents
	struct stat s1;
	char c;
	if(fstat(fd,&s1)== -1)
	{
		perror("\nFile opened failed");
		exit(1);
	}
	char *ptr = mmap(NULL,s1.st_size,PROT_READ,MAP_SHARED,fd,0);
	write(fd3,ptr,s1.st_size);
	close(fd);
	close(fd3);
}


