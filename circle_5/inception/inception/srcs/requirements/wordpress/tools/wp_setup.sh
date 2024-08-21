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
  wp user create "$WORDPRESS_USER" "$WORDPRESS_USER_EMAIL" --user_pass="$WORDPRESS_USER_PASSWORD" --role=contributor --allow-root
else
  echo "User '$WORDPRESS_USER' already exists."
fi