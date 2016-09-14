
public class ArraySummingElements3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int numarray[] = {21, 16, 86, 21, 3};
		int sum = 0;
		
		for(int counter = 0; counter < numarray.length; counter++){
			sum += numarray[counter];
		}
		
		System.out.println("The sum of these numbers is " + sum);
		
	}

}

// this program sums up all the numbers in the array