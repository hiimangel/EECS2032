#!/bin/bash

for ((i=0;i<$#;i++)); do
eval echo -n $"$"$(($#-i))
done
echo ""

