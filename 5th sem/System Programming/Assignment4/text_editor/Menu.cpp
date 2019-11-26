

vector<string> options;
int sel_idx;
string menu_id;
int menu_in_y;
string menu_str;
int back;


void selection() // highlight seleted option
{
	char z; int x = 1;
	wattron(menuwin, A_REVERSE);
	int itr = 18;
	while(itr--)
	{
		z = mvwinch(menuwin, sel_idx + 1, x);
		mvwprintw(menuwin, sel_idx+1, x, "%c", z);
		x++;
	}

	wattroff(menuwin, A_REVERSE);
}

void display() // repaint display menu window
{
	werase(menuwin);
	box(menuwin,0,0);

	int x = 1, y  = 1;
	for(int i = 0; i < options.size(); i++)
	{
		mvwprintw(menuwin, y, x, options[i].c_str());
		y += 1;
	}

	selection();
	wrefresh(menuwin);
}

void menu(string v = "main") // menu setup
{
	curs_set(0);
	box(menuwin,0,0);

	if(v == "main")
	{
		menu_id = "main";
		options.clear();
		options.push_back("File");
		options.push_back("Edit");
		options.push_back("Search");
		options.push_back("History");
		options.push_back("Close");
		options.push_back("Exit");
	}
	else if(v == "file")
	{
		menu_id = "file";
		options.clear();
		options.push_back("New File");
		options.push_back("Open File");
		options.push_back("Save");
		options.push_back("Save as");
		options.push_back("Back");
	}
	else if(v == "search")
	{
		menu_id = "search";
		options.clear();
		options.push_back("Find");
		options.push_back("Find and Replace");
		options.push_back("Back");
	}
	else if(v == "edit")
	{
		menu_id = "edit";
		options.clear();
        options.push_back("Insert");
		options.push_back("Select");
		options.push_back("Copy");
		options.push_back("Cut");
		options.push_back("Paste");
		options.push_back("Back");
	}
	else if(v == "history")
	{
		menu_id = "history";
		options.clear();
		options.push_back("Undo");
		options.push_back("Redo");
		options.push_back("Back");
	}

	//if(sel_idx >= options.size())
	sel_idx = 0;
	display();
}

void menu_close()
{
	werase(menuwin);
	wrefresh(menuwin);
	curs_set(1);
}


int is_char2(char ch) // check if input is valid char
{
	if(ch >= 'a' && ch <= 'z') return 1;
	if(ch >= 'A' && ch <= 'Z') return 1;
	if(ch >= '0' && ch <= '9') return 1;
	if(ch == '.') return 1;
	if(ch == '-') return 1;
	if(ch == '_') return 1;
	if(ch == ' ') return 1;
	if(ch  == '(' || ch  == ')') return 1;
	if(ch  == '{' || ch  == '}') return 1;
	if(ch  == '[' || ch  == ']') return 1;
	return 0;
}

string menu_input(string s,string prev = "") // handle the string inputs inside menu in while loop
{
	werase(menuwin);
	box(menuwin,0,0);
	back = 0;

	curs_set(1);
	attron(COLOR_PAIR(3));

	menu_str = prev;
	mvwprintw(menuwin, 1, 1, s.c_str());
	wmove(menuwin,2,1);
	
	menu_in_y = 2;

	for(int i = 0; i < prev.size(); i++) // print prev input
	{
		wprintw(menuwin, "%c", prev[i]);
	}

	while(1)
	{
		move(MENUY + 2, WINX + WIN_WIDTH + 3 + min((int)menu_str.size(),17)); // main cursor
		wrefresh(menuwin);
		char ch = getch();
		if(ch == 9 || ch == 27) // escape
		{
			menu_str = "";
			back = 1;
			return "***";
		}
		else if(ch == 10) // enter
		{
			return menu_str;
		}
		else if(ch == 7)
		{
			if(menu_str.size() == 0) continue;
			menu_str = menu_str.substr(0, menu_str.size() - 1);
			wprintw(menuwin, "\b \b");
		}	
		else if(is_char2(ch))
		{
			menu_str += ch;
			if(menu_str.size() <= 17)
			wprintw(menuwin, "%c", ch);
		}
	}
	attron(COLOR_PAIR(2));
	return "ttt";

}


