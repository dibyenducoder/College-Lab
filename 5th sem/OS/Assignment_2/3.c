#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h> //inter process communication 
#include <sys/shm.h> //for shared memory constants
#include <sys/types.h>

int main()
{
	int shmid,status;
	int *a,*b;
	int i,j,k;
	int p,c;
        
   /*OS keeps track of the set of shared memory segments.
	in order to acquire shared memory, we must first request the shared memory from os using shmget() system call.*/

	printf("Enter Producer as p :");
	scanf("%d",&p);
	printf("Enter Consumer as c :");
	scanf("%d",&c);
 		// key_t , size_t , shmflag 
	shmid=shmget(IPC_PRIVATE, 26*sizeof(int), 0777|IPC_CREAT);

/*
 After forking, the parent and chils must attach the shared memory to its local data segment. this is done by shmat(). 
shmat() takes the shmid of the shared memory segment as input and returns the address at which the segment has been attached. thus , shmat() returns the char point 
*/
	for(k=0;k<p;k++)
	{
		if(!fork()) // if fork returns zero
		{
			//child process 

		/* shmat() returns the char pointer which is typecasr here to int and the address is stored in the int pointer b */
			b=(int *)shmat(shmid,0,0); //attached a shared memory address to an address space 
			for(i=0;i<80;)
			{
				sleep(2);
				for(j=0;j<25 && i<80;j++)
				{
					b[25]=b[25]+b[j];
					i++;
					printf("%d-> produced[id:%d] %d\n",k,getpid(),b[j]);
				}
				printf("\n");
			
			}
			//each process should deattach itself after being used 
			shmdt(b);
			exit(0);
		}
		
		//parent process 

		a=(int *)shmat(shmid,0,0);
		for(i=0;i<80;)
		{
			sleep(2);
			for(j=0;j<25 && i<80;j++)
			{
				a[j]=(i+1);
				i++;
				printf("%d -> consumed[id:%d]: %d\n",k,getpid(),a[j]);
			}
 			

		}

		wait(&status); //wait for an unspecied child 
		printf(" TOTAL in parent is = %d \n",a[25]);
		shmdt(a); //detech shared memory from address space 
	    
	}
	shmctl( shmid, IPC_RMID , 0 );//delocates shared memory

	return 0;
}
