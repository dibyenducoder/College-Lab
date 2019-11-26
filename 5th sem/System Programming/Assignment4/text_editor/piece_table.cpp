#include <bits/stdc++.h>
using namespace std;


class piece{
	int added;
	int start;
	int size;
	piece* next;
	piece* prev;
	piece()
	{
		next = NULL;
		prev = NULL;
	}

};

class char_node{
public:	
	char ch;
	char_node* next;
	char_node* prev;
	char_node()
	{
		next = NULL;
		prev = NULL;
	}
	char_node(char a)
	{
		ch = a;
		next = NULL;
		prev = NULL;
	}
};
class linked_string{
	char_node* ptr;
	linked_string()
	{
		ptr = NULL;
	}
	char curr()
	{
		if(ptr != NULL)
		{
			return ptr->ch;
		}
	}
	void insert_ch(char ch)
	{
		if(ptr != NULL)
		{
			char_node* tmp = ptr->next;
			char_node* nc = new char_node(ch);
			ptr->next = nc;
			nc->next = tmp;
			if(tmp != NULL)
			tmp->prev = nc;
			nc->prev = ptr;

			ptr = ptr->next;
		}
		else
		{
			ptr = new char_node(ch);
		}
	}
	int delete_ch()
	{
		if(ptr->prev == NULL)
			return 0;
		char_node* tmp = ptr->prev;
		ptr->prev = ptr->prev->prev;
		ptr->prev->next = ptr;
		delete tmp;
		return 1;
	}
	int curr_right()
	{
		if(ptr->next == NULL)
			return 0;
		ptr = ptr->next;
	}
	int curr_left()
	{
		if(ptr->prev == NULL)
			return 0;
		ptr = ptr->prev;
	}
	string to_string()
	{
		string ans = "";
		if(ptr == NULL) return ans;

		char_node* t = ptr;
		while(1)
		{
			if(t->prev == NULL)
				break;
			t = t->prev;
		}
		
		while(1)
		{
			if(t == NULL) break;
			ans = ans + t->ch;
			t = t->next;
		}
		return ans;
	}
	int empty()
	{
		if(ptr == NULL)
			return 1;
		return 0;
	}
	void clear()
	{

	}


};

class piece_table{
public:
	string main_buff;
	string add_buff;
	linked_string curr_str;
	piece* curr_piece;
	piece* head;
	int offset;

	piece_table()
	{
		offset = 0;
		head = NULL;
		curr_piece = NULL;
	}

	void insert_ch(char ch)
	{
		
	}

	void delete_ch()
	{

	}

	void curr_left()
	{

	}

	void curr_right()
	{

	}


};