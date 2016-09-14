
public class Uler4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int product;
        int pal = 0;
        int bcounter = 999;
        int scounter = 999;
        char[] chararray;
        int biggest = 0;
        while (pal == 0){
        product = bcounter * scounter;
        String sproduct;
        sproduct = Integer.toString(product);
        chararray = sproduct.toCharArray();
        System.out.println(scounter + "   " + bcounter + "   " + product);
        
        	if (chararray.length == 5 && chararray[0] == chararray[4] && chararray[1] == chararray[3]){
        			if(product > biggest){
        				biggest = product;
        			
        			}
        		
                    
                
        	}
        	else if (chararray.length == 6 && chararray[0] == chararray[5] && chararray[1] == chararray[4] && chararray[2] == chararray[3]){
        			if(product > biggest){
        				biggest = product;
        			}
        			
        	}
            else if (scounter > 100){
                scounter--;
            }
            else{
                bcounter--;
                scounter = 999;
            }
        	
        		
        	

        }

	}

}
