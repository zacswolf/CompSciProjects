
import java.util.Scanner;

public class MainClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		Scanner input = new Scanner(System.in);
		
		//the class that you want to import something from, a object = new "class name" ();
		ImportedClass ImportedClassObject = new ImportedClass();
		
		System.out.println("Enter your name here: ");
		String name = input.nextLine();
		
		
		
		//"the object" . "function" ("any variable");
		ImportedClassObject.simpleMessage(name);
		
	}

}
