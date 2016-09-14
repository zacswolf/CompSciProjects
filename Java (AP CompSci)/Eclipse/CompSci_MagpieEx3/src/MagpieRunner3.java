/**
 * MagpieRunner3.java  12/28/2012
 *
 * @author - Robert Glen Martin
 * @author - School for the Talented and Gifted
 * @author - Dallas ISD
 */

import java.util.Scanner;

/**
 * A simple class to run the Magpie class.
 * @author Laurie White
 * @version April 2012
 */
public class MagpieRunner3
{
	/**
	 * Create a Magpie, give it user input, and print its replies.
	 */
	public static void main(String[] args)
	{
		Magpie3 maggie = new Magpie3();

		System.out.println(maggie.getGreeting());
		Scanner in = new Scanner(System.in);
		String statement = in.nextLine();

		while (!statement.equals("Bye"))
		{
			System.out.println(maggie.getResponse(statement));
			statement = in.nextLine();
		}
	}
}
