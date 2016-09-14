
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		double amount;
		double principal = 10000; //starting point
		double rate = .01;//the rate it goes up (1% = .01)
		
		//formula amount = principal (1 + rate)^numberofdays
		
		for (int day = 1; day <= 365; day++){
			amount = principal*Math.pow(1 + rate, day);
			System.out.println(day + "   " + amount);
		}
	}

}
