#include <iostream>  
#include<math.h>
#include<stdlib.h>
#include<cstring>

using namespace std;  

class COMPLEX
{
	private:                  //private data members
		int real,img;
	public:                   //public member functions 

		COMPLEX(int r=0,int i=0)  //constructor with 2 arguments  
		{	
			real=r;
			img=i;
		}
	
		COMPLEX operator +(COMPLEX A)		//defining the addition operator 
		{
			COMPLEX T;
			T.real=real + A.real;
			T.img = img + A.img;
			return T;
		}
		COMPLEX operator -(COMPLEX A)   //defining the substraction operatot
		{
			COMPLEX T ;
			T.real = real - A.real;
			T.img = img - A.img;
			return T;
		}
		
		friend istream & operator >> (istream &input ,COMPLEX &comp); //can access every acess specifier -- for input stream
		friend ostream & operator << (ostream &output ,COMPLEX &comp); // for output stream
}; // end of class COMPLEX


//Inputing the complex number
istream & operator >> (istream &input ,COMPLEX &comp)
{
	string complex;
	input >> complex;
	
	comp.real=0;
	comp.img=0;
	int flag=0,negative=0,negativei=0,num=0,tag=0;
	if(complex[0]=='-')
	{
		complex = complex.substr(1,complex.length());
		negative=1;
	}
	for(int i=0; i<complex.length();i++)
	{
		if(complex[i]=='+' || complex[i]=='-'){
			flag=1;
			tag=1;
			if(complex[i]=='-') negativei=1;
			num=0;
		}
		else if(complex[i]=='i')
		{
			if(flag==0)
			{
				negativei=negative;
				comp.img=comp.real;
				comp.real=0;
			}
			break;
		}
		else 
		{
			if(flag==0)
			{
				num=num*pow(10,i)+(complex[i]-48);
				comp.real=num;
			}
			if(flag==1)
			{
				num=num*pow(10,i-tag-1)+complex[i]-48;
				comp.img=num;
			}
		}
		if(negative==1)
			comp.real=-1*comp.real;
		if(negativei==1)
			comp.img=-1*comp.img;
	}
    return input ;

}

//outputing the complex number 
ostream & operator << (ostream &output ,COMPLEX &comp)
   {
	cout<<comp.real;
	if(comp.img<0)
	{
		cout<<"-";     //if img part is smaller than 0 then it is considered as "-"
	}
	else 
		cout<<"+";      //else "+"
	cout<<fabs(comp.img)<<"i";
	return output;
}
//main function
int main()
	{
	cout<<"\n\n\t--WELCOME TO THE COMPLEX WORLD---\n\n"; 
	COMPLEX comp1,comp2;
	
	int input;
 
	while(1)
	{
	cout<<"\n1.Input the 1st complex number :"
        <<"\n2.Add a Complex Number --\n"
        <<"3.Substract a Complex Number --\n"
        <<"4.Display the Result --\n"
        <<"5.Exit Program\n"
        <<"\nPlease Enter your choice :\n";
    cin>>input;
    
    switch(input)
    {
      case 1:    //1st complex number
		cout<<"Enter the first complex number :";
	        cin>>comp1;
	
	       cout<<"Complex number you entered is : ";
	       cout<<comp1;
               cout<<endl;
	       break;

      case 2: //performs addition operation
                cout<<"Enter the second complex number :";
	        cin>>comp2;
	
	       cout<<"Complex number you entered is : ";
	       cout<<comp2;
               cout<<endl;
        	comp1 = comp1 + comp2;
                cout<<"Addition operation Done !\n\nPress '5' for result :\n\n"; 
        	break;

      case 3: //performs substraction operation
        	cout<<"Enter the second complex number :";
	        cin>>comp2;
	
	       cout<<"Complex number you entered is : ";
	       cout<<comp2;
               cout<<endl;
		comp1 = comp1-comp2;
		 cout<<"Substraction operation Done !\n\nPress '4' for result :\n\n"; 
        	break;

      case 4: //display the result
           
           cout<<"Resulting Complex number is :"<<comp1;
           break;

      case 5: //exiting the program
      	cout << "Thank You !!!\n\n" ;
        exit(0); 

      default : //choice is beyond the desired input
      		cout<<"Wrong Input !\n";
	}
  }
}
