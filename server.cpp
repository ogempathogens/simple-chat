#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int srvSocket = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in srvAddr;
  srvAddr.sin_addr.s_addr = INADDR_ANY;
  srvAddr.sin_port = htons(8080);
  srvAddr.sin_family = AF_INET;

  bind(srvSocket, (struct sockaddr *)&srvAddr, sizeof(srvAddr));
  listen(srvSocket, 10);
  int clnSocket = accept(srvSocket, nullptr, nullptr);

  char buf[1024] = {0};
  while (true) {
    int bytesRecv = recv(clnSocket, buf, sizeof(buf), 0);

    if (bytesRecv <= 0) {
      std::cout << "CLient disconnected\n";
      break;
    }

    buf[bytesRecv] = '\0';
    std::cout << "Client: " << buf << "\n";

    const char *res = "Message received";
    send(clnSocket, res, strlen(res), 0);
  }

  close(clnSocket);
  close(srvSocket);
}
