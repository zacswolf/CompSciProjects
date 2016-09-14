
public class SelectionSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int num[] = {5,1,4,2,8};
	    int store;   //holding variable
	    int first;
	     
	    for (int i = num.length - 1; i > 0; i--)  
	    {
	    	first = 0;   //initialize to subscript of first element
	    	for(int j = 1; j <= i; j++)   //locate smallest element between positions 1 and i.
	    	{
	    		if(num[j] > num[first])         
	            first = j;
	        }
	        store = num[first];   //swap smallest found with element in position i.
	        num[first] = num[i];
	        num[i] = store; 
	    }           
	
	     
	     
	     
	     for (int x = 0; x < num.length; x++){
	    	 System.out.print(num[x] + " ");
	     }
	}

}
