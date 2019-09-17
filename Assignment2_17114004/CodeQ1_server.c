
/**
* @file CodeQ1_server.c
* @brief This file is used for the server side creation of node created using TCP protocol and 
* IPv4 and to send and listen to the messages 
* through the port and also to connect with other client sockets.
*
* @author Abhishek Rathod (17114004)
*
* @date 31/07/2019
*/

#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 

/**
* This is the main method and all the functions used to create, bind the socket and to communicate
* with other sockets are implemented in this method. 
* @author Abhishek Rathod (17114004)
* @param 
* @date 31/09/2019
*/

int main(int argc, char const *argv[]) 
{ 
    /// This is used to store the file descriptors of the socket.
    int server_fd ; 

    /// This will create a new socket for the client when input will be given by client.
    int new_socket ;

    /// This will contain the return value when message will be sent by the client.
    int valread ; 

    /// This will store various socket attributes.
    struct sockaddr_in address;

    int opt = 1; 
    int addrlen = sizeof(address); 
    
    /// This will contian the message that the client has sent.
    char buffer[1024] = {0}; 

    /// This is the message that will be sent to the client.
    char *hello = "Server says : Hello Client !!!"; 
       
    /// Creating socket file descriptor 
    server_fd = socket(AF_INET, SOCK_STREAM, 0) ;
    if (server_fd < 0) { 
        printf("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    /// Assigning various attribute values to the sockaddr_in struct.
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    /// Forcefully binding socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0) { 
        printf("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    /// Waiting for the client to connect
    if (listen(server_fd, 3) < 0) { 
        printf("listen"); 
        exit(EXIT_FAILURE); 
    } 

    /// creating a new socket for the client 
    new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen) ;
    if(new_socket<0) { 
        printf("accept"); 
        exit(EXIT_FAILURE); 
    } 
    /// Reading the value from the client
    valread = read( new_socket , buffer, 1024); 
    printf("%s\n",buffer ); 
    
    /// Sending message to the client.
    send(new_socket , hello , strlen(hello) , 0 ); 
    printf("Hello message sent to the client\n"); 
    
    return 0; 
} 