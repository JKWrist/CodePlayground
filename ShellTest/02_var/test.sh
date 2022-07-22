#!/bin/bash

globalVar1="hello"

function test()
{
  globalVar2="world"
  local localVar="junze"
  echo $localVar
}

#调用函数
test

echo $globalVar1 $globalVar2 $localVar

export environVar="this is in environ"

