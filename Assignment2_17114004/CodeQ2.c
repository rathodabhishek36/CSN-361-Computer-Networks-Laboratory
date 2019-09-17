
/**
* @file CodeQ2.c
* @brief This file contains the code to show that one process is running as zombie 
* and another process is running as orphan process.
*
* @author Abhishek Rathod (17114004)
*
* @date 31/07/2019
*/

#include <stdlib.h> 
#include <unistd.h> 
#include <stdio.h> 
int main() { 

	int x; 
	x = fork(); 

	if (x > 0) {
		printf("IN PARENT PROCESS\nCURRENT PROCESS ID : %d\n", getpid()); 
	}
	else if (x == 0) { 
		sleep(3); 
		x = fork(); 

		if (x > 0) { 
			printf("IN CHILD PROCESS\nCURRENT PROCESS ID :%d\nPARENT PROCESS ID : %d\n", getpid(), getppid()); 

			while(1){ 
				sleep(1); 
			}
			printf("IN CHILD PROCESS\nPARENT PROCESS ID : %d\n", getppid()); 
		} 

		else if (x == 0) {
			sleep(2) ;
			printf("IN GRANDCHILD PROCESS\nCURRENT PROCESS ID :%d\nPARENT PROCESS ID : %d\n",getpid(), getppid()); 
		}
	} 

	return 0; 
} 
