#include <iostream>

using namespace std;

class STRING{
	int size;
	char *a;
	public:
		//constructor 
		STRING(int l=0, char c='\0'){
			if(l>0){
				size=l;
				a=new char[size+1];
				a[size]='\0';
				for(int i=0;i<l;i++)
					a[i]=c;
			}
			else{
				size=0;
				a=NULL;
			}
		}

		//copy constructor
		STRING(const STRING& s){
			size=s.size;
			if(size==0)
				a=NULL;
			else{
				//delete a;
				a=new char[size+1];
				a[size]='\0';
				for(int i=0;i<size;i++)
					a[i]=s.a[i];
			}
			//cout<<"Address of string 1 : "<<&(a)<<endl;
			//cout<<"Address of string 2 : "<<&(s.a)<<endl;
		}

		//assignment operator
		void operator =(const STRING& s){
			if(size!=0)
				delete a;
			size=s.size;
			if(size==0)
				a=NULL;
			else{
				a=new char[size+1];
				a[size]='\0';
				for(int i=0;i<size;i++)
					a[i]=s.a[i];
			}
			//cout<<"Address of string 1 : "<<&(a)<<endl;
			//cout<<"Address of string 2 : "<<&(s.a)<<endl;
		}

		//concatenation
		STRING operator +(const STRING& s){
			STRING res;
			res.size=size+s.size;
			res.a=new char[res.size+1];

			for(int i=0;i<size;i++)
				res.a[i]=a[i];

			for(int i=0;i<s.size;i++)
				res.a[size+i]=s.a[i];
			res.a[res.size]='\0';
			//cout<<res.a<<endl; //Concatenation

			return res;
		}

		//equality checker
		bool operator ==(const STRING& s){
			if(size!=s.size)
				return false;
 
			if(size==0 && s.size==0)
				return true;

			for(int i=0;i<size;i++){
				if(a[i]!=s.a[i])
					return false;
			}
			return true;
		}

		//< relational operator
		bool operator <(const STRING& s){
			if(size==0 && s.size==0)
				return false;

			int min=(size<s.size)?size:s.size;
			for(int i=0;i<min;i++){
				if(a[i]<s.a[i])
					return true;

				else if(a[i]>s.a[i])
					return false;
			}
			//if all prev characters are equal
			if(size==s.size)
				return false; //since both are identical
			if(size<s.size)
				return true; //since first string has less characters so str1<str2
			if(size>s.size)
				return false; ////since first string has more characters so str1>str2
		}

		//> relational operator
		bool operator >(const STRING& s){
			if(size==0 && s.size==0)
				return false;

			int min=(size<s.size)?size:s.size;
			for(int i=0;i>min;i++){
				if(a[i]>s.a[i])
					return true;

				else if(a[i]<s.a[i])
					return false;
			}
			//if all prev characters are equal
			if(size==s.size)
				return false; //since both are identical
			if(size>s.size)
				return true; //since first string has more characters so str1>str2
			if(size<s.size)
				return false; ////since first string has less characters so str1<str2
		}

		friend istream& operator >>(istream &in, STRING &s);
		friend ostream& operator <<(ostream &o, STRING const &s);

		//destructor
		~STRING(){
			if(a!=NULL)
				delete a;
		}
};

//for taking string as input
istream& operator >>(istream& in, STRING& s){
	char ch;
	cout<<"Enter length of string : ";
	in>>s.size;
	char* a=new char[s.size+1];
	a[s.size]='\0';
	cout<<"Enter string : ";
	for(int i=0;i<s.size;i++){
		cin>>ch;
		a[i]=ch;
	}
	s.a=a;
	//cout<<s.a<<endl;
	return in;
}
 

//for displaying string
ostream& operator <<(ostream &o, STRING const &s){
	for(int i=0;i<s.size;i++)
		cout<<s.a[i];
	return o;
}


int main(){
	STRING s1, s2, s3;
	int ch,c;
	char s;
	cout<<"\nWELCOME STRING CLASS ~6\n\n";
	do{
		cout<<"\nEnter choice\n"
		    <<"1. Add two strings(i.e CONCATENATION OF STRING)\n"
		    <<"2. Compare two strings\n"
		    <<"3. Make a copy of a string\n"
		    <<"4. Exit\n\n"
		    <<"Enter Your choice :";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter string 1\n";
				cin>>s1;
				cout<<"Enter string 2\n";
				cin>>s2;
				s3=s1+s2;
                                cout<<"\n\nConcatenation Result :\n";
				cout<<s1<<" + "<<s2<<" = "<<s3<<"\n";
				break;
			case 2:
				cout<<"Enter first string\n";
				cin>>s1;
				cout<<"Enter second string\n";
				cin>>s2;
				do{
					cout<<"\t1. <\n";
					cout<<"\t2. ==\n";
					cout<<"\t3. >\n";
					cout<<"\t\tEnter choice:";
					cin>>c; 
					switch(c){
						case 1: //s1 less than s2 checking
							cout<<s1<<" < "<<s2<<" = "<<(s1<s2)<<"\n";
							break;
						case 2: //Equality
							cout<<s1<<" == "<<s2<<" = "<<(s1==s2)<<"\n";
							break;
						case 3://s1 greater than s2 checking
							cout<<s1<<" > "<<s2<<" = "<<(s1>s2)<<"\n";
							break;
						default://wrong checking
							cout<<"Wrong choice. Enter again!\n";
							s='y';
							continue;
					}
					cout<<"Do you want to continue with the same strings? Press C to change strings, N to stop comparing, and 							any other key to continue :";
					cin>>s;
					if(s=='c' || s=='C'){
						cout<<"Which string do you want to change? 1 or 2\n";
						do{
							cin>>c;
							if(c==1){
								cout<<"Enter string 1\n";
								cin>>s1;
							}
							else if(c==2){
								cout<<"Enter string 2\n";
								cin>>s2;	
							}
							else{
								cout<<"Wrong choice...Enter again\n";
							}
						}while(c!=1 && c!=2);
					}
				}while(s!='n' && s!='N');
				break;
			case 3:
				cout<<"Showing value of string 1 at this moment : "<<s1
				    <<"\nEnter string to copy : \n";
				cin>>s2;
				cout<<"Showing value of string s2 : "<<s2<<endl;
				s1=s2;
				cout<<"Showing new value of string 1 : "<<s1<<endl;
				break;
			case 4:
				cout<<"Thank you\n";
				break;
			default:
				cout<<"Wrong choice...Enter again\n";
		}
	}while(ch!=4);
}
