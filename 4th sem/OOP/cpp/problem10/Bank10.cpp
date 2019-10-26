#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

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

	friend ostream & operator << (ostream& out,const Date& c);
};

//To display date
ostream & operator << (ostream &ost,const Date &c)
{
	ost<<c.day<<"-"<<c.month<<"-"<<c.year<<endl;
}


class Transaction
{
	int account_number;
	int transaction_type;//1- withdrawal 0-deposit
	Date d;
	double amount;

public:
	Transaction(int ano=0,int t=-1,double a=0)
	{
		account_number=ano;
		transaction_type=t;
		Date dt;
		d=dt;
		amount=a;
	}

	//Function to display a transaction
	void displayTrans()
	{
		//ofstream trns;
		//trns.open("Transaction Account.txt",ios::app);
		//trns<<"\n************************************"<<endl;
		cout<<"\n************************************"<<endl;
		cout<<"TRANSACTION DETAILS"<<endl;
		string ty=(transaction_type==0)?"Deposit":"Withdrawal";
		cout<<"Account number: "<<account_number<<endl<<"Date: "<<d<<"transaction_type: "<<ty<<endl<<"Amount: "<<amount<<endl;
		cout<<"***************************************\n"<<endl;
		//trns.close();
	}
};

/*class account_bank{
	private :
	char type[2][10];
	char depo[2][10];
	public:
	account_bank()
	{
		strcpy(type[0],"SAVING");
		strcpy(type[1],"CURRENT");
		strcpy(depo[0],"DEPOSIT");
		strcpy(depo[1],"WITHDRAW");
	}
	void addtofile(int,int,float);	
};

void account_bank::addtofile(int c,int d,float x)
{
	ofstream fout;
	fout.open("bank_file.txt",ios::out|ios::app);
	fout<<type[c-1]<<" "<<depo[d-1]<<" "<<x<<"\n";
	fout.close();
}
*/
class Account //To store account details an abstract class
{

protected:
	int acno;
	string name;
	double balance;
	Transaction t[100];
	int noOfTrans;

public:
	//Parametrized constructor
	Account(int ano,string na,double bal)
	{
		acno=ano;
		name=na;
		balance=bal;
		noOfTrans=0;
	}
	//Set balance
	void setBal(double b)
	{
		balance=b;
	}
	//Get balance
	double getBal()
	{
		return balance;
	}

	//Get account number
	int getAcno()
	{
		return acno;
	}

	//Function to display account details
	void display()
	{
		ofstream acnt;
		acnt.open("Account.txt",ios::app);
		acnt<<"************************************************************"<<endl;
		acnt<<"YOUR ACCOUNT DETAILS ARE:"<<endl<<"Account number: "<<acno<<endl<<"Name: "<<name<<endl<<"Balance: Rs."<<balance<<endl;
		cout<<"\nYour Balance is stored in Account number: "<<acno<<endl;
		if(balance<0)
		{
			acnt<<"OVERDRAFT\n";
			cout<<"OVERDRAFT\n";
		}
		acnt<<"*************************************************************"<<endl;
		acnt.close();
	}
	
	
	//Display all transactions for an account
	void displayTransactions()
	{
		int i;
		for(i=0;i<noOfTrans;i++)
			t[i].displayTrans();
	}

	//Function to desposit
	virtual void deposit(double d)=0;
	//Function to withdraw
	virtual void withdraw(double d)=0;

};


//Class for savings account
class Savings: public Account
{
public:
	//Constructor
	Savings(int ano=0,string n="",double bal=0.0):Account(ano,n,bal)
	{
	}
	//Overriding deposit
	void deposit(double d)
	{
		Transaction temp(acno,0,d);
		t[noOfTrans++]=temp;
		balance+=d;
		cout<<"Deposit successfull"<<endl;
	}
	//Overriding withdraw
	void withdraw(double d)
	{
		if(balance<=500 || (balance-d)<500)
			cout<<"Cannot withdraw...minimum balance must be maintained"<<endl;
		else
		{
			//Storing all transactions
			Transaction temp(acno,1,d);
			t[noOfTrans++]=temp;

			//Update balance
			balance-=d;
			cout<<"Withdraw successfull"<<endl;
		}
	}

	
};

//Class for current account
class Current: public Account
{
public:
	//Constructor
	Current(int ano=0,string n="",double bal=0.0):Account(ano,n,bal)
	{
	}
	//Overriding deposit
	void deposit(double d)
	{
		Transaction temp(acno,0,d);
		t[noOfTrans++]=temp;

		//Update balance
		balance+=d;
		cout<<"Deposit successfull"<<endl;
	}
	//Overriding withdraw
	void withdraw(double d)
	{
		if(balance<=-20000 || (balance-d)<-20000)
			cout<<"Cannot withdraw..overdraft limit reached"<<endl;
		else
		{
			//Storing all transactions
			Transaction temp(acno,1,d);
			t[noOfTrans++]=temp;

			//Update balance
			balance-=d;
			cout<<"Withdraw successfull"<<endl;
		}
	}

};


