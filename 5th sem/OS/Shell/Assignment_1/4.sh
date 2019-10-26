# Array of search words
words=("printf" "scanf" "int")

# Loop to iterate through file names
for i in "$@"
do
	echo "In file $i :"
	# Loop to iterate through search words
	for j in "${words[@]}"
	do
		count=$(grep -o -w $j $i | wc -w)
		echo "$j : $count"
	done
	echo
done