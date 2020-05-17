#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void show_file_list()
{

}

int main(int arg, char* args[])
{
	if (arg == 1)
	{
		// 只显示文件列表
	}
	else if (arg == 2)
	{
		if (strcmp("-l", args[1]) == 0)
		{
			printf("ls -l");
		}
	}
	else 
	{
		printf("参数错误!");
	}
	return 0;
}
