#!/bin/bash


case "$1" in
  -n)
    first_customer=$2 ;  
    last_customer=$3 ; 
    shift 3 

    name_customer="$first_customer $last_customer"

    number=1
    for product in `grep -n "$name_customer" names.txt | cut -d$'\t' -f2` 
      do
        eval "var$number=$product";
        number=$((number+1))
        description=$(grep $product products.txt | cut -d$'\t' -f2)
        price=$(grep $product products.txt | cut -d$'\t' -f4)
        echo "$name_customer bought $description and its price is $price"
    done
    
  ;;
  -N)
    first_customer=$2 ;   
    last_customer=$3 ; 
    shift 3 

    name_customer="$first_customer $last_customer"

    for product in `grep "$name_customer" names.txt | cut -d$'\t' -f2` 
      do
        price=$(grep $product products.txt | cut -d$'\t' -f4)
        total_price=$(($price + total_price)) 
    done
    echo "$name_customer spent $total_price"

  ;;
  -I)
    product_code=$2 ;
    shift 2;
    description_i=$(grep $product_code products.txt | cut -d$'\t' -f2)
    names_whobought="`grep $product_code names.txt | awk  -F'\t' '{ ORS="" }; { print $1; print", " }'`"
    length=${#names_whobought}
    endindex=$(expr $length - 2)
    phrase=${names_whobought:0:$endindex}  
    echo "$phrase. bought $description_i"


  ;;
  -T)
    product_codet=$2 ;
    shift 2 ;

    nm_products=$(grep $product_codet products.txt | cut -d$'\t' -f5)
    value_product=$(grep $product_codet products.txt | cut -d$'\t' -f4) 
    value=$(expr $nm_products '*' $value_product)
    description_t=$(grep $product_codet products.txt | cut -d$'\t' -f2) 
    echo "Total value of $description_t is $value"

  ;;
 esac
