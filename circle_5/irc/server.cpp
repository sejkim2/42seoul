#include <sys/socket.h> //socket()
#include <netinet/in.h> //struct sockaddr_in
#include <arpa/inet.h>  //inet_addr()
#include <unistd.h> //close()
#include <iostream>

int main(void)
{
    //socket : 생성 및 ip, port 할당
    int serv_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(6667);

    //bind : ip, port binding
    if (bind(serv_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        std::cout << "binding error!" << '\n';
        exit(1);
    }

    // listen : clinet 대기 요청
    if (listen(serv_fd, 5) == -1)
    {
        std::cout << "listen error!" << '\n';
        exit(1);
    }

    std::cout << "Server is listening on port 6667 ...." << '\n';

    while (true)
    {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);

        // accept : client 연결
        int client_fd = accept(serv_fd, (struct sockaddr *)&client_addr, &len);
        if (client_fd < 0)
        {
            std::cout << "accept error!" << '\n';
            continue;
        }

        std::cout << "client connected!" << '\n';

        char buffer[1024] = {0};
        int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);

        //close : 소켓 닫기
        close(client_fd);
    }

    close(serv_fd);
}