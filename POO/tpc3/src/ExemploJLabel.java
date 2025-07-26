import javax.swing.*;
import java.awt.*;

public class ExemploJLabel {
    public static void main(String args[]) {
        JFrame janelaPrincipal = new JFrame("Exemplo JLabel1");
        janelaPrincipal.setLayout(new FlowLayout());

        JLabel titulo = new JLabel("Aula de PO",JLabel.CENTER);
        JLabel subtitulo = new JLabel("Java Swing");
        JLabel sala = new JLabel("Lab Programação");
        JLabel hora = new JLabel("14:30 as 17:30");

        janelaPrincipal.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janelaPrincipal.setSize(800,660);

        titulo.setPreferredSize(new Dimension(150,24));
        titulo.setOpaque(true);
        titulo.setBackground(new Color(100,200,210));
        janelaPrincipal.add(titulo);

        subtitulo.setOpaque(true);
        subtitulo.setBackground(Color.GREEN);
        JLabel icon = new
          JLabel("Visto", new ImageIcon("check.png"),
                JLabel.LEFT);
        icon.setPreferredSize(new Dimension(100,100));
        icon.setOpaque(true);
        icon.setBackground(Color.WHITE);

        janelaPrincipal.add(subtitulo);
        janelaPrincipal.add(sala);
        janelaPrincipal.add(hora);
        janelaPrincipal.add(icon);
        janelaPrincipal.setVisible(true);
    }
}
