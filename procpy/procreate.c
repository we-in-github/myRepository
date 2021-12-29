#include "procpy.h"

int procreate(const char *sfile, const char * dfile, int pronum, int block)
{
	int flag;
	pid_t pid;

	int pos;
	char cblock[10];
	char cpos[10];
	bzero(cblock, sizeof(cblock));
	bzero(cpos, sizeof(cpos));

	for(flag = 0; flag < pronum; flag++)
	{
		pid = fork();
		if(pid == 0)
			break;
	}
	
	if(pid > 0)
	{
		printf("parent process pid[%d] 非阻塞回收...\n", getpid());
		pid_t zpid;
		while((zpid = waitpid(-1, NULL, WNOHANG)) != -1)
		{
			if(zpid > 0)
			{
				printf("parent wait sucessfully : zombie pid[%d]\n", zpid);
			}
		}
	}

	else if(pid == 0)
	{
		//偏移量计算
		pos = flag * block;
		sprintf(cpos, "%d", pos);
		sprintf(cblock, "%d", block);
		//重载
		execl("/home/syp/0322/process/procpy/copy", "./copy", sfile, dfile, cblock, cpos, NULL);
	}

	else
	{
		perror("fork call failed");
		exit(-1);
	}
	
	return 0;
}
