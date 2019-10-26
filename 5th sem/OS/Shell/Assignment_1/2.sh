#!/bin/bash

#Counting total number of files
echo "The total number of files is: "
find ./ -type f | wc -w
echo

# Printing number of files in each subdirectory
echo "The directory-wise distribution of files is: "
find . -maxdepth 1 -mindepth 1 -type d | while read dir; 

do
	count=$(find "$dir" -type f | wc -l)
  	echo "$dir : $count "  
done
echo

# Printing files created in last 2 days
echo "The files created in last 2 days are: "
find ./ -type f -mtime -2 | sort
