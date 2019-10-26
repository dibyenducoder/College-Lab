# Taking file name input
echo "Enter file name: "
read filename

# Taking string input
echo "Enter string: "
read string

# Finding the total no of occurences of the string in the file
count=$(grep -o -w $string $filename | wc -w)

# Printing the no of occurences if the word exists else printing error message
if [ $count == 0 ]
then
	echo "The given string doesn't exist in the file"
else
	echo "Number of occurences of the given string is : $count"
	echo
	# Printing the no of occurences per line
	echo "Line-wise frequency: "
	line_number=1

	while read i
	do 
		count=$(echo $i |grep -o -w $string| wc -w)
		if [ $count -gt 0 ]  
		then
			echo "$line_number : $count"
		fi
		let line_number++
	done < $filename

fi