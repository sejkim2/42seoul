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

# open ssl 인증
```
openssl req -newkey rsa:2048 -nodes -keyout /home/sejkim2/inception/srcs/nginx/ssl/nginx.key -x509 -days 365 -out /home/sejkim2/inception/srcs/nginx/ssl/nginx.crt

# /home/sejkim2/ssl 안에 인증 파일들을 저장
```

https://docs.docker.com/build/building/best-practices/#add-or-copy




# 도커 설치
```
sudo apt-get update
sudo apt-get install docker.io
```

# 도커 컴포즈 설치
```
sudo apt-get update
sudo apt-get install docker-compose
```

# dockerfile 로 이미지 빌드
```
docker build -t [image_name] [path]
```

# 도커 이미지 목록 확인
```
docker images
```

# 도커 이미지로 컨테이너 생성
```
docker run -d -p [host의 포트]:[개방된 guest의 호트] [사용될 이미지]
```

# 도커 컨테이너 내부로 접속
```
docker exec -it [컨테이너 넘버] bash
```

# openssl 인증
```
openssl req -newkey rsa:2048 -nodes -keyout server.key -out server.csr
openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.crt
```


# DNS 추가
```
nano /etc/hosts
[add] 127.0.0.1 sejkim2.42.fr
```

# docker-compose 빌드
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
docker run -d -p 3306:3306 -e MYSQL_DATABASE=sejkim2db -e MYSQL_ROOT_PASSWORD=12345 -e MYSQL_USER=sejkim2 -e MYSQL_PASSWORD=111 myriadb
```

https://ksbgenius.github.io/wordpress/2020/08/15/wordpress-installation-part2-php-fpm-install-and-configure.html

```
https://developer.wordpress.org/apis/wp-config-php/
```

# Makefile
```
# Makefile

# 설정할 변수
COMPOSE_FILE = srcs/docker-compose.yml
ENV_FILE = srcs/.env  # .env 파일 경로를 명시적으로 설정

# 호스트 볼륨 디렉토리
MARIADB_VOLUME_DIR = /home/sejkim2/data/mariadb
WORDPRESS_VOLUME_DIR = /home/sejkim2/data/wordpress

# 컨테이너 이름을 변수로 설정
NGINX_CONTAINER_NAME = nginx
MARIADB_CONTAINER_NAME = mariadb
WORDPRESS_CONTAINER_NAME = wordpress

# 기본 목표
all: up

# 호스트 볼륨 디렉토리 생성
create-host-volumes:
	mkdir -p $(MARIADB_VOLUME_DIR) $(WORDPRESS_VOLUME_DIR)

# Docker Compose 서비스를 빌드하고 시작
build-up: create-host-volumes
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) up -d --build

# Docker Compose 개별 서비스를 빌드
build-nginx:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) build $(NGINX_CONTAINER_NAME)

build-mariadb:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) build $(MARIADB_CONTAINER_NAME)

build-wordpress:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) build $(WORDPRESS_CONTAINER_NAME)

# Docker Compose 서비스를 시작
up:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) up -d

# Docker Compose 개별 서비스를 시작
start-nginx:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) up -d $(NGINX_CONTAINER_NAME)

start-mariadb:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) up -d $(MARIADB_CONTAINER_NAME)

start-wordpress:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) up -d $(WORDPRESS_CONTAINER_NAME)

# Docker Compose 서비스를 중지
down:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) down

# Docker Compose 개별 서비스를 중지
stop-nginx:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) stop $(NGINX_CONTAINER_NAME)

stop-mariadb:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) stop $(MARIADB_CONTAINER_NAME)

stop-wordpress:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) stop $(WORDPRESS_CONTAINER_NAME)

# Docker Compose 개별 서비스 상태 확인
status-nginx:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) ps $(NGINX_CONTAINER_NAME)

status-mariadb:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) ps $(MARIADB_CONTAINER_NAME)

status-wordpress:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) ps $(WORDPRESS_CONTAINER_NAME)

# Docker Compose 개별 서비스 로그 출력
logs-nginx:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) logs -f $(NGINX_CONTAINER_NAME)

logs-mariadb:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) logs -f $(MARIADB_CONTAINER_NAME)

