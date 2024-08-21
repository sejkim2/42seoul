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
