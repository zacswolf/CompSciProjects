import java.util.ArrayList;

public abstract class district extends state implements General{
	private String theDistrict;
	private ArrayList<String> rules = new ArrayList<String>();
	public district(){
		super();
		theDistrict = "";
	}
	public district(String State, String district){
		super(State);
		theDistrict = district;
	}
	
	public void move(String district){
		setDistrict(district);
	}
	public void move(String state, String district){
		super.move(state);
		setDistrict(district);
	}
	
	public boolean compareTo(district Student2){
		return super.compareTo((state)Student2) && theDistrict.equals(Student2.getDistrict());
	}
	
	public String addDistrictRule(String NewRules){
		rules.add(NewRules);
		return NewRules;
	}
	public String removeDistrictRule(String NewRules){
		return rules.remove(rules.indexOf(NewRules));
	}
	public String removeDistrictRule(int NewRules){
		return rules.remove(NewRules);
	}
	public String getDistrictRules(){
		String fullRules = "";
		for(int k = 0;k<rules.size();k++){
			fullRules = fullRules +rules.get(k) +", ";
		}
		return fullRules;
	}
	
	
	
	public String getDistrict(){
		return theDistrict;
	}
	public String setDistrict(String district){
		theDistrict = district;
		return theDistrict;
	}

}