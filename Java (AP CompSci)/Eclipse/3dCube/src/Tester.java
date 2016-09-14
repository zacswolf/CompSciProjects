
public class Tester {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long timeNeeded =System.currentTimeMillis();
		System.out.println(timeNeeded);
		cube myCube = new cube(16,16,16);
		myCube.allChangeGreenTo(100);
		int[] rgb = {100, 200, 255};
		myCube.allGradient(10000, rgb);
		timeNeeded =System.currentTimeMillis()-timeNeeded;
		System.out.println(timeNeeded);
	}

}
