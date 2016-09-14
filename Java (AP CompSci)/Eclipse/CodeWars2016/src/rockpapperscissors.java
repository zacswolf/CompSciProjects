import java.util.Scanner;
import java.util.Random;
public class rockpapperscissors {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		Random AI = new Random();
		System.out.println("You want to play best out of what");
		int bestoutof = in.nextInt();
		int Playerwins = 0;
		int AIwins = 0;
		int AIintmove = 0;
		String AImove;
		String Playermove;
		System.out.println("Okay, best out of "+ bestoutof + ". Just say Rock Paper or Scissor");
		while (Playerwins < Math.ceil((bestoutof + 1)/2) && AIwins < Math.ceil((bestoutof + 1)/2)){
			AIintmove = AI.nextInt(3);
			if (AIintmove == 0){
				AImove = "Rock";
			}
			else if (AIintmove == 1){
				AImove = "Paper";
			}
			else {
				AImove = "Scissor";

			}
			//System.out.println(AImove);
			Playermove = in.next();
			
			if (Playermove.equalsIgnoreCase(AImove)){
				System.out.println("Tie, you both choose " + AImove + "!");
			}
			else if(Playermove.equalsIgnoreCase("Paper") && AImove.equalsIgnoreCase("Rock")){
				Playerwins++;
				System.out.println("You won, the AI choose " + AImove + "!");
			}
			else if(Playermove.equalsIgnoreCase("Scissor") && AImove.equalsIgnoreCase("Paper")){
				Playerwins++;
				System.out.println("You won, the AI choose " + AImove + "!");
			}
			else if(Playermove.equalsIgnoreCase("Rock") && AImove.equalsIgnoreCase("Scissor")){
				Playerwins++;
				System.out.println("You won, the AI choose " + AImove + "!");
			}
			
			else if(AImove.equalsIgnoreCase("Paper") && Playermove.equalsIgnoreCase("Rock")){
				AIwins++;
				System.out.println("You lost, the AI choose " + AImove + "!");
			}
			else if(AImove.equalsIgnoreCase("Scissor") && Playermove.equalsIgnoreCase("Paper")){
				AIwins++;
				System.out.println("You lost, the AI choose " + AImove + "!");
			}
			else if(AImove.equalsIgnoreCase("Rock") && Playermove.equalsIgnoreCase("Scissor")){
				AIwins++;
				System.out.println("You lost, the AI choose " + AImove + "!");
			}
			
			if(Playerwins == Math.floor((bestoutof + 1)/2)){
				System.out.println("You won the game! It was " + Playerwins + " to " + AIwins + ".");
			}
			else if(AIwins == Math.floor((bestoutof + 1)/2)){
				System.out.println("You lost the game! It was " + Playerwins + " to " + AIwins + ".");
			}
		}
		
	}

}
