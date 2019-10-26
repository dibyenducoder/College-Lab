//package a7;
//----------------------------------------For String -----------------------------------------------
import java.awt.*;
import javax.swing.*;
import java.util.*;
import java.awt.event.*;
import javax.swing.JFrame;  

interface BasicLinkedList<itemtype>  
{
   public void insert_front(itemtype item);
   public void delete_front();
   public void insert_rear(itemtype item);
}
interface Lsearch<itemtype>  
{
   public void search(itemtype v);
}

     public  class LinkedListApplet_student extends JApplet implements BasicLinkedList<JButton>,Lsearch<JButton>
    {
    JButton insert_Front,insert_Rear,del_Front,search;
    JLabel label,arrow , nul;
    JPanel north_panel,south_panel,lpanel;
    JTextField field;
    LinkedList<JButton> linklist;

    public void init()
    {
        EventQueue.invokeLater(new Runnable()
        {
            //@Override
            public void run()
            {
                app();
            }
        });
    }

    void app()
    {
        linklist = new LinkedList<JButton>();
        north_panel = new JPanel();
        north_panel.setBackground(Color.PINK);

        south_panel = new JPanel();
        south_panel.setBackground(Color.PINK);

        //lpanel = new JPanel();
        //lpanel.setBackground(Color.pink);

        label = new JLabel();
        label.setForeground(Color.BLUE);

        field = new JTextField(50);
        field.setColumns(50);

        north_panel.setLayout(new GridLayout(1,5));
        south_panel.setLayout(new FlowLayout());

        listener list = new listener();

        insert_Front = new JButton("Ins_Front");
        insert_Front.addActionListener(list);
        north_panel.add(insert_Front);

        insert_Rear = new JButton("Ins_Rear");
        insert_Rear.addActionListener(list);
        north_panel.add(insert_Rear);

        del_Front=new JButton("Del_Front");
        del_Front.addActionListener(list);
        north_panel.add(del_Front);

        search=new JButton("search");
        search.addActionListener(list);
        north_panel.add(search);

        north_panel.add(field);
        add(north_panel,BorderLayout.NORTH);
        add(south_panel,BorderLayout.CENTER);
        north_panel.add(label,SwingUtilities.SOUTH);
    }

    private class listener implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent event)
        {
            String command = event.getActionCommand(),text="";
            //int n = Integer.parseInt()
            if(isNumber(field.getText()))
            {
                label.setText("Please Enter String ");
            }
            else
            {
            System.out.println(command);
            if(command.equals("Ins_Front"))
            {
                text=field.getText();

                if(text.length()==0)
                    label.setText("Enter some value!!!");
                else
                {
                    label.setText("Node created successfully");  
                    insert_front(new JButton(text));
                }
            }
            else if(command.equals("Ins_Rear"))
            {
                text=field.getText();
                if(text.length()==0)
                    label.setText("Enter some value!!!");
                else
                {
                    label.setText("Node  created successfully");  
                    insert_rear(new JButton(text));
                }
            }
            else if (command.equals("Del_Front"))
            {
                label.setText("Node Destroyed/Deleted");  
                delete_front();
            }
            else if(command.equals("search"))
                search(new JButton(text));
        }        
    }
}
    
    static boolean isNumber(String s) 
    { 
        for (int i = 0; i < s.length(); i++) 
        if (Character.isDigit(s.charAt(i)) == false) 
            return false; 
  
        return true; 
    } 
    @Override
    public void search(JButton node)
    {
        if(linklist.contains(node))
        {
            //node.setForeground(Color.yellow);
            label.setText("value found:"+node.getText());
        }
        else
            label.setText("No such elements presents in the list");
    }
    @Override
    public void insert_front(JButton item)
    {
        linklist.addFirst(item);
        ListIterator<JButton> itr=linklist.listIterator();
         //arrow=  new JLabel("<html>----><node>null</node></html>");
        JButton node=itr.next();
        //south_panel.add(arrow);
        south_panel.add(node);
        //south_panel.add(arrow);
    }
    @Override
    public void delete_front()
    {
        JButton node=null;
        if(linklist.size()==0)
            label.setText("Cannot delete Node,list is empty!");
        else 
        {
            node=linklist.removeFirst();
            south_panel.remove(node);
            
        }
    }
    @Override
    public void insert_rear(JButton item)
    {
        linklist.addLast(item);
        JButton s=null;
        ListIterator<JButton> itr=linklist.listIterator();
         //arrow=  new JLabel("<html>----><node>null></node></html>");
         //nul = new JLabel("<html><node>null</node></html");
        while(itr.hasNext())
            s=itr.next();
        JButton node=s;
        //south_panel.add(arrow);
        south_panel.add(node);
        //south_panel.add(arrow);
    }
}
