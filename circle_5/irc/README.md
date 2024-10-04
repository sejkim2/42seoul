# IRC

Internet Relay Chat or IRC is a text-based communication protocol on the Internet.
> 인터넷 릴레이 챗(IRC)은 인터넷에서 텍스트 기반의 통신 프로토콜입니다.
It offers real-time messaging that can be either public or private. Users can exchange
direct messages and join group channels.
> 실시간 메시징을 제공하며, 이는 공개적일 수도 있고 비공개적일 수도 있습니다. 사용자는 직접 메시지를 교환하고 그룹 채널에 참여할 수 있습니다.

IRC clients connect to IRC servers in order to join channels. IRC servers are connected
together to form a network.
> IRC 클라이언트는 채널에 참여하기 위해 IRC 서버에 연결합니다. IRC 서버는 서로 연결되어 네트워크를 형성합니다.

## General rules

* Your program should not crash in any circumstances (even when it runs out of
memory), and should not quit unexpectedly.
If it happens, your project will be considered non-functional and your grade will be 0.
> 당신의 프로그램은 어떤 상황에서도 크래시가 발생하지 않아야 하며(메모리가 부족할 때도 포함) 예기치 않게 종료되지 않아야 합니다. 만약 그런 일이 발생하면, 당신의 프로젝트는 비기능적으로 간주되며 점수는 0점이 됩니다.

* You have to turn in a Makefile which will compile your source files. It must not
relink.
> 소스 파일을 컴파일할 Makefile을 제출해야 합니다. 재링크는 하지 않아야 합니다.

* Your Makefile must at least contain the rules:
$(NAME), all, clean, fclean and re.
> 당신의 Makefile은 최소한 다음 규칙을 포함해야 합니다: $(NAME), all, clean, fclean 및 re.

* Compile your code with c++ and the flags -Wall -Wextra -Werror
if you add the flag -std=c++98.
> 코드를 c++로 컴파일할 때는 -Wall -Wextra -Werror 플래그를 사용하고, 추가로 -std=c++98 플래그를 넣어야 합니다.

* Try to always develop using the most C++ features you can (for example, choose
<cstring> over <string.h>). You are allowed to use C functions, but always prefer
their C++ versions if possible.
> 가능한 한 C++의 최신 기능을 사용하여 개발하는 것이 좋습니다(예: <string.h> 대신 <cstring> 선택). C 함수를 사용할 수 있지만, 가능하다면 항상 C++ 버전을 선호해야 합니다.

* Any external library and Boost libraries are forbidden.

You have to develop an IRC server in C++ 98.
> 모든 외부 라이브러리와 Boost 라이브러리는 금지되어 있습니다.

You mustn’t develop a client.
> 클라이언트를 개발해서는 안 됩니다.

You mustn’t handle server-to-server communication.
> 서버 간 통신을 처리해서는 안 됩니다.

Your executable will be run as follows: ./ircserv <port> <password>
> 귀하의 실행 파일은 다음과 같이 실행됩니다: ./ircserv <port> <password>

* port: The port number on which your IRC server will be listening to for incoming
IRC connections.
> port: IRC 서버가 들어오는 IRC 연결을 수신 대기할 포트 번호입니다.

* password: The connection password. It will be needed by any IRC client that tries
to connect to your server.
> password: 연결 비밀번호입니다. 이는 서버에 연결을 시도하는 모든 IRC 클라이언트에 필요합니다.

* Even if poll() is mentionned in the subject and the evaluation scale,
you can use any equivalent such as select(), kqueue(), or epoll().
> 주제와 평가 기준에 poll()이 언급되어 있더라도, select(), kqueue() 또는 epoll()과 같은 동등한 함수를 사용할 수 있습니다.

* The server must be capable of handling multiple clients at the same time and never
hang.
> 서버는 여러 클라이언트를 동시에 처리할 수 있어야 하며, 절대 멈추지 않아야 합니다.

* Forking is not allowed. All I/O operations must be non-blocking.
> 포크(fork)는 허용되지 않습니다. 모든 I/O 작업은 논블로킹(non-blocking) 방식이어야 합니다.

