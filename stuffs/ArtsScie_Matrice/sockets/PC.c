#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    int i;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    char buffer2[256];

    if(argc < 3)
    {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if(server == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if(connect(sockfd,(struct sockaddr*) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    bzero(buffer,256);
    bzero(buffer2,256);
    while(1)
    {
        system("clear");
        for(i = 0; i < 128; i++)
        {
            buffer[i] = 1;
            buffer[i] %= 10;
        }
        for(i = 0; i < 128; i++)
        {
            printf("%d ",buffer[i]);
            if(not((i+1) % 16))
                printf("\n");
        }

        n = write(sockfd,buffer,strlen(buffer));
        if(n < 0)
            error("ERROR writing to socket");

        n = read(sockfd,buffer2,255);
        if(n < 0)
            error("ERROR reading from socket");
    }

    close(sockfd);
    return 0;
}
