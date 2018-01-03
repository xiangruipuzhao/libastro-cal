#!/bin/bash

COMMAND=$1

# build library first if not exist
if [[ ! -f ../src/libastro-cal.a ]];then
        cd ..
        autoreconf --install
        ./configure
        make

        cd tests
fi

if [[ -z $COMMAND ]];then
        gcc test.c -o test ../src/libastro-cal.a -lm
elif [[ $COMMAND = 'clean' ]];then
        rm test
fi