int process_command(); // declarations to handle circular dependency
void rem_command(); // declarations to handle circular dependency
void menu_select() // when enter is pressed - action depending on current selection (menu_id & sel_idx)
{
  	if(menu_id == "main")
    {
    	if(sel_idx == 0) // file
    	{
    		menu("file");
    		return;
    	}
    	if(sel_idx == 1) // edit
    	{
    		menu("edit");
    		return;
    	}
    	if(sel_idx == 2) // search
    	{
    		menu("search");
    		return;
    	}
    	if(sel_idx == 3) // history
    	{
    		menu("history");
    		return;
    	}
    	if(sel_idx == 4) // close
    	{
    		menu_close();
    		mode = 0;
    	}
    	if(sel_idx == 5) // exit
    	{
    		command = "quit";
    		process_command();
    		// rem_command();
    		// menu("main");
    		// return;
    	}
    }
    if(menu_id == "file")
    {
    	if(sel_idx == 0) // new file
    	{	
    		command = "new file";
    		process_command();
    		rem_command();
    		menu("main");
    		return;
    	}	
    	if(sel_idx == 1) // open file
    	{	
    		string op = menu_input("Open:");
    		if(back) 
    		{
    			menu("file");
    			sel_idx = 1;
    			display();
    			return;
    		}
    		command = "open " + op;
    		process_command();
    		rem_command();
    		menu("main");
    		return;
    	}
    	if(sel_idx == 2) // save
    	{
    		command = "save";
    		process_command();
    		rem_command();
    		menu("main");
    		return;
    	}
    	if(sel_idx == 3) // save as
    	{
    		string op = menu_input("Save as:");
    		if(back) 
    		{
    			menu("file");
    			sel_idx = 3;
    			display();
    			return;
    		}
    		command = "saveas " + op;
    		process_command();
    		rem_command();
    		menu("main");
    		return;
    	}
    	if(sel_idx == 4) // back
    	{
    		menu("main");
    		return;
    	}
    }
    if(menu_id == "search")
    {
    	if(sel_idx == 0) // find
    	{
    		string prev = "";
    		while(1)
    		{
	    		string op = menu_input("Find:",prev);
	    		if(back) 
	    		{
	    			menu("search");
	    			sel_idx = 0;
	    			display();	    			
	    			return;
	    		}
	    		prev = op;
	    		find(op);
	    		print_cursor();
	    	}	    	
    		return;
    	}
    	if(sel_idx == 1) // find and replace
    	{
    		string prev = "";
    		string op1,op2;
    		op1 = menu_input("Repalce:",prev);
    		if(back)
    		{
    			menu("search");
    			sel_idx = 1;
    			display();
	    		rem_command();
	    		return;
    		}
    		while(1)
    		{
	    		op2 = menu_input("With:",prev);
	    		if(back) 
	    		{
	    			menu("search");
	    			sel_idx = 1;
	    			display();	    			
	    			return;
	    		}
	    		prev = op2;
	    		replace(op1,op2);
	    		print_cursor();
	    	}	    	
    		return;
    	}
    	if(sel_idx == 2) // back
    	{
    		menu("main");
    		return;
    	}
    }
    if(menu_id == "edit")
    {   
        if(sel_idx == 0) // insert;
        {
            command = "i";
            menu_close();
            mode = 1;
            process_command();
            rem_command();
            return;
        }
    	if(sel_idx == 1) // select
    	{
    		command = "s";
    		menu_close();
    		mode = 2;
    		process_command();
    		rem_command();
    		return;
    	}
    	if(sel_idx == 2) // copy
    	{
    		command = "c";
    		menu_close();
    		mode = 2;
    		process_command();
    		rem_command();
    		return;
    	}
    	if(sel_idx == 3) // cut
    	{
    		command = "x";
    		menu_close();
    		mode = 2;
    		process_command();
    		rem_command();
    		return;
    	}
    	if(sel_idx == 4) // paste
    	{
    		command = "p";
    		menu_close();
    		mode = 2;
    		process_command();
    		rem_command();
    		return;
    	}
    	if(sel_idx == 5) // back
    	{
    		menu("main");
    		return;
    	}
    }
    if(menu_id == "history")
    {
    	if(sel_idx == 0) // undo
    	{
    		command = "u";
    		process_command();
    		rem_command();
    		return;
    	}
    	if(sel_idx == 1) // redo
    	{
    		command = "r";
    		process_command();
    		rem_command();
    		return;
    	}
    	if(sel_idx == 2) // back
    	{
    		menu("main");
    		return;
    	}
    }
}



void menu_handle_ch(char ch) // handle input key ch in menu mode
{
	if(ch == 2) // down
	{
		if(sel_idx < options.size() - 1) sel_idx++; 
		display();
	}
	else if(ch == 3) // up
	{
		if(sel_idx > 0) sel_idx--;
		display();
	}
	else if(ch == 4) // left
	{
		return;
	}
	else if(ch == 5) // right
	{
		return;
	}
	else if(ch == 9 || ch == 27) // escape
    {
    	if(menu_id == "main")
    	{
    		menu_close();
	        mode = 0;
	        return;
    	}
    	if(menu_id == "file")
    	{
    		menu("main");
    		return;
    	}
    	if(menu_id == "search")
    	{
    		menu("main");
    		return;
    	}
        if(menu_id == "edit")
        {
            menu("main");
            return;
        }
        if(menu_id == "history")
        {
            menu("main");
            return;
        }
    	
    }
    else if(ch == 7) // backspace
	{
       return;
	}
    else if(ch == 10) // enter
	{
      menu_select();
	}
	
}