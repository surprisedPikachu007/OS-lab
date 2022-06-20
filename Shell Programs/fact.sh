#find factorial of a number
echo "Enter a number"
read n
number=$n
fact=1

if [ $n -lt 0 ]
then
    echo "Enter a positive number"
    exit
fi

while [ $n -gt 1 ]
do
    fact=$((fact*n))
    n=$((n-1))
done
echo "Factorial of $number is $fact"

