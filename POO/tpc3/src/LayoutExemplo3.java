import javax.swing.*;
import java.awt.*;

public class LayoutExemplo3 {
    public static void main(String args[]) {
        JFrame janela = new JFrame("Exemplo Border Layout");
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setSize(800, 600);
        janela.setLayout(new BorderLayout());
        JLabel titulo = new JLabel("Área topo da janela", JLabel.CENTER);
        titulo.setOpaque(true);
        titulo.setBackground(Color.RED);
        JLabel barraStatus = new JLabel("Data : 6 de Maio 17:04");
        janela.add(titulo, BorderLayout.NORTH);
        janela.add(barraStatus, BorderLayout.SOUTH);

        JPanel contentorBtn = new JPanel(new GridBagLayout() );
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(2, 10, 2, 10); // Margens para os botões

        JButton sendBtn = new JButton("Enviar");
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.fill = GridBagConstraints.HORIZONTAL;
     //   gbc.anchor = GridBagConstraints.CENTER;
        gbc.weightx = 0.0;
      //  gbc.weighty = 0.25;
        contentorBtn.add(sendBtn, gbc);

        JButton saveBtn = new JButton("Guardar");
        gbc.gridx = 0;
        gbc.gridy = 1;

        contentorBtn.add(saveBtn, gbc);

        JButton resetBtn = new JButton("Reset");
        gbc.gridx = 0;
        gbc.gridy = 2;

        contentorBtn.add(resetBtn, gbc);

        JButton cancelBtn = new JButton("Cancelar");
        gbc.gridx = 0;
        gbc.gridy = 3;

        contentorBtn.add(cancelBtn, gbc);

        janela.add(contentorBtn, BorderLayout.EAST);
        janela.setVisible(true);
    }
}
