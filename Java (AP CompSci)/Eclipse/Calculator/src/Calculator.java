//imports input
import java.util.Scanner;


public class Calculator {

	public static void main(String[] args) {
		
		
		
		Scanner aInput = new Scanner(System.in);
		Scanner operator = new Scanner(System.in);
		
		double fnum, snum, answer;
		int operation;
		
		System.out.println("Enter 1st number");
		fnum = aInput.nextDouble();
		
		
		System.out.println("What math operator do you want to use, 1 for Add, 2 for Subtract, 3 for Multiply, or 4 for Divide");
		operation = operator.nextInt();
		
		System.out.println("Enter 2nd number");
		snum = aInput.nextDouble();
		
		switch (operation){
			case 1:
				answer = fnum + snum;
				System.out.println(answer);
			break;
			
			case 2:
				answer = fnum - snum;
				System.out.println(answer);
			break;
			
			case 3:
				answer = fnum * snum;
				System.out.println(answer);
			break;
			
			case 4:
				answer = fnum / snum;
				System.out.println(answer);
			break;
			
			default:
				System.out.println("You did not type a correct number value for a operation");
			break;
		}
		

		
		/*  a int is a whole numbers and if they get change by a math operator
		the product is still a int, even if it has a decimal.
		EX: int5 / int2 = int3 (it should be 2.5 not 3)   */
		
		// a double is a number that has a decimal point and is used when doing fractions
	}

}
