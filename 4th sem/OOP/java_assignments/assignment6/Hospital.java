package hos; 
import java.util.*;

class Hospital{
    ArrayList<Patient> arrp;
    ArrayList<Doctor> arrd;
    ArrayList<Record> arrr;
    Hospital(){
        arrp=new ArrayList<>();
        arrd=new ArrayList<>();
        arrr=new ArrayList<>();
    }
    
    String findDoc(int i){
        for(Doctor d:arrd){
            if(d.getId()==i)
                return d.getName();
        }
        return "";
    }

    void addPatient(){
        Patient p=new Patient();
        p.readData();
        p.display();
        int doc=p.getDocId();
        Scanner sc=new Scanner(System.in);
        while(findDoc(doc).length()==0){
            System.out.println("Doctor not available...Enter doctor id again");
            doc=sc.nextInt();
            p.setDocId(doc);
        }
        p.setDocName(findDoc(doc));
        System.out.println("Allocated doctor : Dr. "+p.getDocName());
        arrp.add(p);
    }

    void addDoctor(){
        Doctor d=new Doctor();
        d.readData();
        d.display();
        
        arrd.add(d);
    }
    
    Patient findPat(){
        System.out.println("Enter patient code");
        Scanner sc=new Scanner(System.in);
        int i=sc.nextInt();
        Patient p=new Patient(i);
        int in=arrp.indexOf(p);
        if(in==-1)
            return null;
        else
            return arrp.get(in);
    }
    
    void observe(){
        Patient p=findPat();
        while(p==null || p.getStatus()==0) {
            System.out.println("Patient not found...Enter patient code again");
            p=findPat();
        }
        p.observe();
        Record r=new Record();
        r.observe(p);
        arrr.add(r);
    }
    
    void dispRecPat(){
        Patient p=findPat();
        while(p==null || p.getStatus()==0) {
            System.out.println("Patient not found...Enter patient code again");
            p=findPat();
        }
        p.showRec();
    }
    
    void dispRec(){
        int i=1;
        System.out.println("Sl.No.\tPatient\tDoctor\tDate\tTime\tSystolic pressure\tDiastolic pressure\tTemperature");
        for(Record r:arrr){
            System.out.print(i++ +"\t");
            r.display();
        }
    }
    
    void discharge(){
        Patient p=findPat();
        p.remove();
        }
    }
    
    