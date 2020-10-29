/*
  Name : Dibyendu Mukhopadhyay
  Roll Number : 001710501077 
  Dept : CSE 
  Present Class : BCSEIII 
*/

/*
	Question : 
	Write a program to convert a program written in simple and restricted C language
into a stream of tokens.
*/

//Solution 
#include<bits/stdc++.h>

using namespace std;
#define printdash cout <<"\n---------------------------------------------------------------------------\n"

set<string> loadTokenTypes(string filename);
void tokenize(string line);
void printTokenAndTypes();
void readFileAndTokenize(string filename);
bool isConstant(string word);

vector<pair<string, string> > tokens_list;
vector<pair<int, int> > row_col_list;
set<string> keywords;	// Set of all keywords
set<string> punc;		// Set of all punctuations
set<string> operators;	// Set of all operators

int main()
{
	// Load the keywords
	keywords=loadTokenTypes("keywords.txt");
	// Load the punctuations
	punc=loadTokenTypes("punctuations.txt");
	// Load the operators
	operators=loadTokenTypes("operators.txt");

	// Read the file and tokenize
	readFileAndTokenize("test.c");

	// Print the tokens
	printTokenAndTypes();


	return 0;
}

// Check if a string is a constant
bool isConstant(string word)
{
	int countdec=0; // Number of decimal points
	bool cons=true;
	int i;

	for(i=0;i<word.length();i++)
	{
		if(word[i]=='.')
			countdec++;
		else
		if(word[i]<'0' || word[i]>'9')
		{
			cons=false;
			break;
		}
	}
	return ((countdec<=1) && cons);
}

// Function to read the keywords, etc. form a file and return a set
set<string> loadTokenTypes(string filename)
{
	const char *file = filename.c_str();

	set<string> tokens;
	
	// Open and read file
	fstream fio;
	string line;

	fio.open(file,ios::in);
	if(!fio)
	{
		cout<<"Error in opening file"<<endl;
		exit(0);
	}
	// Read the file
	while(!fio.eof())
	{
		getline(fio, line);
		
		tokens.insert(line);
	}
	return tokens;
}

