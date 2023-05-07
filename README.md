# born2beroot

## 운영체제  
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
## 리눅스  
> 유닉스 계열 무료 오픈소스 os이다. 누구나 소스코드에 대해 실행, 연구, 수정 등이 가능하므로 접근성이 뛰어나고 오류에 대한 업데이트 역시 굉장히 빠르다. 또한 다양한 배포판이 존재하여, 사용자가 본인의 목적에 맞는 버전을 사용 가능하다. (우분투 등) 
## 우분투와 데비안, 유닉스와 리눅스 
> 유닉스 -> 리눅스 -> 데바안 -> 우분투 (리눅스 기반의 데비안 계열 중 하나인 우분투)  
> 유닉스와 호환되는 자유 소프트웨어 운영체제인 GNU/Linux의 다양한 배포판(데비안, 페도라, 센트os 등) 중 데비안 계열의 우분투  
> 데비안은 안정성이 뛰어나며 리눅스 개발의 리더로 앞서나가고 있다. 패키지 관리 시스템이나 재설치 대신 소프트웨어 업그레이드가 가능하게 지원해주는 기술 등이 데비안에서 처음 보여졌다. 패키지 관리 시스템(APT)은 관리자가 운영 체제 전체를 제어하는 역할을 하는 기술로, 의존성 문제를 해결해주는 훌륭한 기능을 선보인다. (의존성 문제란, 의존 관계에 있는 소프트웨어가 필요로 하는 버전이 맞지 않아 정상적인 설치가 어려운 경우를 말한다.)
> 우분투는 다른 리눅스 배포판에 비해 사용 및 유지가 편해서 널리 사용된다. 보통 유닉스 기반이 아닌 윈도우 os에서 리눅스를 사용하기 위해 사용됨.  
> 맥 os는 유닉스 계열의 Darwin이라는 운영체제를 선택하고 있기 때문에 별도의 리눅스 커널 설치가 필요 없음.
## 가상머신  
> https://www.vmware.com/kr/topics/glossary/content/virtual-machine.html (출처)  
> VM(Virtual Machine)이라고 불리며, 컴퓨터 환경이 하나의 호스트라면, 그 안에 있는 여러 게스트 중 하나이며, 호스트가 가지는 물리적 컴퓨터의 성격과 동일한 기능을 제공하는 소프트웨어 컴퓨터이다. 에뮬레이터와 비슷하다고 볼 수 있는데, 호스트가 에뮬레이터를 물리적으로 다른 장치라고 (실제로는 소프트웨어 장치지만) 믿는 것처럼 가상 머신 또한 호스트가 게스트를 물리적 컴퓨터라고 믿게 된다. 가상 머신은 시스템 가상 머신과 프로세스 가상 머신으로 나눌 수 있는데, 각각은 완전한 운영체제 혹은 단일 프로그램(프로세스)를 제공한다.  
## 하이퍼바이저  
> VMM(Virtual Machine Monitor)라고 불리며, 가상 머신을 생성 및 구동하는데 사용되는 소프트웨어이다.  
## apt 와 aptitude의 차이  
> https://velog.io/@joonpark/aptitude-vs-apt (출처 1)  
> https://ko.linux-console.net/?p=1606#gsc.tab=0 (출처 2)  
> apt는 .deb 패키지 용으로 설계된 소프트웨어 설치 및 제거 프로그램으로 현재는 RPM(레드헷) 패키지와도 호환 가능하다. apt는 cli 기반이며 명령을 호출할 때마다 source.list의 목록에서 종속성을 고려하여 패키지를 설치한다. 새 목록이 추가되거나 시스템이 업데이트 되어도 해당 패키지에 대해 수동적으로 업데이트를 진행하지 않으면 해당 버전을 계속해서 사용 가능하다. (유연성 높음)  
> aptitude는 gui가 추가된 대화형 패키지 관리 도구로 역시 RPM 패키지와도 호환 가능하다. apt는 패키지를 삭제할 때 해당 패키지만 삭제하지만 aptitude는 해당 패키지를 위해서 설치되었던 부속 패키지를 자동으로 삭제해준다. (apt는 수동 삭제 필요) 또한 설치 및 제거 중 종속 충돌이 일어날 때 해결 방법을 제시할 수 있는 똑똑한 관리 프로그램이라 볼 수 있다. 
## SElinux / appArmor  
> https://80000coding.oopy.io/475d966a-4188-4db3-80ad-cb3755a995b6#475d966a-4188-4db3-80ad-cb3755a995b6 (출처 1)  
> https://velog.io/@kdkeiie8/Linux-AppArmor-%EB%A6%AC%EB%88%85%EC%8A%A4-%EC%BB%A4%EB%84%90-%EB%B3%B4%EC%95%88-%EB%AA%A8%EB%93%88 (출처 2)

