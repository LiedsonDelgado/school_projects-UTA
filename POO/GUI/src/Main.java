import java.awt.*;
import javax.swing.*;

public class Main{
    public static void main(String[] args) {
        JFrame mainWindow = new JFrame("Primeiro Exemplo GUI");
        Color bw = new Color(78, 76, 76); //background color window
        Color bt = new Color(93,0,255); //background color title

        JLabel title = new JLabel("Aula de POO",JLabel.CENTER);
        FlowLayout ly = new FlowLayout();

        JLabel title2 = new JLabel("Lab Programacao 14:30 as 17:30");


        JLabel icon = new JLabel(new ImageIcon("check.png"));

        JLabel check = new JLabel("Visto",JLabel.CENTER);

        mainWindow.setLayout(ly);

        mainWindow.setSize(700,700);
        mainWindow.getContentPane().setBackground(bw);

        title.setBackground(new Color(161,5,239));
        title.setOpaque(true);
        title.setPreferredSize(new Dimension(150,25));

        title2.setBackground(new Color(0, 255, 110));
        title2.setOpaque(true);
        title2.setPreferredSize(new Dimension(190,25));

        icon.setOpaque(false);
        icon.setPreferredSize(new Dimension(50,50));

        check.setBackground(new Color(255, 255, 255));
        check.setOpaque(true);
        check.setPreferredSize(new Dimension(100,25));

        mainWindow.add(title);
        mainWindow.add(title2);
        mainWindow.add(icon);
        mainWindow.add(check);

        mainWindow.setVisible(true); //convem manter sempre no final
    }
}