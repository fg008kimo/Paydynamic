#!/bin/ksh

#. /usr/local/profile/setenv
. ${HOME}/.setenv

if [[ $# == 1 ]]
then
	FILE_NAME=$1
	sqlldr $ORACLE_USER/$ORACLE_PASSWORD@$ORACLE_SID control=${FILE_NAME}

else
        echo "usage: [file_name]"
        exit 1

fi
