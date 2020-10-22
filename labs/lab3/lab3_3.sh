#!/bin/bash
read a operator b
add="+"
sub="-"
mult="*"
div="/"
operator="$operator"
if [ "$operator" == "$mult" ]
  then
    echo $(expr "$a" '*' "$b")

elif [ $operator == $add ]
  then
    echo $(expr $a + $b)

elif [ $operator == $div ]
  then
    echo $(($a / $b))

elif [ $operator == $sub ]
  then
    echo $(expr $a - $b)

else
  echo "No such operation $operator"
fi


