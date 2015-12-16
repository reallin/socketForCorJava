#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void print_error(char* error_info)
{
  printf("%s call failed/n", error_info);
  exit(1);
}
