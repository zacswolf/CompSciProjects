
public class Tester {

	public static void main(String[] args) {
		
		
		student Zac = new student("Texas", "AISD", "Anderson", "Zac");
		student Seth = new student("Texas", "AISD", "Anderson", "Zac");
		System.out.println(Zac.toString());
		((school)Zac).move("Akins");
		System.out.println(Zac.toString());
		System.out.println((Zac).compareTo(Seth));
		Zac.addSchoolRule("Must wear uniform on Tuesdays");
		System.out.println(Zac.getSchoolRules());
		Zac.addStateRule("Must not wear uniform on Wednesdays");
		Zac.addSchoolRule("Must wear uniform on Thursdays");
		System.out.println(Zac.getRules());
	}

}
