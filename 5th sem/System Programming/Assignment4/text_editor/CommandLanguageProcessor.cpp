
vector<string> split(string s)
{
    vector<string> ans; string w = ""; int i;
    for(i=0;i<s.size();i++)
    {
        if(s[i] == ' ')
        {
            if(w.size())
            ans.push_back(w); w = "";
        }
        else if(i == s.size()-1)
        {
            w += s[i];
            ans.push_back(w); w = "";
        }
        else
        {
            w += s[i];
        }
    }

    return ans;
}   


void save()
{
    FILE* fp = fopen(file.c_str(), "w");
    for(int i=0;i<gb_size()-1;i++)
    {
        fprintf(fp,"%c",check_gb_at(i) );
    }
    fclose(fp);
}

int process_comand()
{

    if(command.size() == 0) return 0;

    vector<string> words = split(command);


    if(words.size() == 0) return 0;

    // for(int i=0;i<words.size();i++)
    //     cerr << words[i] << endl;

    
    int n = words.size();
    if(words[0] == "insert" || words[0] == "i") // insert
    {
        mode = 1;
        sel_start = 0; sel_end = -1;
        view();
        return 1;
    }
    if(words[0] == "select" || words[0] == "s") // select
    {
        mode = 2;
        sel_start = left_idx;
        if(left_idx != gb_size() - 1)
        sel_end = left_idx;
        else
        sel_end = 0;

        view();
        return 1;
    }
    if(words[0] == "c" && mode == 2) // copy
    {
        clip = "";
        int i = sel_start;
        while(i <= sel_end)
        {
            clip += check_gb_at(i);
            i++;
        }
        mode  = 0;
        sel_start = 0; sel_end = -1;
        view();
        return 1;
    }
    if(words[0] == "x" && mode == 2) // cut
    {
        clip = "";
        int i = sel_start;
        while(i <= sel_end)
        {
            clip += check_gb_at(i);
            i++;
        }
        curr_right();
        while(sel_start <= sel_end)
        {
            E_delete_ch(0);
            if(left_idx == sel_start)
            {
                break;
            }
        }
        mode  = 0;
        sel_start = 0; sel_end = -1;
        load_screen_buffer(0,0,0);
        vc_start = 0;
        view();
        set_view_cursor();
        history.push_back(gb_to_string());
        return 1;
    }
    if(words[0] == "paste" || words[0] == "p")
    {
        for(int i=0;i<clip.size();i++)
        {
            E_insert_ch(clip[i],0);
        }
        sel_start = 0; sel_end = -1;
        load_screen_buffer(0,0,0);
        view();
        set_view_cursor();


        history.push_back(gb_to_string());
        return 1;
    }
    if(words[0] == "find")
    {
        if(n <= 1) return 0;
        mode = 2;
        status();
        find(words[1]);
        return 0;
    }
    if(words[0] == "replace")
    {
        if(n <= 2) return 0;
        mode = 2;
        status();
        replace(words[1],words[2]);
        return 0;
    }
    if(words[0] == "save")
    {
        save();
        return 1;
    }
    if(words[0] == "quit")
    {
        refresh();
        endwin();

        exit(1);
    }
    if(words[0] == "undo" || words[0] == "u")
    {
        if(history.size() < 2) return 0;
        string s = history[history.size() - 2];
        rhistory.push_back(s);
        history.pop_back();
        loadgb_from_string(s);
        load_screen_buffer(0,0,0);
        view();
        set_view_cursor();
    }
    if(words[0] == "redo" || words[0] == "r")
    {
        if(rhistory.size() == 0) return;
        string s = rhistory[rhistory.size()-1];
        
        loadgb_from_string(s);
        load_screen_buffer(0,0,0);
        view();
        set_view_cursor();
    }
    return 0;
}

void rem_command()
{
    move(WIN_HEIGHT + 2, command.size() + (WINX + 3));
    int x = command.size();
    while(x--) printw("\b \b");
    command = "";
}


void commandlanguageprocessor_handle(char ch)
{
		if(ch == 2) // down
    	{
    		move_cursor_down();
    	}
    	else if(ch == 3) // up
    	{
    		move_cursor_up();
    	}
    	else if(ch == 4) // left
    	{
    		move_cursor_left();
    	}
    	else if(ch == 5) // right
    	{
    		move_cursor_right();
    	}
    	
    	else if(ch == 7) // backspace
    	{
            if(mode == 0 || mode == 2)
            {
    		  if(command.size() == 0) return;
    		  command = command.substr(0,command.size() - 1);
    		  printw("\b \b");
            }
            else if(mode == 1)
            {
                V_delete_ch();
            }
    	}
        else if(ch == 9 || ch == 27) // escape
        {
            mode = 0;
            rem_command();
            view();
        }
    	else if(ch == 10) // enter
    	{
            if(mode == 0 || mode == 2)
            {   
                int sc = process_comand();
                if(sc)
                rem_command();
            }
            else if(mode == 1)
            {
                V_insert_ch('\n');
            }
    	}
    	else
    	{
            if(mode == 0 || mode == 2)
            {
    		  printw("%c", ch);
    		  command += ch;
            }
            else if(mode == 1)
            {
                V_insert_ch(ch);
            }
    	}

}