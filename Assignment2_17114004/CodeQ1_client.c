
/**
* @file CodeQ1_client.c
* @brief This file is used for the client side creation of node using TCP protocol and 
* IPv4 and to send and recieve 
* messages through the port and also to connect with other client sockets.
*
* @author Abhishek Rathod (17114004)
*
* @date 31/07/2019
*/

#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 

/**
* This is the main method and all the functions used to create socket and to communicate
* with other sockets are implemented in this method. 
* @author Abhishek Rathod (17114004)
* @param 
* @date 31/09/2019
*/

int main(int argc, char const *argv[]) { 

	/// This is used to store the file descriptors of the socket.
	int sock = 0;
	
	/// This will contain the return value when message will be sent by the client.
	int valread; 

    /// This will store various socket attributes.
	struct sockaddr_in serv_addr; 
	
	/// This is the string the will be sent to the server.
	char *hello = "Client says : Hello Server !!!"; 

	/// 
	char buffer[1024] = {0}; 
	
	/// Creating a socket.
	sock = socket(AF_INET, SOCK_STREAM, 0) ;
	if (sock < 0) { 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

    /// Assigning various attribute values to the sockaddr_in struct.
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	

	/// Convert IPv4 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) { 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	/// Connecting with the server socket.
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 

	/// Sending the message to the sever socket.
	send(sock , hello , strlen(hello) , 0 ); 
	printf("Hello message sent to the server.\n"); 
	valread = read( sock , buffer, 1024); 
	printf("%s\n",buffer ); 
	
	return 0; 
} 
