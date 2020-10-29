#Part - II 
			 Scanner for lexical analyzer to generate the streams of tokens 
------------------------------------------------------------------------------------------------

##Introduction
-------------------------------------------------------------
A simple C program that takes a file as an input and after tokenizing the file it finds what each token name is generally, identifier, keyword, separator, operator, literal.


## Requirements 
---------------------

The user need c++11 or higher to run the code in Windows.

Step 1 : Compile the code 
Now, compile the code by writing this in terminal :
		g++ lex.cpp DFA.cpp -std=c++11

Step 2: Execute the code

Run it:
	  a.exe 

Step 3 : Output is generated and the streams of tokens are followed
Format of Output : 
				
				[LEXEME 		 TOKENS]

The streams of tokens will be generated from line to line. 
Each line will be detected.
 
## Where are tokens specified and which data structure is used?
---------------------------------------------------------------
The known tokens are mentioned in later. Well, vector is mainly used to overcome this since it is simple and robust stack like data structure.

## How does each function works ?
-------------------------------------------------
From the lex.cpp, this is used to work the function :


void lexAnalyzeDFA(string token, DFA *identifierDFA, DFA *integerDFA, DFA *floatDFA, DFA *stringDFA);
bool isWhitespace(char ch);
bool isKeyword(string token);
bool isIdentifier(string token, DFA *dfa);
bool isInteger(string token, DFA *dfa);
bool isFloat(string token, DFA *dfa);
bool isConst(string token);
bool isString(string token, DFA *dfa);
bool isOperator(char ch);
bool isSymbol(char ch);
string stripSpaces(string str);


Well, most of the above functions don't need any explanation as they check whether the tokens are specified or not. Another things, lexAnalyzeDFA() function tokenizes the given file to a vector of strings to detect the identifier, integer, float and string. 

## If so, can we detect error ?
-------------------------------------------------------
The answer to this question is obvious. Yes, We also can detect error. 
Frankly speaking, how can we detect error ? 
here, the intro is here :(Source : https://www.geeksforgeeks.org/error-detection-recovery-compiler/)

Lexical errors are detected during the lexical analysis phase. Typical lexical errors are:
   	*Exceeding length of identifier or numeric constants.
    *Appearance of illegal characters
    *Unmatched string

Here, from the lex.cpp, a function lexAnalyzeDFA() is provided to solve this issue. 
			if it is found unknown token then throws error and shows the ERROR in the output as a sign of lexical error.  


## What are the files are provided to code and explain each of the file for coding?
-------------------------------------------------------------------------------------

->lex.cpp :
    This is the main source file. The Lexical Analyzer is for C source code.
	The program will ask the user to input a file name to be lexically analyzed. Then the program will tokenize all of the input file based on delimiters viz.(whitespace, commas, symbols, and operators). 
	These tokens are then analyzed further to determine the type (keyword, identifier, integer, float, operator, symbol). The program then prints out the streams of characters along with the type of that token.

->DFA.h and DFA.cpp :
	These files define a class that makes a DFA. The DFA class is used in lex.cpp to test if tokens are a part of a given langauge. 
	It is essentially a regular expression checker. This is used to see if a given string is a valid C identifier, integer, float or string literal.
	The DFA class takes an input file upon construction, in which it loads in the rules for the language.


## What are the results of the outputs ?
---------------------------------------------------------
test1.c and test2.c  are input files used to test lex.cpp. They are provided in inside the sampleCode folder. 
They contain a simple C source code.

test2.c containes 2 errors for the sake of testing incorrect identifiers. While,the other test file contains valid C code.
identifier.txt, integer.txt, float.txt, and string.txt are used by DFA.cpp to initialize the regular language that the DFA checks. 
keywords and symbols are done without the need to make a DFA because they can be easily checked with some if statements inside lex.cpp.

