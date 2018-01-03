#!/bin/bash

COMMAND=$1
if [[ ! -f /usr/lib/libastro-cal.a ]];then
        echo "libastro-cal.a is not present in /usr/lib. Please read the main README.md for instructions."
        echo "Aborted"
        exit -1
fi

if [[ -z $COMMAND ]];then
        gcc apparent_diameter.c -o apparent_diameter -lastro-cal -lm
elif [[ $COMMAND = 'clean' ]];then
        rm apparent_diameter
fi
