num1=$[2*3]
num2=$[1+5]
if test $[num1] -eq $[num2]
then
    echo 'The two numbers are equal!'
    if [ y = y ]
    then
        echo '1'
    else
        echo '2'
    fi
else
    echo 'The two numbers are not equal!'
fi