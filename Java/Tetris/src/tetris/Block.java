package tetris;

 /**
 * @(#)Block.java
 *
 *
 * @author 
 * @version 1.00 2012/5/7
 */
import java.awt.Color;
import java.util.ArrayList;

public class Block {
    private Coord pivot = new Coord(0,0);
    private ArrayList<Coord> body = new ArrayList<>();
    Color col;
    
    public Block(Coord c1, Coord c2, Coord c3, Color co){
    	body.add(pivot);
        c1.setColor(co);
    	body.add(c1);
        c2.setColor(co);
    	body.add(c2);
        c3.setColor(co);
    	body.add(c3);
        col = co;
    }
    
    public void left(){
       	for(Coord c : body)
    		c.left();	
    }
    
    public void right(){
    	for(Coord c : body)
    		c.right();
    }
    
    public void fall(){
    	for(Coord c : body)
    		c.down();
    }
    
    public void leftTurn(){
    	for(Coord c : body)
    		c.turnClock();
    }
    
    public void rightTurn(){
    	for(Coord c : body)
    		c.turnCounter();
    }
    
    public ArrayList<Coord> getCoords(){
    	return body;
    }
}

class LBlock extends Block{
	public LBlock(){
		super(new Coord(1,0), new Coord(0,1), new Coord(0,2), Color.BLUE);
	}
}

class JBlock extends Block{
	public JBlock(){
		super(new Coord(-1,0),new Coord(0,1),new Coord(0,2),Color.ORANGE);
	}
}

class SBlock extends Block{
	public SBlock(){
		super(new Coord(1,0),new Coord(0,-1),new Coord(-1,-1), Color.GREEN);
	}
}

class ZBlock extends Block{
	public ZBlock(){
		super(new Coord(-1,0),new Coord(0,-1),new Coord(1,-1), Color.PINK);
	}
}

class TBlock extends Block{
	public TBlock(){
		super(new Coord(-1,0),new Coord(0,-1),new Coord(1,0),Color.CYAN);
	}
}

class OBlock extends Block{
	public OBlock(){
		super(new Coord(1,0), new Coord(0,1), new Coord(1,1), Color.YELLOW);
	}
}

class IBlock extends Block{
	public IBlock(){
		super(new Coord(0,-1), new Coord(0,1), new Coord(0,-2), Color.RED);
	}
}