
public class AlgWkst1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		boolean one = true, two = false, three = false;

		int cnt=0, fun=0;

		System.out.println(one || ++cnt>0);	
		System.out.println(one || cnt++>1);
		System.out.println(one && cnt++>1 || three );
		System.out.println(fun++>0 && cnt++>1 || cnt++>1 ); 
		System.out.println(cnt);
		System.out.println(one || ++cnt>2 && cnt++>2);
		System.out.println(one && cnt++>2 || ++cnt>2 );
		System.out.println( one = false );
		System.out.println( cnt++>5 && two == true);
		System.out.println(cnt++>5 | one==true & cnt++>5 ); 
		System.out.println(!(one && two));
		System.out.println(!(one || two));
		System.out.println(cnt>10);
		System.out.println(cnt);
	}

}
