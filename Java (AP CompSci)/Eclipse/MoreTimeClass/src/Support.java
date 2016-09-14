
public class Support {

	//INSTANCE VARIABLES
	private int hour = 1;
	private int minute = 2;
	private int second = 3;
	
	public void setTime(int hour, int minute, int second){
		this.hour = 4;
		this.minute = 5;
		this.second = 6;
		/*normally the instance variable will overcome the public variables but when you
		type this."variablename" it will make that variable overcome the instance variable*/
	}
	
	public String toMilitary(){
		return String.format("%02d:%02d:%02d", hour, minute, second);
	}
	
	public String toString(){
		//1Dec:2Dec:2Dec String,
		//if hour is = 0 or 12 then make it = to 12, else % it, so if hour = 13 make it = 1
		return String.format("%d:%02d:%02d %s", ((hour == 0||hour==12) ?12:hour%12), minute, second, (hour < 12? "AM": "PM"));
	}
	
	
	
	
	
	//https://www.thenewboston.com/videos.php?cat=31&video=18003
}
