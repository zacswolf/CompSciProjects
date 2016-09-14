import java.util.ArrayList;
import java.util.Random;

public class Rework {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//Soft Configurations (Change often)
		int maxLength = 3; //sets the maximum length for the sequence(one Random)   sets the amount of sequences(Sequential)
		int minLength = 0; ////sets the minimum length for the sequence (Set it 1 under the maxLength to always get that length)   ONLY FOR PASSWORD
		int Mode = 2; // 1 for one random, 2 for a sequential
		int SMode = 1; // 1 for showing, 2 for only showing the last  ONLY FOR SEQUENTIAL
		int[] Imports = {1};
		
		
		//Hard Configurations (Does not usually change
		char[] PunctList = {',',';','\'','\"','?','.','!'};//1
		char[] LowList = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};//2
		char[] NumberList = {'0','1','2','3','4','5','6','7','8','9'};//3
		char[] SpaceList = {' '};//4
		char[] UpList = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};//5
		char[] OtherList = {'@','#','$','%','^','&','*',')','(',']','[','}','{','|','\\','/','_','+','=','-','<','>','`','~'};//6
		
		//Variables that never change
		Random Rand = new Random();
		ArrayList<Character> Chars = new ArrayList<Character>();
		int nextInt = 0;
		char nextChar;
		int length = 0; ////////Do something eventually with the .super thing so you can set the size here if you wanted, so its not just random
		ArrayList<Character> Final = new ArrayList<Character>();
		
		//Stores Imports into the Chars arraylist
		for (int i=0; i < Imports.length; i++){
			 switch (Imports[i]) {
	            case 1: 
	            	for (int a = 0; a< PunctList.length; a++){
	            		Chars.add(PunctList[a]);
	            	}
	                     break;
	            case 2: 
	            	for (int b = 0; b< LowList.length; b++){
	            		Chars.add(LowList[b]);
	            	}
	                     break;
	            case 3: 
	            	for (int c = 0; c< NumberList.length; c++){
	            		Chars.add(NumberList[c]);
	            	}
	                     break;
	            case 4: 
	            	for (int d = 0; d< SpaceList.length; d++){
	            		Chars.add(SpaceList[d]);
	            	}
	                     break;
	            case 5: 
	            	for (int e = 0; e< UpList.length; e++){
	            		Chars.add(UpList[e]);
	            	}
	                     break;
	            case 6: 
	            	for (int f = 0; f< OtherList.length; f++){
	            		Chars.add(OtherList[f]);
	            	}
	                     break;
	                     
	            default: 
	            	//error message
	                     break;
	        }
		}
		
		//Starts touching the Mode setting
		if (Mode == 1){
			//Random
			
			
			if (maxLength <= 0){ //checks to see that maxLength is greater then 0
				//error message
			}
			else if (minLength >= maxLength){
				//error message
			}
			else if (Math.abs(minLength) >= maxLength){
				//error message
			}
			else{
				length = Rand.nextInt(maxLength - Math.abs(minLength)) + 1 + Math.abs(minLength); //sets the length randomly
			}
			
			for (int m = 0; m < length; m++){
				nextInt = Rand.nextInt(Chars.size());
				nextChar = Chars.get(nextInt);
				Final.add(nextChar);
			}
			
			//Print
			for (int print = 0; print < Final.size(); print++){
				System.out.print(Final.get(print));
			}
		}
		else if (Mode == 2){
			//Sequential
			//initializing the array
			int sizeholder =0;
			/*for(int i = 1; i <= maxLength; i++){
				sizeholder = (int) (sizeholder + Math.pow(Chars.size(), i));
			}*/
			String[] FinalSeq = new String[maxLength];
			
			//filling FinalSeq
			for(int y =0; y < FinalSeq.length; y++){
					FinalSeq[y] = "";
				
			}
			
			//logic
			for (int n = 0; n < maxLength; n++){
				for (int o = 0; o < Math.pow(Chars.size(), n+1); o++){
					for (int u = 0; u < n + 1; u++){
						if (FinalSeq[n].equals("")){
							FinalSeq[n] = Chars.get((o+1) % Chars.size()).toString();
						}
						else{
							FinalSeq[n] = FinalSeq[n] + Chars.get((u/*o+1*/) % Chars.size());
						}
					}
				}
			}
			/*for (int n = 0; n < maxLength; n++){
				for (int o = 0; o < Math.pow(Chars.size(), n+1); o++){
						//you need to loop the line below n times again and some how change what the Chars.get(o).toString() is.
						for (int p = 0; p < n; p++){
							FinalSeq[n][o] = FinalSeq[n][o] + Chars.get(p).toString();
							System.out.println(FinalSeq[n][o]);
						}
				}
			}*/
			
			//Print
			System.out.println(sizeholder + " is the size holder, ");
			for (int q =0; q < FinalSeq.length; q++){
					if (FinalSeq[q].equals("")){
						
					}
					else{
						System.out.println(FinalSeq[q]);
					}
				}
			}
			
			
			
		}
		else{
			//error message
		}

	}

}
