#include "SocketHeader.h"

int main(void)
{
  struct sockaddr_in local, client;
  int client_size;
  int s;
  int rc;
  char buf[1];

  s = socket(AF_INET, SOCK_DGRAM, 0);
  if(s <0) print_error("socket");

  local.sin_family = AF_INET;
  local.sin_addr.s_addr = htonl(INADDR_ANY);
  local.sin_port = htons(12345);

  rc = bind(s, (struct sockaddr*)&local, sizeof(local));
  if(rc < 0) print_error("bind");

  client_size = sizeof(client);
  rc = recvfrom(s, buf, 1, 0, (struct sockaddr*)&client, &client_size);
  if(rc < 0) print_error("recvfrom");

  printf("%c\n", buf[0]);

  rc = sendto(s, "2", 1, 0, (struct sockaddr*)&client, client_size);
  if(rc < 0) print_error("sendto");

  return 0;
}
