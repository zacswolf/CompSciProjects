import java.util.Collections;


public class BubbleSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num[] = {5,1,4,2,8};
	     boolean flag = true;   // set flag to true to begin first pass
	     int store;   //holding variable

	     while (flag)
	     {
	    	 flag= false;    //set flag to false awaiting a possible swap
	         for(int i=0; i < num.length -1; i++)
	         {
	        	 if (num[i] > num[i+1])   
	             {
	        		 store = num[i];                //swap elements
	        		 num[i] = num[i+1];
	        		 num[i+1] = store;
	        		 flag = true;              //shows a swap occurred  
	             } 
	         } 
	     }
	     
	     for (int j = 0; j < num.length; j++){
	    	 System.out.print(num[j] + " ");
	     }
	}
}
