# 用TCP寫的聊天室<br />
## [參考資料](http://zake7749.github.io/2015/03/17/SocketProgramming/)
sockaddr_in [參考資料](https://codertw.com/%E5%89%8D%E7%AB%AF%E9%96%8B%E7%99%BC/392331/)
```
sockaddr和sockaddr_in包含的資料都是一樣的，但他們在使用上有區別：

程式設計師不應操作sockaddr，sockaddr是給作業系統用的

程式設計師應使用sockaddr_in來表示地址，sockaddr_in區分了地址和埠，使用更方便。
``` 
<br />
socket(int domain, int type, int protocol)<br />

```
    domain為位址家族(PF_INET)
    type指定通訊的方式(例如 TCP(SOCK_STREAM) 或是
    UDP(SOCK_DGRAM))
    protocol通為通訊代碼，通常設0，可以直接根據type自動設定。SOCK_STREAM 且系列为 AF_INET ，則協議自動為TCP
    ex:tcp 用 IPPROTO_TCP  6
```

int bind(int sock, struct sockaddr *addr, socklen_t addrlen);  //Linux [參考資料](http://c.biancheng.net/cpp/html/3033.html)

```
把sockfd (table的位置)和剛剛設定的sockaddr_in綁定

sock 为 sockfd 文件描述符，addr 为 sockaddr 裝上面宣告sockaddr_in的記憶體位置，addrlen 為 addr 变量的大小，可由 sizeof() 计算得出。

bind(sock,(struct sockaddr*)&server,sizeof(server)); 
```

listen(sock,5);`告訴系統sockfd(table的位置)可以連線跟最大連線數量` [參考資料](http://stenlyho.blogspot.com/2008/08/socket-listen.html)

```listen()用來通知OS/network socketfd的socket已經可以接受建立連線。參數backlog指定同時能處理的最大連接要求，如果連接數目達此上限則client端將收到ECONNREFUSED的錯誤```

Socket在港口等了又等，終於有客人拜訪了，我們可以用函式accept()去接見這名客人。當accept()被調用時，它會為該請求產生出一個新的Socket，並把這個請求從監聽隊列剔除掉。

Prototype
int accept(int sockfd, struct sockaddr addr, socklen_t addrlen); [參考資料](http://zake7749.github.io/2015/03/17/SocketProgramming/)
```
Argument
sockfd
毫無反應，就是個socket的描述符

addr
一樣是個描述Socket資訊的結構，不過他是一個空容器，用於儲存接收到的Client端相關資訊，比如port、IP等等。

addrlen
描述的是addr的大小

Return value
它會傳回一個新的Socket描述符，以後和Client端交談的是這個新創出的Socket，如果失敗則傳回-1(INVALID_SOCKET)
```
Example
```
int forClientSockfd;
struct sockaddr_in client_info;
int addrlen = sizeof(client_addr);
forClientSockfd = accept(sockfd,(structsockaddr*) &client_addr, &addrlen);
```
