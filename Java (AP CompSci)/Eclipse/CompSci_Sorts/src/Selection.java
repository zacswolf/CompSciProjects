//© Zac Schulwolf 2k15
public class Selection {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[] = {9,5,7,2,3};

		int min, minIndex;
		for(int i = 0;i < a.length; i++)
		{
		min = a[i];
		minIndex = i;
		for (int j = i + 1; j < a.length; j++) // Find minimum
		{
			if (a[j] < min) //salient feature
			{
			min = a[j];
			minIndex = j;
			
			}	 
		}
		a[minIndex] = a[i]; // swap
		a[i] = min; 
		System.out.println(a[i]);
		}
	}

}
/*
	A disadvantage of the selection sort is that it will not allow an early exit from the entire process if the list becomes ordered in an early pass.
	O(n^2)
	The program scans for the smallest number then replaces the first number with that number and then repeats this process
	incremental
	if (a[j] < min){min = a[j];minIndex = j;}	 
	if (a[j] < min)
	OD 37645
	1p 37645
	2p 34675
	3p 34576
	4p 34576
	
*/