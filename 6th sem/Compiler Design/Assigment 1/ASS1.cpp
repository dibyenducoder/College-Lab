#include <bits/stdc++.h>
#define debug(str) cout << str //printf("%s",&str) ; 
using namespace std ; 

set<string> LoadSpeechTypes(string filename); 
void gen_PartsOfSpeech(string line , int row );
void print_PartsOfSpeech();
void read_file(string filename);

vector<pair<string, string> > PrtOfSpeech_list;
vector<pair<int, int> > row_col_list;
set<string> verb ; // constains set of all verbs 
set<string> article ; // contains set of all articles		
set<string> pronoun ;	// contains set of all pronoun 
set<string> preposition ; // contains set of all preposition 

int main()
{
		fstream english;
		english.open("data.txt");
		
		//Loading words or string from the files 
		verb = LoadSpeechTypes("verb.txt");
		article = LoadSpeechTypes("article.txt");
		pronoun = LoadSpeechTypes("pronoun.txt");
		preposition = LoadSpeechTypes("preposition.txt");
		
		read_file("paragraph.txt"); // Read the file  
		
		print_PartsOfSpeech();  // Print which words belongs to the parts of speech 
		return 0 ;
}

//Function to read the types(Verb , Article , etc.) of words and return it to set 
set<string> LoadSpeechTypes(string filename)
{
	const char *file = filename.c_str();
	
	set<string> eng_wrd ; // contains the set of string of files 
	//cout << "Reading Files :" << filename << "\n" ;
	
	fstream fn ; // for opening the file 
	string line ; // for line by line in the file 
	
	fn.open(file,ios::in); //opening the file 
	if(!fn) cout << "Error opening file or File Does Not Exists\n" ; //if file does not exists 
	                  //Error message will display  
	
	while(!fn.eof()) //Looping until the file reach at the end 
	{
		getline(fn , line); //get from each and every line 
		debug(line)  ;
		eng_wrd.insert(line); // get string from the file 
	}
	 
	 
	 return eng_wrd ; 
}

//Function to get the type of parts of speech in which which words belongs to 
void gen_PartsOfSpeech(string line , int row)
{
	int col = 0 ; // declare column as zero 
	string word = " "; // declare word as empty 
	
	for(int i = 0 ; i < line.length() ; i++) // Per line 
	{
		
		if(line[i]>='a' && line[i]<='z' || line[i]>='A' && line[i]<='Z') //if there is a character 
		{
			word += line[i]; 
		}
		//cout << "\n";
		col++; // increment column one by one 
		
		
		if(line[i]=='\t' || line[i]==' ') //if there is a space or tabs 
		{
			debug(word); // for debug  
			if(word !=" ") // if there is atleast a single word or character 
			{
				
				if(verb.count(word)) //if word belongs to verb category 
				{
					PrtOfSpeech_list.push_back(make_pair(word, "Verb")); //then word is verb is pushed  
					row_col_list.push_back(make_pair(row, col-word.length())); //current word location 
	
				}
				if(pronoun.count(word)) //if word belongs to pronoun category
				{
					PrtOfSpeech_list.push_back(make_pair(word, "Pronoun"));
					row_col_list.push_back(make_pair(row, col-word.length()));
	
				}
				if(article.count(word)) //if word belongs to article 
				{
					PrtOfSpeech_list.push_back(make_pair(word, "Article"));
					row_col_list.push_back(make_pair(row, col-word.length()));
	
				}
				if(preposition.count(word)) // if word belongs to preposition 
				{
					PrtOfSpeech_list.push_back(make_pair(word, "Preposition"));
					row_col_list.push_back(make_pair(row, col-word.length()));
	
				}
				
			}
			
			word=" "; //if word is done then word becomes empty 
			 // then go back to the for loop to get another word if exists 
			
		}
		
		
	}
		
	}

// Function to read the file (here , it will read the paragraph) 
void read_file(string filename)
{
	const char *file = filename.c_str() ;
	fstream fn ; 
	string line ; 
	int i =  0 ; 
	fn.open(file , ios::in) ; 
	while(!fn.eof())
	{
		getline(fn , line ) ;
		gen_PartsOfSpeech(line , i) ;
		//debug(line) ;
		i++ ;
	}
}

// Printing the categories along with loaction and words 
void print_PartsOfSpeech()
{
	cout << "\nRows\tColumn\t\tWords\t\tParts Of Speech\n";
	
	for(int i = 0 ; i < PrtOfSpeech_list.size() ; i++)
	{
	//	cout << "-----------------------------------------------------\n";
		cout << row_col_list[i].first << "\t" << row_col_list[i].second << "\t\t" << PrtOfSpeech_list[i].first << "\t\t" << PrtOfSpeech_list[i].second << "\n" ;
	}
}

// End of Code 


