import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
public class main {
	public static void main(String[] args) {
		List<String> theList = new LinkedList<String>();
		Scanner in = new Scanner(System.in);
		while(true){
			while(true){
				String a = in.nextLine();
				if (a.equals("END")){
					break;
				}
				else{
					theList.add(a);
				}
			}
			
			
			String[] Class = (String[]) theList.toArray(new String[theList.size()]);
			
			
			
			String Hold;
			for (int i = 0; i < Class.length; i++){
				for (int p = i+1; p < Class.length; p++){
					if (Class[i].compareTo(Class[p]) > 1 ){
						Hold = Class[i];
						Class[i] = Class[p];
						Class[p] = Hold;
					}
				}
			}
		
			for (int i = 0; i < Class.length; i++){
				System.out.println(Class[i]);
			}
			
			
		}
	}
}
