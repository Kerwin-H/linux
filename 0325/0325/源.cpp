#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
	umask(0);//����ǰ���̵��ļ�Ĭ�ϴ���Ȩ����������Ϊ0
	//open(�ļ����� �򿪱�־��Ȩ��)
	int fd = open("./tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0) {
		perror("open error");
		return -1;
	}

	char *ptr = "�����Ҫ�ݼ��ˣ��ÿ���~~\n";
	//write(��������ݣ�����)
	int ret = write(fd, ptr, strlen(ptr));
	if (ret < 0) {
		perror("write error");
		return -1;
	}

	//lseek(�����ƫ������λ��) SEEK_SET SEEK_CUR SEEK_END
	lseek(fd, 0, SEEK_SET);

	char buf[1024] = { 0 };
	ret = read(fd, buf, 1023);
	if (ret < 0) {
		perror("read error");
		return -1;
	}
	printf("%s-%d\n", buf, ret);

	close(fd);
	ret = read(fd, buf, 1023);
	if (ret < 0) {
		perror("read error");
		return -1;
	}
	return 0;
}