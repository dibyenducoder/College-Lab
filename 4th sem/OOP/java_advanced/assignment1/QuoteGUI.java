import Adv1.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class QuoteGUI extends JFrame  
{
	JLabel jl,jl2 ,jl3;
	JButton jb , jb2;
	JPanel jp , jp2 , jp3 , jp4;

	public QuoteGUI()
	{
		setTitle("QuoteOfTheDay");
		setSize(500,500);
		setVisible(true);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

		//setResizable(false);

		jp = new JPanel();//title
		jp4 = new JPanel();//welcome
		jp3 = new JPanel();//quote
		jp2 = new JPanel();//button
		
		jl = new JLabel("Quote Of The Day");
		jl.setFont(new Font("Gargi", Font.BOLD, 17));
		jp.add(jl);
		add(jp,BorderLayout.NORTH);

//-------------Greeting at once -----------------------
		Adv1.Date d = new Adv1.Date();


		JTextArea wel = new JTextArea(1,30);
		wel.setText((String)d.getDate());
		wel.setLineWrap(true);
		//txt.setWrapStyleWord(true);
		wel.setEditable(false);
		wel.setFocusable(false);
		wel.setBackground(UIManager.getColor("Label.background"));
    	wel.setFont(UIManager.getFont("Label.font"));
    	wel.setBorder(UIManager.getBorder("Label.border"));
		wel.setFont(new Font("Courier",Font.BOLD,20));

		//txt.setOpaque(false);
		jp3.add(wel);
		add(jp3);
//----------------------Quote----------------------
		jl2 = new JLabel();
		Adv1.Quote q = new Adv1.Quote();
		//String str =q.printQuote();

		JTextArea txt = new JTextArea(1,30);
		txt.setText((String)q.printQuote());
		txt.setLineWrap(true);
		txt.setWrapStyleWord(true);
		txt.setEditable(false);
		txt.setFocusable(false);
		txt.setBackground(UIManager.getColor("Label.background"));
    		txt.setFont(UIManager.getFont("Label.font"));
    		txt.setBorder(UIManager.getBorder("Label.border"));
		txt.setFont(new Font("Courier",Font.BOLD,20));

		//txt.setOpaque(false);
		jp3.add(txt);
		add(jp3);

		jl2.setHorizontalAlignment(SwingConstants.CENTER);
		jl2.setFont(new Font("Courier",Font.BOLD,25));
		jp3.add(jl2);
		add(jp3,BorderLayout.CENTER);

		jb = new JButton("OK");
		jp2.add(jb);
		add(jp2,BorderLayout.SOUTH);

		jb2 = new JButton("NEXT");
		jp2.add(jb2);
		add(jp2,BorderLayout.SOUTH);
		//jb2.addActionListener(this);

	//} ---------------colors-----------------
		jp.setBackground(Color.BLUE);
    	jp2.setBackground(Color.BLUE);
   		jl.setForeground(Color.ORANGE);
   		txt.setForeground(Color.RED);
   
		validate();



		jb2.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{

				//-------------Color functionality---------
				Random rand = new Random();
				//jp.setBackground(Color.RED);
				int redValue = rand.nextInt(255);
    			int greenValue = rand.nextInt(255);
    			int blueValue = rand.nextInt(255);

    //System.out.println("Red: " + redValue +", Green: " + greenValue + ", Blue: " + blueValue);

    			Color clr = new Color(redValue, greenValue, blueValue);
    			Color clr2 = new Color(255-redValue , 255-greenValue , 255-blueValue);

    			jp.setBackground(clr);
    			jp2.setBackground(clr);
    			jl.setForeground(clr2);
    			txt.setForeground(clr);


    			//----------------------------------------------
    			jp4.setBackground(Color.BLUE);
    			wel.setVisible(false);
				txt.setText((String)q.printQuote());
			}
		});

	}
	public static void main(String args[])
  {
    QuoteGUI q =new QuoteGUI();
  }
	
}