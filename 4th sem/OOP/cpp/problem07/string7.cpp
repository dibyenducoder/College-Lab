#include <iostream>

using namespace std;

class Strng{
	int size;
	int* ref;
	char *a;
	public:
		//constructor 
		Strng(int l=0, char c='\0'){
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
			ref=new int;
			*ref=1;
			cout<<"reference to memory block (cons ):"<<ref<<"="<<*ref<<endl;
		}

		//copy constructor
		Strng(const Strng& s){
			a=s.a;
			size=s.size;
			ref=s.ref;
			*ref=*ref+1;
			cout<<"reference to memory block (copy cons ):"<<ref<<"="<<*ref<<endl;
		}

		//assignment operator
		void operator =(const Strng& s){
			a=s.a;
			size=s.size;
			ref=s.ref;
			*ref=*ref+1;
			cout<<"reference to memory block (op ):"<<ref<<"="<<*ref<<endl;
		}

		//concatenation
		Strng operator +(const Strng& s){
			Strng res;
			res.size=size+s.size;
			res.a=new char[res.size+1];
			for(int i=0;i<size;i++)
				res.a[i]=a[i];
			for(int i=0;i<s.size;i++)
				res.a[size+i]=s.a[i];
			res.a[res.size]='\0';
			cout<<res.a<<endl;
			return res;
		}

		//equality checker
		bool operator ==(const Strng& s){
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
		bool operator <(const Strng& s){
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
		bool operator >(const Strng& s){
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

		friend istream& operator >>(istream &in, Strng &s);
		friend ostream& operator <<(ostream &o, Strng const &s);

		//destructor
		~Strng(){
			*ref=*ref-1;
			cout<<"reference to memory block (=des ):"<<ref<<"="<<*ref<<endl;
			if(*ref==0){
				if(size!=0)
					delete a;
			}
		}
};

//for taking string as input
istream& operator >>(istream& in, Strng& s){
	cout<<"Enter length of string : ";
	in>>s.size;
	char* a=new char[s.size+1];
	a[s.size]='\0';
	cout<<"Enter string : ";
	for(int i=0;i<s.size;i++){
		cin>>a[i];
	}
	s.a=a;
	cout<<s.a<<endl;
	return in;
}
 

//for displaying string
ostream& operator <<(ostream &o, Strng const &s){
	for(int i=0;i<s.size;i++)
		cout<<s.a[i];
	return o;
}


int main(){
	Strng s1, s2, s3;
	int ch,c;
	char s;
	do{
		cout<<"\nEnter choice\n";
		cout<<"1. Add two strings\n";
		cout<<"2. Compare two strings\n";
		cout<<"3. Make a copy of a string\n";
		cout<<"4. Exit\n\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter string 1\n";
				cin>>s1;
				cout<<"Enter string 2\n";
				cin>>s2;
				s3=s1+s2;
				cout<<s1<<" + "<<s2<<" = "<<s3<<"\n";
				break;
			case 2:
				cout<<"Enter first string\n";
				cin>>s1;
				cout<<"Enter second string\n";
				cin>>s2;
				do{
					cout<<"1. <\n";
					cout<<"2. ==\n";
					cout<<"3. >\n";
					cout<<"Enter choice\n";
					cin>>c;
					switch(c){
						case 1:
							cout<<s1<<" < "<<s2<<" = "<<(s1<s2)<<"\n";
							break;
						case 2:
							cout<<s1<<" == "<<s2<<" = "<<(s1==s2)<<"\n";
							break;
						case 3:
							cout<<s1<<" > "<<s2<<" = "<<(s1>s2)<<"\n";
							break;
						default:
							cout<<"Wrong choice. Enter again!\n";
							s='y';
							continue;
					}
					cout<<"Do you want to continue with the same strings? Press C to change strings, N to stop comparing, and any other key to continue\n";
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
				cout<<"Showing value of string 1 at this moment : "<<s1<<"\nEnter string to copy : \n";
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
