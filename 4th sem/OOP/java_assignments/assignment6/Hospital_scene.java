package hos;
import java.util.*;

class Hospital_scene{

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        Patient.setCount();
        Doctor.setCount();
        Hospital h=new Hospital();
        int ch;
        do{
            System.out.println("Enter choice");
            System.out.println("1. Admit patient");
            System.out.println("2. Enter doctor");
            System.out.println("3. Observe a patient");
            System.out.println("4. Discharge a patient");
            System.out.println("5. Display observation records of a patient");
            System.out.println("6. Display all observation records");
            System.out.println("7. Exit");
            ch=sc.nextInt();
            int count  = 0 ;
            switch(ch){
                case 1:
                    if(Doctor.getCount()!=0)
                        h.addPatient();
                    else
                        System.out.println("No Doctors in hospital...Enter doctors first.");
                    break;
                case 2:
                    h.addDoctor();
                    break;
                case 3:
                    if(Patient.getCount()!=0)
                        h.observe();
                    else
                        System.out.println("No patient in hospital");
                    break;
                case 4:
                    if(Patient.getCount()!=0)
                        h.discharge();
                    else
                        System.out.println("No patient in hospital");
                    break;
                case 5:
                    if(Patient.getCount()!=0)
                        h.dispRecPat();
                    else
                        System.out.println("No patient in hospital");
                    break;
                case 6:
                    if(Patient.getCount()!=0)
                        h.dispRec();
                    else
                        System.out.println("No patient in hospital");
                    break;
                case 7:
                    System.out.println("Exitting");
                    break;
            }
        }while(ch!=7);
    }
}