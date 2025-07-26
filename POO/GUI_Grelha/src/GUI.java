import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;

public class GUI extends JFrame{
    public GUI(int linha,int coluna){
        super("Grelha");

        setSize(800,600);
        setLayout(new GridLayout(linha,coluna));
        JPanel container = new JPanel();
        for(int i=0;i<linha;i++) {
            for(int j=0;j<coluna;j++){
                JPanel cell = new JPanel();
                cell.setSize(new Dimension(10,10));
                cell.setBorder(new LineBorder(new Color(0,0,0)));
                cell.setBackground(new Color(0, 193, 106));
                container.add(cell,BorderLayout.CENTER);
                add(container,BorderLayout.CENTER);
            }
        }

        JButton b1 = new JButton("B1");
        JButton b2 = new JButton("B2");
        JButton b3 = new JButton("B4");
        JButton b4 = new JButton("B4");

        JPanel buttonArea = new JPanel();
        buttonArea.add(b1);
        buttonArea.add(b2);
        buttonArea.add(b3);
        buttonArea.add(b4);

        container.add(buttonArea,BorderLayout.EAST);
        setVisible(true);
    }
}
