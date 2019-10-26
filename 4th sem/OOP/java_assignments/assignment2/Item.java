package Assignment2;

import java.util.*;
class Item
{
    //Data members
    private static int id=0;
    private String code;
    private String name;
    private double rate;
    private int qty;
    private String strcode;
    private  int numcode;

    //Constructor
    public Item(String nm, double r,int q)
    {
        name=nm;
        rate=r;
        qty=q;
        strcode=name.substring(0,3);
        strcode=strcode.toUpperCase();
        //numcode=10000+id;
        //String s =Console.WriteLine(qty.toString(D3));
        //String s = Integer.toString(qty);
        //String format = String.format("%%0%dd", digits);
        //String result = String.format(format, qty);
        String s = String.format("%03d", qty);
        code = strcode + s ;
        id++;
    }
    
    //Set rate
    public void setRate(double r)
    {
        rate=r;
    }

    //Set quantity
    public void setQty(int q)
    {
        qty=q;
    }
    
    //Get quantity
    public int getQty()
    {
        return qty;
    }
    
    //Get rate
    public double getRate()
    {
        return rate;
    }
    
    //Get code
    public String getCode()
    {
        return code;
    }
    
    //Function to display item
    public void display()
    {
        System.out.println("Code :"+code+"\nName: "+name+"\nRate: "+rate+"\nQuantity: "+qty);
    }
}