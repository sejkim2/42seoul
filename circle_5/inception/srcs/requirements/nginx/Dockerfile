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