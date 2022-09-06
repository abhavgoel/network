#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035

int main()
{
    int sockid,newsockid;
    char buffer[4096];
    struct sockaddr_in server_addr;
    sockid=socket(AF_INET,SOCK_STREAM,0);
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=INADDR_ANY;
    server_addr.sin_port=htons(SERV_TCP_PORT);
    bind(sockid,(struct sockaddr*)&server_addr,sizeof(server_addr));

    listen(sockid,5);
    newsockid=accept(sockid,(struct sockaddr*)NULL,NULL);

    while(1)
    {
        
        bzero(buffer,4096);
        recv(newsockid,buffer,4096,0);
        printf("\n echoing back %s",buffer);
        send(newsockid,buffer,4096,0);
        


    }
    close(newsockid);
}