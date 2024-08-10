## Inception

# Introduction

* This project aims to broaden your knowledge of system administration by using Docker. You will virtualize several Docker images, creating them in your new personal virtual machine.
> 이 프로젝트는 Docker를 사용하여 시스템 관리에 대한 당신의 지식을 넓히는 것을 목표로 합니다. 당신은 여러 Docker 이미지를 가상화하여, 새 개인 가상 머신에서 그것들을 생성할 것입니다.

# General guidelines
* This project needs to be done on a Virtual Machine.
> 이 프로젝트는 가상 머신에서 수행되어야 합니다.

* All the files required for the configuration of your project must be placed in a srcs folder.
> 프로젝트 구성에 필요한 모든 파일은 srcs 폴더에 배치해야 합니다.

* A Makefile is also required and must be located at the root of your directory. It must set up your entire application (i.e., it has to build the Docker images using docker-compose.yml).
> Makefile도 필요하며, 디렉터리의 루트에 위치해야 합니다. 그것은 전체 애플리케이션을 설정해야 합니다 (즉, docker-compose.yml을 사용하여 Docker 이미지를 빌드해야 합니다).

* This subject requires putting into practice concepts that, depending on your back- ground, you may not have learned yet. Therefore, we advise you not to hesitate to read a lot of documentation related to Docker usage, as well as anything else you will find helpful in order to complete this assignment.
> 이 주제는 당신의 배경에 따라 아직 배우지 않았을 수도 있는 개념들을 실습하는 것을 요구합니다. 따라서 이 과제를 완수하기 위해 도움이 될 만한 Docker 사용 관련 문서와 기타 자료를 많이 읽는 것을 주저하지 마시길 권장합니다.

# Mandatory part

This project consists in having you set up a small infrastructure composed of different services under specific rules. The whole project has to be done in a virtual machine. You have to use docker compose.
> 이 프로젝트는 특정 규칙에 따라 여러 서비스를 포함하는 작은 인프라를 설정하는 것을 포함합니다. 전체 프로젝트는 가상 머신에서 수행되어야 하며, Docker Compose를 사용해야 합니다.

Each Docker image must have the same name as its corresponding service.
Each service has to run in a dedicated container.
> 각 Docker 이미지는 해당 서비스와 동일한 이름을 가져야 합니다. 각 서비스는 전용 컨테이너에서 실행되어야 합니다.

For performance matters, the containers must be built either from the penultimate stable version of Alpine or Debian. The choice is yours.
>성능 문제를 위해, 컨테이너는 Alpine 또는 Debian의 마지막에서 두 번째 안정 버전에서 빌드되어야 합니다. 선택은 당신에게 달려 있습니다.

You also have to write your own Dockerfiles, one per service. The Dockerfiles must be called in your docker-compose.yml by your Makefile.
> 각 서비스마다 하나씩, 자신의 Dockerfile을 작성해야 합니다. Dockerfile은 Makefile을 통해 docker-compose.yml에서 호출되어야 합니다.

It means you have to build yourself the Docker images of your project. It is then for- bidden to pull ready-made Docker images, as well as using services such as DockerHub (Alpine/Debian being excluded from this rule).
> 즉, 프로젝트의 Docker 이미지를 직접 빌드해야 한다는 의미입니다. 따라서 준비된 Docker 이미지를 다운로드하거나 DockerHub와 같은 서비스를 사용하는 것은 금지됩니다 (단, Alpine/Debian은 이 규칙에서 제외됩니다).

You then have to set up:
> 다음으로 설정해야 하는 것은:

* A Docker container that contains NGINX with TLSv1.2 or TLSv1.3 only.
> NGINX가 포함된 Docker 컨테이너로, TLSv1.2 또는 TLSv1.3만을 지원해야 합니다.

* A Docker container that contains WordPress + php-fpm (it must be installed and configured) only without nginx.
> NGINX 없이 WordPress와 php-fpm만 포함된 Docker 컨테이너가 필요합니다 (php-fpm은 설치 및 구성되어야 합니다).

* A Docker container that contains MariaDB only without nginx.
> NGINX 없이 MariaDB만 포함된 Docker 컨테이너가 필요합니다.

* A volume that contains your WordPress database.
> WordPress 데이터베이스를 포함하는 볼륨이 필요합니다.

* A second volume that contains your WordPress website files.
> WordPress 웹사이트 파일을 포함하는 두 번째 볼륨이 필요합니다.

