
public class EnhancedforLoop5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int numarray[]={3,4,5,6,7};
		int total = 0;
		
		//for("variable" "name" : "array name")
		for(int x: numarray){
			total += x;
		}
		
		System.out.println(total); 
		
	}

}
