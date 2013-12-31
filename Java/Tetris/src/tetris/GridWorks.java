package tetris;

/**
 * @(#)GridWorks.java
 *
 *
 * @author Deven Tharp
 * @version 1.00 2012/5/7
 */
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Panel;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Date;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;





public class GridWorks extends JFrame implements KeyListener{
    private JLabel linesHeader = new JLabel("Lines:");
    private JLabel lines = new JLabel("0/50");
    private JLabel gameIns = new JLabel("z=counterclockwise turn, x=clockwise turn, left and right move the block left and right,");
    private JLabel gameIns2 = new JLabel("up to quick drop, and down to speed drop.");
    private JLabel scoreheading = new JLabel("SCORE:");
    private JLabel scoreLabel = new JLabel("0");
    private JLabel level = new JLabel("Level:  1");
    private Panel gamePlaceHolder = new Panel();
    private Game run;
    private GridCanvas grid;
    private NextCanvas next;
    public GridWorks(){
        //game screen basics
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600,900);
        setTitle("Tetris -Deven Tharp");
        setResizable(false);
        run = new Game();
        grid = new GridCanvas(run);
        next = new NextCanvas(run);
        //adding things to the game screen
        add(grid);
        add(next);
        linesHeader.setBounds(450, 350, 300, 20);
        linesHeader.setForeground(Color.MAGENTA);
        add(linesHeader);
        lines.setBounds(450, 370, 300, 20);
        scoreheading.setBounds(470, 520, 300, 20);
        scoreLabel.setBounds(450, 550, 300, 20);
        add(scoreheading);
        add(scoreLabel);
        add(lines);
        gameIns.setBounds(50, 810, 600, 15);
        gameIns2.setBounds(180,825,600,15);
        add(gameIns);
        add(gameIns2);
        add(gamePlaceHolder);
    }
    
    public void start(){
        play();
    }
    
    public void play(){
        while (run.getGrid().inPlay()){
            run.tick();
	}
        end();
        playAgain();
    }
    
    public void end(){
        run.gameOver();
    }
    
    @Override
    public void keyTyped(KeyEvent e) {
        
    }
    
    public Score getScore(){
        return run.getScore();
    }

    @Override
    public void keyPressed(KeyEvent e) {
        Block current = run.getCurrent();
        switch(e.getKeyCode()){
            case KeyEvent.VK_Z:
                grid.actionSwitch(0,current);
                current.rightTurn();
                grid.actionSwitch(1,current);
                break;
            case KeyEvent.VK_X:
                grid.actionSwitch(0,current);
                current.leftTurn();
                grid.actionSwitch(1,current);
                break;
            case KeyEvent.VK_LEFT:
                grid.actionSwitch(0,current);
                current.left();
                grid.actionSwitch(1,current);
                break;
            case KeyEvent.VK_RIGHT:
                grid.actionSwitch(0,current);
                current.right();
                grid.actionSwitch(1,current);
                break;
            case KeyEvent.VK_UP:
                grid.actionSwitch(0,current);
                run.getGrid().instaPlace(current);
                grid.actionSwitch(1,current);
                break;
            case KeyEvent.VK_DOWN:
                grid.actionSwitch(0,current);
                current.fall();
                grid.actionSwitch(1,current);
                break;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {//HERE
        
    }
    
    

    public void levelUpdate(int l) {
        level.setText("Level:  " + l);
    }
    
    public void scoreUpdate(Score s){
        scoreLabel.setText("" + s.getPoints());
    }

    private void playAgain() {
        //JOptionPane.showConfirmDialog((Component)grid, "Play Again?", JOptionPane.YES_NO_OPTION, WIDTH);
    }

    void paintBlock(Block current) {
        grid.actionSwitch(1, current);
    }

    void unPaintBlock(Block current) {
        grid.actionSwitch(0, current);
    }

    void paintNext(Block nxt) {
        next.actionSwitch(1, nxt);
    }

    void clearLines() {
        grid.actionSwitch(2, null);
    }

    void unPaintNext(Block nxt) {
        next.actionSwitch(0, nxt);
    }

    void clearGrid() {
        grid.actionSwitch(3, null);
    }
    
    void clearNext(){
        next.actionSwitch(2, null);
    }
}
class Game{
    private Queue<Block> next;
    private Random ran= new Random();
    private int level = 1;
    private int lines = 0;
    private Grid grid = new Grid();
    private Block current = null;
    private Block nxt = null;
    private GridWorks worker;

    public Game(){
        next = new LinkedList<>();
        getBlocks();
        getBlocks();
        getBlocks();
        current = next.remove();
        nxt = next.peek();
    }
    
    public void setWork(GridWorks g){
        worker = g;
    }
    
    private void getBlocks(){
            switch (ran.nextInt(7)) {
                    case 0 :IBlock i = new IBlock();
                            for (int a = 0; a<ran.nextInt(4); a++)
                                    i.leftTurn();
                            next.add(i);
                    break;
                    case 1 :LBlock l = new LBlock();
                            for (int b = 0; b<ran.nextInt(4); b++)
                                    l.leftTurn();
                            next.add(l);
                    break;
                    case 2 :JBlock j = new JBlock();
                            for (int c = 0; c<ran.nextInt(4); c++)
                                    j.leftTurn();
                            next.add(j);
                    break;
                    case 3 :SBlock s = new SBlock();
                            for (int d = 0; d<ran.nextInt(4); d++)
                                    s.leftTurn();
                            next.add(s);
                    break;
                    case 4 :ZBlock z = new ZBlock();
                            for (int e = 0; e<ran.nextInt(4); e++)
                                    z.leftTurn();
                            next.add(z);
                    break;
                    case 5 :TBlock t = new TBlock();
                            for (int f = 0; f<ran.nextInt(4); f++)
                                    t.leftTurn();
                            next.add(t);
                    break;
                    case 6 :OBlock o = new OBlock();
                            for (int g = 0; g<ran.nextInt(4); g++)
                                    o.leftTurn();
                            next.add(o);
                    break;
            }
    }

    public void tick(){
            try {//SLEEP PHASE
                    Thread.sleep(1000/level);
            }
            catch (InterruptedException ex) {
                    System.err.print("iex" + new Date());
            }
            if(current == null){//BLOCK PHASE
                    getBlocks();
                    nxt = next.peek();
                    current = grid.addBlock(next.remove());
                    worker.paintBlock(current);
                    worker.unPaintNext(nxt);
                    nxt = next.peek();
                    worker.paintNext(nxt);
            }
            else if(grid.blockLandCheck(current)){
                    current = null;//LINE PHASE
                    lines += grid.clearLines();
                    worker.scoreUpdate(grid.getScore());
                    worker.clearLines();
                    levelUp();
            }
            else{//DEFAULT
                    worker.unPaintBlock(current);
                    current.fall();
                    worker.paintBlock(current);
            }
    }

    public Score getScore(){
            return grid.getScore();
    }

    public void gameOver(){
        current = null;
        nxt = null;
        level = 1;
        next.clear();
        lines = 0;
        grid.gameOver();
    }

    public Block getCurrent(){
            return current;
    }
    
    public Block getNext(){
        return next.peek();
    }

    public void levelUp(){
            if(lines>=(level*55)){
                    level++;
                    worker.levelUpdate(level);
            }
    }
    
    public int getLevel(){
        return level;
    }

    public Grid getGrid(){
            return grid;
    }
}




class GridCanvas extends JPanel{
    Game ga;
    Block b;
    int action = 0;
    public GridCanvas(Game gam) {
        ga = gam;
        setBounds(10, 10, 400, 800);
        setBackground(Color.BLACK);
    }
    
    public void actionSwitch(int x, Block bl){
        switch(x){
            case 0: action = 0;
                break;
            case 1: action = 1;
                break;
            case 2: action = 2;
                break;
            case 3: action = 3;
                break; 
        }
        b = bl; 
        repaint();
    }
    
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        g.fillRect(0,20,40,40);
        if(b == null){
            b=ga.getCurrent();
            action(g);
        }
    }
    
    public void paintBlock(Block b, Graphics g){// BOUNDS: X=10+40*getX() Y=10+40XgetY()
        for(Coord c: b.getCoords()){
            g.setColor(c.getColor());
            g.fillRect(c.getX()*40, c.getY()*40, 40, 40);
        }
    }

    public void unPaintBlock(Block b, Graphics g) {
        for(Coord c: b.getCoords()){
            g.setColor(Color.BLACK);
            g.fillRect(c.getX()*40, c.getY()*40, 40, 40);
        }
    }

    public void clearLines(Graphics g){//HERE
        //yes you have to go through the whole thing.
        Color[][] ar = ga.getGrid().getArray();
        for(int r = 0; r<10; r++){
            for(int c = 2; c<22; c++){
                g.setColor(ar[r][c]);
                g.fillRect(r*40, (c-2)*40, 40, 40);
            }
        }       
    }
    private void action(Graphics g) {
        switch(action){
            case 0: unPaintBlock(b, g);
                break;
            case 1: paintBlock(b, g);
                break;
            case 2: clearLines(g);
                break;
            case 3: clearGrid(g);
        }
    }
    
    public void clearGrid(Graphics g){
        g.setColor(Color.BLACK);
        g.clearRect(10, 10, 400, 800);
    }
}

