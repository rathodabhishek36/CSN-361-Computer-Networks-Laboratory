// Abhishek Rathod
// Enrollment No.- 17114004

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
  
// Driver code 
int main() {

    int pid_child1, pid_child2; 
  
    pid_child1 = fork(); 
  
    // If fork() returns zero then it means child process is being executed. 
    if (pid_child1 == 0) { 
        printf("1 child has pid=%d and parent process has pid=%d\n", getpid(), getppid()); 
        sleep(3);
        int gpid1=fork();
        if(gpid1==0){
            printf("1 grand-child has pid=%d and parent process has pid=%d\n", getpid(), getppid());
        }
        else{
            int gpid2=fork(); 
            if(gpid2==0){
                printf("2 grand-child has pid=%d and parent process has pid=%d\n", getpid(), getppid());
            }
        }
    } 
    else { 
        // The root parent process continues here.
        pid_child2 = fork(); 
        if (pid_child2 == 0) { 
            sleep(1); 
            printf("2 child has pid=%d and parent process has pid=%d\n", getpid(), getppid()); 
            sleep(4);
            int gpid1=fork();
            if(gpid1==0){
                printf("3 grand-child has pid=%d and parent process has pid=%d\n", 
                getpid(), getppid());
            }
        else {
            int gpid2=fork(); 
            if(gpid2==0){
                printf("4 grand-child has pid=%d and parent process has pid=%d\n", getpid(), getppid());
            }
        }
          
        } 
        // return value of from fork()>0 for parent process.
        else { 
            sleep(8); // has to be printed in the last.
            printf("root parent has pid=%d\n", getpid()); 
        } 
    } 
  
    return 0; 
}