* Only 1 poll() (or equivalent) can be used for handling all these operations (read,
write, but also listen, and so forth).
> 모든 작업(읽기, 쓰기, 수신 대기 등)을 처리하기 위해 오직 1개의 poll() (또는 동등한 함수)만 사용할 수 있습니다.

* Because you have to use non-blocking file descriptors, it is
possible to use read/recv or write/send functions with no poll()
(or equivalent), and your server wouldn’t be blocking.
But it would consume more system resources.
Thus, if you try to read/recv or write/send in any file descriptor
without using poll() (or equivalent), your grade will be 0.
> 비차단 파일 설명자를 사용해야 하므로, poll() (또는 동등한 함수) 없이 read/recv 또는 write/send 함수를 사용해도 서버는 블로킹되지 않습니다. 하지만 이 경우 시스템 리소스를 더 많이 소모하게 됩니다. 따라서, poll() (또는 동등한 함수) 없이 어떤 파일 설명자에서 read/recv 또는 write/send를 시도하면 점수는 0점이 됩니다.

* Several IRC clients exist. You have to choose one of them as a reference. Your
reference client will be used during the evaluation process.
> 여러 가지 IRC 클라이언트가 존재합니다. 그중 하나를 기준 클라이언트로 선택해야 하며, 이 기준 클라이언트는 평가 과정에서 사용될 것입니다.

* Your reference client must be able to connect to your server without encountering
any error.
> 귀하의 기준 클라이언트는 오류 없이 귀하의 서버에 연결할 수 있어야 합니다.

* Communication between client and server has to be done via TCP/IP (v4 or v6).
> 클라이언트와 서버 간의 통신은 TCP/IP (v4 또는 v6)를 통해 이루어져야 합니다.

* Using your reference client with your server must be similar to using it with any
official IRC server. However, you only have to implement the following features:
> 귀하의 서버와 기준 클라이언트를 사용하는 것은 공식 IRC 서버와 사용하는 것과 유사해야 합니다. 그러나 다음 기능만 구현하면 됩니다:

* You must be able to authenticate, set a nickname, a username, join a channel,
send and receive private messages using your reference client.
> 귀하의 기준 클라이언트를 사용하여 인증, 닉네임 및 사용자 이름 설정, 채널 참여, 개인 메시지 송수신을 할 수 있어야 합니다.

* All the messages sent from one client to a channel have to be forwarded to
every other client that joined the channel.
> 한 클라이언트가 채널에 보낸 모든 메시지는 해당 채널에 참여한 다른 모든 클라이언트에게 전달되어야 합니다.

* You must have operators and regular users.
> 운영자와 일반 사용자가 있어야 합니다.

* Then, you have to implement the commands that are specific to channel
operators:
> 그런 다음, 채널 운영자에게 특화된 명령어를 구현해야 합니다:

* KICK - Eject a client from the channel
  > KICK - 채널에서 클라이언트를 퇴출합니다.
∗ INVITE - Invite a client to a channel
  > INVITE - 클라이언트를 채널에 초대합니다.
∗ TOPIC - Change or view the channel topic
  > TOPIC - 채널 주제를 변경하거나 조회합니다.
∗ MODE - Change the channel’s mode:
  > MODE - 채널의 모드를 변경합니다:
  * i: Set/remove Invite-only channel
    > i: 초대 전용 채널 설정/제거
  * t: Set/remove the restrictions of the TOPIC command to channel operators
    > t: TOPIC 명령어의 제한을 채널 운영자에게 설정/제거
  * k: Set/remove the channel key (password)
    > k: 채널 키(비밀번호)를 설정/제거합니다.
  * o: Give/take channel operator privilege
    > o: 채널 운영자 권한을 부여/회수합니다.
  * l: Set/remove the user limit to channel
    > l: 채널의 사용자 제한을 설정/제거합니다.
* Of course, you are expected to write a clean code.
  > 물론, 깔끔한 코드를 작성하는 것이 기대됩니다.

