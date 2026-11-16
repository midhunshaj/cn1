#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main() {

int sock;
struct sockaddr_in server_addr;
char buffer[1024]={0};

sock=socket(AF_INET,SOCK_STREAM,0);

server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(8080);
server_addr.sin_addr.s_addr=inet_addr("127.0.0.0");

connect(sock,(struct sockaddr *)&server_addr,sizeof(server_addr));

printf("Enter the message");
fgets(buffer,sizeof(buffer),stdin);
send(sock,buffer,strlen(buffer)+1,0);

recv(sock,buffer,sizeof(buffer),0);
printf("Reply from server:%s",buffer);

close(sock);
return 0;

}
