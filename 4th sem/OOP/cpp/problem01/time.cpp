#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string.h>
using namespace std; 

class TIME
{
  private :
	int hour,min,sec; //Private member 

  public:
	
	void input_time(){
		do
		{
			string ml ; 
			char c1,c2;
			cout<<"Enter your Time :\n";
			cin >> hour >> c1 >> min >> c2 >> sec;
		    getline(cin, ml);
                        	
			do{
				
		    	if(ml=="") 
		    	{
		    		goto label2;
            }
			    if(c1!=':' && c2!=':')
				{
				   cout<<"Invalid Input ! \n Please put ':'"; 
				} 
			     else if(hour > 12 && (ml=="am" || ml=="pm"))
				{
				   cout<<"Invalid Input !\n 24 Hour Format cannot have am/pm"; break;
				}
				else if(hour == 00  && (ml=="am" || ml=="pm"))
				{
				   cout<<"Invalid Input !\n 24 Hour Format cannot have am/pm"; break;
				}
				else if(hour <=-1 || min <=-1 || sec <=-1)
				{
				   cout<<"Invalid Input ";  
				}
				
			      /*else if(hour<12 && hour>0 || ml[0]!='a' || ml[0]!='p') 
				{
				   cout<<"Invalid input" ; break;		   
	       			}*/
			      

			}while((c1!=':'&&c2!=':') && (ml!="am" || ml!="pm" || ml!=""));
			
			
			label2:
			if(hour<12&&hour>0)         //if hour > 12 then it is considered as 24 hour format as an input
			{
				//cout<<"Enter am/pm/no :";
				//cin>>ml;
				if(ml=="am" && hour < 12)
					hour=hour;
				else if(ml=="pm" && hour < 12)
					hour+=12;
				else if(ml =="am" && hour==12)
					hour=00;
				else if(ml =="pm" && hour==12)
					hour=hour;
				else if(ml =="") 
					goto label ;     //prime merdian is "no" means it is neither am or pm
				/*if(hour>11||hour<0||min<0||min>=60||sec<0||sec>=60)
					cout<<"Invalid input\n";*/
				if(hour>23||hour<0||min<0||min>=60||sec<0||sec>=60)
					cout<<"Invalid input\n";
				
			}
			else if(hour>12||hour<23)
			{
				goto label ;
			}
		}while(hour>23||hour<0||min<0||min>=60||sec<0||sec>=60);
		label:
		do{
				if(hour>23||hour<0||min<0||min>=60||sec<0||sec>=60)
				cout<<"Invalid input\n";
		}while(hour>23||hour<0||min<0||min>=60||sec<0||sec>=60);
	}
	
	
	//Display 24 hour format 
	void show_24hrs() 
	{
			cout<<"Time in 24 hours format : \n"<<setfill('0')<<setw(2)<<hour<<":"<<setfill('0')<<setw(2)<<min<<":"<<setfill('0')<<setw(2)<<sec<<"\n" ; 
	}

	//Display 12 hour format 
	void show_12hrs()
	{
		if(hour>12)
			cout<<"Time in 12 hours format : \n"<<setfill('0')<<setw(2)<<hour%12<<":"<<setfill('0')<<setw(2)<<min<<":"<<setfill('0')<<setw(2)<<sec<<" "<<"pm";
		else if(hour==0)
			cout<<"Time in 12 hours format : \n"<<12<<":"<<setfill('0')<<setw(2)<<min<<":"<<setfill('0')<<setw(2)<<sec<<" "<<"am";
		else if(hour==12 )
			cout<<"Time in 12 hours format : \n"<<12<<":"<<setfill('0')<<setw(2)<<min<<":"<<setfill('0')<<setw(2)<<sec<<" "<<"pm";
		else
			cout<<"Time in 12 hours format : \n"<<setfill('0')<<setw(2)<<hour<<":"<<setfill('0')<<setw(2)<<min<<":"<<setfill('0')<<setw(2)<<sec<<" "<<"am";
	}
	
	//Adding minutes to user input 
	void addminute(int addmin)
	{
		
		
		int a;
	min+=addmin ;
	a=(min/60);
	//hour%=24;
	min%=60;
	if(min<0)
	{
		min+=60; a--;	
	}
	hour+=a;
	hour%=24;
	if(hour<0) hour+=24;
	cout<<"The new time is ---> \n";
	show_12hrs(); 
	cout<<"\n";
	show_24hrs();
	}
	
	void time_diff()//fn for diff between local & input time
	{
		time_t now=time(0);
		tm *ltm=localtime(&now);
		int a,b,c,diff_h,diff_m,diff_s; 
		long d;
		a=ltm->tm_hour;
		b=ltm->tm_min;
		c=ltm->tm_sec;
		cout<<"current local time - "<<a<<":"<<b<<":"<<c<<endl;
		d=abs(3600*(hour-a)+60*(min-b)+(sec-c));  //total diff in seconds
		diff_s=d%60;
		d/=60;
		diff_m=d%60;
		diff_h=d/60;
		cout<<"difference from input time - "<<diff_h<<"hr"<<diff_m<<"min"<<diff_s<<"sec"<<endl;
	}
};

//Main Function
int main()
{
	TIME t; //t is the object of class Time
	int choice,addmin;
	cout<<"\n\t\t---WELCOME TO THE TIME WORLD---\n\n";
	do
	{
		cout<<"\n\nEnter your choice:"
            <<"\n1.Input time in 12 or 24 hours format\n"
			<<"2.Display time in 24 hours format\n"
			<<"3.Display time in 12 hours format\n"
			<<"4.Add minutes with the time value\n"
			<<"5.Display time difference from local time to your time\n"
			<<"6.Exit\n\n"
			<<"Your choice is:";
		//Menu driven of user's choice 
		cin>>choice;
		switch(choice)
		{
			case 1:
				t.input_time();
				break;
				
			case 2:
				t.show_24hrs();
				break;

			case 3:
				t.show_12hrs();
				break;

			case 4:
				cin>>addmin;
				t.addminute(addmin);
				break;
				
			case 5:
				t.time_diff();
				break;

			case 6:
				cout << "Thank You For Using Time ";
				exit(0);

			default:
				cout<<"wrong input!!";
				break;

		}
	}
	while(choice!=6); //if choice is not 6 then the loop will go over until the choice is 6 (exit program)
	return 0;
}
