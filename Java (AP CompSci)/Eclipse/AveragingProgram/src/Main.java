import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner input = new Scanner(System.in);
		Scanner numinput = new Scanner(System.in);
		int total = 0;
		int grade, number;
		int average;
		int counter = 0;
		
		
		System.out.println("How many Numbers do you want to average?");
		number = numinput.nextInt();
		System.out.println("Ok import " + number +" numbers please.");
		
		
		while (counter < number){
			grade = input.nextInt();
			total = total + grade;
			counter++;
		}
		
		average = total / number;
		System.out.println("Your average is " + average);
	}

}
