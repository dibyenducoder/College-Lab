/*2_a.c*/

/*Each child process performs 10 iterations. The child process displays its name/id and the current iteration number,
 * and sleeps for some random amount of time. Adjust the sleeping duration of the processes to have different outputs 
 * (i.e. another interleaving of processes’traces).
 */

#include <stdio.h>
#include <unistd.h> //for fork
#include <sys/wait.h> //for wait 
#include <stdlib.h>

int main()
{
	pid_t pid; //process identification
	int i;
	pid = fork(); //create fork
	if (pid < 0) { 
		fprintf(stderr, "Fork Failed"); //fork not created such problem arise 
	    return 1;
	}
	else if (pid == 0) {  
		//first process 
        	for (i = 1; i <= 10; i++){
            	sleep(rand()%5);
		
            	printf("Process Y-ID No.:%d",getpid()); //get the process ID for Y
		printf("-->%d\n",i); //which iteration is now Y process gets
		
            }
            exit(0);
	}
	else { 
		if(fork()==0){
			//2nd process 
			for (i = 1; i <= 10; i++){
                               
			    	printf("Process X-ID No.:%d",getpid());
				printf("-->%d\n",i);
			    	sleep(rand()%5);
				
            			}
            		exit(0);
        }
	wait(NULL);
	wait(NULL);
	printf("Child Complete\n");
	}
	return 0;
}
