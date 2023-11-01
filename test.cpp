#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

int main(int argc, char const *argv[])
{
   WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) == 0) {
        char host[256];
        if (gethostname(host, sizeof(host) == 0)) {
            struct addrinfo hints, *info, *p;
            memset(&hints, 0, sizeof(hints));
            hints.ai_family = AF_INET; // IPv4
            hints.ai_socktype = SOCK_STREAM;

            if (getaddrinfo(host, NULL, &hints, &info) == 0) {
                for (p = info; p != NULL; p = p->ai_next) {
                    struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
                    char ipstr[INET_ADDRSTRLEN];
                    inet_ntop(p->ai_family, &(ipv4->sin_addr), ipstr, sizeof(ipstr));
                    std::cout << "IPv4 Address: " << ipstr << std::endl;
                }
                freeaddrinfo(info);
            }
        }
        WSACleanup();
    }
    return 0;
}
