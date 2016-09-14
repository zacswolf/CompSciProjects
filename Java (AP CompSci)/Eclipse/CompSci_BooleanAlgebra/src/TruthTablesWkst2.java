
public class TruthTablesWkst2 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean a;
		boolean b = true;
		boolean c = false;
		a = !(b && c);
		System.out.println(a);
		
		
		boolean d;
		boolean e = true;
		boolean f = true;
		d = !(f || e);
		System.out.println(d);
		
		boolean g;
		boolean h = true;
		boolean i = false;
		boolean j = false;
		g = h && i||(i || j);
		System.out.println(g);
		
		boolean m;
		boolean n = true;
		boolean p = true;
		boolean q = false;
		m = !(n && p)|| p &&(n || q);
		System.out.println(m);
		
	}
}
