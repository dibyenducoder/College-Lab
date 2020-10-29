# Assignment 5
		Group Name-A1
		Class : BCSE-III

## Project 
----------------------------------------
Consider a simple C-likc language with 
Data Type : float (float) and string (string) (a string is a stream of characters)
Assignments to the variables arc performed at the time of declaration
Loop Constructs: for, nested loops are supported 
Relational operators supported in the loop construct are {>,<}
Declarations can be made inside a loop.
A loop body can use arithmetic operations {+ and —} in the prefix form to add 
	float variables and constants and '+' operator to concatenate to strings. 
	Assignment operator '=' is supported. 
	Only function is main°. there is no other function. The main() function may 
	contain arguments. and also a return statement. 
Part I — Construct a CFG for this language 
Part II — Write a lexical analyser to scan thc stream of characters from a program written in the above language and generate stream of tokens. 
Part III — Writc a top-down parser for this language which includes FIRST, FOLLOW, parsing table construction and parsing .

## Project constructs 
-------------------------------------------------
* BCSE-3-Project-75-77-L01-L02
  * 1. CFG    
  	* CFG.txt
  	* README.md
  * 2. Lexical Analysis
  	* DFA_for_RE
  		* float.txt
  		* identifiers.txt
  		* integer.txt
  		* string.txt
  	* outputs
  		* output_test1(part1).PNG
  		* output_test1(part2).PNG
		* output_test2(part1).PNG
		* output_test2(part2).PNG
	  * State Diagram
		* float.png
		* identifier.png
		* integer.png
		* string.png
	 	* DFA.cpp
		* DFA.hp
		* lex.cpp
		* README.md
  * 3. Top Down Parser
  	* outputs
  		* output_test1(part1).PNG
  		* output_test1(part2).PNG
  		* output_test1(part3).PNG
  		* output_test1(part3_continue).PNG
  		* output_test2(part1).PNG
  		* output_test2(part2).PNG
  		* output_test2(part3).PNG
  		* output_test2(part4).PNG
  		* output_test2(part4_continue).PNG
  	* CFG.txt
  	* CFG2.txt
  	* TopDownParser.cpp
  	* README.md
  * sampleCode
  	* test1.c
  	* test2.c
  * README.md
