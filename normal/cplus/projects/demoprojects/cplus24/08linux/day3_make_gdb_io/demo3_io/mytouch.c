#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
void createFile(char* fileName)
{
	if (sizeof(fileName) > 0)
	{
		int fd = open(fileName, O_RDONLY | O_CREAT, 0666);
		if (fd == -1)
		{
			printf("创建文件:%s失败\n", fileName);
			printf("errorno:%d str:%s\n", errno, strerror(errno));
		}
		close(fd);
	}
}

int main(int arg, char* args[])
{
	if (arg <= 1)
	{
		printf("请输入参数\n");
	}
	for (int i = 1; i < arg; i++)
	{
		createFile(args[i]);
	}
	
	return 0;
}
