#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;

//Class to create date type
class Date
{
	int day;
	int month;
	int year;

public:
	//Constructor
	Date()
	{
		time_t now = time(0);
		tm *ltm = localtime(&now);
		year=1900+ltm->tm_year;
		month=1 + ltm->tm_mon;
		day=ltm->tm_mday;
	}

	friend ostream& operator << (ostream& out,const Date& c);
};

//To display date
ostream& operator << (ostream &ost,const Date &c)
{
	ost<<c.day<<"-"<<c.month<<"-"<<c.year<<endl;
}

class BALANCE;

//Class to define a transaction
class TRANSACTION
{
	int ac_no;
	int type;//1- withdrawal 0-deposit
	Date d;
	double amount;

public:
	TRANSACTION(int ano=0)
	{
		ac_no=ano;
		type=-1;
		amount=0.0;
		Date dt;
		d=dt;
	}

	void transact(BALANCE& b);
	void withdraw(BALANCE& b,double amt);
	void deposit(BALANCE& b, double amt);
	void displayTrans();
};


//Class for balance
class BALANCE
{
	int ac_no;
	Date last_update;
	double balance;
	TRANSACTION t[10];
	int noOfTrans;

public:
	BALANCE(int ano=0)
	{
		ac_no=ano;
		Date d;
		last_update=d;
		balance=0.0;
		noOfTrans=0;
	}
	//Function to increase noOfTrans
	void inNoOfTrans()
	{
		noOfTrans++;
	}
	//Function to set balance
	void setBalance(double b)
	{
		balance=b;
	}
	//Function to get balance
	double getBalance()
	{
		return balance;
	}
	//Fucntion to set date
	void setDate(Date dd)
	{
		last_update=dd;
	}
	//Function to get account no
	int get_ac_no()
	{
		return ac_no;
	}
	//function to show details
	void show()
	{
		cout<<endl<<"Account number: "<<ac_no<<endl<<"Date of last update: "<<last_update<<"Balance: "<<balance<<endl<<endl;
	}
	//Display all transactions for an account
	void displayTransactions()
	{
		int i;
		for(i=0;i<noOfTrans;i++)
			t[i].displayTrans();
	}


};


//==============================================================================================
void TRANSACTION::transact(BALANCE& b)
{
	do
	{
		cout<<"Enter type of transaction :\n"
			<<"\t\t0. Deposit\n"
			<<"\t\t1. Withdrawal\n"
		    <<"Press :";
		cin>>type;
		if(type!=0 && type!=1)
			cout<<"Invalid choice"<<endl;
	}
	while(type!=0 && type!=1);

	do
	{
		cout<<"Enter amount"<<endl;
		cin>>amount;
		if(amount<=0)
			cout<<"Invalid amount"<<endl;
	}
	while(amount<=0);

	if(type==0)
		deposit(b,amount);
	else
		withdraw(b,amount);
}

	//Function to withdraw
void TRANSACTION::withdraw(BALANCE& b,double amt)
{
	if(b.getBalance()<amt)
		cout<<"Insufficient balance"<<endl;
	else
	{
		Date d;
		b.setBalance(b.getBalance()-amt);
		b.setDate(d);
		amount=amt;
		cout<<"Withdrawal successfull"<<endl;
		cout<<"==============================="<<endl;
		displayTrans();
		b.inNoOfTrans();
		cout<<"==============================="<<endl;
	}
}

	//Function to deposit
void TRANSACTION::deposit(BALANCE& b, double amt)
{
	Date d;
	b.setBalance(b.getBalance()+amt);
	b.setDate(d);
	amount=amt;
	cout<<"Deposit successfull"<<endl;
	cout<<"==============================="<<endl;
	displayTrans();
	b.inNoOfTrans();
	cout<<"==============================="<<endl;
}

	//Function to display a transaction
