#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	struct stat buffer;
	int ret = stat("1.txt", &buffer);
	if (ret == -1)
	{
		perror("获取文件信息失败：");
	}
	return 0;
}
