#include <cstring>
#include <ctime>
#include <exception>
#include <iostream>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

int main() {
  int cliSocket = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in cliAddr;
  cliAddr.sin_addr.s_addr = INADDR_ANY;
  cliAddr.sin_port = htons(8080);
  cliAddr.sin_family = AF_INET;

  connect(cliSocket, (struct sockaddr *)&cliAddr, sizeof(cliAddr));

  char buf[1024] = {0};
  bool showSrv = true;

  while (true) {
    std::string uinput = "";
    std::cout << "Message: ";
    std::getline(std::cin, uinput);

    if (uinput == "/exit") {
      close(cliSocket);
      break;
    }

    if (uinput == "/server") {
      showSrv = !showSrv;
    }

    if (uinput == "/time") {
      time_t timestamp;
      time(&timestamp);
      std::cout << "Current time: " << ctime(&timestamp);
    }

    if (uinput == "/help") {
      std::vector<std::string> comList = {
          "/time - Display timestamp.",
          "/server - Toggle server response messages.",
          "/exit - Close connection & exit.", "/help - Show this message."};
      for (const auto &com : comList) {
        std::cout << com << "\n";
      }
    }

    send(cliSocket, uinput.c_str(), strlen(uinput.c_str()), 0);

    int srvRes = recv(cliSocket, buf, sizeof(buf), 0);
    buf[srvRes] = '\0';
    if (showSrv)
      std::cout << "Server: " << buf << "\n";
  }

  close(cliSocket);
}
