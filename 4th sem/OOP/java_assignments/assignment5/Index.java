package book;
import java.util.*;
import java.io.*;

class Index{
    
    private Map<String,ArrayList<Integer>> pos;

    Index(BufferedReader txt){
        Scanner sc=new Scanner(txt);
        pos=new HashMap<String, ArrayList<Integer>>();
        int ln=1;
        try{
            String line;
            while(sc.hasNextLine()){
                line=sc.nextLine();
                line=line.toLowerCase();
                String words[]=line.split("\\W+");
                for(String w:words){

                    w=w.toLowerCase();
                    ArrayList<Integer> list=pos.get(w);
                    
                    if(list==null){
                        list=new ArrayList<>();
                        list.add(ln);
                    }
                    else if(!(list.contains((Integer)ln)))
                      list.add(ln);
                    pos.put(w,list);
                }
                ln++;
                //System.out.println();
            }
        }
        finally{
            sc.close();
        }
    }
  
  public String toString(){
        TreeMap<String, ArrayList<Integer>> sorted=new TreeMap<>(pos);
        return sorted.toString();
    }
}