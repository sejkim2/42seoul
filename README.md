# born2beroot

## 운영체제란?  
> 컴퓨터의 자원들을 효율적으로 관리하고, 사용자가 컴퓨터를 효과적으로 사용(생산성이 올라감)하기 위한 환경을 제공하는 프로그램이다. 즉, 컴퓨터와 사용자 간 인터페이스라고 보면 된다. 운영체제가 있기 때문에 사용자는 하드웨어
## 운영체제가 제공하는 기능 : 이러한 공통적인 역할을 운영체제가 수행해줌  
* 자원(프로세스) 관리 및 보호, 스케줄링 ** 여기서 자원이란, cpu 시간, 메모리, 네트워크 대역폭, 저장소 등을 포함한다.
* 컴퓨터와 사용자 간 인터페이스 제공
* 네트워크 관리
* 시스템 오류 검사 및 복구
* 입출력 기능 제공  
## 운영체제를 사용하는 이유  
> 처리능력 향상, 반환시간 단축, 사용 가능도 향상, 신뢰도 향상 등이 있다. 또한 이 네가지 지표는 운영체제 성능 평가의 기준이 된다.  
* 처리능력(Throughput) : 일정 시간 내 시스템이 처리하는 일의 양
* 반환시간(Turn Around Time) : 시스템이 작업을 요구받은 작업을 완료하는데 걸린 시간 (완료 시간 - 의뢰 시간)
* 사용가능도(Availability) : 시스템을 즉시 사용할 수 있는 용량의 양
* 신뢰도(Reaiabilty) : 시스템이 작업을 정확하게 해결하는 정도  
## 리눅스란?  
> 유닉스 계열 무료 오픈소스 os이다. 누구나 소스코드에 대해 실행, 연구, 수정 등이 가능하므로 접근성이 뛰어나고 오류에 대한 업데이트 역시 굉장히 빠르다. 또한 다양한 배포판이 존재하여, 사용자가 본인의 목적에 맞는 버전을 사용 가능하다. (우분투 등) 
## 우분투와 데비안, 유닉스와 리눅스 
> 유닉스 -> 리눅스 -> 데바안 -> 우분투 (리눅스 기반의 데비안 계열 중 하나인 우분투)  
> 유닉스와 호환되는 자유 소프트웨어 운영체제인 GNU/Linux의 다양한 배포판(데비안, 페도라, 센트os 등) 중 데비안 계열의 우분투  
> 데비안은 안정성이 뛰어나며 리눅스 개발의 리더로 앞서나가고 있다. 패키지 관리 시스템이나 재설치 대신 소프트웨어 업그레이드가 가능하게 지원해주는 기술 등이 데비안에서 처음 보여졌다. 패키지 관리 시스템(APT)은 관리자가 운영 체제 전체를 제어하는 역할을 하는 기술로, 의존성 문제를 해결해주는 훌륭한 기능을 선보인다. (의존성 문제란, 의존 관계에 있는 소프트웨어가 필요로 하는 버전이 맞지 않아 정상적인 설치가 어려운 경우를 말한다.)
> 우분투는 다른 리눅스 배포판에 비해 사용 및 유지가 편해서 널리 사용된다. 보통 유닉스 기반이 아닌 윈도우 os에서 리눅스를 사용하기 위해 사용됨.  
> 맥 os는 유닉스 계열의 Darwin이라는 운영체제를 선택하고 있기 때문에 별도의 리눅스 커널 설치가 필요 없음.
## 가상머신이란?  
> https://www.vmware.com/kr/topics/glossary/content/virtual-machine.html (출처)  
> VM(Virtual Machine)이라고 불리며, 컴퓨터 환경이 하나의 호스트라면, 그 안에 있는 여러 게스트 중 하나이며, 호스트가 가지는 물리적 컴퓨터의 성격과 동일한 기능을 제공하는 소프트웨어 컴퓨터이다. 에뮬레이터와 비슷하다고 볼 수 있는데, 호스트가 에뮬레이터를 물리적으로 다른 장치라고 (실제로는 소프트웨어 장치지만) 믿는 것처럼 가상 머신 또한 호스트가 게스트를 물리적 컴퓨터라고 믿게 된다. 가상 머신은 시스템 가상 머신과 프로세스 가상 머신으로 나눌 수 있는데, 각각은 완전한 운영체제 혹은 단일 프로그램(프로세스)를 제공한다.  
## 하이퍼바이저란?  
> VMM(Virtual Machine Monitor)라고 불리며, 가상 머신을 생성 및 구동하는데 사용되는 소프트웨어이다.  
## apt 와 aptitude의 차이란?  
> ??  
## SElinux란?  
> ??  
## AppArmor란?  
> ??  
## 도메인 네임이란?  
> 컴퓨터가 식별하는 ip주소를 인간 친화적인 이름으로 바꾼 것.(www.naver.com에서 naver나 com 같은 것들) DNS를 통해 다시 컴퓨터에게 전달된다. 
## ufw 방화벽이란?  
> 우선 방화벽이란 네트워크 보안 시스템을 말한다. iptables라는 프로그램이 있지만 복잡해서 상대적으로 간단한 ufw 방화벽이 나오게 되었다. ufw 방화벽은 서버 잠금 방지를 위해 비활성화 되어 있으며 활성화 여부는 sudo ufw status 명령을 통해 확인할 수 있다. 기본적으로 ufw 방화벽은 외부에서 들어오는 모든 연결을 차단하고, 서버에서 외부로의 연결만 허용한다. (방화벽의 아웃바인딩 연결 허용) 즉, 사용자가 포트를 연결해주지 않는 이상 외부의 연결이 불가능하다.  
## ssh 연결이란?  
> https://baked-corn.tistory.com/52 (출처)  
> secure shell protocol의 약자로 외부 연결망과 안전하게 통신하기 위해 사용되는 프로토콜이다. 통신에 사용되는 일반적인 프로토콜에 비해 보안적으로 우수하다. ssh로 통신을 할 경우 public key(공개키)와 private key(개인키) 두 종류의 key가 주어지며, public key로 정보를 암호화 하고 private key로 암호화 되어 있는 정보를 복호화 할 수 있다. 복호화 한다는 것은 곧 통신으로 받은 정보를 열람하겠다는 의미이므로 이것에 사용되는 private key는 함부로 노출되어서는 안된다. 따라서 private key는 로컬 장소에 안전하게 내장되어 있다. 클라이언트에서 보낸 public key는 서버의 pricate key와 한 쌍을 이루어 암호화 된 채널을 생성하고 이 채널을 통해 안전한 통신이 가능하다.  
# LVM이란?  
>  (https://user-images.githubusercontent.com/128696540/235417825-2613f4c0-f0c7-43b9-b651-6039244bacc2.png)

## 명령어 정리  
* sudo ufw status : 방화벽 활성화 여부 확인  
* sudo ufw status numbered : 연결된 목록 숫자로 확인  
* sudo ufw delete n : 연결 포트 삭제  
* sudo ufw allow OpenSSH : 방화벽 사용 이전에 수신 SSH 연결 허용  
* sudo ufw allow 4242/tcp : 4242포트 연결 허용  
* sudo ufw enable / disalbe : 방화벽 활성화 / 비활성화  
* su : sudo로 사용자 전환  
* chage -l 계정명 : 패스워드 만기 정보일 출력  
* https://tragramming.tistory.com/87 : 패스워드 만기일 관련 명령어 출처  
* https://nostressdev.tistory.com/9 : 패스워드 설정 관련 명령어 출처  
* sudo groupadd \<groupname> : \<groupname> 이라는 그룹 생성  
* sudo usermod -aG \<groupname> \<username> : \<username> 을 \<groupname>에 추가. 
* groups \<username> : \<username>이 속해있는 그룹
