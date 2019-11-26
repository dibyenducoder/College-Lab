
int vcx,vcy;
int dist;
int vc_width,vc_height;
int vc_start;
int vcy_limit;

char_node* view_buffer[1000][100];


void loadmb() // load main buffer (not used)
{
	main_buffer = "";
	if(file.size() == 0) return;
	char ch;
	fstream fin(file.c_str(), fstream::in);
	while (fin >> noskipws >> ch) 
	{
		if(ch == '\t')
			main_buffer += "    ";
		else 
    	main_buffer += ch;
	}
	main_idx = 0;
}

void status() // show status window (upper right)
{
	for(int i = 0; i < 15; i++)
		for(int j = 0; j < 5; j++)
			mvwprintw(stat, j, i, " "); // clear previous entry
	
	string s;
	if(mode == 0) s = "normal";
	else if(mode == 1) s = "insert";
	else if(mode == 2) s = "select";
	else s = "menu";
	mvwprintw(stat, 0, 0, "%s mode", s.c_str()); // mode

	int x = curr_x; int y = curr_y;
	mvwprintw(stat, 1, 0, "x:%d y:%d", x, y); // cursor position

	string t = "";
	int tv = 32;
	if(view_buffer[curr_y][curr_x] != NULL)
	tv = view_buffer[curr_y][curr_x]->ch;
	if(tv == -2) t += "EOF";
	else
	t += (char)tv;
	if(t == " ") t = "space";
	else if(t == "\n") t = "newline";
	mvwprintw(stat, 2, 0, "ch = %s", t.c_str());
	

	// t = "";
	// tv = gap_buffer[left_idx];
	// t += (char)tv;
	// if(t == " ") t = "space";
	// else if(t == "\n") t = "newline";
	// mvwprintw(stat, 3, 0, "E_ch = %s", t.c_str());
	// wrefresh(stat);

	// int gs = gb_size();
	// mvwprintw(stat, 4, 0, "left_idx=%d size=%d", left_idx,gs);
	// wrefresh(stat);

}



void print_cursor()
{
	if(curr_y < vc_start || curr_y - vc_start >= vc_height) return;
	char z;
	move(curr_y - vc_start + 3, curr_x + (WINX + 2));
    z = inch(); // get char at curr_x,curr_y

    attron(COLOR_PAIR(1));
    attron(A_REVERSE);
    printw("%c", z);		// print cursor
    attroff(A_REVERSE);
    attron(COLOR_PAIR(2)); 

    status();
    move(WIN_HEIGHT + 2, command.size() + (WINX + 3)); // move cursor to command line

}


int valid_selection() // check a selection suggested by sel_start,sel_end is valid
{
    if(sel_start == NULL || sel_end == NULL) return 0;
    E_idx = ebuffer.start(); int f = 0;
    while(E_idx != NULL)
    {
        if(E_idx == sel_start)
        {
            if(f == 1) return 0;
            f = 1;
        }
        if(E_idx == sel_end)
        {
            if(f == 0) return 0;
            f = 1;
        }
        E_idx = E_idx->next;
    }
    return 1;

}

void view() // repaint main text area from vc_start th row of view buffer
{
	status();

	int vcy = vc_start;
	int vcx = 0;

	int x = WINX + 2, y = 3;
	move(y, x);

	int sel = valid_selection();


	E_idx = ebuffer.start();
	if(sel)
	while(E_idx != view_buffer[vcy][vcx])
	{
		if(E_idx == sel_start)
		attron(A_REVERSE);
		E_idx = E_idx->next;
	}
	if(sel && E_idx == sel_start)
	attron(A_REVERSE);

	

	while(y - 3 < vc_height)
	{
		while(x - (WINX+2) < vc_width)
		{
			if(view_buffer[vcy][vcx] == NULL)
			printw(".");
			else
			{
				E_idx = view_buffer[vcy][vcx];

				if(sel && E_idx == sel_start)
					attron(A_REVERSE);

				if(sel_end != NULL && E_idx == sel_end->next)
					attroff(A_REVERSE);

				int ch = E_idx->ch;
				if(ch == '\n') ch = ' ';
				else if(ch == -2) ch = '$';
				printw("%c", ch);
			}
			x++; vcx++;
		}
		y++; x = WINX + 2;  vcy++; vcx = 0;
		move(y, x);
	}
}


