Lex is a tool for building lexical analyzers, that can do some rather lexical stuff like finding keywords, identifiers,etc. Yacc is a parser generator, that can create parsers for real computer languages. Its analysis is normally based upon the output of lex (which is a stream of tokens) and from this we can create our parse-tree of the programming language which is something that is more than lex does.
Therefore,lex and yacc are normally used together. This is how we usually construct an application using both

Input Stream (characters) -> Lex (tokens) -> Yacc (Syntax Tree) -> Our Applcation

From the question 1a., we were told to design a grammar to recognise a string of the form AA...ABB...B, i.e. any number of
`A’s followed by any number of B’s` . Use LEX and YACC to recognise it. Which one is
a better option?
Ans. In my opinion, both are required since Yacc helps us to analyse the structure of the input stream, and operate of the desired output.

In 1b. The answer to the key remains same as the above solution ,the only difference is the strucure and outcome of the program.

---------------------------------------------------------------------------------------------

Q.Which is OS use ? <br/>
Ans.
    
              Linux
 
Q.How did we run ? <br/>
Ans.   

     lex <filename>.l
     yacc -d <filename>.y
     gcc -Wall -o <filename> y.tab.c lex.yy.c (if no mathematical calculation is required...for 1a and 1b)
     gcc -Wall -o <filename> y.tab.c lex.yy.c -lm (if mathematical calculaton is required...for 2 and 3)
 
