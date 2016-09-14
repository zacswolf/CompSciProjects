
public class ArrayTable2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println("Index\tValue");
		int numarray[] = {32, 12, 18, 54, 2};
		
		
		// numarray.length is nameofarray.length and it is the length of a array starting at 0
		for(int counter = 0; counter < numarray.length; counter++){
			System.out.println(counter + "\t" + numarray[counter]);
		}
		
	}

}
