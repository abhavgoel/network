#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035

int main()
{
    int sockid;
    char sendline[4096],recvline[4096];
    struct sockaddr_in server_addr;
    sockid=socket(AF_INET,SOCK_STREAM,0);
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_addr.sin_port=htons(SERV_TCP_PORT);
    connect(sockid,(struct sockaddr*)&server_addr,sizeof(server_addr));

    while(1)
    {
        bzero(sendline,4096);
        bzero(recvline,4096);
        fgets(sendline,4096,stdin);
        send(sockid,sendline,strlen(sendline),0);
        recv(sockid,recvline,4096,0);
        printf("%s",recvline);
    }
}