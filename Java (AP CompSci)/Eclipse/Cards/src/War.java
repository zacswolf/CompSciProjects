import java.util.ArrayList;


public class War {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Deck Deck1 = new Deck();
		Deck1.saying();
		Deck1.Shuffle();
		Deck1.saying();
		System.out.println();
			
		//deal cards
		ArrayList<ArrayList<Card>> Cards = Deck1.deal(2, 7);
		ArrayList<Player> Players= new ArrayList<Player>();
		for (int i = 0; i < Cards.size(); i++){
			Players.add(new Player(Cards.get(i)));
			Players.get(i).Saying();
			System.out.println();
		}
		
		Boolean finished = false;
		int turns = 0;
		Card LastPlayed = new Card("0", "0", 0);
		while (finished==false){
			
			//Players.get(turns%2).getCard(0);//.buffer(Players.get(turns%2).getCard(0)).saying();
			//Players.get(turns%2).remove(0);
			
			if (turns%2 == 0){
				//Players.get(turns%2).getCard(0).saying();
				LastPlayed = Players.get(turns%2).getCard(0);
				Players.get(turns%2).remove(0);
			}
			else{
				ArrayList<Card> TieCards = new ArrayList<Card>();
				
			}
			
			
			
			if (Players.get(turns%2).size() == 0){
				finished = true;
			}
			
			turns++;
		}
		
		
	}

	public void Logic(Card LastPlayed, ArrayList<Player> Players, int turns, ArrayList<Card> TieCards){
		if(Players.get(turns%2).getCard(0).getValue() >= LastPlayed.getValue()){
			Players.get(turns%2).buffer(LastPlayed);
			Players.get(turns%2).buffer(Players.get(turns%2).getCard(0));
		}
		else if(Players.get(turns%2).getCard(0).getValue() <= LastPlayed.getValue()){
			Players.get((turns-1)%2).buffer(Players.get(turns%2).getCard(0));
			Players.get((turns-1)%2).buffer(LastPlayed);
		}
		else{
			System.out.println("It is a tie! So play a faced down and a faced up card.");
			TieCards.add(Players.get(turns%2).getCard(0));
			TieCards.add(LastPlayed);
			TieCards.add(Players.get(turns%2).getCard(0));
			TieCards.add(Players.get((turns-1)%2).getCard(0));
		}
		Players.get((turns+1)%2).remove(0);
	}
	
}
