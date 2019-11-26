
vector<string> split(string s) // split s into words
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

int is_char1(char ch)
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
    if(ch == '!' || ch == '@' || ch == '#') return 1;
    if(ch == '$' || ch == '%' || ch == '&') return 1;
    if(ch == '*' || ch == '=' || ch == '+') return 1;
    return 0;
}

void save() // save file
{
    FILE* fp = fopen(file.c_str(), "w");
    char_node* i = ebuffer.start();
    while(i != NULL)
    {
        if(i->ch == -2) break;
        fprintf(fp,"%c",i->ch);
        i = i->next;
    }
    fclose(fp);
}



int process_command()
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
        sel_start = NULL; sel_end = NULL;
        view();
        return 1;
    }
    if(words[0] == "select" || words[0] == "s") // select
    {
        mode = 2;
        sel_start = ebuffer.ptr;

        if(!ebuffer.end())
        sel_end = ebuffer.ptr;
        else
        sel_end = NULL;

        view();
        return 1;
    }
    if(words[0] == "c" && mode == 2) // copy
    {
        if(!valid_selection()) return 0;
        clip = "";
        char_node* i = sel_start;
        while(i != sel_end->next)
        {
            clip += i->ch;
            i = i->next;
        }
        mode  = 0;
        sel_start = NULL; sel_end = NULL;
        view();
        return 1;
    }
    if(words[0] == "x" && mode == 2) // cut
    {
        if(!valid_selection()) return 0;
        clip = "";
        ebuffer.ptr = sel_start;
        while(ebuffer.ptr != sel_end->next)
        {
            clip += ebuffer.ptr->ch;
            ebuffer.curr_right();
        }

        while(1)
        {
            if(ebuffer.ptr->prev == sel_start)
            {
                E_delete_ch(0);
                break;
            }
            E_delete_ch(0);
        }
        //cerr << "cut1" << endl;

        mode  = 0;
        sel_start = NULL; sel_end = NULL;
        load_screen_buffer(0,0,0);
        vc_start = 0;
        view();
        set_view_cursor();



        history.push_back(gb_to_string());
        return 1;
    }
    if(words[0] == "paste" || words[0] == "p") // paste
    {
        for(int i=0;i<clip.size();i++)
        {
            E_insert_ch(clip[i],0);
        }
        sel_start = NULL; sel_end =  NULL;
        load_screen_buffer(0,0,0);
        view();
        set_view_cursor();


        history.push_back(gb_to_string());
        return 1;
    }
    if(words[0] == "find") // find
    {
        if(n <= 1) return 0;
        if(mode != 3)
        mode = 2;
        status();
        find(words[1]);
        return 0;
    }
    if(words[0] == "replace") // find and replace
    {
        if(n <= 2) return 0;
        if(mode != 3)
        mode = 2;
        status();
        replace(words[1],words[2]);
        return 0;
    }
    if(words[0] == "save") // save file
    {
        save();
        return 1;
    }
    if(words[0] == "quit" || words[0] == "q") // quit
    {
        refresh();
        endwin();

        exit(1);
    }
    if(words[0] == "undo" || words[0] == "u") // undo
    {
        int o_curry = curr_y; // curr_y backup
        if(history.size() < 2) return 0;
        string s = history[history.size() - 2];
        rhistory.push_back(history[history.size() - 1]);
        history.pop_back();

        //cerr << s << endl;

        loadgb_from_string(s);
        load_screen_buffer(0,0,0);
        vc_start = 0;
        view();
        set_view_cursor();
        while(o_curry--) move_cursor_down();
    }
    if(words[0] == "redo" || words[0] == "r") // redo
    {
        int o_curry = curr_y; // curr_y backup
        if(rhistory.size() == 0) return 0;
        string s = rhistory[rhistory.size()-1];
        rhistory.pop_back();
        history.push_back(s);
        
        loadgb_from_string(s);
        load_screen_buffer(0,0,0);
        vc_start = 0;
        view();
        set_view_cursor();
        while(o_curry--) move_cursor_down();
    }
    if(words[0] == "new" && words[1] == "file") // open new file
    {
        history.clear();
        rhistory.clear();
        file = "";
        attron(COLOR_PAIR(3));
        header();
        attron(COLOR_PAIR(2));
        loadgb();
        load_screen_buffer(0,0,0);
        vc_start = 0;
        view();
        set_view_cursor();
        return 1;
    }
    if(words[0] == "saveas") // save file as words[1]
    {
        if(n < 2) return 0;
        file = words[1];
        attron(COLOR_PAIR(3));
        header();
        attron(COLOR_PAIR(2));
        save();
        return 1;
    }
    if(words[0] == "reset") // reset display
    {
        attron(COLOR_PAIR(3));
        box1();
        header();
        attron(COLOR_PAIR(2));
        move(WIN_HEIGHT + 2, WINX);
        attron(COLOR_PAIR(3)); printw(">> ");  attron(COLOR_PAIR(2));
        int l = 30; while(l--) printw(" "); //clear command area
        view();
        set_view_cursor();
        return 1;

    }
    if(words[0] == "open") // open file
    {
        history.clear();
        rhistory.clear();
        if(n < 2) return 0;
        file = words[1];
        attron(COLOR_PAIR(3));
        header();
        attron(COLOR_PAIR(2));
        loadgb();
        load_screen_buffer(0,0,0);
        vc_start = 0;
        view();
        set_view_cursor();
        return 1;

    }
    if(words[0] == "menu" || words[0] == "m")
    {
        mode = 3;
        menu();
        return 1;
    }
    return 0;
}

void rem_command() // remove command 
{
    move(WIN_HEIGHT + 2, command.size() + (WINX + 3));
    int x = command.size();
    while(x--) printw("\b \b");
    command = "";
}


void commandlanguageprocessor_handle(char ch)
{
        if(mode == 3)
        {
            menu_handle_ch(ch);
            return;
        }


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
                int sc = process_command();
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
              if(!is_char1(ch)) return;
              attron(COLOR_PAIR(3)); printw("%c", ch);  attron(COLOR_PAIR(2));
    		  command += ch;
            }
            else if(mode == 1)
            {
                V_insert_ch(ch);
            }
    	}

}