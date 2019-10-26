#include<bits/stdc++.h>

using namespace std;
template<class T,class U>  //design template for generic type
class BILL
{
	string carno; //car number 
	string date;  //date of entering tolltax
	U amount; //amount of vechicles paid
	public:
	void randvehicle()   //vechicles number generate
	{
		for(int i=0;i<10;i++)
		{
			if(i<6)
			{
				if(i==2 || i==3)
					cout<<char(rand()%10+'0');
				else
					cout<<char(rand()%26+'A');
			}
			else
				cout<<char(rand()%10+'0');
		}
		time_t tt;
		struct tm * ti;
    		time (&tt); 
    		ti = localtime(&tt);
    		date=asctime(ti);
	}
	void datedisp()
	{
		cout<<date<<endl;
	}
};
template<class T,class U>
class TOLLTAX
{
	protected:
	T nocar;
	T way;
	U totalfare;
	U tax[2][3];
	T twoW;  //two wheeler
	T threeW; //three wheeler
	T fourW; //four wheeler
	U prepaid; //mode of payment
	U instant;
	public:
		TOLLTAX()
		{
			nocar=0;
			totalfare=0;
			twoW=0;
			threeW=0;
			fourW=0;
			prepaid=0;
			instant=0;
			tax[0][0]=60; //1 wheeler one way
			tax[0][1]=80;
			tax[0][2]=100;
			tax[1][0]=110; //1 wheeler return
			tax[1][1]=145;
			tax[1][2]=180;
		}
		void recieveToll();
		void displayCar();
		void displayAmt();
		friend void randvehicle();
};

template<class T,class U>
void TOLLTAX<T,U>::recieveToll()
{
	int c,d,e;
	cout<<"\nChoose the type of your Car:\n";
	cout<<"\n1.2 Wheeler\n2.3 Wheeler\n3.4 Wheeler\n";
	cin>>c;
	cout<<"Choose one from the following\n";
	cout<<"\n1.One-Way\n2.Return\n";
	cin>>e;       //way of entering
	if(c>3 || e>2)
	{
		cout<<"\nPlease enter a valid Choice:";
		return;
	}
	nocar++;
	cout<<"\nWhat is the payment method in which you would like to pay:";
	cout<<"\n1.Prepaid\n2.Instant\n";
	cin>>d;
	totalfare=totalfare+tax[e-1][c-1];
	if(d==1)
		prepaid=prepaid+tax[e-1][c-1];
	else
		instant=instant+tax[e-1][c-1];
	if(c==1)
		twoW++;
	else if(c==2)
		threeW++;
	else
		fourW++;
	cout<<"\nHere is your Bill\n";
	BILL<int,float>B;
	cout<<"\nVehicle Number:";
	B.randvehicle();
	cout<<"\nAmount you paid:"<<tax[e-1][c-1];
	if(d==1)
		cout<<"\tPrepaid";
	else
		cout<<"\tInstant";	
	if(e==1)
		cout<<"\nOne-Way";
	else
		cout<<"\nReturn";
	cout<<"\nTime:";
	B.datedisp();
	cout<<"\nIt is Valid for 24 Hours";
	cout<<"\n------------------------------\n";
}
template<class T,class U>
void TOLLTAX<T,U>::displayCar()
{
	cout<<"\n2 Wheeler:"<<twoW;
	cout<<"\n3 Wheeler:"<<threeW;
	cout<<"\n4 Wheeler:"<<fourW;
	cout<<"\nTotal Cars:"<<nocar;
}
template<class T,class U>
void TOLLTAX<T,U>::displayAmt()
{
	cout<<"\nPrepaid:"<<prepaid;
	cout<<"\nInstant:"<<instant;
	cout<<"\nTotal Amount:"<<totalfare;
}
int main()
{
	srand(time(NULL));
	TOLLTAX<int,float>T;
	cout<<"\t\tWELCOME TO TOLLTAX\n\n\n";
	while(1)
	{
		int c;
		cout<<"\n1.Receive Toll\n2.Display Number of Cars\n3.Display Amount\n4.Exit\n";
		cout<<"Enter your Choice :\n";
		cin>>c;
		if(c==1)
			T.recieveToll();
		else if(c==2)
			T.displayCar();
		else if(c==3)
			T.displayAmt();
		else
			break;
	}
	return 0;
}