void space() // input(into view buffer) sequence of space and newline characters
{
	char ch = E_idx->ch;

	while(E_idx != NULL && (ch == ' ' || ch == '\n'))
	{
		if(ch == '\n')
		{
			view_buffer[vcy][vcx] = E_idx;
			vcx++;
			while(vcx < vc_width) 
			{
			 	view_buffer[vcy][vcx] = NULL; vcx++; 
			}
			vcy++; vcx = 0;
			E_idx = E_idx->next;
			if(E_idx != NULL)
			ch = E_idx->ch;
			continue;
		}
		view_buffer[vcy][vcx] = E_idx;
		vcx++; 
		E_idx = E_idx->next;
		if(E_idx != NULL)
		ch = E_idx->ch;
		if(vcx == vc_width) 
		{ 
			vcy++; vcx = 0;
			move(vcy, vcx);
		}
	}
}

string nextword() // input(into view buffer) 1 word (sequence of characters before next space/newline)
{
	string w = "";
	char_node* eb;
	
	eb = E_idx;
	char ch = E_idx->ch;
	while(E_idx != NULL && ch != ' ' && ch != '\n')
	{
		w += ch;
		//cerr << E_idx <<" "<< (char)E_idx->ch<<endl;
		E_idx = E_idx->next;
		if(E_idx != NULL)
		ch = E_idx->ch;
		if(w.size() >= 12) break;
	}
	E_idx = eb;
	return w;
}

void load_screen_buffer(int e_idx, int vcx_i, int vcy_i) // load 2d view_buffer
{

	vcx = vcx_i; vcy = vcy_i; 
	E_idx = ebuffer.start();
	while(E_idx != NULL)
	{
		space();

		string w = nextword();

		//if(mode == 1)
		//cerr << w << endl;

		if(vcx + w.size() >= vc_width)
		{
			while(vcx < vc_width) 
			{ 
			  view_buffer[vcy][vcx] = NULL; 
			  vcx++; 
			}
			vcy++; vcx = 0;
		}

		for(int i=0;i<w.size();i++)
		{
			view_buffer[vcy][vcx] = E_idx;
			E_idx = E_idx->next;
			//cerr << (char)E_idx->ch << endl;
			vcx++;
		}
	}

	vcy_limit = vcy;

	while(vcy < 1000)
	{
		while(vcx < vc_width)
		{
			view_buffer[vcy][vcx] = NULL;
			vcx++;
		}
		vcy++; vcx = 0;
	}
}

inline bool exists1 (const std::string& name) { // whether a file exists
    if (FILE *file1 = fopen(name.c_str(), "r")) {
        fclose(file1);
        return true;
    } else {
        return false;
    }   
}

string to_string(int x) // integer to string
{
	string s = "",ans;
	while(x)
	{
		s += '0' + x%10;
		x = x/10;
	}
	ans = "";
	for(int i=s.size()-1;i>=0;i--)
	{
		ans += s[i];
	}
	return ans;
}

void header() // header (file name on top side of box)
{
	if(file.size() == 0)
	{
		string base = "new-file(";
		int ed = 1;
		string fn = "new-file.txt";
		while(exists1(fn))
		{
			fn = base + to_string(ed) + ").txt";
			ed++;
			//cerr << fn << endl;
		}
		file = fn;
	}
	string s = file;

	attron(A_REVERSE);
   	move(1,WINX);
   	printw(" ");
   	for(int i=0;i<s.size();i++)
   		printw("%c", s[i]);
   	int l = WIN_WIDTH - 1 - s.size();
   	while(l--) printw(" ");
    attroff(A_REVERSE);
  

}

void box1() // draw box around the main text display
{
	
	attron(A_REVERSE); // invert foreground and background colors of the terminal
	for(int i = WINX; i <= WIN_WIDTH + WINX; i++)
	{
		move(1, i);
		printw(" ");
		move(WIN_HEIGHT , i);
		printw(" ");
	}
	for(int i = 1; i <= WIN_HEIGHT; i++)
	{
		move(i, WINX);
		printw(" ");
		move(i, WIN_WIDTH + WINX);
		printw(" ");
	}

	attroff(A_REVERSE); // invert back
}


#include "TravellingComponent2.cpp"



void set_view_cursor() // take view cursor to editing cursor (synchronize cursors)
{
	curr_x = 0; curr_y = 0;
	char_node* t = view_buffer[curr_y][curr_x];
	while(t != ebuffer.ptr)
	{
		move_view_cursor_right();
		t = t->next;
	}
	view();
	print_cursor();
}


void V_insert_ch(char ch) // insert character (both buffers)
{
	E_insert_ch(ch);
	load_screen_buffer(0,0,0);
	view();
	set_view_cursor();
}



void V_delete_ch() // delete character (both buffers)
{
	E_delete_ch();
	if(curr_y == vc_start && curr_x == 0) scroll_up();

	load_screen_buffer(0,0,0);
	view();
	set_view_cursor();
}

