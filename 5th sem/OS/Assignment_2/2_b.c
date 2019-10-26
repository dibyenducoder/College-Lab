/*2_b.c
 *compile with " gcc -o 2_b 2_b.c -lpthread -lrt "
*/

/*
*	Modify the program so that X is not allowed to start iteration i before process Y 
*	has terminated its own iteration i-1. Use semaphore to implement this synchronization. 
*/

#include <stdio.h>
#include <unistd.h> // for fork 
#include <stdlib.h> 
#include <semaphore.h> //for semaphore 
#include <sys/wait.h> //for waiting 
#include <fcntl.h> //for manipulating the file 

int main(){
    int i;
    pid_t pid;
    sem_t *sem1;
		 //semname  , oflag  , mode , value
    sem1 = sem_open("OS_SEM", O_CREAT,  0644, 0); // create the named semaphore in locked state
					/*
						O_CREAT : Create the shared memory object if it does not already exists 

						The owner can read and write the file (User) - 6
						User in the same group as the file's owner can read(group) - 4
						All user can read(other) - 4 
						-rw-r--r--
						
						The initial value for the newly created semaphore 
					*/
    pid = fork();

    if(pid < 0)
        perror("Error\n");
    else if(pid == 0)
    {
        
        for (i = 1; i <= 10; i++)
        {
            sem_wait(sem1); // lock the semaphore that is to wait 
            
	    printf("Process Y-ID No.:%d",getpid()); //get the process ID for Y
	    printf("-->%d\n",i); //which iteration is now Y process gets
            sleep(rand()%5); 
        }
    exit(0);
    }
    else
    {
        if(!fork()){  //if fork returns zero 
        for (i = 1; i <= 10; i++)
        {
            
            printf("Process X-ID No.:%d",getpid()); //get the process ID for X
	    printf("-->%d\n",i); //which iteration is now Y process gets
            sem_post(sem1); //release the semaphore that is throwing the signal 
            sleep(rand()%5);
        }
        exit(0);
    }
    wait(NULL);    
    wait(NULL);
    }
    sem_close(sem1); //close the semaphore 
    sem_unlink("OS_SEM");  //remove the specified name semaphore 
    printf("Child Complete\n");
    return 0;
}