* A docker-network that establishes the connection between your containers.
> 컨테이너들 간의 연결을 설정하는 Docker 네트워크가 필요합니다.

Your containers have to restart in case of a crash.
> 컨테이너가 충돌할 경우 재시작되도록 설정해야 합니다.

* A Docker container is not a virtual machine.  Thus, it is not
recommended to use any hacky patch based on ’tail -f’ and so forth
when trying to run it.  Read about how daemons work and whether it’s
a good idea to use them or not.
> Docker 컨테이너는 가상 머신이 아닙니다. 따라서 실행할 때 `tail -f`와 같은 임시방편적인 패치를 사용하는 것은 권장되지 않습니다. 데몬이 어떻게 작동하는지에 대해 읽어보고, 이를 사용하는 것이 좋은 아이디어인지 여부를 확인하세요.

* Of course, using network:  host or --link or links:  is forbidden.
The network line must be present in your docker-compose.yml file.
Your containers musn’t be started with a command running an infinite
loop.  Thus, this also applies to any command used as entrypoint, or
used in entrypoint scripts. The following are a few prohibited hacky
patches:  tail -f, bash, sleep infinity, while true.
> 물론, `network: host` 또는 `--link` 또는 `links:`의 사용은 금지됩니다. `docker-compose.yml` 파일에 `network` 항목이 반드시 포함되어야 합니다. 컨테이너는 무한 루프를 실행하는 명령어로 시작되어서는 안 됩니다. 따라서, 이 규칙은 entrypoint로 사용되는 모든 명령어나 entrypoint 스크립트에서 사용되는 명령어에도 적용됩니다. 다음은 금지된 임시방편적인 패치 몇 가지입니다: `tail -f`, `bash`, `sleep infinity`, `while true`.

* Read about PID 1 and the best practices for writing Dockerfiles.
> PID 1과 Dockerfile 작성에 대한 모범 사례에 대해 읽어보세요.

* In your WordPress database, there must be two users, one of them being the ad- ministrator. The administrator’s username can’t contain admin/Admin or admin- istrator/Administrator (e.g., admin, administrator, Administrator, admin-123, and so forth).
> WordPress 데이터베이스에는 두 명의 사용자가 있어야 하며, 그 중 하나는 관리자여야 합니다. 관리자의 사용자 이름에는 `admin`/`Admin` 또는 `administrator`/`Administrator`가 포함될 수 없습니다 (예: `admin`, `administrator`, `Administrator`, `admin-123` 등).

* Your volumes will be available in the /home/login/data folder of the
host machine using Docker.  Of course, you have to replace the login
with yours.
> 당신의 볼륨은 Docker를 사용하여 호스트 머신의 `/home/login/data` 폴더에서 사용할 수 있습니다. 물론, `login`을 자신의 사용자 이름으로 대체해야 합니다.

To make things simpler, you have to configure your domain name so it points to your local IP address.
> 문제를 간단하게 만들기 위해, 도메인 이름을 로컬 IP 주소를 가리키도록 설정해야 합니다.

This domain name must be login.42.fr. Again, you have to use your own login.
For example, if your login is wil, wil.42.fr will redirect to the IP address pointing to wil’s website.
> 이 도메인 이름은 `login.42.fr`이어야 하며, 여기서 `login`은 자신의 사용자 이름으로 대체해야 합니다. 예를 들어, 사용자 이름이 `wil`이라면, `wil.42.fr`은 `wil`의 웹사이트를 가리키는 IP 주소로 리디렉션되어야 합니다.

* The latest tag is prohibited.
No password must be present in your Dockerfiles.
It is mandatory to use environment variables.
Also, it is strongly recommended to use a .env file to store
environment variables.  The .env file should be located at the root
of the srcs directory.
Your NGINX container must be the only entrypoint into your
infrastructure via the port 443 only, using the TLSv1.2 or TLSv1.3
protocol.
> 최신 태그(`latest`)의 사용은 금지됩니다. Dockerfile에는 비밀번호가 포함되어서는 안 됩니다. 환경 변수를 사용하는 것이 필수입니다. 환경 변수를 저장하기 위해 `.env` 파일을 사용하는 것이 강력히 권장됩니다. `.env` 파일은 `srcs` 디렉터리의 루트에 위치해야 합니다. NGINX 컨테이너는 TLSv1.2 또는 TLSv1.3 프로토콜을 사용하여 포트 443을 통해서만 인프라에 접근할 수 있는 유일한 엔트리포인트여야 합니다.

