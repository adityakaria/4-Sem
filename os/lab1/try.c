#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <stdlib.h> 


int main(int argc, char *argv[]) {
    pid_t pid;
    pid = fork();

    if ( pid<0 ) 
    { 
        printf("failed to create child\n"); 
        exit(0); 
    } 
  
    else if ( pid==0 ) 
    { 
        printf("Child: %d", getpid());
        
        char * argv_list[] = {"ls","-lart","/home",NULL};
        execv("ls",argv_list); 
        
        exit(0); 
    } 
  
    else
    { 
        wait(NULL);
        printf("\nParent: %d", getpid()); 
        printf("\n"); 
    } 
}