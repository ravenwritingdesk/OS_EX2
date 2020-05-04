/* function: 
 * A demo of usage of execvp, child process will execute "mtest1.sh" 
 * And the parent process will wait the child to exit.
 */
//头文件声明
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
//exec的参数设置
char *argv[ ]={"/bin/bash","shell",NULL}; 


int main(void)
{
	pid_t pid;
        //fork创建子进程，并根据fork的返回值判断是否成功
	if( (pid= fork()) < 0)
	{
		printf("fork error\n");
		//exit退出
		exit(0);
	}
        //父进程,fork返回值大于0
        else if(pid != 0)
	{
		//提示此时正在执行父进程
		printf("--------------\n");
                printf("This is Parent process! PID：%d\n",getpid());
                printf("--------------\n");
		//等待子进程执行
                pid = wait(NULL);
                //exit退出
                exit(0);
	}
	//子进程,fork返回值等于0
	else 
	{
		//提示已经进入子进程
		printf("--------------\n");
		printf("This is Subprocess!  PID：%d\n",getpid());
                printf("--------------\n");
                //执行子进程，并判断是否成功
		if (execve("mtest1.sh",argv,NULL) < 0)	
				 printf("execve error\n");

	}
       //检查上面的进程是否退出正常，是否有意外错误发生
        printf("Unexpectded error happened\n");
        
	return 0;
} 





