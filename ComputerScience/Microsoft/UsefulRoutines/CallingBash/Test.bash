#!/bin/bash

VAR=${1}

if [ ${VAR} -eq 1 ] ; then
   echo "LOBO LOBO LOBO"
   exit 0
elif [ ${VAR} -eq 2 ] ; then
   echo "TIAA RUFAAA"
   exit 0
else 
   echo "RUFITO"
   exit 1
fi

