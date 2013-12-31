/*
 */
package tetris;
import java.awt.Font;
import java.awt.KeyboardFocusManager;
import java.awt.Panel;
import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.HashSet;
import java.util.Set;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.KeyStroke;
/**
 */
public class Tetris extends JFrame implements KeyListener{
    private JLabel title = new JLabel("TETRIS");
    private Panel mainplaceHolder = new Panel();
    private JButton play = new JButton("PLAY");
    private JButton score = new JButton("SCORES");
    private JButton instructions = new JButton("INSTRUCTIONS");
    private JButton exit = new JButton("EXIT");
    private JLabel keys = new JLabel("Up and down arrow keys to move selection, z to make selection.");
    private JFrame main = new JFrame();
    private GridWorks game = new GridWorks();
    private JFrame ins = new JFrame();
    private JFrame scr = new JFrame();
    Game run;
    //private JPanel pent = new JPanel();
    
    public Tetris(){
        //main menu basic setup
        main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        main.setSize(600,900);
        main.setTitle("Tetris -Deven Tharp");
        main.setResizable(false);
        //instruction screen basics
        ins.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ins.setSize(600,900);
        ins.setTitle("Tetris -Deven Tharp");
        ins.setResizable(false);
        //score screen basics
        scr.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        scr.setSize(600,900);
        scr.setTitle("Tetris -Deven Tharp");
        scr.setResizable(false);
        //adding things to the main menu
        title.setBounds(25,0,1000,200);
        title.setFont(new Font("Comic Sans", Font.PLAIN, 150));
        main.add(title);
        play.addKeyListener(this);
        play.setActionCommand("play");
        play.setFont(new Font("comic sans", Font.PLAIN, 100));
        play.setBounds(100, 200, 400, 125);
        main.add(play);
        score.addKeyListener(this);
        score.setActionCommand("score");
        score.setFont(new Font("comic sans", Font.PLAIN, 75));
        score.setBounds(100, 350, 400, 125);
        main.add(score);
        instructions.addKeyListener(this);
        instructions.setActionCommand("instructions");
        instructions.setBounds(100, 500, 400, 125);
        instructions.setFont(new Font("comic sans", Font.PLAIN, 45));
        main.add(instructions);
        exit.addKeyListener(this);
        exit.setActionCommand("exit");
        exit.setFont(new Font("comic sans", Font.PLAIN, 100));
        exit.setBounds(100,650, 400, 125);
        main.add(exit);
        keys.setBounds(105,800,600,100);
        main.add(keys);
        mainplaceHolder.setBounds(0,0,0,0);
        main.add(mainplaceHolder);
    	//adding key listeners for escape key functionality
    	game.addKeyListener(this);
    	ins.addKeyListener(this);
    	scr.addKeyListener(this);
        //setting up visibility.
        main.setLocation(0,0);
        scr.setEnabled(false);
        game.setEnabled(false);
        ins.setEnabled(false);
        scr.setVisible(false);
        game.setVisible(false);
        ins.setVisible(false);
        main.setVisible(true);
        //down arrow scrolls down
        Set forwardKeys = getFocusTraversalKeys(KeyboardFocusManager.FORWARD_TRAVERSAL_KEYS);
        Set newForwardKeys = new HashSet(forwardKeys);
        newForwardKeys.add(KeyStroke.getKeyStroke(KeyEvent.VK_DOWN, 0));
        main.setFocusTraversalKeys(KeyboardFocusManager.FORWARD_TRAVERSAL_KEYS, newForwardKeys);
        //up arrow scrolls up
        Set backwardKeys = getFocusTraversalKeys(KeyboardFocusManager.BACKWARD_TRAVERSAL_KEYS);
        Set newBackwardKeys = new HashSet(backwardKeys);
        newBackwardKeys.add(KeyStroke.getKeyStroke(KeyEvent.VK_UP, 0));
        main.setFocusTraversalKeys(KeyboardFocusManager.BACKWARD_TRAVERSAL_KEYS, newBackwardKeys);
        main.setVisible(true);
        run = new Game();
        run.setWork(game);
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
    Tetris tetris = new Tetris();
    }

    @Override
    public void keyTyped(KeyEvent e) {
    	
     if(main.isVisible()&&e.getKeyChar()=='z'){
            switch (((JButton)e.getSource()).getActionCommand()) {//switching between screens
                case "play":
                    Point pos1 = main.getLocationOnScreen();
                    main.setVisible(false);
                    main.setEnabled(false);
                    game.setLocation(pos1);
                    game.setVisible(true);
                    game.setEnabled(true);
                    game.start();
                    break;
                case "instructions":
                    Point pos2 = main.getLocationOnScreen();
                    main.getLocationOnScreen();
                    main.setVisible(false);
                    main.setEnabled(false);
                    ins.setEnabled(true);
                    ins.setLocation(pos2);
                    ins.setVisible(true);
                    break;
                case "score":
                	Point pos3 = main.getLocationOnScreen();
                    main.getLocationOnScreen();
                    main.setVisible(false);
                    main.setEnabled(false);
                    scr.setEnabled(true);
                    scr.setLocation(pos3);
                    scr.setVisible(true);
                    break;
                case "exit": System.exit(0);
                    break;
            }
      }
    }

    @Override
    public void keyPressed(KeyEvent e) {
    	if(!main.isVisible()&&e.getKeyCode()==KeyEvent.VK_ESCAPE){
            if(game.isVisible()){
                game.end();
            }
      	Point pos4 = ((JFrame)e.getSource()).getLocationOnScreen();
        ((JFrame)e.getSource()).setVisible(false);
        ((JFrame)e.getSource()).setEnabled(false);
        main.setLocation(pos4);
        main.setEnabled(true);
        main.setVisible(true);
    }
    }

    @Override
    public void keyReleased(KeyEvent e) {
    }
}
