import java.util.Random;
public class Lab {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long startTime = System.currentTimeMillis();
		
		
		//rand
		Random num = new Random();
		long x = num.nextInt(1000) + 2;
		long a[][] = new long[num.nextInt(1000) + 2][(int) x];
		long b[][] = new long[(int) x][num.nextInt(1000) + 2];
		for (int f = 0; f < a.length; f++){
			for (int g = 0; g< a[f].length; g++){
				a[f][g] = num.nextInt(10000);
			}
		}
		for (int f = 0; f < b.length; f++){
			for (int g = 0; g< b[f].length; g++){
				b[f][g] = num.nextInt(10000);
			}
		}

		
		
		//Hard Code
		/*int a[][] = {{1,2,-2,0},{-3,4,7,2},{6,0,3,1}};
		int b[][] = {{-1,3},{0,9},{1,-11},{4,-5}};*/
		
		
		
		
		
		long ans[][] = new long[a.length][b[0].length];
		if (a[1].length == b.length){
			MatrixMult mm = new MatrixMult(a, b, ans);
		}
		else{
			System.out.println("No Solution");
		}
		
		//time
		long endTime = System.currentTimeMillis();
		System.out.println((endTime - startTime) / 1000.0);
	}

}
