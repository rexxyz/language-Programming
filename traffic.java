import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class traffic implements ItemListener {
    JFrame f;
    JRadioButton rb1;
    JRadioButton rb2;
    JRadioButton rb3;
    JPanel p1;
    JPanel p2;
    JPanel p3;
    JPanel p4;
    ButtonGroup bg;
    
    traffic() {
        f = new JFrame("Traffic Light");
        f.setSize(500,300);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setLayout(null);

        rb1 = new JRadioButton("RED");
        rb2 = new JRadioButton("YELLOW");
        rb3 = new JRadioButton("GREEN");
        
        rb1.setBounds(50, 230,100,50);
        rb2.setBounds(200, 230,100,50);
        rb3.setBounds(350, 230,100,50);

        bg = new ButtonGroup();
        bg.add(rb1);
        bg.add(rb2);
        bg.add(rb3);
        
        // p4 = new JPanel();
        // p4.add(rb1);
        // p4.add(rb2);
        // p4.add(rb3);

        rb1.addItemListener(this);
        rb2.addItemListener(this);
        rb3.addItemListener(this);

        p1 = new JPanel();
        p1.setBackground(Color.WHITE);
        p1.setBounds(50, 50, 100, 80);
        p2 = new JPanel();
        p2.setBackground(Color.WHITE);
        p2.setBounds(200, 50, 100, 80);
        p3 = new JPanel();
        p3.setBackground(Color.WHITE);
        p3.setBounds(350, 50, 100, 80);

        f.add(p1);
        f.add(p2);
        f.add(p3);
        f.add(rb1);
        f.add(rb2);
        f.add(rb3);
        f.setVisible(true);
    }
    public static void main(String[] args) {
        traffic ob = new traffic();
    }

    public void itemStateChanged(ItemEvent e) {
        if(e.getSource() == rb1) {
            p1.setBackground(Color.RED);
            p2.setBackground(Color.WHITE);
            p3.setBackground(Color.WHITE);
        }
        if(e.getSource() == rb2) {
            p1.setBackground(Color.WHITE);
            p2.setBackground(Color.YELLOW);
            p3.setBackground(Color.WHITE);
        }
        if(e.getSource() == rb3) {
            p1.setBackground(Color.WHITE);
            p2.setBackground(Color.WHITE);
            p3.setBackground(Color.GREEN);
        }
    }
}