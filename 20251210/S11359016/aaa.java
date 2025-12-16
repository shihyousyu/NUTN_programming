import java.awt.*;
import java.awt.event.*;

public class aaa {

    static Frame frm = new Frame("Panel class");
    static Panel pnl1to9 = new Panel(new GridLayout(3, 3));
    static Panel operators = new Panel(new GridLayout(4, 1));
    static Panel controls = new Panel(new GridLayout(2, 1, 0, 6));
    static Label monitor = new Label("0 ", Label.RIGHT);
    static Label displayName = new Label("DSG Calculator", Label.LEFT);
    static Button zero = new Button("0");
    static Button dot = new Button(".");
    static Font Bold = new Font("Serief", Font.BOLD, 12);

    public static void main(String[] args) {

        frm.setLayout(null);
        frm.setSize(290, 210);
        frm.setResizable(false);

        monitor.setBounds(20, 30, 170, 30);
        monitor.setBackground(Color.pink);
        monitor.setFont(Bold);
        displayName.setBounds(200, 35, 100, 20);
        displayName.setFont(new Font("Serief", Font.ITALIC + Font.BOLD, 9));

        pnl1to9.setBounds(20, 70, 120, 90);
        for(int i = 1;i <= 9;i++) pnl1to9.add(new Button(Integer.toString(i)));
        for(Component btn : pnl1to9.getComponents()) ((Button)btn).setFont(Bold);

        operators.setBounds(150, 70, 40, 120);
        String[] operatorsArray = {"+", "-", "x", "/"};
        for(String op : operatorsArray) operators.add(new Button(op));
        for(Component btn : operators.getComponents()) {
            ((Button)btn).setForeground(Color.blue);
            ((Button)btn).setFont(Bold);
        }

        controls.setBounds(200, 70, 57, 120);
        String[] controlsArray = {"=", "Clear"};
        for(String co : controlsArray) {
            Button btn = new Button(co);
            btn.setForeground(Color.red);
            btn.setFont(Bold);
            controls.add(btn);
        }

        zero.setBounds(20, 160, 80, 30);
        zero.setFont(Bold);
        dot.setBounds(100, 160, 40, 30);
        dot.setFont(Bold);

        frm.add(monitor);
        frm.add(displayName);
        frm.add(pnl1to9);
        frm.add(operators);
        frm.add(controls);
        frm.add(zero);
        frm.add(dot);
        frm.setVisible(true);

        frm.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(1);
            }
        });


    }

}