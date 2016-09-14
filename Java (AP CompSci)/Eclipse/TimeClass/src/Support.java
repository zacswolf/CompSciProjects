
public class Support {

	private int hour;
	private int minute;
	private int second;
	
	public void setTime(int h, int m, int s){
		// if hour, (h) is >= 0 And less then 24 then use that number, if not make it 0
		hour = ((h>=0 && h<24) ? h : 0);
		minute = ((m>=0 && m<60) ? m : 0);
		second = ((s>=0 && s<60) ? s : 0);
		
	}
	
	public String toMilitary(){
		return String.format("%02d:%02d:%02d", hour, minute, second);
	}
	
	public String toString(){
		//1Dec:2Dec:2Dec String,
		//if hour is = 0 or 12 then make it = to 12, else % it, so if hour = 13 make it = 1
		return String.format("%d:%02d:%02d %s", ((hour == 0||hour==12) ?12:hour%12), minute, second, (hour < 12? "AM": "PM"));
	}
	
	
	
	
	
	
}
