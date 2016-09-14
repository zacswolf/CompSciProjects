
public class LowerChar {
	private int input;
	private int length;
	private char[] charList = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	//constructor allows you the initialize variables as soon as a object is created
	public LowerChar(){
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
