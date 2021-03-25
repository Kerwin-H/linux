#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("printf");
	fprintf(stdout, "fprintf");
	fwrite("fwrite", 6, 1, stdout);
	write(1, "write", 5);

	sleep(3);
	return 0;
}



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp = fopen("./tmp.txt", "r+");
	if (fp == NULL) {
		perror("fopen error");
		return -1;
	}
	fp->_fileno = 1;

	fwrite("nihao\n", 6, 1, fp);

	fclose(fp);
	return 0;
}


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open("./tmp.txt", O_RDWR);
	if (fd < 0) {
		perror("open error");
		return -1;
	}

	dup2(fd, 1);//让1指向fd对应的文件

	printf("file descriptor:%d\n", fd);
	//write(1, )
	//fflush(stdout);

	close(fd);
	return 0;
}