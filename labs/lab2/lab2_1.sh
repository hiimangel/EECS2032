#!/bin/bash
read number1 number2 number3
arr[0]=$((number1))
arr[1]=$((number2))
arr[2]=$((number3))
for ((i = 0; i<3; i++))
do
for((j = 0; j<3-i-1; j++))
do   
if [ ${arr[j]} -gt ${arr[$((j+1))]} ]
then
temp=${arr[j]}
arr[j]=${arr[$((j+1))]}
arr[$((j+1))]=$temp
fi
done
done

min=${arr[0]}
max=${arr[2]}
median=${arr[1]}

dmedian=$(($median * 2))
hmedian=$(($median / 2))
if [ $max -ge $dmedian ] | [ $min -le $hmedian ] ; then
echo $median
echo "WIDE APART"
else
echo $median
echo "CLOSE"
fi
