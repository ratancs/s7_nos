#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	int fd,fd1,count=0;
	char ch='y',buffer;
	if(argc>3)
	{	printf("\nSyntax Error!<try> ./cp source_name destination_name\n");
		exit(0);
	}

	fd=open(argv[1],O_RDWR);
	if(fd==-1)
		{printf("\nCan not open source file .. :(\n");exit(0);}
	fd1=open(argv[2],O_RDWR);
	if(fd1=!-1)
		{printf("\nDestination file exist , OverWrite (Y/N) :");
			scanf("%s",&ch);
		}
	if(ch=='y'||ch=='Y')
		fd1=creat(argv[2],O_RDWR|0666);
	else
		exit(0);
	lseek(fd,0,0);
	while(read(fd,&buffer,sizeof(char)) > 0)
	{
	    write(fd1,&buffer,sizeof(char));
	}
}

