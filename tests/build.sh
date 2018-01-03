#!/bin/bash

COMMAND=$1

if [[ -z $COMMAND ]];then
        gcc test.c -o test ../src/libastro-cal.a -lm
elif [[ $COMMAND = 'clean' ]];then
        rm test
fi


