//NOTE : gb is gap_buffer from earlier implementation, now linked list is being used
//		 for ebuffer (linked_string), function names have not been changed


#include "linked_string.cpp"
#define GMAX 1000000

linked_string ebuffer;
// linked-list-buffer : 1 character -> 1 node

char_node* E_idx;
char_node* sel_start, *sel_end;
vector<string> history;
vector<string> rhistory;



void curr_left() // editing cursor left
{
	ebuffer.curr_left();
	if(mode == 2 && ebuffer.ptr->ch != -2)
	{
		sel_end = ebuffer.ptr; // set selection end in select mode
	}
}

void curr_right() // editing cursor right
{
	ebuffer.curr_right();
	if(mode == 2 && ebuffer.ptr->ch != -2)
	{
		sel_end = ebuffer.ptr; // set selection end in select mode
	}
}

string gb_to_string(); // declarations to handle circular dependency
void loadgb() // load editing buffer from file
{
	if(file.size() == 0) 
	{ return; }
	

	char ch; ebuffer.reset();

	fstream fin(file.c_str(), fstream::in);
	while (fin >> noskipws >> ch) 
	{
		if(ch == '\t')  // replace tab with 3 spaces
		{ 
			ebuffer.insert_ch(' ');
			ebuffer.insert_ch(' ');
			ebuffer.insert_ch(' ');
			continue;
		}
		ebuffer.insert_ch(ch);

	}
	while(ebuffer.curr_left());

	E_idx = ebuffer.start();
	sel_start = NULL; sel_end = NULL;
	history.push_back(gb_to_string());
}

void loadgb_from_string(string s) // load editing buffer from string
{
	char ch;
	// fstream fin(file.c_str(), fstream::in);
	int i = 0; ebuffer.reset();
	while (i < s.size()) 
	{
		ch = s[i];
		if(ch == '\t') // replace tab with 3 spaces
		{
			ebuffer.insert_ch(' ');
			ebuffer.insert_ch(' ');
			ebuffer.insert_ch(' ');
			continue;
		}
		ebuffer.insert_ch(ch);
		i++;
	}
	while(ebuffer.curr_left());
	sel_start = NULL; sel_end = NULL;

	E_idx = 0;
}


string gb_to_string() // get string form editing buffer
{
	int i; string ans = "";
	char_node* t = ebuffer.start();
	while(t != NULL)
	{
		if(t->ch == -2) break;
		ans += (char)t->ch;
		t = t->next;
	}
	return ans;
}



void E_insert_ch(char ch,int h = 1) // insert character into ebuffer
{
	ebuffer.insert_ch(ch);
	if(h)
	history.push_back(gb_to_string());
}



void E_delete_ch(int h = 1) // delete character from ebuffer
{
	ebuffer.delete_ch();
	if(h)
	history.push_back(gb_to_string());
}
