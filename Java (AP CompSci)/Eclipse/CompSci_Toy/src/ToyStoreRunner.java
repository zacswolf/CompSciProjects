//© A+ Computer Science  -  www.apluscompsci.com
//Name -
//Date -
//Class -
//Lab  -

import java.util.Scanner;

import java.util.ArrayList;
import java.util.Collections;

//import static java.lang.System.*;

public class ToyStoreRunner
{
	public static void main( String args[] )
	{
		ArrayList<String> stringArray = new ArrayList<String>();
		Scanner Input = new Scanner(System.in);
		System.out.println("What words do you want to put in, type stop when you are done");
		String Word = null;
		
		while (true){
		Word = Input.nextLine();
		if (Word.equalsIgnoreCase("stop")){
			break;
		}
		stringArray.add(Word);
		}
		
		System.out.println("Ok you can stop now");
		
		//String stringArray[] = {"sorry", "bat", "sorry", "sorry", "sorry", "train", "train", "teddy", "teddy", "ball", "ball"};
		
		
		ArrayList<Integer> numArray = new ArrayList<Integer>();
		int thiscounter = 0;
		while(stringArray.size() > thiscounter){
			numArray.add(0);
			thiscounter++;
		}
		
		int scounter = 0;
		int newValue = 0;
		for(int counter = 0; counter < stringArray.size(); counter++){
			//System.out.println(counter + "\t" + stringArray.get(counter));
			while (true){
				
			if (stringArray.get(scounter).equals(stringArray.get(counter))){
				newValue = numArray.get(scounter) + 1;
				numArray.set(scounter, newValue);
				//System.out.println("Breaking " + stringArray.get(scounter)  + scounter + stringArray.get(counter) + counter + numArray.get(scounter));
				break;
			}
			else{
				scounter++;
				//System.out.println(scounter);
				
			}
			
			}
			scounter = 0;
			
		}
		System.out.println();
		
		for(int counter = 0; counter < numArray.size(); counter++){
			if (numArray.get(counter) != 0){
			System.out.println( stringArray.get(counter) + "\t" + numArray.get(counter));
			}
		}
		/*
		int greatest = 0;
		ArrayList<Integer> numCounter = new ArrayList<Integer>();
		
		
		for(int counter = 0; counter >= numArray.length; counter++){
			if (numArray[counter] > greatest){
				System.out.println("Hi");
				greatest = numArray[counter];
				numCounter.clear();
				numCounter.add(counter);
			}
			
			else if (numArray[counter] == greatest){
				System.out.println("Bye");
				greatest = numArray[counter];
				numCounter.add(counter);
			}
			
		}
		
		
		if (numCounter.size() > 1){
			System.out.println("The Maxs are:");
		}
		else{
			System.out.println("The max is ");
		}
		
		System.out.println(numArray.length);
		System.out.println(stringArray.size());
		System.out.println(numCounter.size());
		for(int counter = 0; counter <= numCounter.size(); counter++){
			System.out.println(stringArray.get(numCounter.get(counter)) + "\t" + numArray[numCounter.get(counter)]);
		}*/
		
		Collections.sort(numArray);
		System.out.println("The Max is " + numArray.get(numArray.size() - 1));
		/*ArrayList<Integer> numbers = new ArrayList<Integer>();
		numbers.add(1);
		numbers.get(0);
		Collections.sort(numbers);*/
		
		
		
		
	}
}