#include <netinet/in.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include<unistd.h>
extern int h_errno;

void bzero(void *s, size_t n);
int main(int argc, char **argv){
    char c;
    char *hostName = argv[1];
    struct sockaddr_in serverAddress;
    struct hostent *serverInfo = gethostbyname(hostName);
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(3434);
    bcopy((char *)serverInfo->h_addr,
        (char *)&serverAddress.sin_addr.s_addr, serverInfo->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM,0);
    if(connect(sockfd,(struct sockaddr *)&serverAddress,sizeof(serverAddress))<0){
        printf("ERROR\n");
    }

    char *message = "GET / HTTP/1.0\r\n\r\n";
    write(sockfd,message,strlen(message));

    while(read(sockfd,&c,1)){
        printf("%c", &c);
    }
    close(sockfd);
    printf("\n");
    return 0;
}