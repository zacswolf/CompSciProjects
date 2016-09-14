
public class pixel {

	private int[] RGB = new int[3];
	
	public pixel(){
		RGB[0] = 0;
		RGB[1] = 0;
		RGB[2] = 0;
	}
	public pixel(int Red, int Green, int Blue){
		RGB[0] = Red;
		RGB[1] = Green;
		RGB[2] = Blue;
	}
	public pixel(int[] rgb){
		RGB = rgb;
	}
	
	
	
	
	
	
	
	
	
	
	
	//setters
	public int[] setColor(int[] rgb){
		RGB = rgb;
		return RGB;
	}
	public int[] setColor(int Red, int Green, int Blue){
		RGB[0] = Red;
		RGB[1] = Green;
		RGB[2] = Blue;
		return RGB;
	}
	public int setRed(int red){
		RGB[0]= red;
		return RGB[0];
	}
	public int setGreen(int green){
		RGB[1]= green;
		return RGB[1];
	}
	public int setBlue(int blue){
		RGB[2]= blue;
		return RGB[2];
	}
	
	
	//getters
	public int[] getColor(){
		return RGB;
	}
	public int getRed(){
		return RGB[0];
	}
	public int getGreen(){
		return RGB[1];
	}
	public int getBlue(){
		return RGB[2];
	}
	
	public String toString(){
		return "[" + RGB[0] + "," + RGB[1] + "," +RGB[2] + "]";
	}
}
