import java.math.BigInteger;


public class Uler3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		BigInteger num = new BigInteger("600851475143");
		BigInteger two = new BigInteger("2");
		BigInteger zero = new BigInteger("0");
		BigInteger half = (num.divide(two));
		BigInteger counter = new BigInteger("1");
		BigInteger last = new BigInteger("1");
		half.doubleValue();//rounds it
		boolean checker;
		int compare = counter.compareTo(half);
        while (compare == -1 ){ //compare less then 
        	compare = counter.compareTo(half);
            checker = num.mod(counter).equals(zero);
            if (checker == true){
            	last = counter;
            	System.out.println(counter);
            }
            counter = counter.nextProbablePrime();

        }
        System.out.println("Here: " + last);
        
        
        //the number 6857 is the answer
        
	}
}


