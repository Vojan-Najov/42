#!/bin/bash

wget https://ftp.postgresql.org/pub/source/v16.0/postgresql-16.0.tar.gz

tar xzf /Users/ccartman/postgresql-16.0.tar.gz

cd /Users/ccartman/postgresql-16.0

./configure --prefix=/Users/ccartman//pgsql16 --with-pgport=5555

make && make install

cd contrib
make && make install

mkdir /Users/ccartman/pgsql16/data

export PGDATA=/Users/ccartman/pgsql16/data
export PATH=/Users/ccartman/pgsql16/bin:$PATH

initdb -U postgres -k -D /Users/ccartman/pgsql16/data

