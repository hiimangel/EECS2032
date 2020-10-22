  pid=LKM356
  descr=$(grep $pid products.txt | cut -d$'\t' -f2)
    productNum=$(grep $pid products.txt | cut -d$'\t' -f5)
    productVal=$(grep $pid products.txt | cut -d$'\t' -f4)
    totalValue=$(expr $productNum '*' $productVal)
    echo "Total value of $descr is $totalValue"
