import java.util.ArrayList;


public abstract class state implements General{
	private String theState;
	private ArrayList<String> rules = new ArrayList<String>();
	public state(){
		theState = "";
	}
	public state(String state){
		theState = state;
	}
	
	public void move(String state){
		setState(state);
	}
	
	public boolean compareTo(state Student2){
		return theState.equals(Student2.getState());
	}
	public String addStateRule(String NewRules){
		rules.add(NewRules);
		return NewRules;
	}
	public String removeStateRule(String NewRules){
		return rules.remove(rules.indexOf(NewRules));
	}
	public String removeStateRule(int NewRules){
		return rules.remove(NewRules);
	}
	public String getStateRules(){
		String fullRules = "";
		for(int k = 0;k<rules.size();k++){
			fullRules = fullRules +rules.get(k) +", ";
		}
		return fullRules;
	}
	
	
	
	
	public String getState(){
		return theState;
	}
	
	public String setState(String state){
		theState = state;
		return theState;
	}

}
