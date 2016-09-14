import java.util.Scanner;

public class MainClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner input = new Scanner(System.in);
		ImportedClass ImportedObject = new ImportedClass();
		
		System.out.println("Enter name of friend here: ");
		
		//takes whatever the user enters and stores it in the string temp
		String temp = input.nextLine();
		//in class importedclass take that variable temp and use it in the set name method
		ImportedObject.setName(temp);
		//now use the saying method in the Imported class
		ImportedObject.saying();
		
		
	}

}
