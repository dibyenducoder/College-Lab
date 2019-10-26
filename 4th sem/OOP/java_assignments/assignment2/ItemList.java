package Assignment2;                                                             
import java.util.*;
public class ItemList
{
    ArrayList<Item> itemList;

    //Constructor
    public ItemList()
    {
        itemList=new ArrayList<>();
    }

    //Function to add an item
    public void addItem()
    {
        Scanner sc=new Scanner(System.in);
        String name;
        System.out.println("Enter name of item");
        name=sc.nextLine();
        double rate;
        int qty;

        do
        {
            System.out.println("Enter rate");
            rate=sc.nextDouble();
            if(rate<=0)
                System.out.println("Invalid rate");
        }
        while(rate<=0);

        do
        {
            System.out.println("Enter qty");
            qty=sc.nextInt();
            if(qty<=0)
                System.out.println("Invalid quantity");
        }
        while(qty<=0);

        Item i=new Item(name,rate,qty);
        i.display();
        itemList.add(i);
    }

    //Function to check if an item is in list
    public int check(String id)
    {
        int pos=-1;
        for(Item i:itemList)
        {
            if(i.getCode().equals(id))
                return ++pos;
            pos++;
        }
        return -1;
    }

    //Function to change rate
    public void changeRate()
    {
        Scanner sc=new Scanner(System.in);
        boolean flag=true;
        String code;
        int pos;
        double rate;
        do
        {
            System.out.println("Enter item code");
            code=sc.nextLine();
            pos=check(code);
            if(pos==-1)
                System.out.println("Invalid code");
        }
        while(pos==-1);

        do
        {
            System.out.println("Enter new rate");
            rate=sc.nextDouble();
            if(rate<=0)
                System.out.println("Invalid rate");
        }
        while(rate<=0);

        Item i=itemList.get(pos);
        i.setRate(rate);
        itemList.set(pos,i);
    }

    //Function to change quantity
    public void changeQty()
    {
        Scanner sc=new Scanner(System.in);
        String code; int pos,qty;
        do
        {
            System.out.println("Enter item code");
            code=sc.nextLine();
            pos=check(code);
            if(pos==-1)
                System.out.println("Invalid code");
        }
        while(pos==-1);

        do
        {
            System.out.println("Enter new quantity");
            qty=sc.nextInt();
            if(qty<=0)
                System.out.println("Invalid rate");
        }
        while(qty<=0);

        Item i=itemList.get(pos);
        i.setQty(qty);
        itemList.set(pos,i);
    }

    //Function to issue
    public void issue()
    {
        Scanner sc=new Scanner(System.in);
        String code; int pos,qty;
        do
        {
            System.out.println("Enter item code");
            code=sc.nextLine();
            pos=check(code);
            if(pos==-1)
                System.out.println("Invalid code");
        }
        while(pos==-1);

        do
        {
            System.out.println("Enter quantity");
            qty=sc.nextInt();
            if(qty<=0)
                System.out.println("Invalid quantity");
        }
        while(qty<=0);

        Item i=itemList.get(pos);
        if(i.getQty()<qty)
            System.out.println("Insufficient quantity");
        else
        {
            System.out.println("Rate: "+i.getRate()+"\nQuantity: "+qty+"\nTotal cost: "+(qty*i.getRate()));
            i.setQty(i.getQty()-qty);
            itemList.set(pos,i);
        }
    }

    //Function to get availability
    public void viewItem()
    {
        Scanner sc=new Scanner(System.in);
        String code; int pos;
        do
        {
            System.out.println("Enter item code");
            code=sc.nextLine();
            pos=check(code);
            if(pos==-1)
                System.out.println("Invalid code");
        }
        while(pos==-1);
        Item i=itemList.get(pos);
        i.display();
    }

    //Find how many items cost more than an amt
    public void moreCount()
    {
        double rate;
        Scanner sc=new Scanner(System.in);
        do
        {
            System.out.println("Enter amt");
            rate=sc.nextDouble();
            if(rate<=0)
                System.out.println("Invalid amt");
        }
        while(rate<=0);
        int count=0;
        for(Item i:itemList)
        {
            if(i.getRate()>rate)
                count++;
        }
        System.out.println("No of items above "+rate+" is "+count);

    }
}