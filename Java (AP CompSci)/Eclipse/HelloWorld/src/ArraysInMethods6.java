
public class ArraysInMethods6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int numarray[] = {3, 4, 5, 6, 7};
		change(numarray); //method(array)
		
		for(int y: numarray){
			System.out.println(y);
		}
	}

	
	public static void change(int x[]){
		for(int counter = 0; counter < x.length; counter++){
			x[counter] += 5;
		}
	}
	
	
	
	
}
