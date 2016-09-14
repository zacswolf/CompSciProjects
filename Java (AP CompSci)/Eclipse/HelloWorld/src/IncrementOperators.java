
public class IncrementOperators {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		int tuna = 5;
		
		//adds 1 to the int tuna
		++tuna;
		System.out.println(tuna);
		//you could also do...
		//making tuna back to 5
		tuna = 5;
		System.out.println(++tuna);
		
		//this way is changes the number after it is printed so you have to print a extra time
		//making tuna back to 5
		tuna = 5;
		System.out.println(tuna++);
		System.out.println(tuna);
		
		//also works with -- for subtraction
		System.out.println(--tuna);
		
		
		
		
		//2 Ways to add 5 to tuna so its value is 10
		tuna = tuna + 5;
		System.out.println(tuna);
		
		//making tuna back to 5
		tuna = 5;
		
		//also
		tuna += 5;
		//This also works with -=, /=, *=
		System.out.println(tuna);
		
		
	}

}
