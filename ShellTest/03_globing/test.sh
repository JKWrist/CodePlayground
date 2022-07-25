#!/bin/bash
mkdir -p day{1..9}/01_doc
mkdir -p day{1..9}/02_code
mkdir -p day{1..9}/03_resource
mkdir -p day{1..9}/04_note

touch {1..4}.txt

gcc main.c -o a.out
./a.out ls *