class NextCanvas extends JPanel{
    Game ga;
    Block b;
    int action;
    public NextCanvas(Game gam) {
        ga = gam;
        setBounds(420, 100, 150, 150);
        setBackground(Color.BLACK);
    }
    
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        if(b == null){
            b=ga.getNext();
        action(g);
        }
    }
    
    public void setBlock(Block bl){
        b = bl;
    }

    public void actionSwitch(int i, Block bl){
            switch(i){
            case 0: action = 0;
                break;
            case 1: action = 1;
                break;
            case 2: action = 2;
                break;
        }
        b = bl; 
        repaint();
    }
    
    public void action(Graphics g){
        switch(action){
            case 0: unPaintNext(b, g);
                break;
            case 1: paintNext(b, g);
                break;
            case 2: clearNext(g);
        }
    }
    
    public void paintNext(Block b, Graphics g){// BOUNDS: X=435+40*getX() Y=100+40*getY()
            for(Coord c: b.getCoords()){
            	g.fillRect(40*getX(),40*getY(), 30, 30);
        }
    }

    public void unPaintNext(Block b, Graphics g) {
        if(b==null)
            b=ga.getNext();
        for(Coord c: b.getCoords()){
            g.setColor(Color.BLACK);
            g.fillRect(c.getX()*40, c.getY()*40, 40, 40);
        }
    }
    
    public void clearNext(Graphics g){
        g.clearRect(410, 100, 150, 150);
    }
}