#!/bin/bash



product_code=LKM356
var="`grep $product_code names.txt | awk  -F'\t' '{ ORS="" }; { print $1; print", " }'` bought $description"
length=${#var}
endindex=$(expr $length - 1)
echo ${var:0:$endindex} 