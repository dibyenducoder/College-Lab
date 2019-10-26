#include <iostream>
#include <cstdlib>
using namespace std; 

class itemlist  //class memeber
{
	int item_code, quantity; 
	double rate;
	char name[30];

public:    //public member data
	
       int getcode() //inputing the code 
	{
		return item_code;
	}
       int putcode()
	{	
	
		return item_code;
	} 
        //inputing item
	void new_item(int code)
	{
		if(code == 0)
		{
			item_code=code;
			name[0]='*';
			quantity=0;
			rate=0;
		}
		else
		{	
			item_code=code;
			cout<<"Enter item name : ";
			cin>>name;
			cout<<"Enter quantity : ";
			cin>>quantity;
			cout<<"Enter the price of each of this item : ";
			cin>>rate;
			cout<<"New item is successfully entered in the stocklist...\n\n";
		}
	}
    //item name function
    string name_item()
    {
    	string itemname;
    	itemname=name;
    	return itemname ;
	}

 //quantity function
    int quantity_item()
	{
		return quantity;
	}
 int rate_item()
	{
		return rate;
	}
	//code of item returns 
	int code()
	{
		int code1;
		code1=item_code;
		return code1;
	}
        //price updating 
	void update_price_item()
	{
		int new_price;
		cout<<"Enter the new price of the item : ";
		cin>>new_price;
		rate=new_price;
	}
	//price of item
    void price_item()
	{
	       int price;
	       price=rate;
	       cout<<name<<"\tcosts Rs.  "<<price<<endl;
	}
        //number of particular items updating
	void update_quantity()
	{
		int q;
		cout<<"Enter no of items to be added : ";
		cin>>q;
		quantity+=q;
	}
        int unit1;
        //number of items bought 
	int update_issued_item()
	{
		int unit;
		do
		{
			cout<<"Enter how many units you need (between 0 to "<<quantity<<") : ";
			cin>>unit;
			unit1=unit;
		}while(quantity<unit);
		
		quantity-=unit; //quantity is/are decreasing if bought 
		return quantity;
	}
       int quantity_buy()
	{
		return unit1;
	}
        //checking the availability of items alongwith price
	void give_data()
	{
		cout<<quantity<<"  "<<name<<" are available...\n";
		cout<<"MRP :Rs. "<<rate<<"\n\n";
	}
       
};

//another class for items to put in the stocklist 
class stocklist
{
	itemlist item[1000];
	int entry; 

public:  //public data 
	void init() //initiatation
	{
		entry=0;
		item[0].new_item(0);
	}
        //initialize the items 
	void new_entry()
	{
		int code,i;char response;
		cout<<"Enter the item code for the new item : ";   //input the item code for item
		cin>>code;
		for(i=0;i<=entry;i++)
		{
			if(item[i].getcode()==code) //code should be different in different items 
			{
				cout<<"Item with same code already exist...\n if you want to update the quantity list enter 'Y'\n";
				cin>>response;
				if(response=='Y')
				{
					item[i].update_quantity();
				}
				break;
			}
		}
		if(i==entry+1)
		{
			entry++;
			item[entry].new_item(code);
		}
		
	}
        //issue items if bought
	
	void issue_item()
	{
		int code,i;
		cout<<"Enter the item code for the item to be issued : ";
		cin>>code;
		for(i=0;i<=entry;i++)
		{
			if(item[i].getcode()==code)
			{
                               
				if(!item[i].update_issued_item())
					delete_item(code);
				break;
			}
			
		}
		if(i==entry+1)
			cout<<"Item code not matched with any present item..\n";

	}
       
	
        //issue items that are already bought should be removed
	void delete_item(int code)
	{
		for(int i=0;i<=entry;i++)
		{
			if(item[i].getcode()==code)
			{
				for(int j=i;j<=entry-1;j++)
				{
					item[j]=item[j+1];
				}
				entry--;
			}
		}
	}
	//updating the item quantity
	void update_item()
	{
		int code,i;
		cout<<"Enter the item code whose price is to be updated : ";
		cin>>code;
		for(i=0;i<=entry;i++)
		{
			if(item[i].getcode()==code)
			{
				item[i].update_quantity();
				break;
			}
			
		}
		if(i==entry+1)
			cout<<"Item code not matched with any present item..\n";
}
        //updating the price 
	void update_price()
	{
		int code,i;
		cout<<"Enter the item code whose price is to be updated : ";
		cin>>code;
		for(i=0;i<=entry;i++)
		{
			if(item[i].getcode()==code)
			{
				item[i].update_price_item();
				break;
			}
			
		}
		if(i==entry+1)
			cout<<"Item code not matched with any present item..\n";
	}
       void price()
	{
         	int code,i;
		cout<<"Enter the item code whose price you want to see : ";
		cin>>code;
		for(i=0;i<=entry;i++)
		{
			if(item[i].getcode()==code)
			{
				item[i].price_item();
				break;
			}
			
		}
		if(i==entry+1)
			cout<<"Item code not matched with any present item..\n";
	}
        //checking the availability of item
	void availability()
	{
		int code,i;
		cout<<"Enter the item code whose availability is to be checked : ";
		cin>>code;
		for(i=0;i<=entry;i++)
		{
			if(item[i].getcode()==code)
			{
				item[i].give_data();
				break;
			}
			
		}
		if(i==entry+1) 
			cout<<"Item not available..\n";
	}
       //display the stocklist alongwith code
       void display()
	{
	   int i;
	    cout <<"SL.No.\tCode Name\tItem Name\tQuantity\tRate(Rs.)";
	    cout<<"\n----------------------------------------------------------------------------\n";
 	    for(i=1;i<=entry;i++)
	    {
		cout<<i<<"."<<"\t"<<item[i].code()<<"\t\t"<<item[i].name_item()<<"\t\t"<<item[i].quantity_item()<<"\t\t"<<item[i].rate_item()<<endl; 
	    }
	    cout<<"\n-----------------------------------------------------------------------------\n";
	}

