#define GMAX 1000000

char gap_buffer[GMAX+1];
int left_idx; int right_idx;
int E_idx;
int sel_start, sel_end;
vector<string> history;
vector<string> rhistory;
// left_idx = last character in left span; left_idx = -1 => left span empty
// right_idx = first charcater in right span; right_idx = GMAX => right span empty


int gb_size()
{
	int ans = (left_idx + 1) + (GMAX - right_idx);
	return ans; 
}


void curr_left()
{
	if(left_idx >= 0) 
	{
		gap_buffer[--right_idx] = gap_buffer[left_idx];
		left_idx--;
	}
	if(mode == 2)
	{
		if(left_idx != gb_size() - 1)
		sel_end = left_idx;
	}
}

void curr_right()
{
	if(right_idx < GMAX)
	{
		gap_buffer[++left_idx] = gap_buffer[right_idx];
		right_idx++;
	}
	if(mode == 2)
	{
		if(left_idx != gb_size() - 1)
		sel_end = left_idx;
	}
}

string gb_to_string();
void loadgb()
{
	left_idx = -1; right_idx = GMAX;
	gap_buffer[--right_idx] = -2;

	if(file.size() == 0) 
	{ curr_right(); return; }

	char ch;
	fstream fin(file.c_str(), fstream::in);
	while (fin >> noskipws >> ch) 
	{
		if(ch == '\t')
		{
			gap_buffer[++left_idx] = ' ';
			gap_buffer[++left_idx] = ' ';
			gap_buffer[++left_idx] = ' ';
			continue;
		}
		gap_buffer[++left_idx] = ch;
	}
	while(left_idx > 0)
	{
		curr_left();
	}

	if(left_idx == -1) curr_right();

	E_idx = 0;

	history.push_back(gb_to_string());

}

void loadgb_from_string(string s)
{
	left_idx = -1; right_idx = GMAX;
	gap_buffer[--right_idx] = -2;


	char ch;
	fstream fin(file.c_str(), fstream::in);
	int i = 0;
	while (i < s.size()) 
	{
		ch = s[i];
		if(ch == '\t')
		{
			gap_buffer[++left_idx] = ' ';
			gap_buffer[++left_idx] = ' ';
			gap_buffer[++left_idx] = ' ';
			continue;
		}
		gap_buffer[++left_idx] = ch;
		i++;
	}
	while(left_idx > 0)
	{
		curr_left();
	}

	if(left_idx == -1) curr_right();

	E_idx = 0;
}



char check_gb()
{
	if(E_idx >= 0 && (E_idx <= left_idx || E_idx >= right_idx) && E_idx < GMAX)
	{
		return gap_buffer[E_idx];
	}

	if(left_idx == -1 && right_idx == GMAX) E_idx = GMAX;
	return 0;
}

char check_gb_at(int i)
{
	//cerr <<i<<" -- "<<left_idx<<endl;
	if(i >= 0 && i < gb_size())
	{
		if(i > left_idx)
		{
			int x = (right_idx + i - left_idx - 1);
			//cerr << "idx = " << x << endl;
			char ch = gap_buffer[x];
			return ch;
		}
		return gap_buffer[i];
	}
	return 0;
}

string gb_to_string()
{
	int i; string ans = "";
	for(i=0;i<gb_size() - 1;i++)
	{
		ans += check_gb_at(i);
	}
	return ans;
}


void get_next()
{
	if(left_idx == -1 && right_idx == GMAX) 
	{
		E_idx = GMAX;
		return;
	}

	if(E_idx == left_idx && right_idx == GMAX)
	{
		E_idx = GMAX;
		return;
	}
	else if(E_idx == left_idx) 
	{
		E_idx = right_idx;
		if(E_idx == GMAX) return;
		return;
	}
	else if(E_idx < left_idx)
	{
		E_idx++;
		return;
	}
	else if(E_idx > left_idx && E_idx < right_idx)
	{
		E_idx = right_idx;
		if(E_idx == GMAX) return;
		return;
	}
	else if(E_idx >= right_idx)
	{
		if(E_idx < GMAX) E_idx++;
		if(E_idx == GMAX) return;
		return;
	}
	return;
}

char char_at(int gb_loc)
{
	if(gb_loc <= left_idx)
		return gap_buffer[gb_loc];
}

void move_to(int gb_loc)
{
	while(gb_loc < left_idx)
	{
		curr_left();
	}

	while(gb_loc > left_idx)
	{
		curr_right();
	}
}

void E_insert_ch(char ch,int h = 1)
{
	curr_left();
	gap_buffer[++left_idx] = ch;
	curr_right();
	if(h)
	history.push_back(gb_to_string());
}



void E_delete_ch(int h = 1)
{
	if(left_idx > 0)
	{
		left_idx--;
		gap_buffer[left_idx] = gap_buffer[left_idx+1];
		if(h)
		history.push_back(gb_to_string());
	}
}
