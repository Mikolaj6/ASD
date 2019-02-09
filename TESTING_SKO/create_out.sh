#!/bin/bash

for file in $2/*.in
do
	$1 <$file >${file%in}out
	
done
