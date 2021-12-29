#include "procpy.h"


int block(const char * sfile, int pronum)
{
	int sfd = open(sfile, O_RDONLY);
	int filesize = lseek(sfd, 0, SEEK_END);//获取文件大小
	close(sfd);
	if(filesize % pronum == 0)
		return filesize/pronum;
	else
		return filesize/pronum + 1;//每个进程多分一字节
}
