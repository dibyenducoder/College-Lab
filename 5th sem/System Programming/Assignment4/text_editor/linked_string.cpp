// #include <bits/stdc++.h>
// using namespace std;

class char_node{ // character node
public:	
	int ch;
	char_node* next;
	char_node* prev;
	char_node()
	{
		next = NULL;
		prev = NULL;
	}
	char_node(int a)
	{
		ch = a;
		next = NULL;
		prev = NULL;
	}
};


class linked_string{ // doubly linked linked list class
public:
	char_node* ptr; // pointer to current character

	linked_string() // constructor
	{
		ptr = NULL;
		ptr = new char_node(-2); // insert default sentinel(EOF)
	}

	void insert_ch(int ch) // insert character to the left of ptr
	{
		if(ptr == NULL)
		{ 	ptr = new char_node(ch);
			return; }

		char_node* tmp = ptr->prev;
		char_node* nc = new char_node(ch);
		ptr->prev = nc;
		nc->next = ptr;
		if(tmp != NULL)
		tmp->next = nc;
		nc->prev = tmp;
	}
	void delete_ch() // delete character to the left of ptr
	{
		if(ptr == NULL) return;
		if(ptr->prev == NULL)
			return;
		char_node* tmp = ptr->prev;
		ptr->prev = ptr->prev->prev;
		if(ptr->prev != NULL)
		ptr->prev->next = ptr;
		delete tmp;
		return;
	}
	int curr_right()
	{
		if(ptr->next == NULL)
			return 0;
		ptr = ptr->next;
		return 1;
	}
	int curr_left()
	{
		if(ptr->prev == NULL)
			return 0;
		ptr = ptr->prev;
		return 1;
	}
	int peek()
	{
		if(ptr == NULL) return -3;
		if(ptr != NULL)
			return ptr->ch;
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
			ans = ans + (char)t->ch;
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
	int end() // whether ptr is at end of linked list
	{
		if(ptr->ch == -2) return 1;
		return 0;
	}
	void reset() // get ptr ro the first node clear everything
	{
		while(ptr->next != NULL)
			ptr = ptr->next;
		while(ptr->prev != NULL)
		{
			delete_ch();
		}
	}
	char_node* start()
	{
		char_node* t = ptr;
		while(t->prev != NULL) t = t->prev;
		return t;
	}


};


// int main()
// {
// 	linked_string ebuffer;

// 	for(int i = 0; i <= 10; i++)
// 	{
// 		char ch = 'a' + rand()%26;
// 		ebuffer.insert_ch(ch);
// 	}

// 	ebuffer.reset();

// 	while(!ebuffer.end())
// 	{
// 		cout << (char) ebuffer.peek();
// 		ebuffer.curr_right();
// 	}
// 	return 0;
// }