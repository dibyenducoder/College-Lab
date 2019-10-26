package Assignment4;

import java.util.prefs.*;
import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Random;
/*import java.awt.FlowLayout;
import java.awt.*;  
import java.awt.event.*;    
import javax.swing.JButton;  
import javax.swing.JFrame;  
import javax.swing.JLabel;  
import javax.swing.JPanel; */

class Quotelist
{

	String[] morning={ 
					//	"Good Morning...",
						"Success is going from failure to failure without losing your enthusiasm. - Winston Churchill",
						"If you can dream it, you can achieve it. - Zig Ziglar",
						"The only way to do great work is to love what you do. - Steve Jobs",
						"Talk is cheap. Show me the code. - Linus Torvalds",
						"When everything seems to be going against you, remember that the airplane takes off against the wind, not with it. – Henry Ford",
						"Life is what we make it, always has been, always will be. - Grandma Moses",
						"I would rather die of passion than of boredom. - Vincent van Gogh",
						"I didn’t fail the test. I just found 100 ways to do it wrong. - Benjamin Franklin",
						"Limitations live only in our minds. But if we use our imaginations, our possibilities become limitless. - Jamie Paolinetti"
					};
	
	String[] noon={
					//"Good Afternoon...",
					"It’s just pathetic to give up on something before you even give it a shot. - Reiko Mikami",
					"If nobody cares to accept you and wants you in this world, accept yourself and you will see that you don’t need them and their selfish ideas. – Alibaba Saluja",
					"Life is not a game of luck. If you wanna win, work hard. - Sora",
					"If you just submit yourself to fate, then that’s the end of it. - Keiichi Maebara",
					"Whatever you do, enjoy it to the fullest. That is the secret of life. - Rider",
					"ometimes I do feel like I’m a failure. Like there’s no hope for me. But even so, I’m not gonna give up. Ever! - Izuku Midoriya",
					"Power comes in response to a need, not a desire. You have to create that need. - Goku",
					"If you don’t like your destiny, don’t accept it. Instead, have the courage to change it the way you want it to be. - Naruto Uzumaki",
					"We can’t waste time worrying about the what if’s. - Ichigo Kurosaki"
				};
	String[] evening={
					"No matter how hard or impossible it is, never lose sight of your goal. – Monkey D Luffy",
					"Do exactly as you like. That is the true meaning of pleasure. Pleasure leads to joy and joy leads to happiness. – Gilgamesh",
					"If you can’t do something, then don’t. Focus on what you can do. – Shiroe",
					"The moment you think of giving up, think of the reason why you held on so long. – Natsu Dragneel",
					"If you wanna make people dream, you’ve gotta start by believing in that dream yourself! – Seiya Kanie",
					"People with talent often have the wrong impression that things will go as they think. - Karma Akabane",
					"Everything has beauty, but not everyone can see. – Confucius",
					"The best revenge is massive success. – Frank Sinatra",
					"Always be a first-rate version of yourself, instead of a second-rate version of somebody else. – Judy Garland"
				};

	String[] night={
					//"Good night...",
					"The darker the night, the brighter the stars, The deeper the grief, the closer is God! - Fyodor Dostoevsky",
					"Each night, when I go to sleep, I die. And the next morning, when I wake up, I am reborn. - Mahatma Gandhi",
					"Melancholy were the sounds on a winter's night. - Virginia Woolf",
					"Object-oriented programming offers a sustainable way to write spaghetti code. It lets you accrete programs as a series of patches. - Paul Graham,",
					"Take positive care of your mind, and it would surely take positive care of your life. - Edmond Mbiaka",
					"Everyday life is like programming, I guess. If you love something you can put beauty into it.  - Donald Knuth",
					"User interface is the process of shifting from chaotic complexity to elegant simplicity. - Akshat Paul",
					"An obstacle is often a stepping stone. - William Prescott",
					"Make each day your masterpiece. - John Wooden"
				};

