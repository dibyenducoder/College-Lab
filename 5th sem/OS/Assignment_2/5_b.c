#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAX_SIZE 80
 
int main()
{
    int fd;
    char *myfifo = "/tmp/tmp_fifo"; //file path
    mkfifo(myfifo, 0666); //creating the FIFO with filepath and permission
    pid_t pid;
    pid = fork();
    char caller[MAX_SIZE], receiver[MAX_SIZE];
    if(pid < 0)
        perror("Error creating fork");
    else if(pid > 0){
    while (1) //Caller calls the Reciever 
    {
        fd = open(myfifo, O_WRONLY); //open the FIFO for write only (O_WRONLY)
        printf("%s", "Caller To receiver: ");
        fgets(caller, MAX_SIZE, stdin);
        if((caller[0]=='E') && (caller[1]=='N') && (caller[2]=='D')) {  //when caller "END" the calls
            write(fd, caller, strlen(caller)+1);
            close(fd);
            break;
        }
        write(fd, caller, strlen(caller)+1);
        close(fd);
        fd = open(myfifo, O_RDONLY); //open the FIFO for read only
        read(fd, receiver, sizeof(caller));
        if((receiver[0]=='E') && (receiver[1]=='N') && (receiver[2]=='D')){
            close(fd);
            break;}
        printf("Caller From Receiver : %s\n", receiver); //reciever can read the caller's message 
        close(fd);
    }
}
    else{ //Reciever calls the Caller 

         while (1)
    {
        fd = open(myfifo,O_RDONLY);
        read(fd, receiver, MAX_SIZE);
        if((receiver[0]=='E') && (receiver[1]=='N') && (receiver[2]=='D')){
            close(fd);
            break;}
        printf("Receiver From caller: %s\n", receiver);
        close(fd);
        printf("%s","Receiver To caller: ");
        fd = open(myfifo,O_WRONLY);
        fgets(caller, MAX_SIZE, stdin);
         if((caller[0]=='E') && (caller[1]=='N') && (caller[2]=='D')){
            write(fd, caller, strlen(caller)+1);
            close(fd);
            break;
        }
        write(fd, caller, strlen(caller)+1);
        close(fd);
    }
    exit(0);
}
    wait(NULL);
    return 0;
}
