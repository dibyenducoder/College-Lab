#Part - III 
		       Write a Top-Down Parser for the given CFG  
--------------------------------------------------------------------

## Introduction 
---------------------------------------------------
In a top-down parser, the parser begins with the start symbol and tries to guess which productions to apply to reach the input string. To do so, top-down parsers need to use contextual clues from the input string to guide its guesswork.

Most top-down parsers are directional parsers, which scan the input in some direction (typically, left to right) when trying to determine which productions to guess. The LL(k) family of parsers is one example of this - these parsers use information about the next k symbols of input to determine which productions to use.

Typically, the parser uses the next few tokens of input to guess productions by looking at which productions can ultimately lead to strings that start with the upcoming tokens. For example, if you had the production

					A → bC

you wouldn't choose to use this production unless the next character to match was b. Otherwise, you would be guaranteed there was a mismatch. Similarly, if the next input character was b, you might want to choose this production.

So where does left recursion come in? Well, suppose that you have these two productions:

				A → Ab | b

This grammar generates all strings of one or more copies of the character b. If you see a b in the input as your next character, which production should you pick? If you choose Ab, then you're assuming there are multiple b's ahead of you even though you're not sure this is the case. If you choose b, you're assuming there's only one b ahead of you, which might be wrong. In other words, if you have to pick one of the two productions, you can't always choose correctly.
More details about left recursion (Source : https://en.wikipedia.org/wiki/Left_recursion)

The issue with left recursion is that if you have a nonterminal that's left-recursive and find a string that might match it, you can't necessarily know whether to use the recursion to generate a longer string or avoid the recursion and generate a shorter string. Most top-down parsers will either fail to work for this reason (they will report that there is some uncertainty about how to proceed and refuse to parse), or they will potentially use extra memory to track each possible branch, running out of space.

In short, top-down parsers usually try to guess what to do from limited information about the string. Because of this, they get confused by left recursion because they can't always accurately predict which productions to use.


## What is the role of Top Down Parser here ?
-----------------------------------------------------------
Given a context-free grammar on a txt file (as shown CFG.txt , CFG2.txt ), they will remove left recursion and apply on the based on FIRST and FOLLOW sets, and after that it will generate a parse table.

## How to run ?
---------------------------------

The user need c++11 or higher to run the code in Windows.

Step 1 : Compile the code 
Now, compile the code by writing this in terminal :
		g++ TopDownParser -std=c++11

Step 2: Execute the code

Run it:
	  a.exe 

Output Format : 
		*Original Production
		*After removing the left recursion, production prints 
		*First Sets 
		*Follow Sets 
		*Parse Tree 
			|-> row,column 


## What is the need of FIRST AND FOLLOW set ?
-------------------------------------------------
FIRST  of a non-terminal would refer to the very first character of the strings that can be derived starting from that non-terminal. The FIRST of a terminal would be the terminal itself.

The FOLLOW of a non-terminal A refers to the FIRST of the non-terminal or terminal that immediately comes after A in the dervivation rules.

They are used by parsing algorithms(most notable Top Down Parser Algorithm) to determine which production to use for parsing a string. If we have a choice of multiple productions, and we wish to generate a string x we would like to use the productions that can generate strings that start with x. This is where FIRST can be used to identify such productions.

Rules are followed from this source : https://www.cs.uaf.edu/~cs331/notes/FirstFollow.pdf

## Which grammar to run 
------------------------------------
* CFG.txt is the main grammar which is constructed from the simple C-like language.This file is taken from the CFG folder. 
* random_CFG2.txt is the sample random grammar which yields the production error. It is done manually to show whether the parsing can show error or not.  
