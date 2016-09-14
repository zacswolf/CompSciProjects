
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//!(a*b) = !a +!b
		//!(a+b) =!a*!b
		
		//Question		a(!b)c + abc + !abc + !ab(!c) + a(!b)
		//				ac + !ab +a(!b)
		boolean a = true;
		boolean b = false;
		boolean c = false;
		boolean d = a && (!b)  && c || a && b && c || !a && b && c || !a && b && (!c) || a && (!b);
		System.out.println(d);
		
		//1st morgan rule
		boolean e = true;
		boolean f = false;
		System.out.println(!(e && f) + "\t" + (!e || !f));
		
		//2nd morgan rule
		boolean g = true;
		boolean h = false;
		System.out.println(!(g || h) + "\t" + (!g && !h));
	}

}
