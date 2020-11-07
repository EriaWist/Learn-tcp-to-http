#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<strings.h>
#include<string.h>
#include <signal.h>
#include<pthread.h>
void readMessage(int sock)
{
    int readSize;
    char temp[256];
    while (readSize = read(sock,temp,sizeof(temp))) {
        temp[readSize] = '\0';
        printf("%s\n", temp);
        bzero(temp, sizeof(temp));
    }
}

            
void sendMessage(int sock){
    while (1) {
        int type_num;
        char buf[256];
        bzero(buf, sizeof(buf));
            if(scanf("%[^\n]",buf)!=EOF && strcmp(buf,"quit")!=0) {
                getchar();
                write(sock,buf,sizeof(buf));
            } else {
                printf("EOF\n");
                close(sock);
                exit(1);
            }
    }
   
}


int main(void) {
    struct sockaddr_in server;
    int sock, readSize,type_num,sw;
    char buf[256],temp[256],shake[]="is join 已加入 準備好了";
    char ip[]="127.0.0.1";
    int port = 5678;
    pid_t pid;

    pthread_t sniffer_thread;
    
    bzero(&server,sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);
    sock = socket(PF_INET,SOCK_STREAM,0);
    if(connect(sock,(struct sockaddr*)&server,sizeof(server))!=0)
        return 0;
    
    pthread_create(&sniffer_thread, 0, sendMessage,sock);
    readMessage(sock);
    

    }
