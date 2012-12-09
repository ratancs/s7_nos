#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	int pid,p1[2],p2[2],i,j,n,buffer[100],buffer2[100],a,b,f,n2;
	
	if((a=pipe(p1))==-1)
		{	printf("\n Erroe in pipe");exit(0);}
	if((b=pipe(p2))==-1)
		{	printf("\nError in pipe2");exit(0);}
	
	pid=fork();
	
	switch(pid)
	{
		case -1 : 	printf("\nError in fork\n");
				exit(0);
		case 0 :
				close(p1[1]);
				close(p2[0]);
				
				printf("\n In child Process\n");
				n=read(p1[0],buffer,sizeof(buffer));
				n=n/sizeof(int);
				n2=0;
				for(i=0;i<n;i++)
				{
					f=0;
				if(buffer[i]==1)
					f=1;
				for(j=2;j<buffer[i]/2;j++)
					if(buffer[i]%j==0)
						{f=1;
						break;}
				if(f==0)
					buffer2[n2++]=buffer[i];
				}
			write(p2[1],buffer2,n2*sizeof(int));
			break;
		default :
				printf("\n In parent process \n ");
				printf("Enter limit :");
				scanf("%d",&n);
				for(i=0;i<n;i++)
					scanf("%d",&buffer[i]);
				write(p1[1],buffer,n*sizeof(int));
				waitpid(pid,NULL,0);
				printf("\n now printing prime number \n");
				n2=read(p2[0],buffer2,sizeof(buffer2));
				n2=n2/sizeof(int);
				for(i=0;i<n2;i++)
					printf("prime=%d\n",buffer2[i]);
				break;
	}

}

			
			


	
