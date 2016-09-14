import java.util.ArrayList;
import java.util.Random;

public class Creator {

	private String charType;
	private String[] numType;
	private int numOfTypes;
	private char[][] done;
	private int usableChars = 0;
	private String OnceorMultiple;
	private ArrayList<Character> usuableCharslist = new ArrayList<Character> ();
	
	//constructor allows you the initialize variables as soon as a object is created
	public Creator(String Type, int length, Boolean Rules, String cType1){
		OnceorMultiple = Type;
		numOfTypes = 1;
		String[] numType = new String[numOfTypes];
		numType[0] = cType1;
	}
	public Creator(String Type, int length, Boolean Rules, String cType1, String cType2){
		OnceorMultiple = Type;
		numOfTypes = 2;
		String[] numType = new String[numOfTypes];
		numType[0] = cType1;
		numType[1] = cType2;
	}
	public Creator(String Type, int length, Boolean Rules, String cType1, String cType2, String cType3){
		OnceorMultiple = Type;
		numOfTypes = 3;
		String[] numType = new String[numOfTypes];
		numType[0] = cType1;
		numType[1] = cType2;
		numType[2] = cType3;
	}
	public Creator(String Type, int length, Boolean Rules, String cType1, String cType2, String cType3, String cType4){
		OnceorMultiple = Type;
		numOfTypes = 4;
		String[] numType = new String[numOfTypes];
		numType[0] = cType1;
		numType[1] = cType2;
		numType[2] = cType3;
		numType[3] = cType4;
	}
	public Creator(String Type, int length, Boolean Rules, String cType1, String cType2, String cType3, String cType4, String cType5){
		OnceorMultiple = Type;
		numOfTypes = 5;
		String[] numType = new String[numOfTypes];
		numType[0] = cType1;
		numType[1] = cType2;
		numType[2] = cType3;
		numType[3] = cType4;
		numType[4] = cType5;
	}
	public Creator(String Type, int length, Boolean Rules, String cType1, String cType2, String cType3, String cType4, String cType5, String cType6){
		OnceorMultiple = Type;
		numOfTypes = 5;
		String[] numType = new String[numOfTypes];
		numType[0] = cType1;
		numType[1] = cType2;
		numType[2] = cType3;
		numType[3] = cType4;
		numType[4] = cType5;
		numType[5] = cType6;
	}

	
	public void setChar(){
		for(int i = 0; i < numOfTypes; i++){
			charType = numType[i];
			if (charType.equals("allChar")){
				//All of the chars types combine
				LowerChar ImportedLC = new LowerChar();
				UpperChar ImportedUC = new UpperChar();
				IPunctChar ImportedIPC = new IPunctChar();
				UPunctChar ImportedUPC = new UPunctChar();
				NumChar ImportedNC = new NumChar();
				SpaceChar ImportedSC = new SpaceChar();
				usableChars = usableChars + ImportedLC.getNum() + ImportedUC.getNum() + ImportedIPC.getNum() + ImportedUPC.getNum() + ImportedNC.getNum();
			}
			else if (charType.equals("LowerChar")){
				//just LowerChar
				LowerChar ImportedLC = new LowerChar();
				usableChars = usableChars + ImportedLC.getNum();
				for (int q = 0; q < ImportedLC.getNum(); q++){
					usuableCharslist.add(ImportedLC.getChar(q));
				}
			}
			else if (charType.equals("UpperChar")){
				//just UpperChar
				UpperChar ImportedUC = new UpperChar();
				usableChars = usableChars + ImportedUC.getNum();
				for (int q = 0; q < ImportedUC.getNum(); q++){
					usuableCharslist.add(ImportedUC.getChar(q));
				}
			}
			else if (charType.equals("IPunctChar")){
				//just IPunctChar
				IPunctChar ImportedIPC = new IPunctChar();
				usableChars = usableChars + ImportedIPC.getNum();
				for (int q = 0; q < ImportedIPC.getNum(); q++){
					usuableCharslist.add(ImportedIPC.getChar(q));
				}
			}
			else if (charType.equals("UPunctChar")){
				//just UPunctChar
				UPunctChar ImportedUPC = new UPunctChar();
				usableChars = usableChars + ImportedUPC.getNum();
				for (int q = 0; q < ImportedUPC.getNum(); q++){
					usuableCharslist.add(ImportedUPC.getChar(q));
				}
			}
			else if (charType.equals("NumChar")){
				//just NumChar
				NumChar ImportedNC = new NumChar();
				usableChars = usableChars + ImportedNC.getNum();
				for (int q = 0; q < ImportedNC.getNum(); q++){
					usuableCharslist.add(ImportedNC.getChar(q));
				}
			}
			else if (charType.equals("SpaceChar")){
				//just SpaceChar
				SpaceChar ImportedSC = new SpaceChar();
				usableChars = usableChars + ImportedSC.getNum();
				for (int q = 0; q < ImportedSC.getNum(); q++){
					usuableCharslist.add(ImportedSC.getChar(q));
				}
			}
		}
	}
	public char getChar(int index){
		return usuableCharslist.get(index);
	}
	
	public int random(){
		Random dice = new Random();
		int num;
		num = 1 + dice.nextInt(5);
		return num;
	}
	
	public void main(){
		//Password Generator
		if (OnceorMultiple.equals("Once")){
			for (int i = 0; i < usuableCharslist.size(); i++){
				//Loops for the amount of chars
				
				done[0][i] =  getChar(random());
			}
		}
		//Story Generator
		else if (OnceorMultiple.equals("Multiple")){
			for (int i = 0; i < usuableCharslist.size(); i++){
				//Loops for the amount of chars
				
			}	
		}
		else{
			System.out.println("When you chose to create a Story or a Password, you miss typed.");
		}
	}
	
	
	public void saying(){
		for(int i= 0; i < done.length; i++){
			for(int q= 0; q < done[i].length; q++){
				System.out.print(done[i][q]);
			}	
		}
	}
}