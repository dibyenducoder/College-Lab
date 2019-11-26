

void scroll_down() // scroll text area down (repaint from view buffer's vc_start+1 th row)
{
	if(vc_start < vcy_limit - 5)
	vc_start++;
	view();
}

void scroll_up() // scroll text area up (repaint from view buffer's vc_start-1 th row)
{
	if(vc_start > 0)
	vc_start--;
	view();
}

void go_back() //get cursor to valid cell on view_buffer if it lands on a cell with NULL entry
{
	while(1)
	{
		char_node* ch = view_buffer[curr_y][curr_x];
		if(ch != NULL) break;
		if(curr_x > 0) curr_x--;
		else if(curr_y == 0) break;
		else //if(curr_x == 0)
		{
			curr_x = vc_width - 1;
			curr_y--;
		}
	}

}

void move_cursor_left(int s = 1) // move both cursor left
{

	if(curr_x == 0 && curr_y == 0) return;

	char z;

	if(s)
	if(curr_y >= vc_start && curr_y - vc_start < vc_height)
	{
		move(curr_y - vc_start + 3, curr_x + (WINX + 2));
    	z = inch();
    	printw("%c", z); // remove old cursor
	}

    if(curr_x > 0 && view_buffer[curr_y][curr_x - 1] != NULL)
    curr_x--;
	else
	{
		if(curr_y > vc_start)
	    { curr_x = vc_width - 1; curr_y--; } 
		else if(curr_y > 0)
		{
			scroll_up();
			curr_y--; curr_x = vc_width - 1;
		}

	}
	
	go_back();
	curr_left();

	if(mode == 2)
		view();

	if(s)
    view();
    print_cursor();
}

void move_cursor_right(int s = 1) // move both cursor right
{
	char z;

	if(s)
	if(curr_y >= vc_start && curr_y - vc_start < vc_height)
	{
		move(curr_y - vc_start + 3, curr_x + (WINX + 2));
    	z = inch();
    	printw("%c", z); // remove old cursor
	}

    if(curr_x < vc_width - 1 && view_buffer[curr_y][curr_x + 1] != NULL)
    curr_x++;
	else
	{
		if(curr_y - vc_start < vc_height - 1)
	    { 	curr_y++; curr_x = 0; }
		else
		{
			scroll_down();
			curr_y++; curr_x = 0;
		}
	}
	
	go_back();
	curr_right();

	if(mode == 2)
		view();

	if(s)
    view();
    print_cursor();
}

void move_view_cursor_right() // move only view cursor left
{
	char z;

	if(curr_y >= vc_start && curr_y - vc_start < vc_height)
	{
		move(curr_y - vc_start + 3, curr_x + (WINX + 2));
    	z = inch();
    	printw("%c", z); // remove old cursor
	}

    if(curr_x < vc_width - 1 && view_buffer[curr_y][curr_x + 1] != NULL) // if there is space on right
    curr_x++;
	else
	{
		if(curr_y - vc_start < vc_height - 1)
	    { 	curr_y++; curr_x = 0; }
		else
		{
			scroll_down();
			curr_y++; curr_x = 0;
		}
	}
	
	go_back();
	//curr_right();
}

void move_cursor_up() // move both cursor up
{
	if(curr_y == 0) return;

	char z;
	if(curr_y >= vc_start && curr_y - vc_start < vc_height)
	{	move(curr_y - vc_start + 3, curr_x + (WINX + 2));
    	z = inch();
    	printw("%c", z); // remove old cursor
    }

    int or_x = curr_x, or_y = curr_y; // original(current) x,y

    int maxitr = vc_width; 
    while(maxitr--) // go left(up at end of line) at max vc_width number of times
    {
    	if(curr_y < or_y && curr_x <= or_x) break; // stop if went past original x in previous line
    	move_cursor_left(0);
    	//curr_left();
    }
    view();
    print_cursor();

}

void move_cursor_down() // move both cursor down
{
	char z;

	if(curr_y >= vc_start && curr_y - vc_start < vc_height)
	{
		move(curr_y - vc_start + 3, curr_x + (WINX + 2));
    	z = inch();
    	printw("%c", z); // remove old cursor
	}

    int or_x = curr_x, or_y = curr_y; // original(current) x,y

    int maxitr = vc_width; 
    while(maxitr--) // go right(down at end of line) at max vc_width number of times
    {
    	if(curr_y > or_y && curr_x >= or_x) break; // stop if went past original x in next line
    	if(curr_y > or_y && view_buffer[curr_y][curr_x+1] == NULL) break; // stop if can't go right in next line
    	move_cursor_right(0);
    	//curr_right();
    }
    view();
    print_cursor();
}


void set_view_cursor();
void highlight(char_node* i, char_node* j) // highlight text form i to j-1(j->prev)
{
	sel_start = i; sel_end = j->prev;

	ebuffer.ptr = j->prev;
	set_view_cursor();
	view();
}

void find(string s) // find s
{
	int m = s.size();

	//cerr << s.size() <<" "<< s << endl;

	char_node* i,*j; int f = 0;
	char_node* start = (s.size() > 1)?ebuffer.ptr:ebuffer.ptr->next;

	for(i = start; i != NULL ; i = i->next)
	{
		string w = ""; int n = s.size();
		j = i;
		while(j != NULL && n > 0)
		{
			w += (j->ch);
			n--;
			j = j->next;
		}
		//cerr << w << endl;
		if(w == s) {  highlight(i,j); break; }
	}
}

void replace(string s,string q) // find and replace s with q
{
	//cerr << "ttttt" << endl;
	
	char_node* i,*j; int f = 0;
	char_node* start = (s.size() > 1)?ebuffer.ptr:ebuffer.ptr->next;

	for(i = start; i != NULL ; i = i->next)
	{
		string w = ""; int n = s.size();
		j = i;
		while(j != NULL && n > 0)
		{
			w += (j->ch);
			n--;
			j = j->next;
		}
		//cerr << w << endl;
		if(w == s) {  f=1; break; }
	}
	
	if(f == 0) return;

	ebuffer.ptr = ebuffer.start();
	while(ebuffer.ptr != j) ebuffer.curr_right();

	int x = s.size();
	while(x--)
	{
		E_delete_ch(0);
	}
	for(int k = 0; k < q.size(); k++)
	{
		E_insert_ch(q[k],0);
		if(k == 0) i = ebuffer.ptr->prev;
	}
	load_screen_buffer(0,0,0);
	highlight(i, ebuffer.ptr);
	history.push_back(gb_to_string());
}
