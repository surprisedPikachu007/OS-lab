echo -n "Enter in fahrenheit: "
read fahr

cel=`echo "scale=2; ($fahr - 32) * 5/9" | bc`
echo "$fahr degrees fahrenheit is $cel degrees celsius"
