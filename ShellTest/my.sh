#!/bin/bash

my_fun()
{
    echo '$0 inside function is ' $0
    echo '$1 inside function is ' $1
    echo '$2 inside function is ' $2
}

my_fun1()
{
    echo "$#"
}

echo '$0 outside function is ' $0
echo '$1 outside function is ' $1
echo '$2 outside function is ' $2

my_fun fp1 "fp2 fp3"

echo 'the number of parameter in "$@" is' $(my_fun1 "$@")
echo 'the number of parameter in "$*" is' $(my_fun1 "$*")

echo 'the number of parameter in '$@' is' $(my_fun1 '$@')
echo 'the number of parameter in '$*' is' $(my_fun1 '$*')