//Class for storing all the Savings account
class Savings_list
{
	Savings list[100];
	int count;

private:
	//Function to check whether name is valid
	int isName(string n)
	{
		int flag=1,i;
		for(i=0;i<n.length();i++)
			if(n[i]!=' ')
				if(n[i]<65 || (n[i]>90 && n[i]<97) || n[i]>122)
				{
					flag=0;
					break;
				}
				return flag;
			}

		public:
			Savings_list()
			{
				count=0;
			}

			//Function to get total number of current account
			int getCount()
			{
				return count;
			}
	//Function to add a savings account
			void addSavings()
			{
				double amount;
				string name;

		//Accept name
				do
				{
					cout<<"Enter name of account holder "<<endl;
					cin>>name;
					if(!isName(name))
						cout<<"Name not valid"<<endl;
				}
				while(!isName(name));

		//Accept starting balance
				cin.ignore();
				do
				{

					cout<<"Enter amount to deposit"<<endl;
					cin>>amount;
					if(amount<500)
						cout<<"Invalid amount...at least Rs.500 must be deposited"<<endl;
				}
				while(amount<500);

				Savings s(10000+count,name,amount);

				cout<<"Your account details are "<<endl;
				s.display();
				list[count++]=s;
				cout<<"Account successfully added"<<endl;
			}

