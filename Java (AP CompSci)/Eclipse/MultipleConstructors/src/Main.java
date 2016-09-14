
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Support supportObject = new Support();
		Support supportObject2 = new Support(5);
		Support supportObject3 = new Support(5,13);
		Support supportObject4 = new Support(5,13,43);
		
		System.out.printf("%s\n", supportObject.toMilitary());
		System.out.printf("%s\n", supportObject2.toMilitary());
		System.out.printf("%s\n", supportObject3.toMilitary());
		System.out.printf("%s\n", supportObject4.toMilitary());
		
	}

}
