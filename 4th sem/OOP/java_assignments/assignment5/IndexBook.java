package book;
import java.util.*;
import java.io.*;

public class IndexBook{
	public static void main(String[] args) {
		//int count=0;
		try{

			Scanner sc=new Scanner(System.in);
			System.out.print ("Enter file path :");
			String src=sc.nextLine();
			BufferedReader br=new BufferedReader(new FileReader(src));
			String index_str=new Index(br).toString();
			index_str = index_str.replace("],","]\n");
			//count++;
			System.out.println(index_str);
		}
		catch(FileNotFoundException e){
			e.printStackTrace();
		}
	}		
}

