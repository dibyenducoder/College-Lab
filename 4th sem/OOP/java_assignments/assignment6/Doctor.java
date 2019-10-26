package hos;
import java.util.*;

class Doctor{
    static int count;
    int id;
    String name;    
    Doctor(){
        count++;
        id=20000+count;
        name="";
    }
    
    int getId(){
        return id;
    }
    
    String getName(){
        return name;
    }
    
    Doctor(int i){
        id=i;
    }

    static void setCount(){
        count=0;
    }

    static int getCount(){
        return count;
    }

    void readData(){
        System.out.println("Enter name");
        Scanner sc=new Scanner(System.in);
        name=sc.nextLine();
    }
    
    void display(){
        System.out.println("Doctor id : "+id);
        System.out.println("Dr. "+name);
    }

    public boolean equals(Object o){
        return((Doctor)o).id==((Doctor)this).id;
    }
}