#!/bin/bash

rm -f *.txt

declare -a arr=("powersave" "performance" "userspace" "ondemand" "conservative" "schedutil" "random")

gcc dataGenerator.c -o dataGenerator
gcc ifelsecheck.c -o ifelsecheck
gcc -I ./ gperfcheck.c -o gperfcheck

for i in "${arr[@]}"
do
	./dataGenerator $i > "$i.txt"
	./ifelsecheck "$i.txt" > "outputifelse-$i.txt"
	./gperfcheck "$i.txt" > "outputgperf-$i.txt"
	cat outputifelse-$i.txt | awk '{ print $7 }' >> nstimeifelse-$i.txt
	cat outputgperf-$i.txt | awk '{ print $7 }' >> nstimegperf-$i.txt
	cat nstimeifelse-$i.txt | sort | awk -v governor=$i 'BEGIN { sum=0; num=0 } { sum += $1; num += 1 } END { printf"\nAvg of %.2f ns for %d runs for string %s in if else\n\n", sum/num, num, governor}'
	cat nstimegperf-$i.txt | sort | awk -v governor=$i 'BEGIN { sum=0; num=0 } { sum += $1; num += 1 } END { printf"\nAvg of %.2f ns for %d runs for string %s in gperf\n\n", sum/num, num, governor}'
done

