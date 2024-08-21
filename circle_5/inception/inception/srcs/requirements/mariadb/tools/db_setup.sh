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
