#!/bin/bash
echo "Is it morning? Please answer yes or no!"
#读取用户输入的一个变量
read YES_OR_NO

case "$YES_OR_NO" in
yes|y|Yes|YES)
    echo "Good morning"
    ;;
[nN][oO]|n|N)
    echo "Good afternoon"
    ;;
*)
    echo "Not recognized"
    ;;
esac