Here is an example diagram of the expected result:
> 다음은 기대하는 결과의 예시 다이어그램입니다:

<img width="552" alt="스크린샷 2024-07-23 오후 3 04 02" src="https://github.com/user-attachments/assets/0ef7165f-8ec8-4f92-8039-772321252907">

Below is an example of the expected directory structure:
> 아래는 기대되는 디렉터리 구조의 예시입니다:

```
$> ls -alR
total XX
drwxrwxr-x 3 wil wil 4096 avril 42 20:42 .
drwxrwxrwt 17 wil wil 4096 avril 42 20:42 ..
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 Makefile
drwxrwxr-x 3 wil wil 4096 avril 42 20:42 srcs
./srcs:
total XX
drwxrwxr-x 3 wil wil 4096 avril 42 20:42 .
drwxrwxr-x 3 wil wil 4096 avril 42 20:42 ..
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 docker-compose.yml
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 .env
drwxrwxr-x 5 wil wil 4096 avril 42 20:42 requirements
./srcs/requirements:
total XX
drwxrwxr-x 5 wil wil 4096 avril 42 20:42 .
drwxrwxr-x 3 wil wil 4096 avril 42 20:42 ..
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 bonus
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 mariadb
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 nginx
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 tools
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 wordpress
./srcs/requirements/mariadb:
total XX
drwxrwxr-x 4 wil wil 4096 avril 42 20:45 .
drwxrwxr-x 5 wil wil 4096 avril 42 20:42 ..
drwxrwxr-x 2 wil wil 4096 avril 42 20:42 conf
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 Dockerfile
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 .dockerignore
drwxrwxr-x 2 wil wil 4096 avril 42 20:42 tools
[...]
./srcs/requirements/nginx:
total XX
drwxrwxr-x 4 wil wil 4096 avril 42 20:42 .
drwxrwxr-x 5 wil wil 4096 avril 42 20:42 ..
drwxrwxr-x 2 wil wil 4096 avril 42 20:42 conf
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 Dockerfile
-rw-rw-r-- 1 wil wil XXXX avril 42 20:42 .dockerignore
drwxrwxr-x 2 wil wil 4096 avril 42 20:42 tools
[...]
$> cat srcs/.env
DOMAIN_NAME=wil.42.fr
# certificates
CERTS_=./XXXXXXXXXXXX
# MYSQL SETUP
MYSQL_ROOT_PASSWORD=XXXXXXXXXXXX
MYSQL_USER=XXXXXXXXXXXX
MYSQL_PASSWORD=XXXXXXXXXXXX
[...]
$>
```

* For obvious security reasons, any credentials, API keys, env
variables etc...  must be saved locally in a .env file and ignored by
git.  Publicly stored credentials will lead you directly to a failure
of the project.
> 명백한 보안 이유로, 모든 자격 증명, API 키, 환경 변수 등은 로컬의 `.env` 파일에 저장하고 git에 의해 무시되어야 합니다. 공개적으로 저장된 자격 증명은 프로젝트의 실패로 이어질 수 있습니다.

# Bonus part

For this project, the bonus part is aimed to be simple.
>

A Dockerfile must be written for each extra service. Thus, each one of them will run inside its own container and will have, if necessary, its dedicated volume.
>

Bonus list:
>

* Set up redis cache for your WordPress website in order to properly manage the cache.
>

* Set up a FTP server container pointing to the volume of your WordPress website.
>

* Create a simple static website in the language of your choice except PHP (Yes, PHP
is excluded!). For example, a showcase site or a site for presenting your resume.
>

* Set up Adminer.
>

* Set up a service of your choice that you think is useful. During the defense, you will have to justify your choice.
> 

* To complete the bonus part, you have the possibility to set up extra
services.  In this case, you may open more ports to suit your needs.
>

* The bonus part will only be assessed if the mandatory part is
PERFECT. Perfect means the mandatory part has been integrally done
and works without malfunctioning.  If you have not passed ALL the
mandatory requirements, your bonus part will not be evaluated at all.
>

# Submission and peer-evaluation

Turn in your assignment in your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don’t hesitate to double check the names of your folders and files to ensure they are correct.
>



__________________________________________________



# debian에서 docker 설치
Debian 12에서 Docker를 설치하는 방법을 단계별로 안내드리겠습니다. 다음 지침을 따라 Docker와 Docker Compose를 시스템에 설치할 수 있습니다.

