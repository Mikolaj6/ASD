#!/bin/bash

for file in $2/*.in
do
	$1 <$file >tmp
	cmp -s tmp ${file%in}out || echo "Test for $file Failed"

	
done

rm tmp
