#include "procpy.h"

int main(int argc,char ** argv)
{
	//argv[1] = sfile argv[2] = dfile argv[3] = blocksize argv[4] = pos
	int blocksize = atoi(argv[3]);
	int pos = atoi(argv[4]);
	char buffer[blocksize];
	bzero(buffer, sizeof(buffer));

	int sfd = open(argv[1], O_RDONLY);
	int dfd = open(argv[2], O_WRONLY|O_CREAT|0664);
	
	lseek(sfd, pos, SEEK_SET);
	lseek(dfd, pos, SEEK_SET);
	
	printf("copyProcess pid[%d] pos[%d] block[%d]\n", getpid(), pos, blocksize);

	int res = read(sfd, buffer, sizeof(buffer));
	write(dfd, buffer, res);
	//close(sfd);
	//close(dfd);
	printf("拷贝完成\n");

	return 0;	
}