1. 기존 Docker 관련 패키지 제거
먼저, 시스템에 이전에 설치된 Docker 패키지가 있는 경우 제거합니다.

bash
코드 복사
sudo apt-get remove docker docker-engine docker.io containerd runc

2. 필요 패키지 업데이트 및 설치
Docker를 설치하기 전에 시스템의 패키지 목록을 업데이트하고 Docker 설치에 필요한 패키지를 설치합니다.

bash
코드 복사
sudo apt-get update
sudo apt-get install \
    ca-certificates \
    curl \
    gnupg \
    lsb-release
    
3. Docker의 공식 GPG 키 추가
Docker의 공식 GPG 키를 추가합니다.

bash
코드 복사
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/debian/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg

4. Docker 저장소 설정
Docker 패키지를 설치할 수 있도록 Docker의 안정적인 저장소를 추가합니다.

bash
코드 복사
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/debian \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
  
5. Docker 엔진 설치
Docker 패키지 목록을 업데이트하고 Docker 엔진을 설치합니다.

bash
코드 복사
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin

6. Docker 설치 확인
Docker가 정상적으로 설치되었는지 확인합니다.

bash
코드 복사
sudo docker run hello-world
위 명령어를 실행하면 Docker가 제대로 설치되었는지 확인하는 메시지가 출력됩니다.

7. Docker Compose 설치
Docker Compose는 최신 버전을 설치합니다. Docker Compose를 독립적으로 설치하는 경우:

최신 버전의 Docker Compose를 다운로드합니다.
bash
코드 복사
sudo curl -L "https://github.com/docker/compose/releases/download/v2.10.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
Docker Compose 바이너리 파일에 실행 권한을 부여합니다.
bash
코드 복사
sudo chmod +x /usr/local/bin/docker-compose
Docker Compose 설치를 확인합니다.
bash
코드 복사
docker-compose --version

8. Docker 서비스 시작 및 자동 시작 설정
Docker 서비스를 시작하고 부팅 시 자동으로 시작되도록 설정합니다.

bash
코드 복사
sudo systemctl start docker
sudo systemctl enable docker

9. 사용자 권한 설정 (선택 사항)
Docker 명령어를 실행할 때마다 sudo를 입력하지 않으려면 현재 사용자를 docker 그룹에 추가합니다.

bash
코드 복사
sudo usermod -aG docker $USER
변경 사항을 적용하려면 로그아웃 후 다시 로그인합니다.

요약
기존 Docker 패키지 제거
필요 패키지 업데이트 및 설치
Docker의 공식 GPG 키 추가
Docker 저장소 설정
Docker 엔진 설치
Docker 설치 확인
Docker Compose 설치
Docker 서비스 시작 및 자동 시작 설정
사용자 권한 설정 (선택 사항)
위 단계를 따르면 Debian 12 시스템에서 Docker 및 Docker Compose를 성공적으로 설치하고 사용할 수 있습니다.


# docker-compose

```
version: '3.7'  # Docker Compose 파일의 버전. Docker Compose의 기능에 따라 호환되는 파일 형식 버전을 지정합니다.

services:  # Docker Compose에서 정의하는 서비스 목록
  nginx:  # 서비스 이름. 이 이름으로 컨테이너를 참조합니다.
    build:
      context: ./requirements/nginx  # Dockerfile과 관련 파일들이 위치한 디렉토리. 빌드 컨텍스트를 설정합니다.
      dockerfile: Dockerfile  # 사용할 Dockerfile의 이름. 기본값은 'Dockerfile'입니다.
    image: 42_nginx_image  # 빌드된 이미지를 '42_nginx_image'라는 이름으로 태깅합니다.
    ports:
      - "443:443"  # 호스트의 443 포트를 컨테이너의 443 포트에 매핑합니다. HTTPS 트래픽을 처리합니다.
    volumes:
      - /home/sejkim2/data/nginx:/var/log/nginx  # 호스트의 /home/sejkim2/data/nginx 디렉토리를 컨테이너의 /var/log/nginx 디렉토리에 마운트합니다. 로그 파일을 호스트와 공유합니다.
    container_name: 42_nginx_container  # 컨테이너의 이름을 '42_nginx_container'로 설정합니다. 컨테이너를 식별하는 데 사용됩니다.

```

# open ssl 인증
openssl req -newkey rsa:2048 -nodes -keyout /home/sejkim2/inception/srcs/nginx/ssl/nginx.key -x509 -days 365 -out /home/sejkim2/inception/srcs/nginx/ssl/nginx.crt

