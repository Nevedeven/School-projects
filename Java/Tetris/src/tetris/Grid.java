package tetris;

import java.awt.Color;

/**
 * @(#)Grid.java
 *
 *
 * @author 
 * @version 1.00 2012/5/7
 */

public class Grid {
    private Color[][] grid;
    private Score scr = new Score();
    private boolean lose = false;

    public Grid() {
	grid = new Color[10][22];
    }
    
    public Block addBlock(Block b){
    	for (Coord c : b.getCoords()){
                if(grid[c.getX()+5][c.getY()+2]!=Color.BLACK)
                    lose = true;
    		grid[c.getX()+5][c.getY()+2]=c.getColor();
    	}
    	return b;
    }
    
    public Color[][] getArray(){
        return grid;
    }
    
    public Color[][] getGrid(){
    	return grid;
    }
    
    public void blockFall(Block b){
    	for (Coord c : b.getCoords())
    		grid[c.getX()+5][c.getY()+2]=Color.BLACK;
        if(!blockLandCheck(b))
                b.fall();
    	for (Coord o : b.getCoords()){
    		grid[o.getX()+5][o.getY()+2]=o.getColor();
    	}
    }
    
    
    
    public int clearLines(){
    	boolean full;
    	int clr = 0;
    	for (int c = 0; c<10; c++){
            full = true;
            for (int r = 0; r<22; r++){
                    if(grid[c][r] == Color.BLACK){
                            full = false;
                    }
            }
            if(full = true){
                    clr++;
                    for(int cl = 0; cl<10; cl++)
                            grid[c][cl] = Color.BLACK;
                    for (int row = 0; row<10; row++)
                            System.arraycopy(grid[row-1], 0, grid[row], 0, 10);
            }
    	}
	    switch (clr) {
	    	case 0 :break;
	    	case 1 : scr.addPoints(100);
	    		break;
	    	case 2 : scr.addPoints(250);
	    		break;
	    	case 3 : scr.addPoints(500);
	    		break;
	    	case 4 : scr.addPoints(1000);
	    		break;
            }
		return clr;	
   	}
    
    
   	
   	public boolean blockLandCheck(Block b){
   		boolean land = false;
   		for(Coord c: b.getCoords())
   			if(grid[c.getX()+5][c.getY()+3]!=Color.BLACK)
   				land = true;
   		return land;
   	}
   	
   	public void blockClockTurn(Block b){
   		int offset = 0;
   		for(Coord c : b.getCoords())
   		{
   			c.turnClock();
   			if(c.getX()<0)
   				offset++;
   			else if(c.getX()>9)
   				offset--;
   		}
   		for (Coord c : b.getCoords()){
    		grid[c.getX()+5][c.getY()+2]=Color.BLACK;
   		}
   		b.leftTurn();
   		for (Coord o : b.getCoords()){
    		grid[o.getX()+offset+5][o.getY()+2]=o.getColor();
   		}
   	}
   	
   	public void blockCounterTurn(Block b){
   		int offset = 0;
   		for(Coord c : b.getCoords())
   		{
   			c.turnCounter();
   			if(c.getX()<0)
   				offset++;
   			else if(c.getX()>9)
   				offset--;
   		}
   		for (Coord c : b.getCoords()){
    		grid[c.getX()+5][c.getY()+2]=Color.BLACK;
   		}
   		b.rightTurn();
   		for (Coord o : b.getCoords()){
    		grid[o.getX()+offset+5][o.getY()+2]=o.getColor();
   		}
   	}
   	
   	public void blockLeft(Block b){
   		int offset = 0;
   		for(Coord c : b.getCoords())
   		{
   			c.left();
   			if(c.getX()<0)
   					offset=1;
   			else if(c.getX()>9)
   					offset=-1;
   		}
   		for (Coord c : b.getCoords()){
    		grid[c.getX()+5][c.getY()+2]=Color.BLACK;
   		}
   		b.left();
   		for (Coord o : b.getCoords()){
    		grid[o.getX()+offset+5][o.getY()+2]=o.getColor();
   		}
   	}
   	
   	public void blockRight(Block b){
   		int offset = 0;
   		for(Coord c : b.getCoords())
   		{
   			c.right();
   			if(c.getX()<0)
   					offset=1;
   			else if(c.getX()>9)
   					offset=-1;
   		}
   		for (Coord c : b.getCoords()){
    		grid[c.getX()+5][c.getY()+2]=Color.BLACK;
   		}
   		b.right();
   		for (Coord o : b.getCoords()){
    		grid[o.getX()+offset+5][o.getY()+2]=o.getColor();
   		}
   	}
   	
   	public Score getScore(){
   		return scr;
   	}
   	
   	public boolean inPlay(){
            return lose;
   	}
   	
   	public void instaPlace(Block b){
   		while(!blockLandCheck(b)){
   			blockFall(b);
   		}
   	}
   	
   	public void gameOver(){
   		for (int c = 0; c<10; c++)
   			for(int r = 0; r<22; r++)
   				grid[c][r] = Color.BLACK;
                scr.reset();
   	}
}