 	void bill()
	{
		 int i,quantity=0,total=0;
	    cout <<"SL.No.\tCode Name\tItem Name\tQuantity\tRate(Rs.)";
	    cout<<"\n----------------------------------------------------------------------------\n";
 	    for(i=1;i<=entry;i++)
	    {
		cout<<i<<"."<<"\t"<<item[i].putcode()<<"\t\t"<<item[i].name_item()<<"\t\t"<<item[i].quantity_buy()<<"\t\t"<<item[i].rate_item()*item[i].quantity_buy()<<endl; 
             quantity=quantity+item[i].quantity_buy();
	     total=total+item[i].rate_item()*item[i].quantity_buy();
	    }
	    cout<<"\n-----------------------------------------------------------------------------\n";
	    cout<<"GRAND TOTAL --"<<"\t\t\t\t"<<quantity<<"\t\t"<<total<<endl;
       
	}

};


int main()
{
	stocklist t; // items in the stocklist
	t.init(); //initialize the items
	int choice,ch;
      
    cout<<"\n\t---WELCOME TO THE SHOP---\n\n";
    label :
	do{
    	    cout<<"\n1.Admin Mode ---"
    		<<"\n2.User Mode ---"
    		<<"\n3.Exit"
    		<<"\n4.Screen Clear --"
    		<<"\n\nYour Choice is : ";
    	cin>>ch;
    	
    	switch(ch)
    	{
		case 1 :
		 	do
		 	{
			cout<<"Enter the operation you want to perform : "
		    <<"\n1.Add item"
		    <<"\n2.Display the stocklist --"
		    <<"\n3.Item Quantity update --"
			<<"\n4.Item price update --"
			<<"\n5.Check availability --"
			<<"\n6.Exit"
			<<"\n\nYour choice is -- ";
		cin>>choice;
		switch(choice)
		{
			case 1:  //items to store in the stocklist -- entry is needed
				t.new_entry();
				break;

			case 2: //buying items
				t.display();
				break;
			
			case 3: //updating item quantity
				t.update_item();
				break;
				
			case 4: //price may increase or decrease -- updating the price is needed for item
				t.update_price();
				break;

			case 5: //checking items are available or not and number of items are present along with price
				t.availability();
				break;

			case 6: //exit status of program
				goto label ;
				break;
			
			default: //choice is beyond desired input
				cout<<"Wrong input..\n";
				break;
					
		}

	}while(1);

   case 2:
     do
	  {
		cout<<"Enter the operation you want to perform : "
		    <<"\n1.Display The Stocklist"
		    <<"\n2.Place Order"
			<<"\n3.Price of Item"
			<<"\n4.Check availability"
			<<"\n5.Bill"
			<<"\n6.Exit"
			<<"\n\nYour choice is -- ";
		cin>>choice;
		switch(choice)
		{
			case 1:  //items to store in the stocklist -- entry is needed
				t.display();
				break;

			case 2: //buying items
				t.issue_item();
				break;

			case 3: //price may increase or decrease -- updating the price is needed for item
				t.price();
				break;

			case 4: //checking items are available or not and number of items are present along with price
				t.availability();
				break;
			case 5://Bill of your order
				t.bill(); 
				break;

			case 6: //exit status of program
				goto label;
				break;				

			default: //choice is beyond desired input
				cout<<"Wrong input..\n";
				break;
					
		}

	}while(1);
  
  case 3: 
  	cout <<"\n\nThank You !\nHope You Come Again !\n\n";
  	exit(1); break;
  	
  case 4:
  	system("CLS");
  	break;
  	
  default :
  	cout <<"Wrong Choice... !\n" ; break;
  }
}while(1);  	
	
return 0;
}
