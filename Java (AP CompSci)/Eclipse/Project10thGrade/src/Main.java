

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for (int i = 0; i <= 90; i = i + 30){
			long store = 0;
			
			for (int j = 0; j < 10; j++){
				long startTime = System.nanoTime();
				int counter = 0;
				int value;
				long fib;
				value = i;

				long[] array = new long[value + 1];
				while (counter <= value){
					if (value >= 0 && counter == 0){
						array[0] = 0;
					}
					if (value >= 1 && counter == 1){
						array[1] = 1;
					}
					if (value >= 2 && counter >= 2){
						array[counter] = array[counter - 1] + array[counter - 2];
					}

					counter = counter + 1;
				}
				fib = array[value];
				long endTime = System.nanoTime();
        
        
				store = store + (endTime - startTime);
			}
			System.out.println((store / 10.0));
		}
	}

}
