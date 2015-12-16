#include "SocketHeader.h"

int main(void)
{
  struct sockaddr_in server, local;
  int s;
  int rc;
  int server_size;
  char buf[1];

  s = socket(AF_INET, SOCK_DGRAM, 0);
  if(s < 0) print_error("socket");

  local.sin_family = AF_INET;
  local.sin_addr.s_addr = htonl(INADDR_ANY);
  local.sin_port = htons(0);

  rc = bind(s, (struct sockaddr*)&local, sizeof(local));
  if(rc < 0) print_error("bind");

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_port = htons(12345);
  server_size = sizeof(server);

  rc = sendto(s, "1", 1, 0, (struct sockaddr*)&server, server_size);
  if(rc <= 0) print_error("sendto");

  rc = recvfrom(s, buf, 1, 0, (struct sockaddr*)&server, &server_size);
  if(rc <= 0) print_error("recvfrom");
  
  printf("%c\n",buf[0]);
  return 0;
}
