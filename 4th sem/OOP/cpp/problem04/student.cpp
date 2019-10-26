#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>

int student=0;
int cseStudent=0;
int electroStudent=0;
int electricStudent=0;
int mechStudent=0;
int code;
using namespace std;
//string crs1;
class STUDENT
{
	string name;
	string dept;
	int roll,year_of_admission;
 public:
   // int roll,year_of_admission;
	int course;   /*computer science , electrical , mechanical , civil*/
	//string name;
	//string dept;
	int marks[5];
	int count[4];
	double sum;	
	double total;
	double average;
	double total_sum;
	int deptChoice;
	//string crs;
public:
	void admission(int c,int y)
	{
		int check=0;
		year_of_admission=y;
		course=c;

		if(course==1)
			{code=1;
			 dept="CSE";
			deptChoice=0;
			 }
		else if(course==2)
			{code=2;
			 dept="ECE";
			deptChoice=1;
			}
		else if(course==3)
			{code=3;
			dept="EE";
			deptChoice=2;
			 }
		else if(course==4)
			{code=4;
			dept="ME";
			deptChoice=3;
			 }

		//roll=y*100000+code*1000+(count[code]+1);
		
		do
		{
			cin.ignore();
			cout<<"Enter student name : ";
			
			getline(cin,name);

			for(int i=0;name[i]!='\0';i++)
			{
				if(name[i]>='0'&&name[i]<='9')
				{
					cout<<"Invalid name format...";
					check=1;
					break;
				}
			}
		}while(check==1);

		//count[code]++;
		switch(deptChoice)
	  {
	  	case 0:
	  		
	  		cseStudent++;
	  		roll=y*100000+code*1000+(count[code]+cseStudent);
	  		cout<<"Admission is successful..\n\tStudent roll number is -- "<<roll<<"\n";
			break;
	  	case 1:
	  		
	  		electroStudent++;
	  		roll=y*100000+code*1000+(count[code]+electroStudent);
	  		cout<<"Admission is successful..\n\tStudent roll number is -- "<<roll<<"\n";
			break;
	  	case 2:
	  		
	  		electricStudent++;
	  		roll=y*100000+code*1000+(count[code]+electricStudent);
	  		cout<<"Admission is successful..\n\tStudent roll number is -- "<<roll<<"\n";
			break;
	  	case 3:
	  		
	  		mechStudent++;
	  		roll=y*100000+code*1000+(count[code]+mechStudent);
	  		cout<<"Admission is successful..\n\tStudent roll number is -- "<<roll<<"\n";
			break;
	  	default :
	  		cout<<"\nWrong option selected";
	  		admission(course,year_of_admission);
	}
	student++;
}

 string student_course()
 {
 	return dept;
 }
	
	void prepare_marksheet()
	{
		sum=0;
		for(int i=0;i<5;i++)
		{
			cout<<"Enter the marks in "<<i+1<<"th subject : ";
			cin>>marks[i];
			if(marks[i]<0||marks[i]>100)
			{
				printf("marks must be between 0 to 100\n");
				//sum+=marks[i];
				i--;
			}
			else sum+=marks[i];
			//total=sum;
			//total=(double)sum/5;
		}
		total=(double)sum/5;
	}

	void show_marksheet()
	{
		average=0;
		cout<<"\t\tSTUDENT INFO ~"<<name<<endl;
		sum=0;
		cout<<"Name : "<<name<<"\n"<<"Roll no : "<<roll<<"\n"<<"course :"<<dept<<"\n";
		for(int i=0;i<5;i++)
		{
			cout<<"Marks in "<<i+1<<"th subject : "<<marks[i]<<"\t";
			cout<<"Grade : ";
			if(marks [i]<=100&&marks[i]>90)
				cout<<"S";
			else if(marks [i]<=90&&marks[i]>80)
				cout<<"A";
			else if(marks [i]<=80&&marks[i]>70)
				cout<<"B";
			else if(marks [i]<=70&&marks[i]>60)
				cout<<"C";
			else if(marks [i]<=60&&marks[i]>50)
				cout<<"D";
			else if(marks [i]<=50&&marks[i]>40)
				cout<<"E";
			else cout<<"X";

			sum+=(double)marks[i];
			cout<<"\n";
		}
		//total_sum = sum;
		average=(double)sum/5;
		//if(total_sum)
		cout<<"average : "<<average<<"%\n";
	}
/*	double percentage(){
		int i;
		for(i=0;i<student;i++)
		{
			average
		}
	}*/
	void no_of_students()
	{
	
		cout<<"SL.No.\t\tCourse\t\tTotal Number of student"<<endl
		    <<"-----------------------------------------------\n"
		    <<"1.\t\tCOMPUTER SCIENCE                   "<<cseStudent<<"\n"
		    <<"2.\t\tELECTRONICS AND TELECOMMUNICATION  "<<electroStudent<<"\n"
		    <<"3.\t\tELECTRICAL                         "<<electricStudent<<"\n"
		    <<"4.\t\tMECHANICAL                         "<<mechStudent<<"\n"
		    <<"-----------------------------------------------\n"
		    <<"Total |No of students :                  "<<student<<endl
		    <<"-----------------------------------------------\n";
		
}
	int getroll()
	{
		return roll;
	}
	friend class TOPPER;
	friend void university_topper();
	friend void dept_topper();
	friend void display();
};

