#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{

	int a,n,num,buf[100],buf2[100],p[2],pid,i,j;

	a=pipe(p);

	if(a==-1)
	{	printf("error in pipe");exit;}


	pid=fork();
	
switch(pid)
{
	case -1 :
 			printf("Error in child process"); exit(0);
		break;
	case 0:
		printf("\n Inchild process id =%d ",pid);
		n=read(p[0],buf,sizeof(buf));
		n=n/sizeof(int);
		for(i=0;i<n;i++)
		printf("\nnum =%d ",buf[i]);
		break;
	default :
		printf("in parent process id =%d ",getpid());
		printf("\nEnter limit: ");
		scanf("%d",&num);
		for(j=0;j<num;j++)
{			printf("enter num\n");scanf("%d",&buf2[j]);}
		write(p[1],buf2,num*sizeof(int));
		waitpid(pid,NULL,0);
}
close(p[0]);
close(p[1]);
return 0;
}
	
