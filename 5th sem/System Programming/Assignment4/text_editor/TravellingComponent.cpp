

void scroll_down()
{
	if(vc_start < vcy_limit - 5)
	vc_start++;
	view();

	
}

void scroll_up()
{
	if(vc_start > 0)
	vc_start--;
	view();
}

void go_back()
{
	while(1)
	{
		int ch = view_buffer[curr_y][curr_x];
		if(ch != -1) break;
		if(curr_x > 0) curr_x--;
		else if(curr_y == 0) break;
		else //if(curr_x == 0)
		{
			curr_x = vc_width - 1;
			curr_y--;
		}
	}

}

void move_cursor_left(int s = 1)
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

    if(curr_x > 0 && view_buffer[curr_y][curr_x - 1] != -1)
    curr_x--;
	else
	{
		if(curr_y > vc_start)
	    { curr_x = vc_width-1; curr_y--; } 
		else if(curr_y > 0)
		{
			scroll_up();
			curr_y--; curr_x = vc_width-1;
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

void move_cursor_right(int s = 1)
{
	char z;

	if(s)
	if(curr_y >= vc_start && curr_y - vc_start < vc_height)
	{
		move(curr_y - vc_start + 3, curr_x + (WINX + 2));
    	z = inch();
    	printw("%c", z); // remove old cursor
	}

    if(curr_x < vc_width - 1 && view_buffer[curr_y][curr_x + 1] != -1)
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

void move_view_cursor_right()
{
	char z;

	if(curr_y >= vc_start && curr_y - vc_start < vc_height)
	{
		move(curr_y - vc_start + 3, curr_x + (WINX + 2));
    	z = inch();
    	printw("%c", z); // remove old cursor
	}

    if(curr_x < vc_width - 1 && view_buffer[curr_y][curr_x + 1] != -1)
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

void move_cursor_up()
{
	if(curr_y == 0) return;

	char z;
	if(curr_y >= vc_start && curr_y - vc_start < vc_height)
	{	move(curr_y - vc_start + 3, curr_x + (WINX + 2));
    	z = inch();
    	printw("%c", z); // remove old cursor
    }

    int or_x = curr_x, or_y = curr_y;

    int maxitr = vc_width;
    while(maxitr--)
    {
    	if(curr_y < or_y && curr_x <= or_x) break;
    	move_cursor_left(0);
    	//curr_left();
    }
    view();
    print_cursor();

}

void move_cursor_down()
{
	char z;

	if(curr_y >= vc_start && curr_y - vc_start < vc_height)
	{
		move(curr_y - vc_start + 3, curr_x + (WINX + 2));
    	z = inch();
    	printw("%c", z); // remove old cursor
	}

    int or_x = curr_x, or_y = curr_y;

    int maxitr = vc_width;
    while(maxitr--)
    {
    	if(curr_y > or_y && curr_x >= or_x) break;
    	if(curr_y > or_y && view_buffer[curr_y][curr_x+1] == -1) break;
    	move_cursor_right(0);
    	//curr_right();
    }
    view();
    print_cursor();
}


void set_view_cursor();
void highlight(int i, int j)
{
	sel_start = i; sel_end = j;

	while(left_idx < j)
	{
		curr_right();
	}
	while(left_idx > j)
	{
		curr_left();
	}
	set_view_cursor();
	view();
}

void find(string s)
{
	int i,j; int m = s.size();
	for(i=left_idx;i<gb_size() - 1;i++)
	{
		string w = "";
		for(j=i;j<=min(i+m-1,gb_size()-2);j++)
		{
			w += check_gb_at(j);
		}
		//cerr << w << endl;
		if(w == s) { highlight(i,j-1); break; }
	}
}

void replace(string s,string q)
{
	cerr << "ttttt" << endl;
	int i,j; int m = s.size(); int f = 0;
	for(i=left_idx;i<gb_size() - 1;i++)
	{
		string w = "";
		for(j=i;j<=min(i+m-1,gb_size()-2);j++)
		{
			w += check_gb_at(j);
		}
		//cerr << w << endl;
		if(w == s) {  f=1; break; }
	}
	
	if(f == 0) return;

	while(left_idx < j)
	{
		curr_right();
	}
	while(left_idx > j)
	{
		curr_left();
	}

	int x = s.size();
	while(x--)
	{
		E_delete_ch();
	}
	for(int k = 0; k < q.size(); k++)
	{
		E_insert_ch(q[k]);
	}

	load_screen_buffer(0,0,0);
	highlight(i, i+q.size()-1);

}
