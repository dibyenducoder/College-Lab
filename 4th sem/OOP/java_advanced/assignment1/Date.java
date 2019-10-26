package Adv1;
import java.text.SimpleDateFormat;
import java.util.Calendar;
public class Date
{

	String[] morning={ "Good Morning ..."};
	
	String[] noon={ "Good AfterNoon..." };
	String[] evening={  "Good Evening ..."};

	String[] night={
					"Good night...",
					};

	String[] independece={
							"Happy Independence Day..."
							};
	String[] teacher={
						"Happy Teacher's  Day" };
	//int count = 0;
	public String getDate()
	{
		
		//Random rand = new Random();
		//int index = rand.nextInt(1000)%8;
		int index = 0;
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