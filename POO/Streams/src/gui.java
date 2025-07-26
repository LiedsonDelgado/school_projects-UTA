import javax.swing.*;
import javax.swing.border.LineBorder;
import java.util.*;
import java.awt.*;

public class gui extends JFrame {
    JComboBox<String> opc;
    JTextArea textArea;

    public gui(){
        super("WINDOW");
        setSize(new Dimension(800,800));
        setBackground(new Color(0,0,0));
        setLayout(new BorderLayout());

        textArea = new JTextArea();
        textArea.setEnabled(false);
        JPanel cont1 = new JPanel();
        JPanel cellCont = new JPanel();
        cellCont.setSize(new Dimension(500,500));

        JButton b1 = new JButton("load");
        b1.setBackground(new Color(50, 97, 68));
        b1.addActionListener(e->loadGame());

        JButton b2 = new JButton("save");
        b2.setBackground(new Color(50, 97, 68));
        b2.addActionListener(e->saveGame());

        JButton b3 = new JButton("close");
        b3.setBackground(new Color(50, 97, 68));
        b3.addActionListener(e->closeGame());

        String[] opcoes = {"V.1","V.2","V.3"};
        opc = new JComboBox<>(opcoes);
        opc.setSize(new Dimension(100,100));

        cont1.add(b1);
        cont1.add(b2);
        cont1.add(b3);

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                JPanel cell = new JPanel();
                cell.setSize(new Dimension(10,10));
                cell.setBorder(new LineBorder(new Color(0,0,0)));
                cell.setBackground(new Color(0, 134, 38));
                cellCont.add(cell,BorderLayout.CENTER);
                add(cellCont,BorderLayout.SOUTH);
            }
        }

        add(cont1,BorderLayout.CENTER);
        add(textArea,BorderLayout.NORTH);
        add(opc,BorderLayout.SOUTH);

        setVisible(true);
    }

    public void saveGame(){
        System.out.println("Game Saved!");
        textArea.setText("Game Saved!");
    }

    public void loadGame(){
        System.out.println("Game Loaded!");
        Pessoa p1 = new Pessoa("Liedson","27/08/2005",19,1.80,85);
        textArea.setText(p1.getAnoNascimento());
    }

    public void closeGame(){
        System.out.println("Game Closed!");
        textArea.setText("");
    }
}