logs-wordpress:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) logs -f $(WORDPRESS_CONTAINER_NAME)

# Docker Compose 환경을 완전히 정리
clean:
	docker-compose --env-file $(ENV_FILE) -f $(COMPOSE_FILE) down --volumes --remove-orphans

# 호스트 볼륨 디렉토리 삭제
clean-host:
	sudo rm -rf $(MARIADB_VOLUME_DIR) $(WORDPRESS_VOLUME_DIR)

# 전체 환경 정리
reset: clean clean-host volume-clean prune

# 컨테이너를 삭제하지 않고, 이미지 삭제
prune:
	docker image prune -a -f

# 볼륨을 삭제
volume-clean:
	docker volume prune -f
```

# .env
```
# mariadb
MYSQL_ROOT_PASSWORD=12345
MYSQL_DATABASE=sejkim2_database
MYSQL_USER=sejkim2
MYSQL_PASSWORD=111

# wordpress_db
WORDPRESS_DB_NAME=sejkim2_database
WORDPRESS_DB_USER=sejkim2
WORDPRESS_DB_PASSWORD=111
WORDPRESS_DB_HOST=mariadb:3306

# wordpress info
WORDPRESS_URL=sejkim2.42.fr
WORDPRESS_TITLE=sejkim2_blog

# admin info
WORDPRESS_ADMIN_USER=songpa
WORDPRESS_ADMIN_PASSWORD=222
WORDPRESS_ADMIN_EMAIL=sejkim2@student.42.kr

# user info
WORDPRESS_USER=user1
WORDPRESS_USER_EMAIL=user1@example.com
WORDPRESS_USER_PASSWORD=333
WORDPRESS_USER_ROLE=subscriber

# certificates
CERT_PATH=/etc/nginx/ssl
```

# docker-compose.yml
```
version: '3.7'

services:
  nginx:
    build:
      context: ./requirements/nginx
      dockerfile: Dockerfile
      args:
        CERT_PATH: ${CERT_PATH}
        KEY_PATH: ${CERT_PATH}
        WORDPRESS_URL: ${WORDPRESS_URL}
    image: nginx:1.0
    ports:
      - "443:443"
    container_name: nginx
    depends_on:
      - wordpress
    env_file:
      - .env
    volumes:
      - wordpress_data:/var/www/html/wordpress
    restart: always
    networks:
      - 42_network
  
  mariadb:
    build:
      context: ./requirements/mariadb
      dockerfile: Dockerfile  
    image: mariadb:1.0 
    expose:
      - "3306"
    env_file:
      - .env
    volumes:
      - mariadb_data:/var/lib/mysql
    container_name: mariadb
    restart: always
    networks:
      - 42_network
  
  wordpress:
    build:
      context: ./requirements/wordpress
      dockerfile: Dockerfile
    image: wordpress:1.0
    depends_on:
      - mariadb
    expose:
      - "9000"
    env_file:
      - .env
    volumes:
      - wordpress_data:/var/www/html/wordpress
    container_name: wordpress
    restart: always
    networks:
      - 42_network

volumes:
  mariadb_data:
    driver: local
    driver_opts:
      type: 'bind'
      device: /home/sejkim2/data/mariadb
      o: 'bind'
  
  wordpress_data:
    driver: local
    driver_opts:
      type: 'bind'
      device: /home/sejkim2/data/wordpress
      o: 'bind'

networks:
  42_network:
    name: 42_network
    driver: bridge
