#include<stdio.h>
void main()
{
	int p,q;
	p=fork();
	q=fork();
printf("\n p=%d q=%d And PROCESS= %d\n",p,q,getpid());
}
