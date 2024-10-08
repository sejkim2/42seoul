#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

int main(void)
{
    //socket : 소켓 생성
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    //서버에 설정된 ip주소 및 port 번호로 초기화
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6667);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 서버 IP

    //connect : server에서 listen과 accept 사이에 request를 보냄
    //tcp 기반의 3 handshake 수행(1:client->server로 syn 2: server가 수신하고 ack를 client로 보냄 3:client가 수신 후 ack를 server로 보냄)
    connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    std::cout << "Connected to the server!" << '\n';

    while (true)
    {
        std::string input;
        std::cout << "input : ";
        std::getline(std::cin, input);
        if (input == "exit")
            break ;

        send(sock_fd, input.c_str(), input.length(), 0);
    }
    close(sock_fd); // 소켓 닫기
    return 0;
}
