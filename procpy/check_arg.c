#include "procpy.h"


int check_arg(const char *sfile, int argnum, int pronum)
{
	//判断源文件是否存在
	if(access(sfile, F_OK) != 0)
	{
		perror("check_arg error:源文件不存在");
		exit(-1);
	}
	//参数数量是否满足
	if(argnum < 3)
	{
		perror("check_arg error:参数数量异常");
		exit(-1);
	}
	//进程数量是否溢出
	if(pronum <= 0 || pronum >= 100)
	{
		perror("check_arg error:进程数量要大于0,小于100");
		exit(-1);
		
	}

	return 0;
}
