package assng1;

import java.util.*;
import java.text.SimpleDateFormat;
class StudentDept extends Student
{
    static String[] deptList={"BCSE","ETCE","CHEM","MECH"};
    static int[] deptCount={0,0,0,0};
    static int[] deptRoll={0,0,0,0};
    String dept;
    
    StudentDept(){
        super(); //involes the parent class (student class)
        dept="";
    }

    String getDept(){
        return dept;
    }

    static int getCount(int dep){
        return deptCount[dep];
    }

    void readData(){
        super.readData();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter course of study:\n1.BCSE\n2.ETCE\n3.CHEM\n4.MECH\n>>>");
        int d=sc.nextInt();
        dept=deptList[--d];
        deptCount[d]++;
        deptRoll[d]++;
        Calendar c=Calendar.getInstance();
        c.setTime(adm_date);
        roll=dept+(c.get(Calendar.YEAR)%100);
        if(deptCount[d]<10)
            roll=roll+"00"+deptRoll[d];
        else if(deptCount[d]<100)
            roll=roll+"0"+deptRoll[d];
        else
            roll=roll+deptRoll[d];
    }

    void display(){
        System.out.println("==========================================================");
        System.out.println("Name : "+name);
        System.out.println("Roll : "+roll);
        System.out.println("Course of study : "+course);
        System.out.println("Department : "+dept);
        System.out.print("Admission date : ");
        SimpleDateFormat f=new SimpleDateFormat("dd/MM/yyyy");
        System.out.println(f.format(adm_date));
        if(marks[0]>0.0){
                    System.out.println("Total marks :"+total);
                    System.out.println("Average marks : "+(total/5));
        }
        System.out.println("==========================================================");
    }
    
}
