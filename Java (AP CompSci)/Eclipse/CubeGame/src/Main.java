import java.util.Scanner;
import java.util.Random;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println("Welcome to the cube game! Use the wasd to move, the [ key to move up, and the ' key to go down in order to control the selecting cube.");;
		Scanner UserInput = new Scanner(System.in);
		int maxx, maxy, maxz;
		int level = 1;
		int coord[]={0, 0, 0};
		int victory;
		char input = ' '; // the space is so it is something at the beginning
		int pointsleft;
		double numpoints;//how many points per map
		int numsection;//how many places to move per map
		Random Number = new Random();
		while (input != 'q'){
			System.out.println("Welcome to level " + level + "!");
			
			maxx = level;
			maxy = level;
			maxz = level;
			coord[0] = 0; 
			coord[1] = 0; 
			coord[2] = 0; 
			victory = 0; //0 is false, 1 is true
			
			//how many point there are
			numsection = (level * level * level); 
			numpoints = numsection / 10;
			//rounding
			if(numpoints < 1){
				numpoints = 1;//rounds to 1 so there will always be a point cube
			}
			else if(numpoints < 1){
			numpoints = Math.round(numpoints);//if there are multiple point cubes and it does not / evenly it will normally round
			}
			
			int intnumpoints = (int) numpoints;//makes numpoints a int in this situation
			
			pointsleft = intnumpoints;
			System.out.println("There are " + intnumpoints + " number of point on this map, find them all!");
			int points[] = new int[intnumpoints *3];//makes the array 
			//spawning in the points
			for (int counter = 0; counter < intnumpoints * 3; counter++){
				points[counter] = Number.nextInt(level * 2 + 1 );
			}
			for (int counter = 0; counter < points.length; counter++){ //this whole for statement is to fix a bug that sometimes gave a number too high other then the line below
				points[counter] = points[counter] - level;//other then this part, this makes the numbers - too
				if(points[counter] > level){
					points[counter] = level;
				}
				else if (Math.abs(points[counter]) > level && points[counter] < -level){ // to double check
					points[counter] = -level;
				}
				System.out.println(points[counter]);
			}
			
			
			
			while (victory == 0){
				input = UserInput.next().charAt(0);
				
				if (input == 'w'){
					coord[0] = coord[0] + 1;
					if (coord[0] > maxx){
						coord[0] = coord[0] - 1;
						System.out.println("You have hit the border of the cube!");
					}
				}
				if (input == 'a'){
					coord[1] = coord[1] - 1;
					if (Math.abs(coord[1]) > maxy){
						coord[1] = coord[1] + 1;
						System.out.println("You have hit the border of the cube!");
					}
				}
				if (input == 's'){
					coord[0] = coord[0] -1;
					if (Math.abs(coord[0]) > maxx){
						coord[0] = coord[0] + 1;
						System.out.println("You have hit the border of the cube!");
					}
				}
				if (input == 'd'){
					coord[1] = coord[1] + 1;
					if (coord[1] > maxy){
						coord[1] = coord[1] - 1;
						System.out.println("You have hit the border of the cube!");
					}
				}
				if (input == '['){
					coord[2] = coord[2] + 1;
					if (coord[2] > maxz){
						coord[2] = coord[2] - 1;
						System.out.println("You have hit the border of the cube!");
					}
				}
				if (input == '\''){
					coord[2] = coord[2] - 1;
					if (Math.abs(coord[2]) > maxz){
						coord[2] = coord[2] + 1;
						System.out.println("You have hit the border of the cube!");
					}
				}
				
				for(int counter = 0; counter < points.length / 3; counter++){ //this is to check to see if the player is on a point
					int counter2 = 0;
					if (coord[counter2] == points[counter2] && coord[counter2 + 1] == points[counter2 + 1] && coord[counter2 + 2] == points[counter2 + 2]){
						pointsleft = pointsleft - 1;
						points[counter2] = level + 1;//this gets rid of this point
						points[counter2 + 1] = level + 1;//this gets rid of this point
						points[counter2 + 2] = level + 1;//this gets rid of this point
						System.out.println("You have hit a point! There are " + pointsleft +" points left!");
					}
					counter2 = counter2 + 3;
					System.out.println("Cycle");
				}
				System.out.println(coord[0] + "\t" + coord[1] + "\t" + coord[2]);
				
				
				if (pointsleft == 0){
				victory = 1;
				}
			}
			
			level++;
		}
		
		
		
	}

}
