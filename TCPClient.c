#include "SocketHeader.h"

int main(void)
{
 struct sockaddr_in peer;
 int s;
 int rc;
 char buf[1];

 peer.sin_family = AF_INET;
 peer.sin_port = htons(12345);
 peer.sin_addr.s_addr = inet_addr("127.0.0.1");
 s = socket(AF_INET, SOCK_STREAM, 0);
 if(s<0) print_error("socket");

 rc = connect(s, (struct sockaddr*)&peer,sizeof(peer));
 if(rc) print_error("connect");

 rc = send(s, "1", 1, 0);
 if(rc <= 0) print_error("send");

 rc = recv(s, buf, 1, 0);
 if(rc <= 0) print_error("recv");
 else printf("%c\n", buf[0]);

 return 0;
}
