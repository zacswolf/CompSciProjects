
public class Helper {
	private int month;
	private int day;
	private int year;
	
	public Helper(int m, int d, int y){
		month = m;
		day = d;
		year = y;
		
		System.out.printf("The construtuctor for this is %s\n", this);
		//"this" is a reference to the current object
	}
	
	public String toString(){
		return String.format("%d/%d/%d", month, day, year);
	}
}
