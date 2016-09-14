import java.util.ArrayList;
import java.util.List;


public class test2 {

	private static String sentence = "The";
	public static void main(String[] args) {
		System.out.println(getBlankPositions());
		System.out.println(countWords());
		for(int k=0;k<countWords(); k++){
			System.out.println(getWords()[k]);
		}

		
	}
	
	
	public static List<Integer> getBlankPositions(){
		List<Integer> blanks = new ArrayList<Integer>();
		for(int a = 0; a < sentence.length(); a++){
			if(sentence.charAt(a) == ' '){
				blanks.add(a);
			}
		}
		return blanks;
	}
	
	public static int countWords(){
		return 1+ getBlankPositions().size();
	}
	
	public static String[] getWords(){
		String[] words = new String[countWords()];
		int start =0;
		for (int c=0;c<countWords()-1;c++){
			words[c]=sentence.substring(start, getBlankPositions().get(c));
			start = getBlankPositions().get(c)+1;
		}
		words[words.length-1] = sentence.substring(start);
		return words;
	}

}
