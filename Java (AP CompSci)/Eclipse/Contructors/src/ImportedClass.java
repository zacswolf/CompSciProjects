
public class ImportedClass {
	//this private string is a instance variable
	private String friendName;
	
	//constructor allows you the initialize variables as soon as a object is created
	public ImportedClass(String name){
		friendName = name;
	}
	
	
	
	/*public void setName(String name){
		friendName = name;
	}*/
	
	public String getName(){
		return friendName;
	}
	
	public void saying(){
		//for printf it lets you do %s
		//if you use %s then you put the name of the string "getName" after the quotes and a ,
		System.out.printf("Your friend is %s", getName());
	}
	
}
