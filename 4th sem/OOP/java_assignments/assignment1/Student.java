package assng1;

import java.util.*;
import java.text.SimpleDateFormat;

class Student implements Comparable<Student>
{
    protected static int count;
    protected static String[] courseList={"Undergraduate","Postgraduate"};
    protected String roll;
    protected String name;
    protected String course;
    protected Date adm_date;
    protected double marks[];
    protected double total;
    //constructor
    Student()
    {
        count+=1;
        name="";
        course="";
        adm_date=new Date();
        marks=new double[]{-1.0,0.0,0.0,0.0,0.0,0.0};
        //marks=-1 denotes that the student has not appeared for exam
        total=0.0;
    }

    Student(String r){
        roll=r;
    }

    static void setCount()
    {
        count=0;
    }

    static int getCount(){
        return count;
    }

    String getRoll(){
        return roll;
    }

    double getTotal(){
        return total;
    }

    String getName()
    {
        return name;
    }

    String getCourse()
    {
        return course;
    }

    Date getDate()
    {
        return adm_date;
    }

    //function to receive student data
    void readData()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Name :");
        name=sc.nextLine();
        System.out.println("Enter course of study:\n1.Undergraduate\n2.Postgraduate");
        course=courseList[sc.nextInt()-1];
    }

    //function to receive marks
    void recMarks()
    {
        System.out.println("Enter marks of 5 subjects");
        Scanner sc=new Scanner(System.in);
        int i;
        marks[0]=1.0;//denotes the student has appeared for at least one exam
        for(i=1;i<=5;i++){
            System.out.print("Subject "+i+" : ");
            marks[i]=sc.nextDouble();
            total+=marks[i];
        }
    }
    //function to display details of students
    void display()
    {
        System.out.println("==========================================================");
        System.out.print("Name : "+name);
        System.out.print("Roll : "+roll);
        System.out.print("Course of study : "+course);
        System.out.print("Admission date : ");
        SimpleDateFormat f = new SimpleDateFormat("dd/MM/yyyy");
        System.out.println(f.format(adm_date));
        int i=0;
        for(double m:marks)
            System.out.println("Subject"+(i++)+": "+m);
        if(marks[0]>0.0)
        {
            System.out.println("Total marks :"+total);
            System.out.println("Average marks : "+(total/5));
        }
        else
        {
            System.out.println("marks not yet entered");
        }
        System.out.println("==========================================================");
    }

    //overriding compareTo function for comparing/sorting
    public int compareTo(Student s2){
        return (int)(-this.total+s2.total);
    } 

@Override
public String toString(){
    return String.format(this.roll);
    }
}