	String[] independece={

							"Freedom is never dear at any price. It is the breath of life. What would a man not pay for living? - Mahatma Gandhi.",
							"Let new India arise out of peasants' cottage, grasping the plough, out of huts, cobbler and sweeper. - Swami Vivekananda",
							"The shots that hit me are the last nails to the coffin of the British rule in India.- Lala Lajpat Rai ",
							"One individual may die for an ideas,but that idea will,after his death,incarnate itself in a thousand lives. - Netaji Subhash Chandra Bose ",
							"Our nation is like a tree of which the original trunk is swarajya and the branches are swadeshi and boycott. - Subhas Chandra Bose "
						};
	String[] teacher={
						"A good teacher can inspire hope, ignite the imagination, and instill a love of learning - Brad Henry Love",
						"Success is not a good teacher, failure makes you humble - Shah Rukh Khan",
						"Fear is not a good teacher. The lessons of fear are quickly forgotten- Mary Catherine Bateson",
						"The teacher should be like the conductor in the orchestra, not the trainer in the circus- Abhijit Naskar",
						"The purpose of teachers should be to add to the sum of human knowers rather than the sum of human knowledge - Stuart Sherman"
					};
	int count = 0;
	public String getQuote()
	{
		
		Random rand = new Random();
		int index = rand.nextInt(1000)%8;
		Calendar c = Calendar.getInstance();
		int timeOfDay = c.get(Calendar.HOUR_OF_DAY);
		int month=c.get(Calendar.MONTH);
		int day=c.get(Calendar.DAY_OF_MONTH);
		if(day==15&&month==8)
		{
			

			return(independece[index]);
			//count++;
		}
		else if(day==5&&month==9)
		{
			return(teacher[index]);
		}
		else if(timeOfDay>3&&timeOfDay<12)
		{
			
			
			return(morning[index]);
			//count++;
		}
		else if(timeOfDay>12&&timeOfDay<17)
		{
			
			return(noon[index]);
			//count++;
		}
		else if(timeOfDay>17&&timeOfDay<20)
		{
			
			return(evening[index]);
			//count++;
		}
		else
		{
			
			return(night[index]);
			//count++;
		}
		
		
	}

}

public class Quote
{
	String quote;
	Quotelist q=new Quotelist();
	String[] list=new String[5];

	public void printQuote() throws Exception
	{
		/*JFrame frame = new JFrame("Quote");  
		JLabel lab,l1,l2;  
		JPanel panel = new JPanel();  
        panel.setLayout(new FlowLayout()); 
        JButton button = new JButton();  
        button.setText("Next"); */
		try
		{
			int i;
			// This will define a node in which the preferences can be stored
			Preferences prefs= Preferences.userRoot().node("com/alom/preferences");
			// prefs.put("vbn","bcbcdc");
		    for(i=0;i<5;i++)
		    {
		    	String a=Integer.toString(i);
		    	// prefs.put(a,"0");
			    list[i]=prefs.get(a,"0");
			}
			
			do
			{ 
				quote=q.getQuote();
				// System.out.println("abcd\n");
			    if (checkPrefs(prefs,quote))
			    {
			    	
			    	int j;

			    	new Quote().putPrefs(prefs,list[1],0);
			    	new Quote().putPrefs(prefs,list[2],1);
			    	new Quote().putPrefs(prefs,list[3],2);
			    	new Quote().putPrefs(prefs,list[4],3);
			    	// for(j=0;j<4;j++)
			    	// {
			    	// 	new Quote().putPrefs(prefs,list[i+1],i);
			    	// }
			    	new Quote().putPrefs(prefs,quote,4);
			    	// System.out.println("dssb\n");
			    	break;
			    }
			    
			}while(true);
		    System.out.println("\t\t\tQuote of the day:");
		    System.out.println("\t\t------------------------\n\n");
		    System.out.println(quote);
		    /*l1 = new JLabel("Quote of the day");
		    l2 = new JLabel("------------------");
		    OutputStream stream = new FileOutputStream("pref.xml");
		    panel.add(l1);
		    panel.add(l2);
		    lab = new JLabel(quote);
		    panel.add(lab);
		    prefs.exportNode(stream);  
        	panel.add(button);  
        	frame.add(panel);  
        	frame.setSize(800, 200);  
        	frame.setLocationRelativeTo(null);  
        	*/
        	/*button.addActionListener(new ActionListener(){  
    		public void actionPerformed(ActionEvent e){  
            	panel.add(lab); 

    }  
    }); */ 
        	//frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        	//frame.setVisible(true);
        	//frame.pack();

        

		}
		catch(Exception ex)
		{
			System.out.println("Exception!!\n");
		}  
    }
    public void putPrefs(Preferences prefs,String s,int index) 
    {
    	// System.out.println("print\n");
    	String a=Integer.toString(index);
        prefs.put(a,s);
    }
    public boolean checkPrefs(Preferences prefs,String quote) 
    {
    	int i;
    	// System.out.println("daaa\n");
        for(i=0;i<5;i++)
        {
        	// System.out.println(quote+" "+list[i]+"\n");
        	if(quote.equals(list[i]))
        	{
        		// System.out.println("llll\n");
        		return false;
        	}
        }
        return true;
    }
    /*public boolean checkWelcome(String wel)
    {
    	boolean isPrinted = false;
    	while(1)
    	{
    		isPrinted = true ; 
    		break;
    		System.out.println(wel);
    	}
    }*/
}
