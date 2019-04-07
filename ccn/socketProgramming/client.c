// Client side
#include <unistd.h>
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 

#define SERV_PORT 9040
#define SERV_IP_ADD "127.0.0.1"

int main(int argc, char const *argv[])
{
    while(1) {
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    // char *clientMessage = "The client sends his regards";
    char buffer[1024] = {0};

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("ERROR: Socket could not be created.\n");
        return -1;
    }
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);

    if(inet_pton(AF_INET, SERV_IP_ADD, &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported.\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    
        printf("Client: Please enter your message:  \t");
        char *clientMessage;
        scanf("%s", clientMessage);
        send(sock , clientMessage , strlen(clientMessage) , 0 ); 
        printf(">>Client message sent\n"); 
        valread = read( sock , buffer, 1024); 
        printf("%s\n",buffer );
    }

    return 0;
}
