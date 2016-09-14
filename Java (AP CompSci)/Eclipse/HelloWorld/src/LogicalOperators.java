
public class LogicalOperators {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int boy, girl;
		boy = 18;
		girl = 68;
		
		
		// && is for multiple test and is a (and)
		if (boy > 10 && girl < 60) {
			System.out.println("You can enter");
			//only when both are right
		}
		else{
			System.out.println("You can not enter");
			//when 1 or 2 of 2 is wrong
		}
		
		
		
		// || is for multiple test and is a (or)
		if (boy > 10 || girl < 60) {
			System.out.println("You can enter");
			//when 1 or 2 of the 2 is right
		}
		else{
			System.out.println("You can not enter");
			//only when both are wrong 
		}
		
		
		
		
	}

}
