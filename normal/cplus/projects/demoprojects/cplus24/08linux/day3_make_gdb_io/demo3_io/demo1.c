#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>                                                                                
#include <fcntl.h> 

int main()
{
	close(1);
	int fd = open("1.log", O_RDONLY | O_CREAT, 0666);
	write(1, "hello, c\n", 9);
	flush();
	printf("hello\n");
	close(fd);
	return 0;
}
