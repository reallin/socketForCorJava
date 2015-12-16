#include "SocketHeader.h"

int main(void)
{
 struct sockaddr_in local;
 int s;
 int s1;
 int rc;
 char buf[1];

 local.sin_family = AF_INET;
 local.sin_port = htons(12345);
 local.sin_addr.s_addr = htonl(INADDR_ANY);

 s = socket(AF_INET, SOCK_STREAM, 0);    
 if(s < 0) print_error("sock");

 rc = bind(s, (struct sockaddr*)&local, sizeof(local));
 if(rc < 0) print_error("bind");

 rc = listen(s,5);
 if(rc < 0) print_error("listen");

 s1 = accept(s, NULL, NULL);
 if(s1 < 0) print_error("accept");

 rc = recv(s1, buf, 1,0);
 if(rc <= 0) print_error("recv");

 printf("%c\n", buf[0]);

 rc = send(s1, "2", 1, 0);
 if(rc <= 0) print_error("send");

 return 0;
}


