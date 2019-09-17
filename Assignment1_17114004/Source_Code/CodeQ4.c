// Abhishek Rathod
// Enrollment No.- 17114004
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
   
int main() 
{ 
    char hostname[256]; 
    char *IP_address; 
    struct hostent *host_ptr; 
    int check_name; 
  
    // stores hostname in the variable 'hostname' 
    check_name = gethostname(hostname, sizeof(hostname)); 
    
    if (check_name == -1){ 
        printf("Error while retrieving Hostname !!!"); 
        exit(1); 
    } 
  
    // To retrieve host information. 
    // returns pointer to some struct hostent if present or else NULL 
    host_ptr = gethostbyname(hostname); 

    if (host_ptr == NULL){ 
        printf("Error while retrieving Host Information !!!"); 
        exit(1); 
    } 
  
    // To convert an Internet network address into ASCII string 
    IP_address = inet_ntoa(*((struct in_addr*)host_ptr->h_addr_list[0])) ; 

    if (IP_address == NULL){ 
        printf("Error while getting IP address !!!") ; 
        exit(1); 
    } 
  
    printf("Hostname is : %s\n", hostname); 
    printf("Host IP is : %s\n", IP_address); 
  
    return 0; 
}