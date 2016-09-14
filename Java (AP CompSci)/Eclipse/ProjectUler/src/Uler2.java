

public class Uler2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub


		int counter = 0;
		int value = 4000000;
		int fib = 0;
        int[] array = new int[value + 1];
        while ( fib <= value){
        if (value >= 0 && counter == 0){
            array[0] = 0;
        }
        if (value >= 1 && counter == 1){
            array[1] = 1;
        }
        if (value >= 2 && counter >= 2){
            array[(int) counter] = array[counter - 1] + array[counter - 2];
        }
        if (array[counter] % 2 == 0){
        	fib = array[counter] + fib;
        	System.out.println("hi");
        }
        counter = counter + 1;
        }
        System.out.println(fib);
	}

}
