
import java.awt.BorderLayout;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferInt;

import javax.swing.JFrame;

import java.util.Random;
//The Stuff about the blue lines can be deleted, I might use it later.

public class MainSave1 extends Canvas implements Runnable{
	
	private static final long serialVersionUID = 1L;
	
	public static int WIDTH = 360;
	public static int HEIGHT = WIDTH/12 * 9;
	public static int SCALE = 3;
	public static String NAME = "MainSave1";
	
	private JFrame frame;

	public boolean running = false;
	public int tickCount = 0;
	private Random dice = new Random();

	private BufferedImage image = new BufferedImage(WIDTH, HEIGHT, BufferedImage.TYPE_INT_RGB);//we draw this image in render to help blue lines
	private int[] pixels = ((DataBufferInt) image.getRaster().getDataBuffer()).getData(); //Pixels Variable we use this in ticks
	private int rectedArea = 0; 
	
	
	public MainSave1() {
		setMinimumSize(new Dimension(WIDTH * SCALE, HEIGHT * SCALE));
		setMaximumSize(new Dimension(WIDTH * SCALE, HEIGHT * SCALE));
		setPreferredSize(new Dimension(WIDTH * SCALE, HEIGHT * SCALE));
		
		frame = new JFrame(NAME);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new BorderLayout());
		
		frame.add(this,BorderLayout.CENTER);
		frame.pack();
		setResizable(false);
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);

		setBackground(Color.BLACK);
	}
	private void setResizable(boolean b) {
		// TODO Auto-generated method stub
		
	}
	private void setDefaultCloseOperation(int exitOnClose) {
		// TODO Auto-generated method stub
		
	}
	public synchronized void start() {
		running = true;
		new Thread(this).start();
		
	}
	
	public synchronized void stop() {
		running = false;
		
	}
	
	public void run() {
		long lastTime = System.nanoTime();
		double nsPerTick = 1000000000D/60D;
		
		int ticks = 0;
		int frames = 0;
		
		long lastTimer = System.currentTimeMillis();
		double delta = 0;
		
		while (running){
			long now = System.nanoTime();
			delta += (now - lastTime) / nsPerTick;
			lastTime = now;
			boolean shouldRender = true;
			while (delta >= 1) {
				ticks++;
				tick();
				delta -= 1;
				shouldRender = true;
			}
			
			//This is to lower max FBS
			try {
				Thread.sleep(2); //Just type this and it will be auto Generated
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			//Ending Here
			
			if (shouldRender){
				frames++;
				render();
			}
			
			if (System.currentTimeMillis() - lastTimer >= 1000){
				lastTimer += 1000;
				System.out.println(ticks + " ticks, " + frames + " frames");  //Displays Ticks and Frames
				frames = 0;
				ticks = 0;
			}
		}
	}
	
	
	public void tick(){
		//Every time a tick happens This loop will cycle
		tickCount++;
		/*
		for (int i = 0; i < pixels.length; i++){
			pixels[i] = i + tickCount; 					//created blue lines
		}*/
	}
	
	public void render(){
		BufferStrategy bs = getBufferStrategy();
		if (bs == null){
			createBufferStrategy(3); 
			/*the Higher you go the more processing power you would need.
			so 10K would be a very, very bad buffer...*/
			return;
		}
		
		

		Graphics g = bs.getDrawGraphics();
		
		
		g.setColor(Color.WHITE);

		while (((WIDTH * SCALE) * (HEIGHT * SCALE)) /2 > rectedArea){
			
			int Width = 1 + 5 + dice.nextInt(35);
			int Height = 1 + 5 + dice.nextInt(35);
			int X = 1 + dice.nextInt((WIDTH * SCALE)- Width);
			int Y = 1 + dice.nextInt((HEIGHT * SCALE) - Height);
			
			//if (//if you wanted them to not over lap do it here!){ 
			g.drawRect(X, Y, Width, Height);
			rectedArea = rectedArea + (Width * Height);
			//}
			
		}
		

		/*.drawRect(0, 0, 30, 40);
		g.setColor(Color.RED);
		g.drawRect(0, 0, 1, 1);					//This is Example Code
		g.drawRect(30, 0, 1, 1);
		g.drawRect(0, 40, 1, 1);
		g.drawRect(30, 40, 1, 1);*/
		
		
		
		
		//g.drawImage(image, 0, 0, getWidth(), getHeight(), null); //helps draw blue lines
		g.dispose();
		bs.show();
	}
	
	public static void main(String[] args){
		// TODO Auto-generated method stub
		 new MainSave1().start();


		
	}
	



	

}
