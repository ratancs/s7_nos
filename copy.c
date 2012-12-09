//12100051
#include<stdio.h>
void main(int argc,char *argv[])
{
	char command[50];
	if(argc!=3)
		printf("ERROR : Syntax wrong try   ./copy source destination");
	else
	{
		sprintf(command,"cp %s %s",argv[1],argv[2]);
		if(system(command)==0)
			printf("%s Sucessfully copied to %s",argv[1],argv[2]);
		else
			printf("Copy failed !!!");
	}
}
		
		
	