> 리눅스의 응용 프로그램 보안 시스템이다. 핵심 작동 원리는 프로그램에서 실행할 수 있는 권한을 제한해주는 것으로 MAC을 이용하여 DAC보다 강력한 보안 시스템을 제공한다. appArmor는 설치 후 root user일 때 /etc/apparmor.d/ 파일을 수정하여 보안 규칙을 부여할 수 있다. 파일 수정 후에는 sudo apparmor_parser -r /etc/apparmor.d/profile_name 명령을 통해 appArmor에게 변경 사항을 알린다. 
 
> DAC (임의적 접근 통제)  
* 해당 프로그램이 user 혹은 group의 소유이면 권한을 준다.  
* ls -l 에서 나오는 9bit의 접근 권한(각각 user, group, other)에 따라 권한이 다름.  
* root 권한에 접근이 가능하다면 (sudo 등)임의로 접근이 가능하므로 더 엄격한 보안 체계가 필요함. --> 강제적 접근 통제가 탄생한 배경 
> MAC (강제적 접근 통제)  
* 관리자가 설정한 보안 정책에 따라 권한을 부여하며 appArmor가 해당 보안 정책을 관리하기 때문에 root 권한을 얻는 것만으로는 접근이 불가능하다.(DAC보다 엄격한 통제)
## 도메인 네임  
> 컴퓨터가 식별하는 ip주소를 인간 친화적인 이름으로 바꾼 것.(www.naver.com에서 naver나 com 같은 것들) DNS를 통해 다시 컴퓨터에게 전달된다. 
## ufw 방화벽  
> 우선 방화벽이란 네트워크 보안 시스템을 말한다. iptables라는 프로그램이 있지만 복잡해서 상대적으로 간단한 ufw 방화벽이 나오게 되었다. ufw 방화벽은 서버 잠금 방지를 위해 비활성화 되어 있으며 활성화 여부는 sudo ufw status 명령을 통해 확인할 수 있다. 기본적으로 ufw 방화벽은 외부에서 들어오는 모든 연결을 차단하고, 서버에서 외부로의 연결만 허용한다. (방화벽의 아웃바인딩 연결 허용) 즉, 사용자가 포트를 연결해주지 않는 이상 외부의 연결이 불가능하다.  
## ssh 연결  
> https://baked-corn.tistory.com/52 (출처)  
> secure shell protocol의 약자로 외부 연결망과 안전하게 통신하기 위해 사용되는 프로토콜이다. 통신에 사용되는 일반적인 프로토콜에 비해 보안적으로 우수하다. ssh로 통신을 할 경우 public key(공개키)와 private key(개인키) 두 종류의 key가 주어지며, public key로 정보를 암호화 하고 private key로 암호화 되어 있는 정보를 복호화 할 수 있다. 복호화 한다는 것은 곧 통신으로 받은 정보를 열람하겠다는 의미이므로 이것에 사용되는 private key는 함부로 노출되어서는 안된다. 따라서 private key는 로컬 장소에 안전하게 내장되어 있다. 클라이언트에서 보낸 public key는 서버의 pricate key와 한 쌍을 이루어 암호화 된 채널을 생성하고 이 채널을 통해 안전한 통신이 가능하다.  
## LVM  
> https://eunbin00.tistory.com/105 (출처)  
>  ![download](https://user-images.githubusercontent.com/128696540/235417904-d202b6bd-2e2b-4337-ac65-98908db0baaf.png)  
>  기존 운영체제의 파일 읽기 쓰기 방식은 물리적 디스크에 직접 접근하여 기록하는 방식이었다. 유연성을 위해서 채택된 lvm 방식에서는 파일 시스템이 lvm 위의 가상 블록 장치에서 읽기 및 쓰기를 수행한다. 물리적 디스크에서는 여러 파티션으로 분할하여 시스템 성능 향상 및 유지 보수를 얻을 수 있다. 이러한 방식은 디스크 용량이 부족할 경우 새 디스크를 추가해야 하며 정보 저장에 대한 유연성이 떨어진다. lvm을 사용한다면 디스크를 추가할 때 특정 저장 공간에 대한 볼륨 사이즈만 키워주면 독립적인 파티션이 연결되어 유연하게 정보를 저장할 수 있다. 효율적인 파티션 공간 활용이 가능해진 것이다.  
* pv : 물리 볼륭, /dev/sda5 같은 실제 파티션  
* vg : 볼륨 그룹, 여러 물리 볼륨이 묶여있는 그룹
* lv : 논리 볼륭, 볼륨 그룹을 파티션을 나눌 때 각각의 파티션
* pe : 물리 볼륨이 가진 일정 블록
* le : 논리 볼륨이 가진 일정 블록  
## sudo 와 root 
> root로 로그인 하는 것은 보안상 좋지 않기 때문에 sudo 명령을 통해 임시로 root 권한을 빌릴 수 있음. sudo 사용자는 log에 기록이 남는다.  
## sudo 설정하기  
1. apt-get install sudo : sudo 설치  
2. visudo : sudo 정보 수정  
<img width="1296" alt="Screen Shot 2023-05-07 at 1 19 42 PM" src="https://user-images.githubusercontent.com/128696540/236657413-338bce3d-bc4a-4b15-9a5f-e0d3c3c009be.png">

  
* env_reset : 특정 환경변수를 제외한 모든 환경변수 초기화(보안상의 이유)  
* mail_badpass : 패스워드 오류 시 지정된 이메일로 오류 보고  
* passwd_tries=n : 패스워드 오류 회수 제한  
* badpass_message : 패스워드 오류 시 메시지 출력. 
* log_input, log_output : sudo를 통한 입출력 기록    
* iolog_dir=path : sudo 명령 사용 기록을 해당 경로의 파일에 저장  
* requiretty : tty 적용 (tty를 적용하여 현재 로그인 사용자의 세션과 터미널이 연결되어 있을 때만 sudo 명령을 사용 가능하게 함)  
* secure_path : 해당 경로에 저장되어 있는 명령어들만 sudo로 명령 가능하게 제한  
* alias specification : 복잡한 이름에 대해 별칭 지정  
* user privilege specification : 사용자나 그룹에 대한 권한 수정.  
 user    host=(runas) command  
 위의 형식에서 user는 권한을 부여할 사용자의 이름이고, host는 해당 사용자가 권한을 사용할 수 있는 호스트 머신의 이름이다. runas는 해  당 사용자가 명령을 실행할 때 사용할 수 있는 다른 사용자의 이름(예를 들어 root라면 root의 권한을 빌릴 수 있음)이다. command는 해당 사용자가 실행할 수 있는 명령어이다.  
 user     ALL=(ALL:ALL) ALL  
 위 형식은 모든 호스트에서 어떤 사용자든지 어떤 명령어든지 실행할 수 있는 권한을 부여한다. 이 권한은 시스템 관리자가 시스템을 관리하거나 유지보수할 때 유용하다.  
* Allow members of group sudo to execute any command : sudo 그룹에서의 privilege specification 형식  
## 명령어 정리  
* sudo ufw status : 방화벽 활성화 여부 확인  
* sudo ufw status numbered : 연결된 목록 숫자로 확인  
* sudo ufw delete n : 연결 포트 삭제  
* sudo ufw allow OpenSSH : 방화벽 사용 이전에 수신 SSH 연결 허용  
* sudo ufw allow 4242/tcp : 4242포트 연결 허용  
* sudo ufw enable / disalbe : 방화벽 활성화 / 비활성화  
* su : sudo로 사용자 전환  
* hostnamectl set-hostname [hostname] : hostname 변경
* chage -l 계정명 : 패스워드 만기 정보일 출력  
* https://tragramming.tistory.com/87 : 패스워드 만기일 관련 명령어 출처  
* https://nostressdev.tistory.com/9 : 패스워드 설정 관련 명령어 출처  
* sudo groupadd \<groupname> : \<groupname> 이라는 그룹 생성  
* sudo usermod -aG \<groupname> \<username> : \<username> 을 \<groupname>에 추가. 
* groups \<username> : \<username>이 속해있는 그룹

##주요 설치  
* appArmor  
  * app install apparmor : apparmor 설치  
  * aa-status : apparmor 설치 유무 확인
* sudo 설치 및 설정  
  * sudo 설치
  * 비밀 번호 3회 시도  
  * 메시지 출력  
  * 로그 기록  
  * tty  
  * 경로 설정  
* 패스워드 설정  
  * sudo vi /etc/login.defs : 전체적인 패스워드 정책 관리
  * PASS_MAX_DAYS : 패스워드를 사용 가능한 최대 날짜
  * PASS_MIN_DAYS : 패스워드 수정 가능하기까지 최소 날짜
  * PASS_WARN_AGE : 패스워드를 수정하라는 경고 메시지를 보내주는 기한
  * sudo apt install libpam-pwquality : 더 엄격한 정책을 위해 추가 패키지 설치
  * sudo vi /etc/pam.d/common-passwd
  * 이후 패스워드 추가 설정   : https://nostressdev.tistory.com/9 참고
  * 패스워드 설정 이전에 생성된 계정인 root와 기존 user에 대한 적용 필요  
  * passwd -e <username> : 강제 만료 명령  
  * chage -m 2 -M 30 -W 7 <username>. 
  * sudo vi /etc/shadow로 확인 가능  
* ufw 설정  
  * sudo apt-get update
  * sudo apt-get upgrade  
  * sudo apt-get install ufw
  * ufw 설치
  * sudo ufw enable/disalbe : 활성화/비활성화  
  * sudo ufw status : ufw 활성화 확인  
  * sudo ufw allow/deny <portnumber> : 포트 접속/차단  
  * sudo ufw delete deny <portname> : ufw 룰 삭제
  * 22 : ssh 포트
* ssh 설정
  * sudo apt-get install openssh-server : openssh 설치  
  * ssh-keygen rsa : key 생성  
  * id_rsa 경로로 확인  
* 스크립트 작성  
printf "#Disk Usage: "
df -a -BM | grep /dev/map | awk '{sum+=$3}END{print sum}' | tr -d '\n'
printf "/"
df -a -BM | grep /dev/map | awk '{sum+=$4}END{print sum}' | tr -d '\n'
printf "MB ("
df -a -BM | grep /dev/map | awk '{sum1+=$3 ; sum2+=$4 }END{printf "%d", sum1 / sum2 * 100}' | tr -d '\n'
printf "%%)\n"

printf "#CPU load: "
mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'
  
  * chmod +x <script name.sh>. 
  * crontab -e. 
  * */10 * * * * /root/filename.sh | wall
