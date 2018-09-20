if [ -z "$1" ]
then
	num=100
else
	num="$1"
fi
case=100
limit=5300

exceed=0
count=1
sum=0
best=1000000
worst=0
passed=1
while [ $count -lt $(expr $case + 1) ]
do
	arg=$(ruby -e "puts (1..$num).to_a.shuffle.join(' ')")
	line=$(./push_swap $arg | wc -l)
	checker=$(./push_swap $arg | ./checker $arg)
	echo "$count - $checker"
	sum=$(expr $sum + $line)
	if [ $line -lt $best ]
	then
		best=$line
	fi
	if [ $line -gt $worst ]
	then
		worst=$line
	fi
	if [ $line -gt $limit ]
	then
		exceed=$(expr $exceed + 1)
	fi
	if [ $checker != "OK" ]
	then
		passed=0
	fi
	count=$(expr $count + 1)
done
echo "num   : $num"
echo "case  : $case"
echo "avg   : $(expr $sum / $(expr $count - 1))"
echo "best  : $(expr $best)"
echo "worst : $(expr $worst)"
echo "exceed: $exceed"
if [ $passed == 1 ]
then
	echo "Test  : OK"
else
	echo "Test  : KO"
fi
