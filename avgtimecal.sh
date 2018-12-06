#!/bin/bash

rm -f firstcheck.txt secondcheck.txt ifelseout.txt ifelselastout.txt gperffirstcheck.txt gperfsecondcheck.txt gperfout.txt gperflastout.txt

gcc ifelsecheck.c -o ifelsecheck
gcc ifelsechecklast.c -o ifelsechecklast
gcc -I ./ gperfcheck.c -o gperfcheck
gcc -I ./ gperfchecklast.c -o gperfchecklast

./ifelsecheck > ifelseout.txt
./ifelsechecklast > ifelselastout.txt
./gperfcheck > gperfout.txt
./gperfchecklast > gperflastout.txt

cat ifelseout.txt | awk '{ print $7 }' >> firstcheck.txt
cat ifelselastout.txt | awk '{ print $7 }' >> secondcheck.txt
cat gperfout.txt | awk '{ print $7 }' >> gperffirstcheck.txt
cat gperflastout.txt | awk '{ print $7 }' >> gperfsecondcheck.txt

cat firstcheck.txt | sort | awk 'BEGIN { sum=0; num=0 } { sum += $1; num += 1 } END { printf"\nAvg of %.2f ns for %d runs for string at start\n\n", sum/num, num }'
cat secondcheck.txt | sort | awk 'BEGIN { sum=0; num=0 } { sum += $1; num += 1 } END { printf"\nAvg of %.2f ns for %d runs for string at end\n\n", sum/num, num }'
cat gperffirstcheck.txt | sort | awk 'BEGIN { sum=0; num=0 } { sum += $1; num += 1 } END { printf"\nAvg of %.2f ns for %d runs for gperf string first\n\n", sum/num, num }'
cat gperfsecondcheck.txt | sort | awk 'BEGIN { sum=0; num=0 } { sum += $1; num += 1 } END { printf"\nAvg of %.2f ns for %d runs for gperf string last\n\n", sum/num, num }'
