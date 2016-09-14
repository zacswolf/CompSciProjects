/**
 * Magpie2.java  12/28/2012
 *
 * @author - Jane Doe
 * @author - Period n
 * @author - Id nnnnnnn
 *
 * @author - I received help from ...
 *
 */

/**
 * A program to carry on conversations with a human user.
 * This is the initial version that:
 * <ul><li>
 *       Uses indexOf to find strings
 * </li><li>
 * 		    Handles responding to simple words and phrases
 * </li></ul>
 * This version uses a nested if to handle default responses.
 * @author Laurie White
 * @version April 2012
 */
public class Magpie2
{
	/**
	 * Get a default greeting
	 * @return a greeting
	 */
	public String getGreeting()
	{
		return "Hello, let's talk.";
	}

	/**
	 * Gives a response to a user statement
	 *
	 * @param statement
	 *            the user statement
	 * @return a response based on the rules given
	 */
	public String getResponse(String statement)
	{
		String response = "";
		
		if (statement.indexOf(" no ") >= 0)
		{
			response = "Why so negative?";
		}
		else if (statement.indexOf("mother") >= 0
				|| statement.indexOf("father") >= 0
				|| statement.indexOf("sister") >= 0
				|| statement.indexOf("brother") >= 0)
		{
			response = "Tell me more about your family.";
		}
		else if (statement.indexOf("dog") >= 0 || statement.indexOf(" cat ") >= 0){
			response = "Tell me more about your pets.";
		}
		else if (statement.indexOf("Mr. Wrencher") >= 0 || statement.indexOf("Mr. Sperry") >= 0){
			response = "He sounds like a good teacher.";
		}
		else if (statement.indexOf("died") >= 0 || statement.indexOf("death") >= 0){
			response = "I am sorry to hear that";
		}
		else if (statement.indexOf("how") >= 0 && statement.indexOf("weather") >= 0){
			response = "It is decent.";
		}
		else if (statement.indexOf("what") >= 0 && statement.indexOf("food") >= 0 && statement.indexOf(" favorite ") >= 0 && statement.indexOf(" my ") == -1){
			response = "I like ice cream.";
		}
		else if (statement.indexOf("my") >= 0 && statement.indexOf("food") >= 0 && statement.indexOf(" favorite ") >= 0 && statement.indexOf(" what ") == -1){
			response = "I like that too!";
		}
		
		statement.trim();
		if (statement.length() < 1){
			response = "Please say something.";
		}
		else
		{
			response = getRandomResponse();
		}
		return response;
	}

	/**
	 * Pick a default response to use if nothing else fits.
	 * @return a non-committal string
	 */
	private String getRandomResponse()
	{
		final int NUMBER_OF_RESPONSES = 6;
		double r = Math.random();
		int whichResponse = (int)(r * NUMBER_OF_RESPONSES);
		String response = "";

		if (whichResponse == 0)
		{
			response = "Interesting, tell me more.";
		}
		else if (whichResponse == 1)
		{
			response = "Hmmm.";
		}
		else if (whichResponse == 2)
		{
			response = "Do you really think so?";
		}
		else if (whichResponse == 3)
		{
			response = "You don't say.";
		}
		else if (whichResponse == 4)
		{
			response = "Thats neat.";
		}
		else if (whichResponse == 5)
		{
			response = "Awww Yeah!";
		}

		return response;
	}
}
