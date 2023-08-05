#!/bin/bash
#!/bin/bash -x

function func1()
{
    for FRUIT in apple banana pear
    do
        echo "fruit list ${FRUIT}"
    done
}

function func2()
{
    sum=0
    for i in {1..100}
    do
        sum=$[sum+i]
    done
    echo $sum
}

function func3()
{
    for f in $(ls)
    do
        if [ -f $f ]
        then
            echo "normal file"
        elif [ -d $f ]
        then
            echo "directory"
        else
            echo "don't know"
        fi
    done
}

function func4()
{
    sum=0
    i=1
    while [ $i -le 100 ]
    do
        sum=$[sum+i]
        i=$[i+1]
    done

    echo $sum
}

#func1
#func2
#func3
func4