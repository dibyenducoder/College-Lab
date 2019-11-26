#include <bits/stdc++.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
using namespace std;

int WIN_WIDTH = 58; // 58
int WIN_HEIGHT = 26; // 26
int WINX = 26; // 24
int MENUY = 17;

string main_buffer;
int main_idx;
string command; // command on command line (>> ....)
string file; // file name
int curr_x,curr_y; // current cursor position in veiw buffer
WINDOW* win; // main display window
WINDOW* stat; // stat display window
WINDOW* menuwin; // menu window
int mode; // 0 = normal, 1 = insert, 2 = select, 3 = menu
string clip; // clipboard for storing copied/cut text


#include "EditingComponent2.cpp"
#include "ViewingComponent2.cpp"
//#include "TravellingComponent.cpp" 
//travelling component included by viewing comp
#include "Menu.cpp"

#include "CommandLanguageProcessor2.cpp"

int main(int argn, char** args)
{
	system("wmctrl -r :ACTIVE: -b add,maximized_vert,maximized_horz"); // maximize terminal
	freopen("debug.txt", "w", stderr);
	sleep(1);


	file = "";
	if(argn > 1)
	{
		string str(args[1]);
		file = str;
	}

	initscr();                      // Start ncurses mode
    noecho();                       // Don't echo keystrokes
    cbreak();                       // Disable line buffering
    keypad(stdscr, true); 
    start_color();

    curr_x = 0; curr_y = 0;
    dist = 0;
    vc_width = WIN_WIDTH - 4; vc_height = WIN_HEIGHT - 4;
    vc_start = 0;
    mode = 0; // normal mode
    



    win = newwin(WIN_HEIGHT, WIN_WIDTH, WINX, 1);
    stat = newwin(10, 20, 3, WINX + WIN_WIDTH + 2);
    menuwin = newwin(10, 20, MENUY, WINX + WIN_WIDTH + 2);
    

    box1(); // draw box around main text area
    refresh();  // refresh display

    loadgb(); // load editing buffer(linked-list)
    
    header(); // header (top border with filename)

    // char_node* t = ebuffer.start();
    // while(t != NULL)
    // { cerr << (char)t->ch; t = t->next; }
    // endwin();   
    // return 0;


    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(2));

    //loadmb();
    load_screen_buffer(0,0,0); // load screen buffer (2d char_node* array)

    //cerr << "load screen buffer" << endl;

    view();

    //cerr << "view" << endl;
    
    command = "";

    //curs_set(0);

    move(WIN_HEIGHT + 2, WINX);
    int itr = 100;
    while(itr--) printw(" ");
    move(WIN_HEIGHT + 2, WINX);
    attron(COLOR_PAIR(3)); printw(">> ");  attron(COLOR_PAIR(2));
    while(1)
    {
    	print_cursor();
        wrefresh(stat); // refresh stat window
        attron(COLOR_PAIR(3));
    	char ch = getch();
        attron(COLOR_PAIR(2));
        //cerr << (int)ch << endl;
    	commandlanguageprocessor_handle(ch); // handle input key ch
    }

    endwin();  // stop ncurses

	return 0;
}