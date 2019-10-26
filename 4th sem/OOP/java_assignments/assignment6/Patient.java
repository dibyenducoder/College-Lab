package hos;
import java.util.*;
import java.text.SimpleDateFormat;

public class Patient{
    static int count;
    int id;
    int status;
    int docId;
    String name;
    String docName;
    int hbp;
    int lbp;
    double temp; //temperature in fahrenheit
    ArrayList<Record> obs;

    Patient(){
        count++;
        id=10000+count;
        docId=-1;
        status=1;
        name="";
        docName="";
        hbp=120;
        lbp=80;
        temp=98.6;
        obs=new ArrayList<>();
    }
    
    Patient(int i){
        id=i;
    }

    static void setCount(){
        count=0;
    }

    static int getCount(){
        return count;
    }

    int getId(){
        return id;
    }
    
    String getName(){
        return name;
    }
    
    void setDocId(int i){
        docId=i;
    }
    
    void setDocName(String n){
        docName=n;
    }

    int getDocId(){
        return docId;
    }
    
    String getDocName(){
        return docName;
    }
    
    int getHBP(){
        return hbp;
    }
    
    int getLBP(){
        return lbp;
    }
    
    double getTemp(){
        return temp;
    }

    void readData(){
        System.out.println("Enter name");
        Scanner sc=new Scanner(System.in);
        name=sc.nextLine();
        System.out.println("Enter doctor id you want to be assigned");
        docId=sc.nextInt();
    }

    void observe(){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter systolic blood pressure\n");
        hbp=sc.nextInt();
        System.out.println("Enter diastolic blood pressure\n");
        lbp=sc.nextInt();
        System.out.println("Enter temperature\n");
        temp=sc.nextDouble();
        Record r=new Record();
        r.observe(this);
        obs.add(r);
    }
    
    void display(){
        System.out.println("Patient id : "+id);
        System.out.println("Name : "+name);
    }
    
    void showRec(){
        int i=1;
        System.out.println("Patient id : "+id+"\n"+"Patient name : "+name+"\n"+"Observing Doctor : Dr."+docName);
        System.out.println("Sl.No.\tDate\tTime\tSystolic pressure\tDiastolic pressure\tTemperature");
        for(Record r:obs){
            System.out.print(i++ +"\t");
            r.dispPat();
        }
    }
    
    void remove(){
        status=0;
    }
    
    int getStatus(){
        return status;
    }

    public boolean equals(Object o){
        return((Patient)o).id==this.id;
    }
}

//------------------------------------------------------------------------------------------

class Record{
    String patName;
    String docName;
    Date obsDate;
    int hbp;
    int lbp;
    double temp;
    
    void observe(Patient p){
         patName=p.getName();
         docName=p.getDocName();
         obsDate=new Date();
         hbp=p.getHBP();
         lbp=p.getLBP();
         temp=p.getTemp();
    }
    
    void display(){
        SimpleDateFormat f=new SimpleDateFormat("dd/MM/yyyy");
        SimpleDateFormat f2=new SimpleDateFormat("hh:mm:ss");
        System.out.println(patName+"\t"+docName+"\t"+f.format(obsDate)+"\t"+f2.format(obsDate)+"\t"+hbp+"\t"+lbp+"\t"+temp);
    }
    
    void dispPat(){
        SimpleDateFormat f=new SimpleDateFormat("dd/MM/yyyy");
        SimpleDateFormat f2=new SimpleDateFormat("hh:mm:ss");
        System.out.println(f.format(obsDate)+"\t"+f2.format(obsDate)+"\t"+hbp+"\t"+lbp+"\t"+temp);
    }
}