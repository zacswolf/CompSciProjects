
public class VariableLength {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(average(43, 56, 76, 8, 65, 76, 2, 31));
	}

	public static int average(int...numbers){
		//the ... means it can be any number of numbers
		int total =0;
		for(int x:numbers){
			total+=x;
		}
		return total/numbers.length;
	}
}
