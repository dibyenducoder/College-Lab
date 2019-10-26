package Ass3;

public class Stack
{
    static final int MAX = 1000;
    int top;
    char a[] = new char[MAX]; // Maximum size of Stack
 
    public boolean isEmpty()
    {
        return (top<0);
    }

    Stack()
    {
        top=-1;
    }
 
    public boolean push(char x)
    {
        if (top>=MAX)
        {
            System.out.println("Stack Overflow");
            return false;
        }
        else
        {
            a[++top]=x;
            return true;
        }
    }
 
    public char pop()
    {
        //System.out.println(top);
        if (top<0)
        {
            //System.out.println("Stack Underflow");
            return 0;
        }
        else
        {
            char x=a[top--];
            return x;
        }
    }
}