void TRANSACTION::displayTrans()
{
	cout<<"TRANSACTION DETAILS"<<endl;
	string ty=(type==0)?"Deposit":"Withdrawal";
	cout<<"Account number: "<<ac_no<<endl<<"Date: "<<d<<"Type: "<<ty<<endl<<"Amount: "<<amount<<endl;
}

//=====================================================================================================

class BALANCE_LIST
{
	BALANCE list[100];
	int count;

public:
	BALANCE_LIST()
	{
		count=0;
	}
	//Function to get total number
	int getCount()
	{
		return count;
	}
	//Function to add new account
	void addAccount()
	{
		double amount;
		BALANCE b(10000+count);
		do
		{
			cout<<"Enter amount to deposit"<<endl;
			cin>>amount;
			if(amount<=0)
				cout<<"Invalid amount"<<endl;
		}
		while(amount<=0);
		b.setBalance(amount);
		Date d;
		b.setDate(d);
		cout<<"Your account details are "<<endl;
		b.show();
		list[count++]=b;
		cout<<"Account successfully added"<<endl;
	}

	//Function to check whether a ac_no is in list
	int getAcno(int ano)
	{
		int i,flag=0;
		for(i=0;i<count;i++)
		{
			if(list[i].get_ac_no()==ano)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			return i;
		else
			return -1;
	}

	//For transaction
	int transactionWithAcno(int ano)
	{
		if(getAcno(ano)==-1)
		{
			cout<<"Invalid account number"<<endl;
			return 0;
		}
		TRANSACTION temp(ano);
		temp.transact(list[getAcno(ano)]);
		return 1;
	}

	//Get details of an account
	void dispDetails(int ano)
	{
		list[getAcno(ano)].show();
	}

		//Function to display all transactions for a particular account
	void displayAllTrans(int acno)
	{
		list[getAcno(acno)].displayTransactions();
	}

};

int main()
{
	int ch,acno;
	BALANCE_LIST lst;
	cout<<"\n\t\tWELCOME TO ONLINE JU-LAB BANK OF INDIA(OD-BOI)\n"
		<<"\t-----------------------------------------------\n";
	do
	{
		cout<<"1. Add new account\n"
			<<"2. Transact with existing account\n"
			<<"3. Details of an account\n"
			<<"4. Get transactions for an account\n"
			<<"5. Exit\n"
			<<"Enter choice :";
		 
		 cin>>ch;

		switch(ch)
		{
			case 1:
			lst.addAccount();
			break;

			case 2:
			if(lst.getCount()==0)
			{
				cout<<"Add some new account first"<<endl;
				break;
			}
			do
			{
				cout<<"Enter account number"<<endl;
				cin>>acno;
				if(lst.getAcno(acno)==-1)
					cout<<"Invalid account number..Re-enter"<<endl;
			}
			while(lst.getAcno(acno)==-1);
			lst.transactionWithAcno(acno);
			break;

			case 3:
			if(lst.getCount()==0)
			{
				cout<<"Add some new account first"<<endl;
				break;
			}
			do
			{
				cout<<"Enter account number"<<endl;
				cin>>acno;
				if(lst.getAcno(acno)==-1)
					cout<<"Invalid account number..Re-enter"<<endl;
			}
			while(lst.getAcno(acno)==-1);
			lst.dispDetails(acno);
			break;

			case 4:
			if(lst.getCount()==0)
			{
				cout<<"Add some new current account first"<<endl;
				break;
			}
			do
			{
				cout<<"Enter account number"<<endl;
				cin>>acno;
				if(lst.getAcno(acno)==-1)
					cout<<"Invalid account number..Re-enter"<<endl;
			}
			while(lst.getAcno(acno)==-1);
			lst.displayAllTrans(acno);
			break;

			case 5:
			cout<<"Quitting"<<endl;
			exit(0);

			default:
			cout<<"Invalid choice"<<endl;
		}
		

	}
	while(ch!=5);
}

