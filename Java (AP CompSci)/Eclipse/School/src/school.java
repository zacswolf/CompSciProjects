import java.util.ArrayList;

public abstract class school extends district implements General{
	private String theSchool;
	private ArrayList<String> rules = new ArrayList<String>();
	public school(){
		super();
		theSchool = "";
	}
	public school(String State, String district, String school){
		super(State, district);
		theSchool = school;
	}
	
	public void move(String School){
		setSchool(School);
	}
	public void move(String state, String district, String school){
		super.move(state, district);
		setSchool(school);
	}
	
	public boolean compareTo(school Student2){
		return super.compareTo((district)Student2) && theSchool.equals(Student2.getSchool());
	}
	public String addSchoolRule(String NewRules){
		rules.add(NewRules);
		return NewRules;
	}
	public String removeSchoolRule(String NewRules){
		return rules.remove(rules.indexOf(NewRules));
	}
	public String removeSchoolRule(int NewRules){
		return rules.remove(NewRules);
	}
	public String getSchoolRules(){
		String fullRules = "";
		for(int k = 0;k<rules.size();k++){
			fullRules = fullRules +rules.get(k) +", ";
		}
		return fullRules;
	}
	
	
	
	
	public String getSchool(){
		return theSchool;
	}
	public String setSchool(String school){
		theSchool = school;
		return theSchool;
	}

}