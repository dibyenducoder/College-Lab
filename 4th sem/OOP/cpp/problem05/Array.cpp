#include<iostream>

using namespace std;

class Array
{
	int size;
	int* arr;

public:
	//Parametrized constructor
	Array(int s=0,int a=0)
	{
		if(s>0)
		{
			size=s;
			arr=new int[size];
			for(int i=0;i<size;i++)
				arr[i]=a;
		}
		else{
			size=0;
			arr=NULL;
		}
	}
	//Copy constructor
	Array(const Array& a)
	{
		size=a.size;
		arr=new int[a.size];
		for(int i=0;i<size;i++)
			arr[i]=a.arr[i];

	}
	//Constructor for initialisation with another Array
	Array(const int* Array)
	{	
		// size=len(Array);
		// arr=new int[size];
		int i;
		for(i=0;i<size;i++)
			arr[i]=Array[i];

	}

	void operator =(const int* a)
	{	

		int i;
		for(i=0;i<size;i++)
			arr[i]=a[i];

	}

	//to make a=b do the assignment
	void operator =(const Array& a)
	{

		size=a.size;
		arr=new int[a.size];
		int i;
		for(i=0;i<size;i++)
			arr[i]=a.arr[i];
	}

	//a+b will add the corresponding elements
	Array operator +(Array b)
	{
		//Validate
		Array c(b.size,0);
		int i;
		for(i=0;i<size;i++)
			c.arr[i]=arr[i]+b.arr[i];
		return c;
	}

	//a[k] will return kth element
	int operator [](int i)
	{
		return arr[i];
	}

	//a*5 will multiply the elements with 5
	Array operator *(int n)
	{
		int i;
		Array c(size,0);
		for(i=0;i<size;i++)
			c.arr[i]=n*arr[i];
		return c;
	}

	//Function to get size of Array
	int getSize()
	{
		return size;
	}

	//Function to display Array
	void display()
	{
		int i;
		for(i=0;i<size;i++)
			cout<<arr[i]<<" ";

	}

	friend Array operator *(int n,Array a);
	friend ostream & operator <<(ostream& o,Array& a);
	friend istream& operator >>(istream& in, Array& a);

};

Array operator *(int n, Array a)
{
	Array c(a.size);
	for(int i=0;i<a.size;i++)
		c.arr[i]=n*a.arr[i];
	return c;
}

ostream & operator <<(ostream& o,Array& a)
{
	o<<"Size : "<<a.size<<endl;
	for(int i=0;i<a.size;i++)
		o<<a.arr[i]<<" ";
	o<<endl;
	return o;
}

istream& operator >>(istream& in,Array& a){
	int x;
	cout<<"Enter length of array : ";
	do{
		in>>a.size;
		if(a.size<0)
			cout<<"Wrong choice..Enter again!!\n";
		else
			break;
	}while(1);
	int* ar=new int[a.size];
	//a[s.size]='\0';
	cout<<"Enter array elements : \n";
	for(int i=0;i<a.size;i++){
		cout<<"Element "<<(i+1)<<" : ";
		cin>>x;
		ar[i]=x;
	}
	a.arr=ar;
	return in;
}

int main()
{
	int ch,size=0,i,ind;
	int* arr1;
	int* arr2;
	Array a1;
	Array a2;
	cout<<"\t\t\tWELCOME TO ARRAY WORLD--\n\n";
	do
	{
		cout<<"1. Enter 2 arrays --\n"
		      "2. Add the 2 arrays --\n"
		      "3. Multiply first array by scalar --\n"
		      "4. Get ith element of first array --\n"
		      "5. Make a copy of an Array object into the first array --\n"
		      "6. Make a copy of an array into the first array(Not as an Object) --\n"
		      "7.Exit\n"
		      "\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"Enter first array\n";
				cin>>a1;
				size++;
				cout<<a1;
				cout<<"Enter second array\n";
				cin>>a2;
				size++;
				cout<<a2;
			break;
		}
			case 2:
			
			{
				if(size==0)
				{
					cout<<"First enter two Arrays"<<endl;
					break;
				}
				else
					if(a1.getSize()!=a2.getSize())
					{
						cout<<"Can't add arrays with different lengths"<<endl;
						break;
					}
					Array sum(a1.getSize());
					sum=a1+a2;
					cout<<"Sum : ";
					cout<<sum<<endl;
					break;
				}
				

				case 3:
				{
					if(size==0)
					{
						cout<<"First enter two Arrays"<<endl;
						break;
					}
					int n;
					cout<<"First array "<<endl<<a1;
					cout<<"Enter scalar"<<endl;
					cin>>n;
					Array f(a1.getSize(),0);
					f=n*a1;
					cout<<"Doing "<<n<<"*a1 gives "<<endl;
					cout<<f<<endl;
					f=a1*n;
					cout<<"Doing a1*"<<n<<" gives"<<endl;
					cout<<f<<endl;
					break;
				}

				case 4:
				{
					if(size==0)
					{
						cout<<"First enter two Arrays"<<endl;
						break;
					}
					do
					{
						cout<<"First array "<<endl<<a1;
						cout<<"Enter index"<<endl;
						cin>>ind;
						if(ind>=a1.getSize() || ind<0)
							cout<<"Invalid index"<<endl;
					}
					while(ind>=a1.getSize() || ind<0);
					cout<<"The required element is "<<a1[ind]<<endl;
					break;
				}

				case 5:{
					if(size==0)
					{
						cout<<"First enter array"<<endl;
						break;
					}
					cout<<"First array "<<endl<<a1<<endl;
					cout<<"Enter new Array object"<<endl;
					cin>>a2;
					a1=a2;
					cout<<"First Array "<<endl<<a1<<endl;
				}
				break;

				case 6:{
					if(size==0)
					{
						cout<<"First enter array"<<endl;
						break;
					}
					cout<<"First array "<<endl<<a1<<endl;
					cout<<"Enter new array"<<endl;
					cout<<"Enter size of array"<<endl;
					int s,x;
					cin>>s; //size of an array
					int* ar=new int[s];
					cout<<"Enter array elements : \n";
					for(int i=0;i<s;i++){
						cout<<"Element "<<(i+1)<<" : ";
						cin>>x;
						ar[i]=x;
					}
					a1=Array(s);
					a1=ar;
					cout<<"First Array "<<endl<<a1<<endl;
				}
				break;

				case 7:
					cout<<"Thank You ! "<<endl;
					break;

				default:
				cout<<"Invalid choice"<<endl;
			}
		}
		while(ch!=7);
		return 0;
}
