import java.util.ArrayList;
import java.util.Random;


public class Player {

	private ArrayList<Card> Hand;
	private ArrayList<Card> Buffer = new ArrayList<Card>();//used in War
	
	public Player(ArrayList<Card> hand){
		Hand = hand;
	}
	
	public Card Play(Deck Deck1, int index){
		Card PlayCard = Hand.get(index);
		Deck1.useCard(PlayCard);
		Hand.remove(index);
		
		return PlayCard;
	}

	public int size(){
		return Hand.size();
	}
	
	public ArrayList<Card> getCards(){
		return Hand;
	}
	
	public Card getCard(int index){
		return Hand.get(index);
	}
	
	public Card buffer(Card Card1){ //used in War
		Buffer.add(Card1);
		return Card1;
	}
	public void playBuffer(){ //used in War
		Random dice = new Random();
		int rand;
		Card Holder;
		for(int i = 0; i < Buffer.size(); i++){
			rand = dice.nextInt(Buffer.size());
			Holder = Buffer.get(i);
			Buffer.set(i, Buffer.get(rand));
			Buffer.set(rand, Holder);
		}
		for(int i = 0; i < Buffer.size(); i++){
			Hand.add(Buffer.get(i));
		}
		Buffer.clear();
	}
	
	public void Draw(Deck Deck1){
		Hand.add(Deck1.getCard(Deck1.size()-1));
		Deck1.delCard(Deck1.size()-1);
	}
	
	public void remove(int index){
		Hand.remove(index);
	}
	
	public void Saying(){
		for (int i = 0; i < Hand.size(); i++){
			Hand.get(i).saying();
		}
	}
	
	public void indexSaying(){
		for (int i = 0; i < Hand.size(); i++){
			Hand.get(i).indexSaying(i);
		}
	}
	
}
