
public class MainClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//Because "Seth" is in the () the friend is seth
		ImportedClass ImportedObject = new ImportedClass("Seth");
		//same with ed
		ImportedClass ImportedObject2 = new ImportedClass("ED");
		
		//passed both objects into the method saying
		ImportedObject.saying();
		ImportedObject2.saying();
		
	}

}
