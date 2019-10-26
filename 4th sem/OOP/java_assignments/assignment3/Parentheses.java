import java.util.*;
import Ass3.*;

public class Parentheses
{
	public static void main(String[] args)
	{
		int resp;
		do
		{
			Ass3.pstring pr=new Ass3.pstring();
			pr.input();
			if(pr.check())
				System.out.println("match\n");
			else
				System.out.println("not match\n");
			System.out.println("press 1 to continue, 0 to exit");
			Scanner sc=new Scanner(System.in);
			resp=sc.nextInt();
		}while(resp==1);
	}
}