/home/sejkim2/ssl 안에 인증 파일들을 저장


https://docs.docker.com/build/building/best-practices/#add-or-copy

```
# 베이스 이미지로 Debian 12 사용
FROM debian:12

# 패키지 업데이트 및 MariaDB 서버 설치
RUN apt-get update && \
    apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

# 환경 변수 설정 (필요에 따라 수정)
ENV MYSQL_ROOT_PASSWORD=rootpassword
ENV MYSQL_DATABASE=mydatabase
ENV MYSQL_USER=myuser
ENV MYSQL_PASSWORD=mypassword

# 포트 3306 열기
EXPOSE 3306

# MariaDB 서버 시작
CMD ["sh", "-c", "service mysql start && tail -f /dev/null"]
```


```
FROM debian:11

# 설치 및 클린업
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    curl \
    && rm -rf /var/lib/apt/lists/*

# dump_init 설치
RUN curl -Lo /usr/local/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.2/dumb-init_1.2.2_amd64 && \
    chmod +x /usr/local/bin/dumb-init

# 인증서와 키 파일을 포함시킬 디렉토리 생성
RUN mkdir -p /etc/nginx/ssl

# SSL 인증서와 키 파일 복사
COPY server.crt /etc/nginx/ssl/server.crt
COPY server.key /etc/nginx/ssl/server.key

# Nginx 설정 파일 복사
COPY conf/nginx.conf /etc/nginx/nginx.conf

# 로그 디렉토리 설정
VOLUME ["/var/log/nginx"]

# 443 포트 개방
EXPOSE 443

# dumb-init을 엔트리포인트로 설정
ENTRYPOINT ["/usr/local/bin/dumb-init", "--"]

# Nginx 실행
CMD ["nginx", "-g", "daemon off;"]
```

도커 설치
```
sudo apt-get update
sudo apt-get install docker.io
```

도커 컴포즈 설치
```
sudo apt-get update
sudo apt-get install docker-compose
```

dockerfile 로 이미지 빌드
```
docker build -t [image_name] [path]
```

도커 이미지 목록 확인
```
docker images
```

도커 이미지로 컨테이너 생성
```
docker run -d -p [host의 포트]:[개방된 guest의 호트] [사용될 이미지]
```

도커 컨테이너 내부로 접속
```
docker exec -it [컨테이너 넘버] bash
```

openssl 인증
```
openssl req -newkey rsa:2048 -nodes -keyout server.key -out server.csr
openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.crt
```

nginx.conf
```
user www-data;
worker_processes auto;
pid /run/nginx.pid;
error_log /var/log/nginx/error.log;
include /etc/nginx/modules-enabled/*.conf;

events {
    worker_connections 768;
}

http {
    ##
    # Basic Settings
    ##
    sendfile on;
    tcp_nopush on;
    types_hash_max_size 2048;
    include /etc/nginx/mime.types;
    default_type application/octet-stream;

    ##
    # SSL Settings
    ##
    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_prefer_server_ciphers on;

    ##
    # Logging Settings
    ##
    access_log /var/log/nginx/access.log;

    ##
    # Gzip Settings
    ##
    gzip on;

    ##
    # Virtual Host Configs
    ##
    server {
        listen 443 ssl;
        server_name sejkim2.42.fr;

        ssl_certificate /etc/nginx/ssl/server.crt;
        ssl_certificate_key /etc/nginx/ssl/server.key;

        ssl_protocols TLSv1.2 TLSv1.3;
        ssl_ciphers HIGH:!aNULL:!MD5;

        location / {
            root /usr/share/nginx/html;
            index index.html;
        }
    }

    # HTTP에서 HTTPS로 리다이렉션
    # server {
    #     listen 80;
    #     server_name yourdomain.com;

    #     location / {
    #         return 301 https://$host$request_uri;
    #     }
    # }
}

```

DNS 추가
```
nano /etc/hosts
[add] 127.0.0.1 sejkim2.42.fr
```

docker-compose 빌드
```
docker-compose up -d --build
```

```
CMD ["executable","param1","param2"](실행 양식, 이 양식이 기본 양식)
CMD ["param1","param2"](ENTRYPOINT의 기본 파라미터로 사용)
CMD command param1 param2(쉘 형태) -> pid1이 shell 프로세스

ENTRYPOINT ["executable", "param1", "param2"] : 기본 형식
ENTRYPOINT command param1 param2 : 셸 형식
```

