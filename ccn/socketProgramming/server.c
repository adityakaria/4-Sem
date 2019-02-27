// Server side
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define SERV_PORT 9040
#define SERV_IP_ADD 127.0.0.1


char * checkIP(char *name) {
    if (!strcmp(name, "www.abcd.com")) {
        char *ip = "0.0.0.0";
        return ip;
    }
    else if (!strcmp(name, "www.abcd.com")) {
        char *ip = "98.139.183.24";
        return ip;
    }
    else if (!strcmp(name, "www.yahoo.com")) {
        char *ip = "12.2.2.3";
        return ip;
    }
    else if (!strcmp(name, "www.apple.com")) {
        char *ip = "64.233.169.99";
        return ip;
    }
    else if (!strcmp(name, "www.google.com")) {
        char *ip = "128.8.237.77";
        return ip;
    }
    else if (!strcmp(name, "www.facebook.com")) {
        char *ip = "31.13.69.160";
        return ip;
    }
    else {
        char *ip = "NOT FOUND";
        return ip;
    }
}

int main(int argc, char *argv[]) {
    while(1) {
    // map<string, string> dnsTablel;

    // dnsTable.insert(make_pair("www.abcd.com", "0.0.0.0"));
    // dnsTable.insert(make_pair("www.yahoo.com", "98.139.183.24"));
    // dnsTable.insert(make_pair("www.apple.com", "12.2.2.3"));
    // dnsTable.insert(make_pair("www.google.com", "64.233.169.99"));
    // dnsTable.insert(make_pair("www.umd.edu", "128.8.237.77"));
    // dnsTable.insert(make_pair("www.komadi.com", "10.1.11.12"));
    // dnsTable.insert(make_pair("www.facebook.com", "31.13.69.160"));

    
    // www.abcd.com 0.0.0.0
    // www.yahoo.com 98.139.183.24
    // www.apple.com 12.2.2.3
    // www.google.com 64.233.169.99
    // www.umd.edu 128.8.237.77
    // www.komadi.com 10.1.11.12
    // www.facebook.com 31.13.69.160 
    // 123.34.5.89

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;

    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    // char *serverMessage = "Winternet is coming.";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( SERV_PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    
        // char *serverMessage = "OK";
        valread = read( new_socket , buffer, 1024); 
        printf("%s\n", buffer);
        
        char * serverMessage = checkIP(buffer);
        // string servMessage = dnsTable.find(buffer);

        send(new_socket, serverMessage, strlen(serverMessage), 0);
        printf(">>Server message sent\n");
    }    
    return 0;
}
