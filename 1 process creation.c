#include<sys/types.h>
#include<stdio.h>
#include<process.h>
int main()
{
	int pid_t,pid,pid1,p,p1;
	pid=fork();
	if(pid==-1)
	{
		printf("entered the connection..");
	}
	else
	{
		if(pid==0)
		{
			printf("\n child process1:\n\n");
			p=getppid();
			printf("parent process id of child1:%d\n",p);
			p1=getpid();
			printf("parent process id of child1:%d\n",p1);
		}
		else
		{
			pid1=fork();
			if(pid==0)
			{
				printf("\n child process2:\n\n");
				p=getppid();
				printf("parent process id of child2:%d\n",p);
				p1=getpid();
				printf("parent process id of child2:%d\n",p1);
			}
			else
			{
				printf("this is parent process \n");
				p=getppid();
				printf("grant parent:%d\n",p);
				p=getpid();
				printf("process id of parent:%d\n",p1);
			}
		}
	}
	return 0;
}
