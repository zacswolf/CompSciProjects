
import static java.lang.System.*;
import java.awt.Color;

public class GridTester
{
	public static void main(String[] args)
	{
		Grid gridTest = new Grid(2,2);
		
		System.out.println(gridTest.getNumRows());
		System.out.println(gridTest.getNumCols());
		
		gridTest.setSpot(0,0,new Piece("red checker"));
		System.out.println(gridTest.toString(0,0));	
		
		gridTest.setSpot(1,1,new Piece(100,100,"black bishop"));
		System.out.println(gridTest.toString(1,1));	

		gridTest.setSpot(1,1,new Piece(200 ,200, 20, 20, "bishop", Color.WHITE));
		System.out.println(gridTest.toString(1,1));	
		
		System.out.println(gridTest.getSpot(1,0));		
		System.out.println(gridTest.getSpot(0,1));							
	}
}