	//Function to check whether an account number is in list
			int isPresent(int ano)
			{
				int i,flag=0;
				for(i=0;i<count;i++)
				{
					if(list[i].getAcno()==ano)
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

	//Get details of an account
			void dispDetails(int ano)
			{
				list[isPresent(ano)].display();
			}

	//For transaction
			int transactionWithAcno(int ano)
			{
				int transaction_type;
				double amount;
				do
				{
					cout<<"Enter transaction_type of transaction"<<endl<<"0. Deposit"<<endl<<"1. Withdrawal"<<endl;
					cin>>transaction_type;
					if(transaction_type!=0 && transaction_type!=1)
						cout<<"Invalid choice"<<endl;
				}
				while(transaction_type!=0 && transaction_type!=1);

				do
				{
					cout<<"Enter amount"<<endl;
					cin>>amount;
					if(amount<=0)
						cout<<"Invalid amount"<<endl;
				}
				while(amount<=0);
				if(transaction_type==0)
					list[isPresent(ano)].deposit(amount);
				else
					list[isPresent(ano)].withdraw(amount);
				return 1;
			}

				//Function to display all transactions for a particular account
			void displayAllTrans(int acno)
			{
				list[isPresent(acno)].displayTransactions();
			}

		};



//Class for current account
		class Current_list
		{
			Current list[100];
			int count;

		private:
//Function to check whether name is valid
			int isName(string n)
			{
				int flag=1,i;
				for(i=0;i<n.length();i++)
					if(n[i]!=' ')
						if(n[i]<65 || (n[i]>90 && n[i]<97) || n[i]>122)
						{
							flag=0;
							break;
						}
						return flag;
					}

				public:
					Current_list()
					{
						count=0;
					}

//Function to get total number of current account
					int getCount()
					{
						return count;
					}

//Function to add a savings account
					void addCurrent()
					{
						double amount;
						string name;

//Accept name
						do
						{
							cout<<"Enter name of account holder "<<endl;
							cin>>name;
							if(!isName(name))
								cout<<"Name invalid"<<endl;
						}
						while(!isName(name));

//Accept starting balance
						do
						{
							cin.ignore();
							cout<<"Enter amount to deposit"<<endl;
							cin>>amount;
							if(amount<=0)
								cout<<"Invalid amount...at least Rs.500 must be deposited"<<endl;
						}
						while(amount<=0);

						Current s(20000+count,name,amount);

						cout<<"Your account details are "<<endl;
						s.display();
						list[count++]=s;
						cout<<"Account successfully added"<<endl;
					}

//Function to check whether an account number is in list
					int isPresent(int ano)
					{
						int i,flag=0;
						for(i=0;i<count;i++)
						{
							if(list[i].getAcno()==ano)
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

//Get details of an account
					void dispDetails(int ano)
					{
						list[isPresent(ano)].display();
					}

//For transaction
					int transactionWithAcno(int ano)
					{
						int transaction_type;
						double amount;
						do
						{
							cout<<"Enter transaction_type of transaction"<<endl<<"0. Deposit"<<endl<<"1. Withdrawal"<<endl;
							cin>>transaction_type;
							if(transaction_type!=0 && transaction_type!=1)
								cout<<"Invalid choice"<<endl;
						}
						while(transaction_type!=0 && transaction_type!=1);

						do
						{
							cout<<"Enter amount"<<endl;
							cin>>amount;
							if(amount<=0)
								cout<<"Invalid amount"<<endl;
						}
						while(amount<=0);
						if(transaction_type==0)
							list[isPresent(ano)].deposit(amount);
						else
							list[isPresent(ano)].withdraw(amount);
						return 1;
					}

	//Function to display all transactions for a particular account
					void displayAllTrans(int acno)
					{
						list[isPresent(acno)].displayTransactions();
					}

				};




	int main()
	{
	int ch,acno,choice;
	Savings_list listS;
	Current_list listC;
    cout<<"\n\t\tWELCOME TO ONLINE BANK OF INDIA(OD-BOI)\n"
		<<"\t-----------------------------------------------\n";
	do
	{
		cout<<"1. Add new account\n"
			<<"2. Transact with existing account\n"
			<<"3. Display details of an account\n"
			<<"4. Display transaction details of existing account\n"
			<<"5. Exit\n"
			<<"Enter choice :";
		cin>>ch;

		switch(ch)
		{
			case 1:
			cout<<"1.savings\n2.Current\nYour option : ";
			cin>>choice;

			if(choice==1)
				listS.addSavings();
			else
				listC.addCurrent();
			break;

			case 2:
			cout<<"1.savings\n2.Current\nYour option : ";
			cin>>choice;

			if(choice==1)
			{

				if(listS.getCount()==0)
				{
					cout<<"Add some new savings account first"<<endl;
					break;
				}
				do
				{
					cout<<"Enter account number"<<endl;
					cin>>acno;
					if(listS.isPresent(acno)==-1)
						cout<<"Invalid account number..Re-enter"<<endl;
				}
				while(listS.isPresent(acno)==-1);
				listS.transactionWithAcno(acno);
				break;
			}

			else
			{

				if(listC.getCount()==0)
				{
					cout<<"Add some new current account first"<<endl;
					break;
				}
				do
				{
					cout<<"Enter account number"<<endl;
					cin>>acno;
					if(listC.isPresent(acno)==-1)
						cout<<"Invalid account number..Re-enter"<<endl;
				}
				while(listC.isPresent(acno)==-1);
				listC.transactionWithAcno(acno);
				break;
			}

			case 3:
			cout<<"1.savings\n2.Current\nYour option : ";
			cin>>choice;

			if(choice==1)
			{

				if(listS.getCount()==0)
				{
					cout<<"Add some new savings account first"<<endl;
					break;
				}
				do
				{
					cout<<"Enter account number"<<endl;
					cin>>acno;
					if(listS.isPresent(acno)==-1)
						cout<<"Invalid account number..Re-enter"<<endl;
				}
				while(listS.isPresent(acno)==-1);
				listS.dispDetails(acno);
				break;
			}

			else
			{

				if(listC.getCount()==0)
				{
					cout<<"Add some new current account first"<<endl;
					break;
				}
				do
				{
					cout<<"Enter account number"<<endl;
					cin>>acno;
					if(listC.isPresent(acno)==-1)
						cout<<"Invalid account number..Re-enter"<<endl;
				}
				while(listC.isPresent(acno)==-1);
				listC.dispDetails(acno);
				break;
			}

			case 4:
			cout<<"1.savings\n2.Current\nYour option : ";
			cin>>choice;

			if(choice==1)
			{

				if(listS.getCount()==0)
				{
					cout<<"Add some new savings account first"<<endl;
					break;
				}
				do
				{
					cout<<"Enter account number"<<endl;
					cin>>acno;
					if(listS.isPresent(acno)==-1)
						cout<<"Invalid account number..Re-enter"<<endl;
				}
				while(listS.isPresent(acno)==-1);
				listS.displayAllTrans(acno);
				break;

			}
			else
			{

				if(listC.getCount()==0)
				{
					cout<<"Add some new current account first"<<endl;
					break;
				}
				do
				{
					cout<<"Enter account number"<<endl;
					cin>>acno;
					if(listC.isPresent(acno)==-1)
						cout<<"Invalid account number..Re-enter"<<endl;
				}
				while(listC.isPresent(acno)==-1);
				listC.displayAllTrans(acno);
				break;
			}


			case 5:
			cout<<"Quitting"<<endl;
			exit(0);

			default:
			cout<<"Invalid choice"<<endl;

		}
	}
	while(ch!=9);
	
	return 0;
	}
