
public class UPunctChar {
	private int input;
	private int length;
	private char[] charList = {'@','#','$','%','^','&','*',')','(',']','[','}','{','|','\\','/','_','+','=','-','<','>','`','~'};
	
	//constructor allows you the initialize variables as soon as a object is created
	public UPunctChar(){
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