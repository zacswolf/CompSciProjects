//imports the Input
import java.util.Scanner;


public class HelloWorld {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// Hello world
		System.out.println("Hello world");
		
		
		// variables
		double anumber;
		anumber = 5.28;
		
		// print anumber
		System.out.println(anumber);
		
		
		//user input
		System.out.println("Type a number!");
		Scanner UsersNumber = new Scanner(System.in);
		//print user input
		System.out.println(UsersNumber.nextLine());
	}

}
