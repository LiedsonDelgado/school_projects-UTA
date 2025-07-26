import java.awt.*;
import javax.swing.*;

public class BorderLayoutTPC {
    public static void main(String[] args) {
        JFrame window = new JFrame("BorderLayout");
        window.setSize(700, 700);
        window.setLayout(new BorderLayout());

        //topArea
        JLabel topArea = new JLabel("Area topo da janela",JLabel.CENTER);
        topArea.setOpaque(true);
        topArea.setBackground(new Color(255, 0, 0));
        topArea.setPreferredSize(new Dimension(700,30));

        //note
        JLabel note = new JLabel("Data: 28 de Maio 22:14", JLabel.LEFT);

        //buttonPanel
        JPanel buttonPanel = new JPanel(new GridBagLayout());

        JButton b1 = new JButton("Enviar");
        JButton b2 = new JButton("Guardar");
        JButton b3 = new JButton("Reset");
        JButton b4 = new JButton("Cancelar");

        b1.setPreferredSize(new Dimension(150,10));
        buttonPanel.add(b1);

        b2.setPreferredSize(new Dimension(150,10));
        buttonPanel.add(b2);

        b3.setPreferredSize(new Dimension(150,10));
        buttonPanel.add(b3);

        b4.setPreferredSize(new Dimension(150,10));
        buttonPanel.add(b4);

        buttonPanel.setLayout(new GridLayout(4,1,0,90));

        //area do centro-sendo uma area vazia
        JPanel centerPanel = new JPanel();

        //add dos componentes ao objeto JFrame
        window.add(topArea, BorderLayout.NORTH);
        window.add(buttonPanel,BorderLayout.EAST);
        window.add(note,BorderLayout.SOUTH);
        window.add(centerPanel,BorderLayout.CENTER);

        window.setVisible(true);
    }
}
