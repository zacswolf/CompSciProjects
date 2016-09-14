
public class NestedIfStatement {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int age = 60;
		
		if (age < 50){
			System.out.println("Your are young");
		}else{
			System.out.println("Your are old");
			
			if (age > 75){
				System.out.println("Your really old");
			}else{
				System.out.println("Dont worry you are not really that old");
			}
		}
			
	}

}
