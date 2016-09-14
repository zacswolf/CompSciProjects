
public class Uler1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int maxnumber = 1000;
	    int counter = 1;
	    int five = 0;
	    int three = 0;
	    int newcounter = 0;
	    while (five + 5 < maxnumber){
	    	counter++;
	        five =  (counter) *5;
	        }
	    System.out.println(counter);
	    while (three + 3 < maxnumber){
	    	counter++;
	    	newcounter++;
	        three =  (newcounter) *3;
	        }
	    int number[] = new int [counter];
	    System.out.println(counter);
	    int maxcounts = counter;
	    five = 0;
	    three = 0;
	    counter = 0;
	    int sum = 0;
        int c = 0;
        newcounter = 0;
        
        
        
	        while (five + 5 < maxnumber){
	        five =  (counter +1) *5;
	        number[counter] = five;
	        counter++;
	        }
	        System.out.println("5 is done");
	        while (three + 3 < maxnumber){
	        three =  (newcounter +1) *3;
	        number[counter] = three;
	        counter++;
	        newcounter++;
	        }
	        System.out.println("3 is done");
	        while( c < maxcounts){
	        sum = sum + number[c];
	        c++;
	        }
	        
	        System.out.println(sum);
	        
	        //subtract all multiples of 15 because we cant have it counting twice
	        int ftean = 0;
	        int value = 0;
	        counter = 1;
	        while (ftean + 15 < 1000){
	        	ftean = counter * 15;
	        	value = value + ftean;
	        	counter++;
	        }
	        System.out.println(sum - value);
	}

}
