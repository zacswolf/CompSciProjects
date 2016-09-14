
public class ArraysMultidimensional7 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int firstarray[][]={{8, 9, 10, 11}, {12, 13, 14, 15}};
		
		/*System.out.println(firstarray[0][0]);
		System.out.println(firstarray[1][3]);*/
		
		int secondarray[][]={{30, 31, 32, 33}, {43}, {4, 5, 6}};
		
		/*System.out.println(secondarray[0][2]);
		System.out.println(secondarray[1][0]);
		System.out.println(secondarray[2][2]);*/
		
		System.out.println("This is the first array");
		display(firstarray);
		
		System.out.println("This is the second array");
		display(secondarray);
	}

	public static void display(int x[][]){
		for (int row=0;row<x.length;row++){
			//loops through the rows
			for(int column=0;column<x[row].length;column++){
				//loops through the columns
				System.out.print(x[row][column] + "\t");
			}
			System.out.println();
		}
		
		
	}
	
	
}