## For MacOS only
* Since MacOS doesn’t implement write() the same way as other Unix
OSes, you are allowed to use fcntl().
You must use file descriptors in non-blocking mode in order to get a
behavior similar to the one of other Unix OSes.
> MacOS가 다른 Unix OS와 동일한 방식으로 write()를 구현하지 않기 때문에 fcntl()을 사용할 수 있습니다. 다른 Unix OS와 유사한 동작을 얻기 위해서는 파일 설명자를 논블로킹 모드로 사용해야 합니다.

* However, you are allowed to use fcntl() only as follows:
fcntl(fd, F_SETFL, O_NONBLOCK);
Any other flag is forbidden.
> 하지만 fcntl()은 다음과 같이만 사용할 수 있습니다:  
`fcntl(fd, F_SETFL, O_NONBLOCK);`  
다른 플래그는 금지되어 있습니다.

* Verify absolutely every possible error and issue (receiving partial data, low bandwidth,
and so forth).
To ensure that your server correctly processes everything that you send to it, the
following simple test using nc can be done:
> 모든 가능한 오류와 문제(부분 데이터 수신, 낮은 대역폭 등)를 반드시 확인해야 합니다. 서버가 전송하는 모든 것을 올바르게 처리하는지 확인하기 위해, 다음과 같은 간단한 테스트를 nc를 사용하여 수행할 수 있습니다:

```
\$> nc 127.0.0.1 6667
com^Dman^Dd
\$>
```

* Use ctrl+D to send the command in several parts: ’com’, then ’man’, then ’d\n’.
In order to process a command, you have to first aggregate the received packets in
order to rebuild it.
> ctrl+D를 사용하여 명령을 여러 부분으로 전송합니다: 'com', 그 다음 'man', 그리고 'd\n'입니다. 명령을 처리하기 위해서는 먼저 수신한 패킷을 집계하여 다시 조립해야 합니다.

## Bonus part
Here are the extra features you can add to your IRC server so it looks even more like and
actual IRC server:
> 여기 귀하의 IRC 서버를 실제 IRC 서버와 더 유사하게 만들기 위해 추가할 수 있는 기능들이 있습니다:

* Handle file transfer.
  > 파일 전송을 처리합니다.

* A bot.
  > 봇을 추가합니다.

* The bonus part will only be assessed if the mandatory part is
PERFECT. Perfect means the mandatory part has been integrally done
and works without malfunctioning. If you have not passed ALL the
mandatory requirements, your bonus part will not be evaluated at all.
> 보너스 부분은 필수 부분이 완벽할 때만 평가됩니다. "완벽"이란 필수 부분이 전적으로 완료되어 오류 없이 작동해야 함을 의미합니다. 필수 요구 사항을 모두 통과하지 못한 경우, 보너스 부분은 전혀 평가되지 않습니다.

## Submission and peer-evaluation
Turn in your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don’t hesitate to double check the names of
your files to ensure they are correct.
> 기타 리포지토리에서 과제를 제출하세요. 방어 중에는 리포지토리 내의 작업만 평가됩니다. 파일 이름이 올바른지 꼭 다시 확인하는 것을 잊지 마세요.

You are encouraged to create test programs for your project even though they won’t
be submitted and won’t be graded. Those tests could be especially useful to test
your server during defense, but also your peer’s if you have to evaluate another ft_irc
one day. Indeed, you are free to use whatever tests you need during the evaluation process.
> 프로젝트를 위해 테스트 프로그램을 만드는 것이 권장됩니다. 비록 제출하거나 점수를 받지 않지만, 이러한 테스트는 방어 중 서버를 테스트하는 데 특히 유용할 수 있습니다. 또한, 다른 ft_irc를 평가해야 할 경우에도 도움이 될 수 있습니다. 평가 과정에서 필요한 모든 테스트를 자유롭게 사용할 수 있습니다.

Your reference client will be used during the evaluation process.
> 귀하의 기준 클라이언트는 평가 과정에서 사용될 것입니다.
