
public class UpperChar {
	private int input;
	private int length;
	private char[] charList = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	//constructor allows you the initialize variables as soon as a object is created
	public UpperChar(){
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