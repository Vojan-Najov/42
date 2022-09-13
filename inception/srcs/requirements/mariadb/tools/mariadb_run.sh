#! /bin/sh

if [ -d /run/mariadb];
then
	chown -R mysql:mysql /run/mariadb
else
	mkdir -p /run/mariadb
	chown -R mysql:mysql /run/mariadb
fi

if [ -d /var/lib/mysql/mysql ];
then
	chown -R mysql:mysql /var/lib/mysql
else
	chown -R mysql:mysql /var/lib/mysql
	mysql_install_db --user=mysql --datadir=/var/lib/mysql
	
