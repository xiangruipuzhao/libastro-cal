#!/bin/bash

COMMAND=$1
if [[ ! -f /usr/lib/libastro-cal.a ]];then
        echo "libastro-cal.a is not present in /usr/lib. Please read the main README.md for instructions."
        echo "Aborted"
        exit -1
fi

if [[ -z $COMMAND ]];then
        gcc apparent_asteroid_diameter.c -o apparent_asteroid_diameter -lastro-cal -lm -O2
        gcc asteroid_diameter.c -o asteroid_diameter -lastro-cal -lm -O2
elif [[ $COMMAND = 'clean' ]];then
        rm apparent_asteroid_diameter
        rm asteroid_diameter
fi
