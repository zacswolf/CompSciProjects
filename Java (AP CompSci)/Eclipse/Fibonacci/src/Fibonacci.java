import java.util.Scanner;
import java.math.*; // for the big int
public class Fibonacci {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		int counter = 0;
		int value;
        BigInteger fib;
        BigInteger zero = new BigInteger("0");
        BigInteger one = new BigInteger("1");
        //String command;
        Scanner num = new Scanner(System.in);
        System.out.println("Say a number up to 53925");
        value = num.nextInt();

        BigInteger[] array = new BigInteger[value + 1];
        while ( counter <= value){
        	if (value >= 0 && counter == 0){
        		array[0] = zero;
        	}
        	if (value >= 1 && counter == 1){
        		array[1] = one;
        	}
        	if (value >= 2 && counter >= 2){
        		array[(int) counter] = array[counter - 1].add (array[counter - 2]);
        	}
        	//System.out.println(counter + "    " + array[counter]);
        	counter = counter + 1;
        }
        fib = array[value];
        System.out.println("Your value is " + fib + ".");
        //System.out.println(fibonacci(10));
	}
	
	/*public static int fibonacci (int n){
		if (n == 0){
			return 0;
		}
		else if (n == 1){
			return 1;
		}
		else{
			return fibonacci(n-1) + fibonacci(n-2);
		}
	}*/
	
	
	

}
