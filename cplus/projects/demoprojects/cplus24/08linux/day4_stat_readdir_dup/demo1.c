#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char file_name[1024] = "tem_%d";

	int i = 0;
	while (1)
	{
		sprintf(file_name, "tem_%d", i++);
		if (open(file_name, O_RDONLY | O_CREAT, 0666) < 0)
		{
			perror("open error: ");
			printf("fd is %d\n", i);
			exit(0);
		}
	}

	return 0;
}
