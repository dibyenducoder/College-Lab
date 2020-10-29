#include <bits/stdc++.h>
#include <thread>
#include <string>
#include <mutex>
using namespace std;
mutex mu,mu3,mu5,mu6;
int tt=2;  		//transmission time
int nc=0;							
int total_td=0;
struct packet
{
	string s;
	bool f;
	public:
		packet()
		{
			s="";
			f=false;
		}
};
bool flag=false;
int avt=0;
int total_size=16;
packet p;
int finish_count=0;
void delay(int number_of_seconds) 
{ 
    int milli_seconds = 200 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 
void flip(string &r,int i)
{
	if(r[i]=='1')
		r[i]='0';
	else
		r[i]='1';
}
void file_write(string f)
{
	fstream file; 
	string str(total_size,'0');
	for(int i=0;i<total_size/2;i++)
	{
		flip(str,rand()%total_size);
	}
	file.open(f,fstream::out); 
    file<<str;
    file.close(); 
}
string file_open(string f)
{
	fstream file; 
    string word; 
    file.open(f,fstream::in);
    file>>word;
    file.close(); 
    return word; 
}
int frame_size=8;
mutex mu2;
 mutex mu1;
void one_persistent_sender(string s,int i)
{
	string word=file_open(s);
	int l=word.length()/frame_size;
	int count=0;
	int k=0;
	clock_t st = clock();

	while(count<word.length())
	{
		int td = clock();
		while(p.f);
		while(flag);
		mu3.lock();
		p.f=true;
		p.s=word.substr(count,frame_size);
		flag=!flag; 
		delay(tt);
		mu3.unlock();
		if(flag==false)
		{
			mu.lock();
			p.f=false; 
			p.s="";
			flag=false;
		//	cout<<"collision occured for thread "<<i<<endl;
			nc++;
			k++;
			if(k>10)
			{
				cout<<"sending not possible "<<i<<endl;
				finish_count++;
				return;
			}
			
			delay(tt*(rand()%(int)pow(k,2.0)));
			total_td+=(clock()-td);
			mu.unlock();
			continue;
		}
		mu3.lock();
		cout<<"frame no"<<count/frame_size<<"   "<<word.substr(count,frame_size)<<"  thread no "<<i<<endl;
		k=0;
		count+=frame_size;
		p.f=false;
		flag=false;
		total_td+=(clock()-td);
		mu3.unlock();
	}
//	cout<<"data transfer successfull for sender- "<<i<<endl;
	finish_count++;
	clock_t ft = clock();
	avt+=(ft-st);
	return;
}
void p_persistent_sender(string s,int i)
{
	string word=file_open(s);
	int l=word.length()/frame_size;
	int count=0;
	int k=0;
	flag=false;
	clock_t st = clock();
	while(count<word.length())
	{
		int td = clock();
		while(flag);
		while(1)
		{
			
			flag=false;
			srand(time(0));
			int p=rand()%10;
			if(p>3)
			{
				break;
			}
			else
			{
				delay(5);
				while(flag);
			}
			
		}
		mu3.lock();
		p.s=word.substr(count,frame_size);
		flag=!flag; 
		delay(tt);
		mu3.unlock();
		if(flag==false)
		{
			mu.lock();
			p.s="";
			flag=false;
			cout<<"collision occured for thread "<<i<<endl;
			k++;
			nc++;
			if(k>10)
			{
				cout<<"sending not possible "<<i<<endl;
				finish_count++;
				return;
			}
			
			delay(tt*(rand()%(int)pow(k,2.0)));
			total_td+=(clock()-td);
			mu.unlock();
			continue;
		}
		mu3.lock();
		cout<<"frame no "<<count/frame_size<<"   "<<word.substr(count,frame_size)<<"  thread no "<<i<<endl;
		k=0;
		count+=frame_size;
		flag=false;
		total_td+=(clock()-td);
		mu3.unlock();
	}
//	cout<<"data transfer successfull for sender- "<<i<<endl;
	finish_count++;
	clock_t ft = clock();
	avt+=(ft-st);
	return;
}
void non_persistent_sender(string s,int i)
{
	flag=false;
	string word=file_open(s);
	int l=word.length()/frame_size;
	int count=0;
	int k=0;
	clock_t st = clock();
	while(count<word.length())
	{
			int td = clock();
		while(1)
		{
			if(!flag)
			break;
			delay(rand()%2);
			
		}
		mu3.lock();
		p.s=word.substr(count,frame_size);
		flag=!flag; 
		delay(tt);
		mu3.unlock();
		if(flag==false)
		{
			mu.lock();
			p.s="";
			flag=false;
		//	cout<<"collision occured for thread "<<i<<endl;
			k++;
			nc++;
			if(k>10)
			{
				cout<<"sending not possible "<<i<<endl;
				finish_count++;
				return;
			}
			delay(tt*(rand()%(int)pow(k,2.0)));
			total_td+=(clock()-td);
			mu.unlock();
			continue;
		}
		mu3.lock();
		cout<<"frame no "<<count/frame_size<<"   "<<word.substr(count,frame_size)<<"  thread no "<<i<<endl;
		k=0;
		count+=frame_size;
		flag=false;
		total_td+=(clock()-td);
		mu3.unlock();
	}
//	cout<<"data transfer successfull for sender- "<<i<<endl;
	finish_count++;
	clock_t ft = clock();
	avt+=(ft-st);
	return;

}
void menu()
{
	int size=10;
	avt=0;
	string s[size];
	for(int i=0;i<size;i++)
	{
		s[i]="s"+to_string(i)+".txt";
		file_write(s[i]);
	}
	
	while(1)
	{
		finish_count=0;
		total_td=0;
		avt=0;
		int indx;
		cout<<"Enter your choice -1 to exit \n0- one persistent\n1- non persistent\n2- p persistent\n";
		cin>>indx;
		nc=0;
		if(indx==-1)
		break;
		else if(indx==0)
		{
			thread t[size];
			for(int i=0;i<size;i++)
				t[i]=thread(one_persistent_sender,s[i],i);
			while(finish_count!=10);
			for(int i=0;i<size;i++)
				t[i].detach();
		}
		else if(indx==1)
		{
			thread t[size];
			for(int i=0;i<size;i++)
				t[i]=thread(non_persistent_sender,s[i],i);
			while(finish_count!=10);
			for(int i=0;i<size;i++)
				t[i].detach();
		}
		else if(indx==2)
		{
			thread t[size];
			for(int i=0;i<size;i++)
				t[i]=thread(p_persistent_sender,s[i],i);
			while(finish_count!=10);
			for(int i=0;i<size;i++)
				t[i].detach();
		}
		cout<<"Total Collision: "<<nc<<endl;
		cout<<"Total transmission time for all frame: "<<total_td<<endl;
		cout<<"average transmission time: "<<total_td*1.0/(size*total_size/frame_size)<<endl;
		cout<<"Total time taken: "<<avt<<endl;
		cout<<"ThroughPut: "<<120*total_size*size*1.0/avt<<endl;
		cout<<"Efficiency: "<<100.0*(size*total_size/frame_size)/(nc+(size*total_size/frame_size))<<endl;
	}
}
int main()
{
	menu();
}
