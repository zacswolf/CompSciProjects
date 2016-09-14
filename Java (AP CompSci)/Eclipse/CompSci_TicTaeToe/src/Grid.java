import java.awt.Graphics;
import java.awt.Color;
import java.awt.Font;

public class Grid
{
	private int rws;
	private int clms;
	private Drawable[][] grid = new Drawable [rws][clms];
	
	public Grid()
	{
		setSize(0,0);
	}

	public Grid(int rows, int cols)
	{
		setSize(rows,cols);
		
	}

	public void setSize(int rows, int cols)
	{
		rws = rows;
		clms = cols;
		grid = new Drawable[rws][clms];

	}

	public void setSpot(int row,int col, Drawable val)
	{
		grid[row][col] = val;

	}
	
	public Drawable getSpot(int row, int col)
	{
		return grid[row][col];
	}
	
	public int getNumRows()
	{
		return grid.length;
	}
	
	public int getNumCols()
	{
		return grid[0].length;
	}

	public boolean drawGrid(Graphics window)
	{
		boolean full=true;
		///for loop for row
		for (int i = 0; i < getNumRows(); i++){
			///for loop for col
			for (int j = 0; j < getNumCols(); j++){
				//get current Drawable
					//if it is null
					if (grid[i][j] != null){
						grid[i][j].draw(window);
						
					}
					//else
					else{
						full = false;
					}
			}
		}
		return full;

	}
	
	private void draw(Graphics window) {
		// TODO Auto-generated method stub
		
	}

	public String toString(int row, int col)
	{
		String output="" + getSpot(row, col).toString();





		return output;
	}
}