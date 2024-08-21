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
