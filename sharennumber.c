#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

int main()
{
	int shm_size,n,i,lar,smal;
	long shmid;
	key_t key;
	int *shm,*s;
	
	printf("\nEnter The limit :");
	scanf("%d",&n);
	shm_size=n*sizeof(int);
	key=123452;
	if((shmid=shmget(key,shm_size,IPC_CREAT|0666))< 0)	
		{printf("\nError in creating s.m. ");exit(0);}

/*	if((shm = shmat(shmid, NULL, 0)) == (int *)-1){
		printf("Error in attach");
		exit(0);}*/
 	if ((shm = shmat(shmid, NULL, 0)) == (int *) -1) {
     perror("shmat");
     exit(1);
   }
	s=shm;
	
	for(i=0;i<n;i++,s++)
		scanf("%d",s);
	
	printf("reached here");

	if(fork()==0)
	{
		s=shm;
		lar=*s;
		smal=*s;
		for(i=1;i<n;i++){
		if(*(s+i)>lar)
			lar=*(s+i);
		else if(*(s+i)<smal)
			smal=*(s+i);
		}
	}
	else
	{	wait(NULL);
		return 0;
	}
	printf("\nLargest=%d \t Smallest=%d",lar,smal);
	return 0;
}
