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