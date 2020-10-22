#!/bin/bash

echo "Hi Mr $(grep $USER /etc/passwd | cut -d':' -f5 | awk '{print $1}'), today is $(date +"%A")"

