
public class Method1 {
	public static void main(String[] args) {
		long startTime = System.currentTimeMillis();
		
		double pi = 0.0;
		long ValueOfPrecision = 1000000000;
		double stockPile = 0.0;
		int num = 1;
		
		
		for (int i = 1; i <= ValueOfPrecision; i++){
			if(i % 2 == 1){
				stockPile = (double)4/num;
			}
			else{
				stockPile = (double)-4/num;
			}
			
			pi = stockPile + pi;
			num = num + 2;
		}
		System.out.println(pi);
		
		long endTime = System.currentTimeMillis();
		System.out.println((endTime - startTime) / 1000.0);
	}
}
