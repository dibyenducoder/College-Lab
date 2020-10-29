/* Lexical Analyzer for the C programming language
* First read the README.md file for the description of this program. 
* So that the code will be easier to understand.
*/
#include <bits/stdc++.h>
#include "DFA.h"
#include <tchar.h>

using namespace std;

void lexAnalyzeDFA(string token, DFA *identifierDFA, DFA *integerDFA, DFA *floatDFA, DFA *stringDFA);
bool isWhitespace(char ch);

//Tokens of C 
bool isKeyword(string token);
bool isIdentifier(string token, DFA *dfa);
bool isInteger(string token, DFA *dfa);
bool isFloat(string token, DFA *dfa);
bool isConst(string token);
bool isString(string token, DFA *dfa);
bool isOperator(char ch);
bool isSymbol(char ch);

string stripSpaces(string str);

int flag = 0 ;
int main(int argc, _TCHAR* argv[])
{
	string inputFile , input;
	inputFile = "../sampleCode/";
	cout << "Enter a txt file for lexical analysis: " ;
	cin >> input;

	input = inputFile + input ;

	ifstream file(input);

	if (file.is_open()) {
		string line;	// the line to be read in from file
		string token;	// the token to be analyzed
		char lookahead;	// char that looks ahead for spaces and symobls

		DFA identifierDFA("DFA_for_RE/identifier.txt");
		DFA integerDFA("DFA_for_RE/integer.txt");
		DFA floatDFA("DFA_for_RE/float.txt");
		DFA stringDFA("DFA_for_RE/string.txt");

		cout << setw(24) << left << "LEXEME" << right << "TOKENS" << endl;
		cout << "----------------------------------------\n";
		while (getline(file, line)) {
			
			for (int i = 0; i < line.length(); i++) {
				lookahead = line[i];
				if (isWhitespace(lookahead)) {
					// token can be analyzed since we hit a whitespace
					lexAnalyzeDFA(token, &identifierDFA, &integerDFA, &floatDFA, &stringDFA);
					token.clear();
				} 
				else if (isSymbol(lookahead)) {
					// token can be analyzed since we hit a symbol
					lexAnalyzeDFA(token, &identifierDFA, &integerDFA, &floatDFA, &stringDFA);
					token.clear();
					cout << setw(24) << left << lookahead << right << "Symbol" << endl;
				}
				else if (isOperator(lookahead)) {
					// token can be analyzed since we hit an operator
					lexAnalyzeDFA(token, &identifierDFA, &integerDFA, &floatDFA, &stringDFA);
					token.clear();
					cout << setw(24) << left << lookahead << right << "Operator" << endl;
				}
				else if (lookahead == '"'){
					// token can be analyzed since we hit the start of a string
					lexAnalyzeDFA(token, &identifierDFA, &integerDFA, &floatDFA, &stringDFA);
					token.clear();

					token.push_back(lookahead);
					i++;
					lookahead = line[i];

					while(lookahead != '"') {
						token.push_back(lookahead);
						i++;
						lookahead = line[i];
					}

					token.push_back(lookahead);
				}

				else {
					// didn't hit a delimiter, so append lookahead to token
					token.push_back(lookahead);
				}
			}
		}
		if(flag!=0) cout<<"\n\nLexical Error Detected !\nCode Not Accepted!\n\n"; 
		else cout << "\n\nCode Accepted !\n\n";

	} 
	else {
		cout << "Error : Unable to open file " << input << endl;
	}

	return 0;
}


void lexAnalyzeDFA(string token, DFA *identifierDFA, DFA *integerDFA, DFA *floatDFA, DFA *stringDFA) {
	if (token.length() > 0) 
	{
		if (isKeyword(token)) 
		{
			cout << setw(24) << left << token << right << "Keyword" << endl;
		}

		 else if (isIdentifier(token, identifierDFA)) 
		 {
			cout << setw(24) << left << token << right << "Identifier" << endl;
		} 
		else if (isInteger(token, integerDFA)) 
		{
			cout << setw(24) << left << token << right << "Integer" << endl;
		} 
		else if (isFloat(token, floatDFA))
		{
			cout << setw(24) << left << token << right << "Float" << endl;
		} 
		else if (isString(token, stringDFA)) 
		{
			cout << setw(24) << left << token << right << "String Literal" << endl;
		} 
		else 
		{
			cout << setw(24) << left << token << right << "Error" << endl;
			flag = 1 ;
		}
	}
}

// returns true if the char argument is whitespace or a comma (since commas serve as delimiters in C)
bool isWhitespace(char ch) 
{
	if (ch == ' ' || ch == '\t' || ch == '\n' || ch == ',') {
		return true;
	} else {
		return false;
	}
}

// returns true if the char argument is a special symbol
bool isSymbol(char ch) 
{
	if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch ==';' || ch == '[' || ch == ']') {
		return true;
	} 
	else {
		return false;
	}
}

// returns true if the char argument is an operator
bool isOperator(char ch) 
{
	if (ch == '+' || ch == '-' || ch == '=' || ch == '/' || ch =='*' || ch =='%' || ch =='<' || ch=='>') {
		return true;
	} 
	else {
		return false;
	}
}

//returns true if the token is a keyword 
bool isKeyword(string token)
 {
	if (token == "for" || token == "while" || token == "if" || token == "else" || token == "int" || token == "float"
		|| token == "short" || token == "do" || token == "char" || token == "return" || token == "auto" || token == "struct" || token == "union"
		|| token == "break" || token == "long" || token == "double" || token == "const" || token == "unsigned" || token == "switch" || token == "continue"
		|| token == "signed" || token == "void" || token == "case" || token == "enum" || token == "register" || token == "typedef" || token == "default"
		|| token == "goto" || token == "extern" || token == "static" || token == "string") {
		return true;
	} 
	else 
	{
		return false;
	}
}

bool isIdentifier(string token, DFA *dfa)
 {
	return dfa->inLanguage(token);
}

bool isInteger(string token, DFA *dfa) 
{
	return dfa->inLanguage(token);
}

bool isFloat(string token, DFA *dfa) 
{
	return dfa->inLanguage(token);
}

bool isString(string token, DFA *dfa) 
{
	return dfa->inLanguage(stripSpaces(token));
}

string stripSpaces(string str) 
{
	string noSpaces;
	for (int i = 0; i < str.length(); i++) 
	{
		if (str[i] != ' ') {
			noSpaces.push_back(str[i]);
		}
	}
	return noSpaces;
}
