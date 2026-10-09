import java.awt.*;
import java.awt.event.*;
import java.lang.Math;

public class App extends Frame implements ActionListener, MouseListener, MouseMotionListener{
    App(String title){super(title);}

    private final int DRAW_STRAIGHT_LINE = 1;
    private final int DRAW_OVAL = 2;
    private final int DRAW_RECTANGLE = 3;
    private final int SELECT = 4;
    private final int RESIZE = 5;
    private final String STRAIGHT_LINE = "STRAIGHT LINE";
    private final String OVAL = "OVAL";
    private final String RECTANGLE = "RECTANGLE";

    static App frm = new App("Drawing Applet");

    static MenuBar mb = new MenuBar();
    static Menu drawMenu = new Menu("Draw");
    static Menu operatorsMenu = new Menu("Operators");
    static MenuItem straightLineMI = new MenuItem("Straight Line");
    static MenuItem ovalMI = new MenuItem("Oval");
    static MenuItem rectangleMI = new MenuItem("Rectangle");
    static MenuItem selectMI = new MenuItem("Select");
    static MenuItem resizeMI = new MenuItem("Resizee");

    private int mode = 0;
    private String nowGraphic = "";

    private int posX, posY, startX, startY, endX, endY, W, H;
    private int newX, newY, newStartX, newStartY, newEndX, newEndY;
    private int dx, dy, start_dx, start_dy, end_dx, end_dy;

    public static void main(String[] args){
        frm.setSize(300, 400);

        straightLineMI.addActionListener(frm);
        ovalMI.addActionListener(frm);
        rectangleMI.addActionListener(frm);
        selectMI.addActionListener(frm);
        resizeMI.addActionListener(frm);

        drawMenu.add(straightLineMI);
        drawMenu.add(ovalMI);
        drawMenu.add(rectangleMI);
        operatorsMenu.add(selectMI);
        operatorsMenu.add(resizeMI);

        mb.add(drawMenu);
        mb.add(operatorsMenu);

        frm.addMouseListener(frm);
        frm.addMouseMotionListener(frm);

        frm.setMenuBar(mb);

        frm.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
        frm.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        MenuItem mi = (MenuItem) e.getSource();
        if(mi == straightLineMI) mode = DRAW_STRAIGHT_LINE;
        else if(mi == ovalMI) mode = DRAW_OVAL;
        else if(mi == rectangleMI) mode = DRAW_RECTANGLE;
        else if(mi == selectMI) mode = SELECT;
        else if(mi == resizeMI) mode = RESIZE;
        else mode = 0;
    }

    private boolean isDrawMode(int mode) {return mode == DRAW_STRAIGHT_LINE || mode == DRAW_OVAL || mode == DRAW_RECTANGLE;}

    public void mousePressed(MouseEvent e) {
        if(isDrawMode(mode)) {
            startX = e.getX();
            startY = e.getY();
            if(mode == DRAW_STRAIGHT_LINE) nowGraphic = STRAIGHT_LINE;
            else if(mode == DRAW_OVAL) nowGraphic = OVAL;
            else if(mode == DRAW_RECTANGLE) nowGraphic = RECTANGLE;
            repaint();
        }
        else if(mode == SELECT) {
            dx = e.getX() - posX;
            dy = e.getY() - posY;
            start_dx = e.getX() - startX;
            start_dy = e.getY() - startY;
            end_dx = e.getX() - endX;
            end_dy = e.getY() - endY;
        }
    }
    public void mouseDragged(MouseEvent e) {
        if(isDrawMode(mode) || mode == RESIZE){
            endX = e.getX();
            endY = e.getY();
            posX = Math.min(startX, endX);
            posY = Math.min(startY, endY);
            W = Math.abs(startX - endX);
            H = Math.abs(startY - endY);
            repaint();
        }

        else if(mode == SELECT) {
            newX = e.getX() - dx;
            newY = e.getY() - dy;
            newStartX = e.getX() - start_dx;
            newStartY = e.getY() - start_dy;
            newEndX = e.getX() - end_dx;
            newEndY = e.getY() - end_dy;
            if(dx > 0 && dx < W && dy > 0 && dy < H)
                repaint();
        }
    }

    public void paint(Graphics g) {
        if(isDrawMode(mode) || mode == RESIZE){
            if(nowGraphic == STRAIGHT_LINE) g.drawLine(startX, startY, endX, endY);
            else if(nowGraphic == OVAL) { g.setColor(Color.RED); g.fillOval(posX, posY, W, H);}
            else if(nowGraphic == RECTANGLE) { g.setColor(Color.YELLOW); g.fillRect(posX, posY, W, H);}
        }
        else if(mode == SELECT) {
            posX = newX;
            posY = newY;
            startX = newStartX;
            startY = newStartY;
            endX = newEndX;
            endY = newEndY;

            if(nowGraphic == STRAIGHT_LINE) g.drawLine(startX, startY, endX, endY);
            else if(nowGraphic == OVAL) { g.setColor(Color.RED); g.fillOval(posX, posY, W, H);}
            else if(nowGraphic == RECTANGLE) { g.setColor(Color.YELLOW); g.fillRect(posX, posY, W, H);}
        }
        if(mode == SELECT || mode == RESIZE) {
            g.setColor(Color.BLACK);
            Graphics2D g2d = (Graphics2D) g.create();
            Stroke dashed = new BasicStroke(1, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 0, new float[]{9}, 0);
            g2d.setStroke(dashed);
            g2d.drawRect(posX, posY, W, H);
            g2d.dispose();
        }
    }

    public void mouseMoved(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
    public void mouseClicked(MouseEvent e) {}

}