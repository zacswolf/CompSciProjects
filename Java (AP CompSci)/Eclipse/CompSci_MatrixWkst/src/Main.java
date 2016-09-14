
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//find how many times a certain number appears 
		int[][] mat = {{1,2,3,4,5,6}, {1,2,3,4,5,6}};
		int val = 3;
		int times = 0;
		int num = 0;
		
		for (int bcounter = 0; bcounter < mat.length; bcounter++){
			for (int scounter = 0; scounter < mat[bcounter].length; scounter++){
				num = mat[bcounter][scounter];
				if (num == val){
					times++;
				}
			}
		}
		System.out.println(times);
		
		//find odd numbers
		int thenum = 0;
		
		
		for (int bcounter = 0; bcounter < mat.length; bcounter++){
			for (int scounter = 0; scounter < mat[bcounter].length; scounter++){
				thenum = mat[bcounter][scounter];
				if (thenum % 2 == 1 ){
					System.out.println(thenum);
				}
			}
		}
		
	}

}
