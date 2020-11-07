#include <pthread.h>        // 引用 pthread 函式庫 負責線程
#include <unistd.h>         //負責sleep()

#include <stdlib.h>         //基本的Libraries
#include <stdio.h>          //基本io
#include <string.h>         //字串處理以及bzero清空

//#include <sys/types.h>
//#include <sys/socket.h>
#include <netinet/in.h>   //sockaddr_in會用到\ /*<netinet/in.h>在<arpa/inet.h>有被include所以不加也沒差*/
#include <arpa/inet.h>    //inet_addr用到

int a=0;
void *print_message(void *argu) {    // 印出一次 訊息
    char buf[1024]={0};
    int recvSize;//存回傳資料大小
    int client_scokfd = *(int *)argu;//將無狀態資料轉成整數
    while (1) {
        recvSize=recv(client_scokfd, buf, sizeof(buf), 0);
        buf[recvSize]='\0';
        printf("%s\n",buf);
        printf("---------------------\n");
        printf("資料內容\n");
        printf("資料大小 : %d\n",recvSize);
        printf("來源client_sockfd : %d\n",client_scokfd);
        printf("---------------------\n");
    }
    return NULL;
}

void *print_mary(void *argu) {     // 每隔一秒鐘印出一次 Mary 的函數
    while (1) {
        printf("Mary\n");
        scanf("%d",&a);
        
    }
    return NULL;
}

int main() {     // 主程式開始
    pthread_t message_thread;     // 宣告執行緒
    
    struct sockaddr_in server,client;//存一些socket資料

    /*
     程式設計師不應操作sockaddr，sockaddr是給作業系統用的
     程式設計師應使用sockaddr_in來表示地址，sockaddr_in區分了地址和埠，使用更方便。
    */
    
    int sockfd;//存socket table第幾個位置(數字)
    
    bzero(&server,sizeof(server));//把sockaddr_in的server清空
    //要用到<string.h>
    
    //設定ip地址,port
    server.sin_family = AF_INET;//AF是設定addr所以是AF不是PF 但其實沒差
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(5678);
    //設定ip地址,port
    sockfd = socket(PF_INET,SOCK_STREAM,0);
    /*
    domain為位址家族(PF_INET)
    type指定通訊的方式(例如 TCP(SOCK_STREAM) 或是
    UDP(SOCK_DGRAM))
    protocol通為通訊代碼，通常設0，可以直接根據type自動設定。SOCK_STREAM 且系列为 AF_INET ，則協議自動為TCP
    ex:tcp 用 IPPROTO_TCP  6
    */
    bind(sockfd,(struct sockaddr*)&server,sizeof(server));//綁定sockfd和設定sockaddr_in server
    listen(sockfd,5);//告訴系統設定好了 以及做大連線數量
    int addrlen=sizeof(client);//取得sockaddr_in大小
    int client_scokfd;//存新連線fd
    while (client_scokfd=accept(sockfd,(struct sockaddr_in*) &client, &addrlen)) {
        pthread_create(&message_thread, NULL, &print_message, (void *)&client_scokfd);//執行緒 print_george
        /*第一個放pthread_t(存線程狀態資料) */
    }
    return 0;
}
