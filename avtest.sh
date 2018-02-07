#!/bin/bash

echo -e '\033[0mGetting an average in a range from 0 to 9'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..9).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 99'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 499'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res

echo -e '\033[0mGetting an average in a range from 0 to 69'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..69).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res