class TOPPER : public STUDENT
{
	public :
		void display()
		{
			cout <<"\nName        :"<<name;
			cout<<"\nRoll Number  :"<<roll;
			cout<<"\nDepartment   :"<<dept;
			cout<<"\nPercentage   :"<<total<<"%\n";
		}
};


STUDENT s[10000];
//STUDENT cse[10000],me[10000],ee[10000],ece[10000];
TOPPER t[1];
void  university_topper()
{
	cout<<"\t\tUniversity Topper ~\n";
	cout<<"\t-------------------------\n";
	int i,j,k,l;
	for(i=0;i<student;i++)
	{
		if (s[i].sum > s[i+1].sum)
		   {	j=i; }
	}
	t[0].name=s[j].name;
	t[0].roll=s[j].roll;
	t[0].dept=s[j].dept;
	t[0].total = s[j].total;
	
	t[0].display();
}

int validate_date(int d,int m,int y)
{
	//validating date
	if(y<1900 || y>2018 || m<1 || m>12 || d<0 || d>31){
		cout<<"Wrong date\nEnter once again\n";
		return 0;
	}
	if(m==2 && ((y%4==0 && d>29) || (y%4!=0 && d>28))){
		cout<<"Wrong date\nEnter once again\n";
		return 0;
	}
	if((m==4 || m==6 || m==9 || m==11) && d>30){
		cout<<"Wrong date\nEnter once again\n";
		return 0;
	}
	time_t today=time(0);
	tm *loc=localtime(&today);
	int yr_tod=1900+loc->tm_year;
	int mn_tod=loc->tm_mon+1;
	int d_tod=loc->tm_mday;
	if(y>yr_tod || (y==yr_tod && m>mn_tod) || (y==yr_tod && m==mn_tod && d>d_tod)){
		cout<<"Cannot use later date\n";
		return 0;
	}
	return 1;
	
}
void display()
{
int i;
int j;
j=0;
    cout<<"\n\t\tJADAVPUR UNIVERSITY STUDENT DETAILS LIST\n\n";
	cout<<"SL NO.\t\tName\t\tRoll Number\t\tDepartment\n";
	cout<<"\n----------------------------------------------------------------------------\n";
	for(i=0;i<student;i++)
	{
		j++;
		cout<<j<<".\t"<<s[i].name<<"\t\t"<<s[i].roll<<"\t\t"<<s[i].dept<<endl;	
	}
	cout<<"\n----------------------------------------------------------------------------\n";
}

int main()
{

	int choice;
	int course_name;
	int d,m,y,index=0,i,r;
	cout<<"\n\t\tWELCOME TO JADAVPUR UNIVERSITY\n";
	do
	{
		cout<<"\n\nEnter the operation:\n"
		    <<"1.Admission\n"
			<<"2.Enter marks\n"
			<<"3.Marksheet display\n"
			<<"4.No. of students\n"
			<<"5.Student Details List\n"
			<<"6.University Topper\n"
			
			<<"7.Exit\n\n"
			<<"Enter your choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"\tCourse Available :\n\t\t1.CSE \n\t\t2.ECE\n\t\t3.EE\n\t\t4.ME\n\n";
				cout<<"Enter the course name : ";
				cin>>course_name;
				
				if(course_name==1||course_name==2||course_name==3||course_name==4)
				{
					do
					{
						cout<<"Enter the date (in dd mm yyyy) : ";
						scanf("%d %d %d",&d,&m,&y);
						if(!validate_date(d,m,y))
								cout<<"\nYou have entered a wrong date,try for another time.";
						else break;
					}while(1);

					s[index].admission(course_name,y);
					index++;
				}
				else
				{
					cout<<"Invalid course name.. Try again later..\n";
					break;
				}
				
				break;
				
			case 2:
				cout<<"Enter roll number : ";
				cin>>r;
				for(i=0;i<index;i++)
				{
					if(s[i].getroll()==r)
					{
						s[i].prepare_marksheet();
						break;
					}
				}
				if(i==index)
					cout<<"The roll is invalid...\n";
				break;

			case 3:
				cout<<"Enter roll number : ";
				cin>>r;
				for(i=0;i<index;i++)
				{
					if(s[i].getroll()==r)
					{
						s[i].show_marksheet();
						break;
					}
				}
				if(i==index)
					cout<<"The roll is invalid...\n";
				break;

			case 4:
				s[index-1].no_of_students();
				break;
			case 5:
				display();
				break;
			
			case 6:
				university_topper();
				break;
			
		/*	case 7:
				dept_topper();
				break;*/
				
			case 7:
				cout<<"\nThank You For Using\n";
				exit(0);
				break;

			default:
				cout<<"Invalid input \n";
				break;

		}
	}while(1);
	return 0;

}

