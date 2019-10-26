package Assignment2;

import java.util.*;
class Item_main
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner (System.in);
        int ch1,ch2,ch3;
        ItemList i=new ItemList();
        do
        {
            System.out.println("1. SEO\n2. Shopkeeper\n3.Exit");
            System.out.print("Enter choice :");
            ch1=sc.nextInt();
            switch(ch1)
            {
                case 1:
                //Functions for SEO
                do
                {
                    System.out.println("1.Add new item\n2. Change rate of existing item\n3. Update quantity\n4. Issue an item\n5. View price or quantity of an item\n6. Find how many items cost more than a given amount\n7. Go back");
                    System.out.print("Enter choice :");
                    ch2=sc.nextInt();

                    switch(ch2)
                    {
                        case 1:
                        i.addItem();
                        break;

                        case 2:
                        i.changeRate();
                        break;

                        case 3:
                        i.changeQty();
                        break;

                        case 4:
                        i.issue();
                        break;

                        case 5:
                        i.viewItem();
                        break;

                        case 6:
                        i.moreCount();
                        break;

                        default:
                        System.out.println("Invalid choice");
                        break;

                    }
                }
                while(ch2!=7);
                break;

                case 2:
                //For sk
                do
                {
                    System.out.println("1. Update quantity\n2. Issue an item\n3. View price or quantity of an item\n4. Find how many items cost more than a given amount\n5. Go back");
                    System.out.print("Enter choice :");
                    ch2=sc.nextInt();

                    switch(ch2)
                    {
                        case 1:
                        i.changeQty();
                        break;

                        case 2:
                        i.issue();
                        break;

                        case 3:
                        i.viewItem();
                        break;

                        case 4:
                        i.moreCount();
                        break;

                        default:
                        System.out.println("Invalid choice");
                        break;

                    }
                }
                while(ch2!=5);

                break;

                default:
                System.out.println("invalid choice");
            }

        }
        while(ch1!=3);
    }
}