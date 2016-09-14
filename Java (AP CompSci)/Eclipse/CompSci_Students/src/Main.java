
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Student Student1 = new Student("Colin", 16, "Male");
		Student Student2 = new Student("Zac", 16, "Other");
		Student Student3 = new Student("Dylan", 16, "Male");
		Student Student4 = new Student("Olivia", 17, "Female");
		Student Student5 = new Student("Michael", 17, "Male");
		Student Student6 = new Student("Sandra", 18, "Female");
		Student Student7 = new Student("Dustin", 17, "Male");
		Student Student8 = new Student("Jonmarc", 18, "Male");
		Student Student9 = new Student("Quinton", 17, "Male");
		Student Student10 = new Student("Arman", 16, "Other");
		Student Student11 = new Student("Seth", 16, "Male");
		Student[] People = {Student1, Student2, Student3, Student4, Student5, Student6, Student7, Student8, Student9, Student10, Student11};
		
		SortAge(People);
		
		//printing
		System.out.println("# \t Age \t Sex");
		for (int i = 0; i < People.length; i++){
			System.out.println(i + "\t" + People[i].getName() + "\t" + People[i].getAge() + "\t" + People[i].getSex());
		}
		
		System.out.println();
		System.out.println();
		
		
		//Class stats
		System.out.println("Class Stats");
		String name ="Zac";
		int nummales=0;
		int numfemales=0;
		int numother=0;
		int num14 =0;
		int num15 =0;
		int num16 =0;
		int num17 =0;
		int num18 =0;
		for (int i = 0; i < People.length; i++){
			if (name.equalsIgnoreCase(People[i].getName())){
				System.out.println("I am student number #: " + i);
			}
			if(People[i].getSex().equalsIgnoreCase("Male")){
				nummales++;
			}
			else if(People[i].getSex().equalsIgnoreCase("Female")){
				numfemales++;
			}
			else{
				numother++;
			}
			
			if(People[i].getAge() == 14){
				num14++;
			}
			else if(People[i].getAge() == 15){
				num15++;
			}
			else if(People[i].getAge() == 16){
				num16++;
			}
			else if(People[i].getAge() == 17){
				num17++;
			}
			else if(People[i].getAge() == 18){
				num18++;
			}
			
			
			
		}
		System.out.println("We have " + nummales + " number of males, " + numfemales + " number of females, and " + numother + " number of others");
		System.out.println("We have " + num14 + " 14 year olds, " + num15 + " 15 year olds, " + num16 + " 16 year olds, " + num17 + " 17 year olds, and " + num18 + " 18 year olds");
		
	}
	
	private static Student[] SortAge(Student[] People){
		Student Holder= new Student(null,0,null);
		for (int i = 0; i < People.length; i++){
			for (int j = 0; j < People.length; j++){
				if(People[i].getAge() < People[j].getAge()){
					Holder = People[j];
					People[j] = People[i];
					People[i] = Holder;
				}
				
			}
		}
		return People;
	}
	
	
	
	
	private static Student[] SortName(Student[] People){
		Student Holder= new Student(null,0,null);
		for (int i = 0; i < People.length; i++){
			for (int j = 0; j < People.length; j++){
				if((int)People[i].getName().charAt(0) < (int)People[j].getName().charAt(0)){
					Holder = People[j];
					People[j] = People[i];
					People[i] = Holder;
					
				}
				
			}
		}
		return People;
	}
	
	
	private static Student[] SortSex(Student[] People){
		Student Holder= new Student(null,0,null);
		for (int i = 0; i < People.length; i++){
			for (int j = 0; j < People.length; j++){
				if((int)People[i].getSex().charAt(0) < (int)People[j].getSex().charAt(0)){
					Holder = People[j];
					People[j] = People[i];
					People[i] = Holder;
				}
				
			}
		}
		return People;
	}
	

}
