
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Support supportObject = new Support();
		
		//defaults
		System.out.println(supportObject.toMilitary());
		System.out.println(supportObject.toString());
		
		//set time
		supportObject.setTime(13, 27, 6); // this is not in use in this example
		
		//with the time set
		System.out.println(supportObject.toMilitary());
		System.out.println(supportObject.toString());

		//https://www.thenewboston.com/videos.php?cat=31&video=18003
	}

}
