
public class test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] mat = new int[3][2];
		mat[0][0] = 1;
		mat[0][1] = 2;
		mat[1][0] = 3;
		mat[1][1] = 4;
		mat[2][0] = 5;
		mat[2][1] = 6;
		for (int p = 0;p<mat.length; p++){
		reverseArray(mat[p]);
		}
		
		int[] hold;
		for(int c = 0; c<(mat.length)/2; c++){
			hold = mat[c];
			mat[c] = mat[mat.length-c-1];
			mat[mat.length-c-1] = hold;
		}
		
		for (int d = 0;d<mat.length; d++){
		for (int p = 0;p<mat[d].length; p++){
			System.out.println(mat[d][p]);
		}
		}
	}
	
	public static void reverseArray(int[] arr){
		for (int i=0; i < arr.length/2;i++){
			int temp = arr[i];
			arr[i] = arr[arr.length-i-1];
			arr[arr.length-i-1] = temp;
		}
	}
	

}
