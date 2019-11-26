
int vcx,vcy;
int dist;
int vc_width,vc_height;
int vc_start;
int vcy_limit;

int view_buffer[1000][100];


void loadmb()
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

void status()
{
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 5; j++)
			mvwprintw(stat, j, i, " "); // clear previous entry
	
	string s;
	if(mode == 0) s = "normal";
	else if(mode == 1) s = "insert";
	else s = "select";
	mvwprintw(stat, 0, 0, "%s mode", s.c_str());

	int x = curr_x; int y = curr_y;
	mvwprintw(stat, 1, 0, "x:%d y:%d", x, y);

	string t = "";
	int tv = check_gb_at(view_buffer[curr_y][curr_x]);
	if(tv == -2) t += "EOF";
	else
	t += (char)tv;
	if(t == " ") t = "space";
	else if(t == "\n") t = "newline";
	mvwprintw(stat, 2, 0, "ch = %s", t.c_str());
	wrefresh(stat);

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
    z = inch();

    attron(COLOR_PAIR(1));
    attron(A_REVERSE);
    printw("%c", z);
    attroff(A_REVERSE);
    attron(COLOR_PAIR(2));

    status();
    move(WIN_HEIGHT + 2, command.size() + (WINX + 3));

}

void view()
{
	status();
	int vcy = vc_start;
	int vcx = 0;

	int x = WINX + 2, y = 3;
	move(y, x);

	E_idx = view_buffer[vcy][vcx];
	if(E_idx >= sel_start && sel_start <= sel_end)
	attron(A_REVERSE);

	while(y - 3 < vc_height)
	{
		while(x - (WINX+2) < vc_width)
		{
			if(view_buffer[vcy][vcx] == -1)
			printw(".");
			else
			{
				E_idx = view_buffer[vcy][vcx];

				if(sel_start <= sel_end)
				{
					if(E_idx == sel_start)
					attron(A_REVERSE);
					if(E_idx == sel_end+1)
					attroff(A_REVERSE);
				}

				int ch = check_gb_at(E_idx);
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


void space()
{
	char ch = check_gb_at(E_idx);

	while(E_idx < gb_size() && (ch == ' ' || ch == '\n'))
	{
		if(ch == '\n')
		{
			view_buffer[vcy][vcx] = E_idx;
			vcx++;
			while(vcx < vc_width) 
			{
			 	view_buffer[vcy][vcx] = -1; vcx++; 
			}
			vcy++; vcx = 0;
			E_idx++;
			ch = check_gb_at(E_idx);
			continue;
		}
		view_buffer[vcy][vcx] = E_idx;
		vcx++; 
		E_idx++;
		ch = check_gb_at(E_idx);
		if(vcx == vc_width) 
		{ 
			vcy++; vcx = 0;
			move(vcy, vcx);
		}
	}
}

string nextword()
{
	string w = "";
	int or_E_idx = E_idx;
	char ch = check_gb_at(E_idx);
	while(E_idx < gb_size() && ch != ' ' && ch != '\n')
	{
		w += ch;
		E_idx++;
		ch = check_gb_at(E_idx);
		if(w.size() >= 12) break;
	}
	E_idx = or_E_idx;
	return w;
}

void load_screen_buffer(int e_idx, int vcx_i, int vcy_i)
{

	vcx = vcx_i; vcy = vcy_i; E_idx = e_idx;
	while(E_idx < gb_size())
	{
		space();

		string w = nextword();

		//if(mode == 1)
		//cerr << w << endl;

		if(vcx + w.size() >= vc_width)
		{
			while(vcx < vc_width) 
			{ 
			  view_buffer[vcy][vcx] = -1; 
			  vcx++; 
			}
			vcy++; vcx = 0;
		}

		for(int i=0;i<w.size();i++)
		{
			view_buffer[vcy][vcx] = E_idx;
			E_idx++;
			vcx++;
		}
	}

	vcy_limit = vcy;

	while(vcy < 1000)
	{
		while(vcx < vc_width)
		{
			view_buffer[vcy][vcx] = -1;
			vcx++;
		}
		vcy++; vcx = 0;
	}
}

inline bool exists1 (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

string to_string(int x)
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

void header()
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
    print_cursor();

}

void box1()
{
	
	attron(A_REVERSE);
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

	attroff(A_REVERSE);
}


#include "TravellingComponent.cpp"



void set_view_cursor()
{
	curr_x = 0; curr_y = 0;
	int n = left_idx;
	while(n > 0)
	{
		move_view_cursor_right();
		n--;
	}
	view();
	print_cursor();
}


void V_insert_ch(char ch)
{
	E_insert_ch(ch);
	load_screen_buffer(0,0,0);
	view();
	set_view_cursor();
}



void V_delete_ch()
{
	E_delete_ch();
	if(curr_y == vc_start && curr_x == 0) scroll_up();

	load_screen_buffer(0,0,0);
	view();
	set_view_cursor();
}

