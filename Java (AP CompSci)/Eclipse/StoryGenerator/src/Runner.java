import java.util.Scanner;
public class Runner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String Type;
		System.out.println("Do you want to make one randomized story/password \"O,\" or a multiple counting story/password \"M,\"");
		Scanner Input = new Scanner(System.in);
		if (Input.nextLine().equals("O")){
			Type = "Once";
		}
		else{
			Type = "Multiple";
		}
		
		System.out.println("How many chars do you want your "+ Type + " to be?");
		int length = Input.nextInt();
		
		Boolean Rules;
		if (Type.equals("Story")){
		System.out.println("Do you want to use the Story Rules? Y for yes, N for no.");
			if (Input.nextLine().equals("Y")){
				Rules = true;
			}
			else{
				Rules = false;
			}
		}
		else{
			Rules = false;
		}
		
		Creator ImportedObject = new Creator(Type, length, Rules, "allChar");
		ImportedObject.saying();
	}

}
