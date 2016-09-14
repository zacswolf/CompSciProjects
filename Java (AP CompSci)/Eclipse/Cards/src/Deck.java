import java.util.ArrayList;
import java.util.Random;
public class Deck {
	
	private ArrayList<Card> Deck = new ArrayList<Card>();
	private ArrayList<Card> Used = new ArrayList<Card>();
	public Deck(ArrayList<Card> deck){
		Deck = deck;
	} 
	public Deck(){
		Deck.add(new Card("Spade", "2", 2));
		Deck.add(new Card("Spade", "3", 3));
		Deck.add(new Card("Spade", "4", 4));
		Deck.add(new Card("Spade", "5", 5));
		Deck.add(new Card("Spade", "6", 6));
		Deck.add(new Card("Spade", "7", 7));
		Deck.add(new Card("Spade", "8", 8));
		Deck.add(new Card("Spade", "9", 9));
		Deck.add(new Card("Spade", "10", 10));
		Deck.add(new Card("Spade", "Jack", 11));
		Deck.add(new Card("Spade", "Queen", 12));
		Deck.add(new Card("Spade", "King", 13));
		Deck.add(new Card("Spade", "Ace", 14));		
		Deck.add(new Card("Heart", "2", 2));
		Deck.add(new Card("Heart", "3", 3));
		Deck.add(new Card("Heart", "4", 4));
		Deck.add(new Card("Heart", "5", 5));
		Deck.add(new Card("Heart", "6", 6));
		Deck.add(new Card("Heart", "7", 7));
		Deck.add(new Card("Heart", "8", 8));
		Deck.add(new Card("Heart", "9", 9));
		Deck.add(new Card("Heart", "10", 10));
		Deck.add(new Card("Heart", "Jack", 11));
		Deck.add(new Card("Heart", "Queen", 12));
		Deck.add(new Card("Heart", "King", 13));
		Deck.add(new Card("Heart", "Ace", 14));
		Deck.add(new Card("Clover", "2", 2));
		Deck.add(new Card("Clover", "3", 3));
		Deck.add(new Card("Clover", "4", 4));
		Deck.add(new Card("Clover", "5", 5));
		Deck.add(new Card("Clover", "6", 6));
		Deck.add(new Card("Clover", "7", 7));
		Deck.add(new Card("Clover", "8", 8));
		Deck.add(new Card("Clover", "9", 9));
		Deck.add(new Card("Clover", "10", 10));
		Deck.add(new Card("Clover", "Jack", 11));
		Deck.add(new Card("Clover", "Queen", 12));
		Deck.add(new Card("Clover", "King", 13));
		Deck.add(new Card("Clover", "Ace", 14));
		Deck.add(new Card("Diamond", "2", 2));
		Deck.add(new Card("Diamond", "3", 3));
		Deck.add(new Card("Diamond", "4", 4));
		Deck.add(new Card("Diamond", "5", 5));
		Deck.add(new Card("Diamond", "6", 6));
		Deck.add(new Card("Diamond", "7", 7));
		Deck.add(new Card("Diamond", "8", 8));
		Deck.add(new Card("Diamond", "9", 9));
		Deck.add(new Card("Diamond", "10", 10));
		Deck.add(new Card("Diamond", "Jack", 11));
		Deck.add(new Card("Diamond", "Queen", 12));
		Deck.add(new Card("Diamond", "King", 13));
		Deck.add(new Card("Diamond", "Ace", 14));
	}
	
	
	
		public void Shuffle(){
			Random dice = new Random();
			int rand;
			Card Holder;
			for(int i = 0; i < Deck.size(); i++){
				rand = dice.nextInt(Deck.size());
				Holder = Deck.get(i);
				Deck.set(i, Deck.get(rand));
				Deck.set(rand, Holder);
			}
			
		}
		public void useCard(Card Card1){
			Used.add(Card1);
		}
		
		public int size(){
			return Deck.size();
		}
			
		public Card getCard(int index){
			return Deck.get(index);
		}
		
		public void delCard(int index){
			Deck.remove(index);
		}
		
		public void delCard(Card Card1){
			for(int i = 0; i < Deck.size(); i++){
				if (Deck.get(i) == Card1){
					Deck.remove(i);
					break;
				}
			}
		}
		
		public ArrayList<ArrayList<Card>> deal(int players, int cardsperplayer){
			ArrayList<ArrayList<Card>> Cards = new ArrayList<ArrayList<Card>>();
			ArrayList<Card> Hand = new ArrayList<Card>();
			for (int i = 1; i <= players; i++){
				for (int j =0; j < cardsperplayer; j++){
					Hand.add(Deck.get(0));
					Deck.remove(0);	
				}
				Cards.add(Hand);
				Hand = new ArrayList<Card>();
			}
			return Cards;
		}
	
		public void saying(){
			for (int i = 0; i < Deck.size(); i++){
				Deck.get(i).saying();
			}
		}
		public void indexSaying(){
			for (int i = 0; i < Deck.size(); i++){
				Deck.get(i).indexSaying(i);
			}
		}
	
}
