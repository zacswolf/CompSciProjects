
public class CardTester {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
			Card Card1= new Card("Heart", "Ace", 11);
			System.out.println(Card1.getSuit());
			System.out.println(Card1.getRank());
			System.out.println(Card1.getValue());
			Card1.saying();
			
			Card Card2= new Card("Heart", "4", 4);
			System.out.println(Card2.getSuit());
			System.out.println(Card2.getRank());
			System.out.println(Card2.getValue());
			Card2.saying();
			
			
			
	}

}