```

# mariadb

## tools
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

## Dockerfile
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

# nginx

## conf/nginx.conf
```
user www-data;
worker_processes auto;  # nginx가 사용하는 워커 프로세스의 수 정의 (auto : cpu 코어 수에 맞게 생성)
error_log /var/log/nginx/error.log;
include /etc/nginx/modules-enabled/*.conf;

# 워커 프로세스가 처리할 수 있는 최대 연결 개수 지정 : ulimit -n
events {
    worker_connections 1024;
}

http {
    ##
    # SSL Settings
    ##
    ssl_protocols TLSv1.2 TLSv1.3;

    ##
    # Logging Settings
    ##
    access_log /var/log/nginx/access.log;

    ##
    # Virtual Host Configs
    ##
    server {
        listen 443 ssl;
        server_name __WORDPRESS_URL__;

        ssl_certificate __CERT_PATH__/server.crt;
        ssl_certificate_key __KEY_PATH__/server.key;
        ssl_ciphers HIGH:!aNULL:!MD5;

        root /var/www/html/wordpress;
        index index.php index.html index.htm;

        # 기본 페이지 요청 처리
        location / {
            try_files $uri $uri/ /index.php?$args;
        }

        # Favicon location
        location /favicon.ico {
            root /usr/share/nginx/html/favicon;
        }

        # PHP-FPM 처리
        location ~ \.php$ {
            try_files $uri =404;
            fastcgi_split_path_info ^(.+\.php)(/.+)$;
            fastcgi_pass wordpress:9000;  # PHP-FPM 컨테이너의 서비스 이름과 포트
            fastcgi_index index.php;
            include fastcgi_params;
            fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
            fastcgi_param PATH_INFO $fastcgi_path_info;
        }

        # .htaccess 파일 접근 차단
        location ~ /\.ht {
            deny all;
        }

        location /bonus_page {
            alias /var/www/html/static_site;
            index index.html;

            try_files $uri $uri/ =404;
        }
    }
}
```

## static_site

# index.html
```
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bonus Page</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <header>
        <h1>Welcome to the Bonus Page</h1>
    </header>
    <main>
        <p>This is a simple static page showcasing a bonus feature.</p>
        <button id="clickMeButton">Click Me!</button>
        <p>
            Visit my GitHub profile: 
            <a href="https://github.com/sejkim2" target="_blank" id="githubLink">GitHub Profile</a>
        </p>
    </main>
    <script src="script.js"></script>
</body>
</html>
```

# script.js
```
document.addEventListener('DOMContentLoaded', function () {
    const button = document.getElementById('clickMeButton');
    button.addEventListener('click', function () {
        alert('Button clicked!');
    });
});
```

# style.css
```
body {
    font-family: Arial, sans-serif;
    margin: 0;
    padding: 0;
    background-color: #f4f4f4;
    color: #333;
}

header {
    background-color: #007bff;
    color: white;
    padding: 10px;
    text-align: center;
}

main {
    padding: 20px;
    text-align: center;
}

button {
    padding: 10px 20px;
    font-size: 16px;
    color: #fff;
    background-color: #007bff;
    border: none;
    border-radius: 5px;
    cursor: pointer;
}

button:hover {
    background-color: #0056b3;
}

a {
    color: #007bff;
    text-decoration: none;
}

a:hover {
    text-decoration: underline;
}
```

## Dockerfile
```
FROM debian:11

ARG CERT_PATH
ARG KEY_PATH
ARG WORDPRESS_URL

# 설치 및 클린업
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    curl \
    && rm -rf /var/lib/apt/lists/*

# dumb-init 설치
RUN curl -Lo /usr/local/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.2/dumb-init_1.2.2_amd64 && \
    chmod +x /usr/local/bin/dumb-init

# 인증서와 키 파일을 포함시킬 디렉토리 생성
RUN mkdir -p ${CERT_PATH}

# SSL 인증서와 키 생성
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout ${KEY_PATH}/server.key \
    -out ${CERT_PATH}/server.crt \
    -subj "/C=/ST=/L=/O=/OU=/CN="

COPY static/favicon.ico /usr/share/nginx/html/favicon/favicon.ico
COPY static_site /var/www/html/static_site

# Nginx 설정 파일 복사
COPY conf/nginx.conf /etc/nginx/nginx.conf

# 설정 파일 내의 변수 설정
RUN sed -i "s|__WORDPRESS_URL__|${WORDPRESS_URL}|g" /etc/nginx/nginx.conf \
    && sed -i "s|__CERT_PATH__|${CERT_PATH}|g" /etc/nginx/nginx.conf \
    && sed -i "s|__KEY_PATH__|${KEY_PATH}|g" /etc/nginx/nginx.conf
# 443 포트 개방
EXPOSE 443

# dumb-init을 엔트리포인트로 설정하고 Nginx를 실행
ENTRYPOINT ["/usr/local/bin/dumb-init", "--"]

# Nginx를 포그라운드 모드로 실행
CMD ["nginx", "-g", "daemon off;"]
```

# wordpress

## conf/php-fpm.conf
```
; /etc/php/7.4/fpm/php-fpm.conf

[global]
daemonize = no
include=/etc/php/7.4/fpm/pool.d/*.conf
```

## conf/www.conf
```
; /etc/php/7.4/fpm/pool.d/www.conf

[www]
user = www-data
group = www-data
listen = 0.0.0.0:9000
listen.owner = www-data
listen.group = www-data
pm = dynamic
pm.max_children = 5
pm.start_servers = 2
pm.min_spare_servers = 1
pm.max_spare_servers = 3
pm.max_requests = 500
chdir = /
```

## tools/wp_setup.sh
```
#!/bin/bash

# WordPress 디렉토리로 이동
cd /var/www/html/wordpress

# wp-config.php 파일이 이미 존재하는 경우, WordPress가 이미 설치된 것으로 간주
if [ -f wp-config.php ]; then
  echo "WordPress is already installed."
else
  # wp-config.php 파일 생성
  wp config create \
      --dbname="$WORDPRESS_DB_NAME" \
      --dbuser="$WORDPRESS_DB_USER" \
      --dbpass="$WORDPRESS_DB_PASSWORD" \
      --dbhost="$WORDPRESS_DB_HOST" \
      --dbcharset="utf8" \
      --dbcollate="" \
      --allow-root

  # WordPress 설치 (루트 사용자로 실행되도록 --allow-root 옵션 추가)
  wp core install \
      --url="$WORDPRESS_URL" \
      --title="$WORDPRESS_TITLE" \
      --admin_user="$WORDPRESS_ADMIN_USER" \
      --admin_password="$WORDPRESS_ADMIN_PASSWORD" \
      --admin_email="$WORDPRESS_ADMIN_EMAIL" \
      --skip-email \
      --allow-root
fi

# 일반 사용자 계정 생성
if ! wp user get "$WORDPRESS_USER" --allow-root > /dev/null 2>&1; then
  wp user create "$WORDPRESS_USER" "$WORDPRESS_USER_EMAIL" --user_pass="$WORDPRESS_USER_PASSWORD" --role=subscriber --allow-root
else
  echo "User '$WORDPRESS_USER' already exists."
fi
```

## Dockerfile
```
FROM debian:11

# 환경 변수 설정
ENV DEBIAN_FRONTEND=noninteractive

# 패키지 목록을 업데이트하고 PHP-FPM 및 필요한 패키지를 설치
RUN apt-get update && \
    apt-get install -y \
    php-fpm \
    php-mysql \
    wget \
    unzip \
    curl \
    less \
    && apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# dumb-init 설치
RUN curl -Lo /usr/local/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.2/dumb-init_1.2.2_amd64 && \
    chmod +x /usr/local/bin/dumb-init

# PHP-FPM의 기본 설정을 복사
COPY conf/php-fpm.conf /etc/php/7.4/fpm/php-fpm.conf

# PHP-FPM의 pool 설정을 복사
COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

# WordPress 다운로드 및 설치
RUN mkdir -p /var/www/html && \
    wget https://wordpress.org/latest.zip -O /tmp/wordpress.zip && \
    unzip /tmp/wordpress.zip -d /var/www/html/ && \
    chown -R www-data:www-data /var/www/html/wordpress && \
    rm /tmp/wordpress.zip

# wp-cli 설치
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# WordPress 설정 스크립트 추가
COPY tools/wp_setup.sh /usr/local/bin/wp_setup.sh
RUN chmod +x /usr/local/bin/wp_setup.sh

# PHP-FPM이 포트 9000에서 리스닝하도록 설정
EXPOSE 9000

# dumb-init을 엔트리포인트로 설정하고 PHP-FPM을 실행
ENTRYPOINT ["/usr/local/bin/dumb-init", "--"]

# setup-wp.sh 스크립트를 실행한 후 PHP-FPM을 포그라운드 모드로 실행
CMD ["/bin/sh", "-c", "/usr/local/bin/wp_setup.sh && php-fpm7.4 -F"]
```
