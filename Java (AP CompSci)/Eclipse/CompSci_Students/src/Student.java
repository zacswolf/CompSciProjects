
public class Student {

	private String Name;
	private int Age;
	private String Sex;
	
	public Student(String name, int age, String sex){
		Name =name;
		Age = age;
		Sex = sex;
	}
	public String getName(){
		return Name;
	}	
	public int getAge(){
		return Age;
	}	
	public String getSex(){
		return Sex;
	}	
}
