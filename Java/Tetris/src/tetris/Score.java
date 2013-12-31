package tetris;

/**
 * @(#)Score.java
 *
 *
 * @author 
 * @version 1.00 2012/5/7
 */


public class Score {
	private int scr = 0;
	private String name = "";
    public Score() {	
    }
    
    public void addPoints(int amt){
    	scr += amt;
    }
    
    public int getPoints(){
    	return scr;
    }
    
    public void setName(String n){
    	name = n;
    }
    
    public String getName(){
    	return name;
    }
    
    public void reset(){
        scr = 0;
    }
    
    @Override
    public String toString(){
    	return String.format("%-20s: %-10o", name, scr);
    }
}