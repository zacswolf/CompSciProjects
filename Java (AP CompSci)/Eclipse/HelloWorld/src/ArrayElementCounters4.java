import java.util.Random;

public class ArrayElementCounters4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Random rand = new Random();
		int freq[] = new int[7]; 
		//made a array name freq and set it equal to 7 elements in that array
		
		//in order to change how many times it rolled, change the max it will roll for
		for(int roll = 0; roll < 6; roll++){
			++freq[1 +rand.nextInt(6)];
			//++freq = add 1 each time that this hits this number
			//[1 + rand.nextInt(6)] = 1 + "a random number 0 to 5", soooo its a rand 1 to 6
			
			//so if it rolled a 6 it would add 1 to the 6th slot, ++freq[6]
		}
		
		System.out.println("Face\tFrequency");
		
		for(int face = 1; face < freq.length; face++){
			System.out.println(face +"\t" + freq[face]);
		}
	}

}
