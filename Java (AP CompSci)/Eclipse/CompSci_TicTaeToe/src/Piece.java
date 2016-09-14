import java.awt.Color;
import java.awt.Graphics;
import java.awt.Font;

public class Piece extends Drawable implements Nameable
{
	private String name;
	private Color color;
	
	public Piece()
	{
		super(5,5,5,5);
		setName("empty");
		setColor(Color.BLUE);		
	}

	public Piece(String n)
	{
		super(5,5,5,5);
		setName(n);
		setColor(Color.BLUE);
	}

	public Piece(int x, int y, String n)
	{
		super(x,y,5,5);
		setName(n);
		setColor(Color.BLUE);
	}

	public Piece(int x, int y, int w, int h, String n)
	{
		super(x,y,w,h);
		setName(n);
		setColor(Color.BLUE);	
	}

	public Piece(int x, int y, int w, int h, String n, Color c)
	{
		super(x,y,w,h);
		setName(n);
		setColor(c);
	}

	public void setName(String n)
	{
		name = n;

	}

	public void setColor(Color c)
	{
		color = c;

	}
	
	public String getName()
	{
		return name;
	}
	
	public Color getColor()
	{
		return color;
	}
	
	public void draw(Graphics window)
	{
		window.setFont(new Font("TAHOMA",Font.BOLD,28));
		window.setColor(getColor());
		


	}
	
	public String toString()
	{
		return super.toString() + " " + getName() + " " + getColor();
	}
}