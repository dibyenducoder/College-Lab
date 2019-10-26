package Ass3;
import java.util.Scanner;

public class pstring
{
	String p;
	Stack s=new Stack();

	public void input()
	{
		System.out.println("Enter your string of parentheses:");
		Scanner sc=new Scanner(System.in);
		p=sc.nextLine(); 
	} 

	public boolean check()
	{
		int k;
		for(k=0;k<p.length();k++)
		{
			int i=k;
			if(p.charAt(i)=='('||p.charAt(i)=='{'||p.charAt(i)=='[')
				s.push(p.charAt(i));
			else if(p.charAt(i)==')')
			{
				if(s.isEmpty()||s.pop()!='(')
				{
					return false;
				}
			}
			else if(p.charAt(i)=='}')
			{
				if(s.isEmpty()||s.pop()!='{')
				{
					return false;
				}
			}
			else if(p.charAt(i)==']')
			{
				if(s.isEmpty()||s.pop()!='[')
				{
					return false;
				}
			}
		}
		if(!s.isEmpty())
			return false;
		return true;
	}
}