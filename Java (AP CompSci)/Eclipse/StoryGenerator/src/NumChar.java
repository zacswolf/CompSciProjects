
public class NumChar {
	private int input;
	private int length;
	private	char[] charList = {'0','1','2','3','4','5','6','7','8','9'};
	
	//constructor allows you the initialize variables as soon as a object is created
	public NumChar(){
		input = 0;
	}
	
	
	public char getChar(int theInput){
		input = theInput;
		char Letter = charList[input];
		return Letter;
	}
	public int getNum(){
		length = charList.length;
		return length;
	}
}