<img width="1023" alt="Screen Shot 2024-08-07 at 4 05 47 PM" src="https://github.com/user-attachments/assets/f36893bb-63f7-401c-81a5-92f58ac12072">
출처 : https://haward.tistory.com/m/190

```
FROM debian:11

# 패키지 관리자를 업데이트하고 MariaDB 서버와 dumb-init을 설치
RUN apt-get update -y && \
    apt-get install -y mariadb-server curl && \
    curl -Lo /usr/local/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.2/dumb-init_1.2.2_amd64 && \
    chmod +x /usr/local/bin/dumb-init && \
    rm -rf /var/lib/apt/lists/*

# MariaDB 설정: 모든 네트워크에서 MariaDB에 접근할 수 있도록 bind-address 설정
RUN sed -i 's/^bind-address\s*=.*/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

# 데이터 디렉토리 설정
VOLUME ["/var/lib/mysql"]

# MariaDB 소켓 디렉토리 생성 및 권한 설정
RUN mkdir -p /run/mysqld && chown mysql:mysql /run/mysqld

# 데이터베이스 및 사용자 생성 스크립트 추가
COPY tools/db_setup.sh /docker-entrypoint-initdb.d/
RUN chmod +x /docker-entrypoint-initdb.d/db_setup.sh

# 3306 포트 개방
EXPOSE 3306

# dumb-init을 엔트리포인트로 설정
ENTRYPOINT ["/usr/local/bin/dumb-init", "--"]

# MariaDB를 안전 모드로 실행하고 초기화 스크립트를 실행
CMD ["/bin/bash", "-c", "/usr/bin/mysqld_safe & /docker-entrypoint-initdb.d/db_setup.sh && wait"]
```

```
#!/bin/bash
set -e

# 서버가 시작될 때까지 대기
echo "Waiting for MariaDB server to start..."
while ! mysqladmin ping --silent -u root -p"$MYSQL_ROOT_PASSWORD"; do
    sleep 1
done

# SQL 명령어를 포함할 SQL 파일을 생성합니다.
echo "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;" > /docker-entrypoint-initdb.d/db1.sql
echo "CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';" >> /docker-entrypoint-initdb.d/db1.sql
echo "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO \`${MYSQL_USER}\`@'%';" >> /docker-entrypoint-initdb.d/db1.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';" >> /docker-entrypoint-initdb.d/db1.sql
echo "FLUSH PRIVILEGES;" >> /docker-entrypoint-initdb.d/db1.sql

# 생성된 SQL 파일을 MariaDB에 적용합니다.
mysql -u root -p"$MYSQL_ROOT_PASSWORD" < /docker-entrypoint-initdb.d/db1.sql

```

```
docker run -d -p 3306:3306 -e MYSQL_DATABASE=sejkim2db -e MYSQL_ROOT_PASSWORD=12345 -e MYSQL_USER=sejkim2 -e MYSQL_PASSWORD=111 myriadb
```


```
version: '3.7'  # Docker Compose 파일의 버전. Docker Compose의 기능에 따라 호환되는 파일 형식 버전을 지정합니다.

services:  # Docker Compose에서 정의하는 서비스 목록
  nginx:  # 서비스 이름. 이 이름으로 컨테이너를 참조합니다.
    build:
      context: ./requirements/nginx  # Dockerfile과 관련 파일들이 위치한 디렉토리. 빌드 컨텍스트를 설정합니다.
      dockerfile: Dockerfile  # 사용할 Dockerfile의 이름. 기본값은 'Dockerfile'입니다.
    image: 42_nginx_image:1.0  # 빌드된 이미지를 '42_nginx_image'라는 이름으로 태깅합니다.
    ports:
      - "443:443"  # 호스트의 443 포트를 컨테이너의 443 포트에 매핑합니다. HTTPS 트래픽을 처리합니다.
    container_name: 42_nginx_container  # 컨테이너의 이름을 '42_nginx_container'로 설정합니다. 컨테이너를 식별하는 데 사용됩니다.
  
  mariadb:
    build:
      context: ./requirements/mariadb
      dockerfile: Dockerfile  
    image: 42_mariadb_image:1.0 
    expose:
      - "3306"
    env_file:
      - .env
    volumes:
      - mariadb_data:/var/lib/mysql
    container_name: 42_mariadb_container

volumes:
  mariadb_data:
    driver: local
    external: false
    driver_opts:
      type: 'bind'
      device: /home/sejkim2/data/mariadb
      o: 'bind'
```
