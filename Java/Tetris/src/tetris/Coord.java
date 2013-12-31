package tetris;

//Coord, Grid, and Block go into Game. Game, Score, and Line go into GridWorks.

import java.awt.Color;


public class Coord{
	private int x = 0;
	private int y = 0;
        private Color c;
	
	public Coord(int xi, int yi){
		x=xi;
		y=yi;
	}
	
	public void down(){
		y++;
	}
	
	public void left(){
		x--;
	}
	
	public void right(){
		x++;
	}
	
	public void turnClock(){
		int temp = y;
		y = 0-x;
		x = temp;
	}

	public void turnCounter(){
		int temp = x;
		x = 0-y;
		y = temp;
	}
    
        public void setColor(Color cs){
            c = cs;
        }

        public Color getColor(){
            return c;
        }
	
	public int getX(){
		return x;
	}
	
	public int getY(){
		return y;
	}
	
}