// Function to tokenize every line
void tokenize(string line, int rownum)
{
	int i, colnum=1;	// colnum stores the current column number
	string word="";
	bool isLiteral=false;
	bool isCharConst=false;
	bool isComment = false ; 

	for(i=0;i<line.length();i++)
	{
		string character(1,line[i]);
		// cout<<word<<endl;
		if(line[i]=='/' && line[i+1]=='/')
		{
			isComment = true ;
		}

		if(line[i]==' ' || line[i]=='\t')
		{
			if(word!="" && !isComment)
			{
				// Check if word is in any of the predefined symbols
				if(keywords.count(word)!=0) // Means it is a keyword
				{
					// Insert it
					// cout<<"Inserting into keyword"<<endl;
					tokens_list.push_back(make_pair(word, "Keyword            "));
				}
				// Check if word is a constant
				else
				if(isConstant(word))
					// Insert it as constant
					tokens_list.push_back(make_pair(word, "Constant           "));
				else
				{
	
					tokens_list.push_back(make_pair(word, "Identifier         "));
				
				}
				row_col_list.push_back(make_pair(rownum, colnum-word.length()));
				word="";
			}
		}
		else
		if(punc.count(character)!=0 && !isComment) //Means it is a punctuation
		{
			// Insert the previously acquired word if it is not null
			if(!isLiteral)	// Case for beginning of literal
			{
				// Start the literal
				tokens_list.push_back(make_pair(character, "Punctuation       "));
				row_col_list.push_back(make_pair(rownum, colnum));
				isLiteral=true;
			}
			else
			if(!isCharConst)
			{
				tokens_list.push_back(make_pair(character, "Punctuation        "));
				row_col_list.push_back(make_pair(rownum, colnum));
				isCharConst=true;
			}
			if(word!="")
			{
				// Check if word is in any of the predefined symbols
				if(keywords.count(word)!=0) // Means it is a keyword
					// Insert it as keyword
					tokens_list.push_back(make_pair(word, "Keyword            "));
				// Check if word is a literal
				else
				if(isLiteral && character=="\"")
				{
					// Then it is end of literal
					isLiteral=false;
					// Insert it as literal
					tokens_list.push_back(make_pair(word, "Literal            "));
				}
				else
				if(isCharConst && character=="\'") //single quotation
				{
					// Then it is end of literal
					isCharConst=false;
					// Insert it as literal
					tokens_list.push_back(make_pair(word, "Character Constant "));
				}
				// Check if word is a constant
				else
				if(isConstant(word))
					// Insert it as constant
					for(int i = 0 ; i < word.length() ; i++)
					{
						if(word[i]=='.')
							{
								tokens_list.push_back(make_pair(word, "Floating point-INUM"));
								break;
							}
						else 
							tokens_list.push_back(make_pair(word, "Integer-INUM       "));
					}
					
				else
					// Insert it as identifier
					tokens_list.push_back(make_pair(word, "Identifier-ID      "));
				row_col_list.push_back(make_pair(rownum, colnum-word.length()));
				word="";
			}
			// If punctuation is within the literal then make sure it is not inserted
			if(!isLiteral && !isCharConst)
			{
				// Also insert the punctuation
				tokens_list.push_back(make_pair(character, "Punctuation        "));
				row_col_list.push_back(make_pair(rownum, colnum));
			}

		}
		else
		if(operators.count(character)!=0 && !isComment) // means if it is an operator
		{
			
			// Insert the previously acquired word if it is not null
			if(word!="")
			{
				// Check if word is in any of the predefined symbols
				if(keywords.count(word)!=0) // Means it is a keyword
					// Insert it as keyword
					tokens_list.push_back(make_pair(word, "Keyword            "));
				// Check if word is a constant
				else
				if(isConstant(word))
					// Insert it as constant
					tokens_list.push_back(make_pair(word, "Constant           "));
				else
					// Insert it as identifier
					tokens_list.push_back(make_pair(word, "Identifier-ID      "));
				row_col_list.push_back(make_pair(rownum, colnum-word.length()));
				word="";
			}

			string tempchar=character+line[i+1];
			// Check case for == , ++ ...
			if(operators.count(tempchar)!=0) // If it is a two character operator
			{
				character+=line[i+1];
				colnum++;
				i++;
			}
			// operators with different types 
			if(character == "+" || character == "-" || character == "*" ||
				character == "/" || character == "%" || character == "++"
				|| character == "--" || character == "+=" || character == "-=" 
				|| character == "*=")
			{
				tokens_list.push_back(make_pair(character, "Arith-operator     "));
			}
			if(character == "<" || character == ">" || character == "==" 
				|| character == "!=" || character == "<=" ||  character == ">=" )
			{
				tokens_list.push_back(make_pair(character, "Rel-operator       "));
			}
			if(character == "&&" || character == "||" || character == "!")
			{
				tokens_list.push_back(make_pair(character, "Logical-operator   "));
			}
			if(character == "&" || character == "|" || character == "^" 
			|| character == "<<" || character == ">>" )
			{
				tokens_list.push_back(make_pair(character, "Bitwise-operator   "));
			}
			row_col_list.push_back(make_pair(rownum, colnum-character.length()+1));
		}
		else
			word+=line[i];
		colnum++;
		if(line[i]=='\t')
			colnum+=3;
	}
}

// Function to read the file and tokenize it
void readFileAndTokenize(string filename)
{
	const char *file = filename.c_str();
	string inc = "#";
	// Open and read file
	fstream fio;
	string line;
	int i=1;
	fio.open(file, ios::in);
	// Read the file
	while(!fio.eof())
	{  
		while(getline(fio, line))
		{
			//ignore #include and #define since it is not part of tokens 
			if (line.find(inc) == string::npos)
			{
			i++ ;
            tokenize(line,i);
			}
		}	

	}
}
// Function to print the tokens and types
void printTokenAndTypes()
{
	
	int i;
	cout << "\t\tSYMBOL TABLE\t\t\n" ;
	printdash ; 
	cout << "Tokenid " << "Tokentype "<< "\t\t\tLexeme " << "\t\tPosition(Row,Col)" << "\n";
	printdash ; 
	for(i=0;i<tokens_list.size();i++)
	{
		cout << i << "\t" << tokens_list[i].second <<"\t\t" << tokens_list[i].first <<
			 "\t\t" << "(" << row_col_list[i].first <<","<< row_col_list[i].second <<")" <<endl;
	}
}