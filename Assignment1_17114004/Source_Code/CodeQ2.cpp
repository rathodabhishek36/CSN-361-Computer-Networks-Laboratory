// Abhishek Rathod
// Enrollment No.- 17114004

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <net/if.h>
#include <unistd.h>

using namespace std;


int main() {

	char mac[32]={0};

	int fd;
	struct ifreq ifr;
	const char *iface = "eno1"; // for ethernet 
	char *mac_temp;
	
	fd = socket(AF_INET, SOCK_DGRAM, 0);

	ifr.ifr_addr.sa_family = AF_INET;
	strncpy((char *)ifr.ifr_name , (const char *)iface , IFNAMSIZ-1);

	ioctl(fd, SIOCGIFHWADDR, &ifr);

	close(fd);
	
	mac_temp = (char *)ifr.ifr_hwaddr.sa_data;
	
	//display mac address
	sprintf((char *)mac,(const char *)"%.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n" , mac_temp[0], mac_temp[1], mac_temp[2], 
																			mac_temp[3], mac_temp[4], mac_temp[5]) ;

	cout<<"Mac Address : "<<mac<<endl ;

	return 0;
}
