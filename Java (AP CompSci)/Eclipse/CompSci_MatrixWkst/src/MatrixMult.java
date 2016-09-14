
public class MatrixMult {
	public MatrixMult(long a[][], long b[][], long[][] ans){	
		long hold = 0;
		for (int i = 0; i < a.length; i++){
			//System.out.println("1st loop");
			for (int k = 0; k < b[0].length; k++){
				//System.out.println("Loop 1b");
				for (int j = 0; j <a[i].length; j++){
					//System.out.println("loop 2a");
					hold = a[i][j] * b[j][k] + hold;
				}
				ans[i][k] = hold;
				//System.out.println(hold);
				hold = 0;
			}
		}
		
		//printing
		//print ans
		for (int i= 0; i < ans.length; i++){
			//System.out.println("loop 3a");
			for (int j = 0; j< ans[i].length; j++){
				//System.out.println("loop 3b");
				System.out.print(ans[i][j] + "\t");
			}
			System.out.println("");
		}
		
	}
}
