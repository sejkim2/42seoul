# 42cursus

* 데비안과 로키의 차이점
  * 둘 다 리눅스 배포판이지만 로키는 centos의 후속작으로 데비안보다 퍼포먼스가 뛰어나지만 전문가가 아니면 다루기가 어렵다. 지속적 업데이트가 특징이다. 
  * 데비안은 수많은 사용자가 존재하며 높은 개방성으로 접근성이 높다. 점진적 업데이트가 특징이다.
* 운영체제란
  * 사용자와 하드웨어 간 인터페이스로, 사용자가 컴퓨터의 작동 원리를 모르더라도 이용하는데 불편함이 없게 해주기 때문에 개발 생산성 발전에 기여한다.
* 가상 머신을 사용하는 이유
  * 서로 다른 운영체제를 운영하기 위해 별도의 하드웨어를 구매할 필요 없이 하나의 기기에서 여러 체제를 시험해 볼 수 있어 비용과 시간 면에서 큰 장점을 얻는다.
  * 호스트에서 작동되는 가상 운영체제는 게스트라 불리는데 게스트가 일반적인 방법으로는 호스트에 접근할 수 없기 때문에 안전성이 보장된다.
* 하이퍼바이저
  * 가상 머신을 생성 및 구동하기 위해 사용되는 인터페이스이다. 호스트와 게스트 간 연결을 도와주며 호스트의 자원의 일부를 이용해 게스트가 필요한 만큼의 자원을 할당해준다.
  * 실행되는 위치에 따라 타입 1과 타입 2로 나뉘는데 타입 1은 호스트의 하드웨어에서 직접 실행되기 때문에 리소스 할당 과정이 필요없어 오버헤드가 적다. 
  * 타입 2는 호스트의 운영체제에서 실행되며 Vitual box가 이에 해당된다. 
* AppArmor
  * 애플리케이션 보안 프로그램으로 접근 권한과 관련한 보안 정책을 강화해준다.
  * 기존 접근 권한은 DAC 체계가 있는데 sudo 등을 이용해 이 권한을 수정할 수 있기 때문에 DAC 정책이 나왔다.
  * 접근 권한을 충족해도 appArmor에서 추가로 권한 정책을 관리하기 때문에 엄격한 통제가 가능하다.
  * aa-status : 활성화 여부 확인
* lvm과 파티션  
  * lvm은 물리적 공간을 논리적으로 다시 분할하는 역할을 한다. 이를 통해 파티션 관리가 유연해진다.  
  * 파티션 : 1~4까지는 주 파티션으로 할당 가능하며 그 이후부터는 확장 파티션이 된다. 주 파티션은 실제 하드 공간에 직접 할당되며 확장 파티션은 여러개의 논리 파티션으로 다시 분할 가능하며 공간의 가변에 따라 유연하게 바뀔 수 있다.  
  * lsblk : 파티션 영역 확인
* apt와 aptitiue
  * 둘 다 패키지 관리 소프트웨어 
* ssh 프로토콜
  * systemctl status ssh : ssh 연결 여부 확인
  * vim /etc/ssh/sshd_config : 기존 포트를 4242로 수정
  * ssh username@hostIp -p portnum
* ufw
  * ufw status : ufw 활성화 여부 확인
  * ufw allow portnum : 포트 허용
  * ufw deny portnum : 포트 차단
  * ufw delete deny portnum : 포트 룰 삭제
* hostname 수정
  * hostnamectl set-hostname [hostname] : hostname 변경
* 패스워드 정책
  * vim /etc/login.defs : 수정 날짜 등과 관련된 정책 수정
  * https://tragramming.tistory.com/87 출처) : 정책 수정 이전의 계정에 대한 수정
  * vim /etc/pam.d/common-password : 엄격한 패스워드 정책 관리를 위해 사용하는 패키지
* sudo 정책
  * visudo : sudo 정책 확인
* 유저 추가 및 그룹 추가
  * adduser [username] : 새 유저 추가
  * cat /etc/passwd : 존재하는 유저 목록 보기 (사용자 계정 정보를 보는 파일)
  * deluser [username] : 유저 삭제
  * groupadd [groupname] : 새 그룹 추가
  * usermod -aG [groupname] [username] : 그룹에 유저 추가
  * cat /etc/group : 존재하는 그룹 목록 보기
* tty
  * 터미널로 직접 접속한 상태
* 쉘 스크립트와 cron
  * service crontab start/stop : 크론 탭 활성화 / 비활성화
  * systemctl enable cron
  * systemctl disable cron
  * systemctl is-enabled cron
* bonus 파트 : lighttpd, Mariadb, php, phpmyadmin 
  * lighttpd : 경량 서버용 프로그램, 여러 환경에서 돌아가는 아피치에 비해 운용에 부담이 적으며 프록시를 지원하므로 캐싱을 활용한 효율적인 네트워킹 가능
  * sudo systemctl stop/start/enable lighttpd.service :  중지/시작/활성화
  * mariadb : mysql 기반의 데이터 베이스이며 성능, 보안, 접근성 면에서 개선되었다.
  * sudo mysql -u root -p : db 관리
  * php : 서버 개발 용 스크립트 언어로, 웹 페이지를 동적으로 만들 때 역시 사용된다. 높은 이식성과 빠른 속도가 장점이며 db와의 연동도 자유롭다.
  * sudo lighttpd-enable-mod fastcgi/fastcgi-php
  * service lighttpd force-reload
  * sudo systemctl stop/start/enable mysql.service : 중지/시작/활성화
  * sudo systemctl restart mysql.service
  * wordpress : 웹 페이지 제작 홈페이지
  * 추가 서비스는 phpMyAdmin을 설치하였고 db를 gui로 쉽게 관리해준다. 
  * 10.12.9.7://8080/phpmyadmin으로 접속
