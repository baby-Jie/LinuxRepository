#!/bin/bash

create_user_name=$1
if [ id $create_user_name$ ]; then
	echo "$1 exists"
else
	echo "$1 does not exist"
fi
