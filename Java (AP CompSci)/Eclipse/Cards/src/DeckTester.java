import java.util.ArrayList;
import java.util.Scanner;
public class DeckTester {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//fill deck
		ArrayList<Card> deck = new ArrayList<Card>();
		String Suit = null;
		String Rank = null;
		int Value = 0;
		for (int i = 0; i < 4; i++){
			for (int j =2; j <= 14; j++){
				switch(i){
					case 0:
						Suit = "Heart";
					break;
					case 1:
						Suit = "Spade";
					break;
					case 2:
						Suit = "Clover";
					break;
					case 3:
						Suit = "Diamond";
					break;
				}
				switch(j){
					case 2:
						Rank = "2";
						Value = 2;
						break;
					case 3:
						Rank = "3";
						Value = 3;
					break;
					case 4:
						Rank = "2";
						Value = 4;
					break;
					case 5:
						Rank = "5";
						Value = 5;
					break;
					case 6:
						Rank = "6";
						Value = 6;
					break;
					case 7:
						Rank = "7";
						Value = 7;
					break;
					case 8:
						Rank = "8";
						Value = 8;
					break;
					case 9:
						Rank = "9";
						Value = 9;
					break;
					case 10:
						Rank = "10";
						Value = 10;
					break;
					case 11:
						Rank = "Jack";
						Value = 10;
					break;
					case 12:
						Rank = "Queen";
						Value = 10;
					break;
					case 13:
						Rank = "King";
						Value = 10;
					break;
					case 14:
						Rank = "Ace";
						Value = 11;
					break;
			}
				deck.add(new Card(Suit, Rank, Value));
			}
		}
		
		
		
		Deck Deck1 = new Deck(deck);
		Deck1.saying();
		Deck1.Shuffle();
		Deck1.saying();
		Deck1.size();
		System.out.println();
		
		//deal cards
		ArrayList<ArrayList<Card>> Cards = Deck1.deal(2, 7);
		ArrayList<Player> Players= new ArrayList<Player>();
		for (int i = 0; i < Cards.size(); i++){
			Players.add(new Player(Cards.get(i)));
			Players.get(i).Saying();
			System.out.println();
		}
		
		
		//Play all cards
		int Size = Players.get(0).size();
		System.out.println(Players.size());
		System.out.println(Players.get(0).size());
		/*for (int i = 0; i < Players.size(); i++){
			for(int j = 0; j < Size; j++){
				Players.get(i).Play(Deck1, 0).saying();
			}
		}*/
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
		
		Scanner input = new Scanner(System.in);
		
		Boolean end = false;
		int turns = 0;
		String Operation;
		int CardIndex;
		Card LastPlayed = Deck1.getCard(Deck1.size()-1);
		Deck1.useCard(LastPlayed);
		Deck1.delCard(LastPlayed);
		
		while(end == false){
			System.out.println(LastPlayed.getSuit() + ", " + LastPlayed.getRank() + " was played last.");
			//Players.get(turns % Size).Saying();
			System.out.println();
			System.out.println("Player " + turns % Size + " it is your turn!");
			System.out.println("What do you want to do? Draw or Play?");
			Operation = input.next();
			if (Operation.equalsIgnoreCase("Draw")){
				Players.get(turns % Size).Draw(Deck1);
				Players.get(turns % Size).getCard(Players.get(turns % Size).size()-1).saying();
			}
			else if (Operation.equalsIgnoreCase("Play")){
				Players.get(turns % Size).indexSaying();
				System.out.println("What card do u want to play?");
				CardIndex = input.nextInt();
				LastPlayed = Players.get(turns % Size).Play(Deck1, CardIndex);
				//need to see if the card they placed is good with the rules
				//LastPlayed = Players.get(turns % Size).getCard(CardIndex-1);
				System.out.println(LastPlayed.getSuit() + ", " + LastPlayed.getRank() + " was played last.");
			}
			turns++;
		}
}
}