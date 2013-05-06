#!/bin/bash
#use C-c to stop the test.
n=1

./case > in.txt                     #create a input file "in.txt"
./sgu > sgu.txt <in.txt            #readin in.txt outpu my program result
./sample > sample.txt <in.txt     #readin in.txt outpu the right result

#if file results are same, do next test, otherwise exit
while diff sgu.txt sample.txt -q
do 
    echo  $n
    ./case > in.txt                     #create a input file "in.txt"
    ./sgu > sgu.txt <in.txt            #readin in.txt outpu my program result
    ./sample > sample.txt <in.txt     #readin in.txt outpu the right result
    n=$((n+1))
done


