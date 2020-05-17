#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(int arg, char* args[])
{
	if (arg <= 1)
	{
		printf("请输入参数\n");
		return 0;
	}
	int fd = open(args[1], O_RDONLY);
	if (fd == -1)
	{
		printf("%s\n", strerror(errno));
		return errno;
	}
	char buffer[2048];

	int ret = 0;
	while (ret = read(fd, buffer, sizeof(buffer)))
	{
		printf("%s", buffer);
	}
	return 0;
}
