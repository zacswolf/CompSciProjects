import java.util.ArrayList;

public class student extends school implements General{
	
	private String name;
	private ArrayList<Double> grades = new ArrayList<Double>();
	
	public student(){
		super();
		name = "";
	}
	public student(String state, String district, String school, String Name){
		super(state, district, school);
		name = Name;
	}
	
	public int addGrade(double Grade){
		grades.add(Grade);
		return (int)(Math.round(Grade));
	}
	public int getGrade(){
		double total = 0;
		for(int k=0; k<grades.size(); k++){
			total= total + grades.get(k);
		}
		total = total/(grades.size()-1);
		return (int)(Math.round(total));
	}
	
	
	
	
	public boolean compareTo(student Student2){
		return super.compareTo(Student2) && name.equals(Student2.getName());
	}
	public String getRules(){
		String endString ="";
		if(getStateRules().length()>0){
			endString= endString + "State Rules: " + getStateRules();
		}
		if(getDistrictRules().length()>0){
			endString= endString + "District Rules: " + getDistrictRules();
		}
		if(getSchoolRules().length()>0){
			endString= endString + "School Rules: " + getSchoolRules();
		}
		
		
		return endString;
	}
	
	
	
	
	public String toString(){
		return "Student: " + getName() + "\tSchool: " + getSchool() + "    \tDistrict: "+ getDistrict() + "\tState: " + getState();
	}
	public String getName(){
		return name;
	}
	public String setName(String Name){
		name = Name;
		return name;
	}

}