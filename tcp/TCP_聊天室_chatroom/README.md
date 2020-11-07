# 用TCP寫的聊天室<br />
## 參考資料
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

```把sock (table的位置)和剛剛設定的sockaddr_in綁定

sock 为 socket 文件描述符，addr 为 sockaddr 裝上面宣告sockaddr_in的記憶體位置，addrlen 為 addr 变量的大小，可由 sizeof() 计算得出。

bind(sock,(struct sockaddr*)&server,sizeof(server));```

listen(sock,5);`告訴系統sock(table的位置)可以連線跟最大連線數量` [參考資料](http://stenlyho.blogspot.com/2008/08/socket-listen.html)

```listen()用來通知OS/network socketfd的socket已經可以接受建立連線。參數backlog指定同時能處理的最大連接要求，如果連接數目達此上限則client端將收到ECONNREFUSED的錯誤```
