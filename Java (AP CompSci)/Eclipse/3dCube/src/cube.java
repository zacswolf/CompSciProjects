
public class cube {
	
	pixel[][][] pixels;
	
	public cube(){
		pixels = new pixel[1][1][1];
		fill(0,0,0);
	}
	
	public cube(int DimensionX, int DimensionY, int DimensionZ){
		pixels = new pixel[DimensionX][DimensionY][DimensionZ];
		fill(0,0,0);
	}
	
	private void fill(int r, int g, int b){
		for(int x = 0; x< pixels.length; x++){
			for(int y = 0; y< pixels.length; y++){
				for(int z = 0; z< pixels.length; z++){
					pixels[x][y][z] = new pixel(r,g,b);
				}
			}
		}
	}
	
	public void allColor(int[] rgb){
		for(int x = 0; x< pixels.length; x++){
			for(int y = 0; y< pixels.length; y++){
				for(int z = 0; z< pixels.length; z++){
					pixels[x][y][z].setColor(rgb);
				}
			}
		}
	}
	public void allChangeRedTo(int red){
		for(int x = 0; x< pixels.length; x++){
			for(int y = 0; y< pixels.length; y++){
				for(int z = 0; z< pixels.length; z++){
					pixels[x][y][z].setRed(red);
				}
			}
		}
	}
	public void allChangeGreenTo(int green){
		for(int x = 0; x< pixels.length; x++){
			for(int y = 0; y< pixels.length; y++){
				for(int z = 0; z< pixels.length; z++){
					pixels[x][y][z].setGreen(green);
				}
			}
		}
	}
	public void allChangeBlueTo(int blue){
		for(int x = 0; x< pixels.length; x++){
			for(int y = 0; y< pixels.length; y++){
				for(int z = 0; z< pixels.length; z++){
					pixels[x][y][z].setBlue(blue);
				}
			}
		}
	}
	
	//used to help the gradient methods
	private double[][][][] getColorDif(long milisec, int[]rgb){
		double redDif[][][] = new double[pixels.length][pixels[0].length][pixels[0][0].length];
		double greenDif[][][] = new double[pixels.length][pixels[0].length][pixels[0][0].length];
		double blueDif[][][] = new double[pixels.length][pixels[0].length][pixels[0][0].length];
		
		for(int x = 0; x< pixels.length; x++){
			for(int y = 0; y< pixels.length; y++){
				for(int z = 0; z< pixels.length; z++){
					redDif[x][y][z] = rgb[0]-pixels[x][y][z].getRed();
					greenDif[x][y][z] = rgb[1]-pixels[x][y][z].getGreen();
					blueDif[x][y][z] = rgb[2]-pixels[x][y][z].getBlue();
					redDif[x][y][z] = redDif[x][y][z]/milisec;
					greenDif[x][y][z] = greenDif[x][y][z]/milisec;
					blueDif[x][y][z] = blueDif[x][y][z]/milisec;
				}
			}
		}
		double[][][][] colors = {redDif, greenDif, blueDif};
		return colors;
	}
	
	//Gradients
	public void allGradient(long milisec, int[]rgb){
		double redDif[][][] = getColorDif(milisec, rgb)[0];
		double greenDif[][][] = getColorDif(milisec, rgb)[1];
		double blueDif[][][] = getColorDif(milisec, rgb)[2];
		System.out.println(redDif[0][0][0]);
		long start = System.currentTimeMillis();
		pixel[][][] original = new pixel[pixels.length][pixels.length][pixels.length];
		
		for(int x = 0; x< pixels.length; x++){
			for(int y = 0; y< pixels.length; y++){
				for(int z = 0; z< pixels.length; z++){
					original[x][y][z] = new pixel(pixels[x][y][z].getRed(),pixels[x][y][z].getGreen(),pixels[x][y][z].getBlue());
				}
			}
		}
		
		long timeNeeded =milisec+System.currentTimeMillis();
		System.out.println(original[0][0][0].getRed());
		while(System.currentTimeMillis() < timeNeeded){
			for(int x = 0; x< pixels.length; x++){
				for(int y = 0; y< pixels.length; y++){
					for(int z = 0; z< pixels.length; z++){
						pixels[x][y][z].setRed( original[x][y][z].getRed() + (int) ( Math.round( (System.currentTimeMillis() - start) * (redDif[x][y][z]) ) ) );
						pixels[x][y][z].setGreen( original[x][y][z].getGreen() + (int) ( Math.round( (System.currentTimeMillis() - start) * (greenDif[x][y][z]) ) ) );
						pixels[x][y][z].setBlue( original[x][y][z].getBlue() + (int) ( Math.round( (System.currentTimeMillis() - start) * (blueDif[x][y][z]) ) ) );
					}
				}
			}
			System.out.println(toString());
		}
	fill(rgb[0],rgb[1],rgb[2]);
	System.out.println(toString());
	}
	public void redGradient(long milisec, int[]rgb){
		double redDif[][][] = getColorDif(milisec, rgb)[0];
		
		long start = System.currentTimeMillis();
		long timeNeeded =milisec+start;
		while(System.currentTimeMillis() < timeNeeded){
			for(int x = 0; x< pixels.length; x++){
				for(int y = 0; y< pixels.length; y++){
					for(int z = 0; z< pixels.length; z++){
						pixels[x][y][z].setRed( pixels[x][y][z].getRed() + (int) ( Math.round( (System.currentTimeMillis() - start) * (redDif[x][y][z]) ) ) );
					}
				}
			}
		}
	}
	public void greenGradient(long milisec, int[]rgb){
		double greenDif[][][] = getColorDif(milisec, rgb)[1];
		
		long start = System.currentTimeMillis();
		long timeNeeded =milisec+start;
		while(System.currentTimeMillis() < timeNeeded){
			for(int x = 0; x< pixels.length; x++){
				for(int y = 0; y< pixels.length; y++){
					for(int z = 0; z< pixels.length; z++){
						pixels[x][y][z].setGreen( pixels[x][y][z].getGreen() + (int) ( Math.round( (System.currentTimeMillis() - start) * (greenDif[x][y][z]) ) ) );
					}
				}
			}
		}
	}
	public void blueGradient(long milisec, int[]rgb){
		double blueDif[][][] = getColorDif(milisec, rgb)[2];
		
		long start = System.currentTimeMillis();
		long timeNeeded =milisec+start;
		while(System.currentTimeMillis() < timeNeeded){
			for(int x = 0; x< pixels.length; x++){
				for(int y = 0; y< pixels.length; y++){
					for(int z = 0; z< pixels.length; z++){
						pixels[x][y][z].setBlue( pixels[x][y][z].getBlue() + (int) ( Math.round( (System.currentTimeMillis() - start) * (blueDif[x][y][z]) ) ) );
					}
				}
			}
		}
	}
	
	public String toString(){
		String message = "";
		for(int x = 0; x< pixels.length; x++){
			for(int y = 0; y< pixels.length; y++){
				for(int z = 0; z< pixels.length; z++){
					message = message + pixels[x][y][z].toString() + " ";
				}
				message = message + "\n";
			}
			message = message + "\n";
		}
		message = message + "\n";
	return message;
	}
	
}
