import javax.swing.*;
import java.awt.*;

public class LayoutExemplo1 {
    public static void main(String args[]) {
        JFrame janela = new JFrame("Exemplo Border Layout");
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setSize(800,600);
        janela.setLayout(new BorderLayout());
        JLabel titulo = new JLabel("Área topo da janela", JLabel.CENTER);
        titulo.setPreferredSize(new Dimension(800,100));
        titulo.setOpaque(true);
        titulo.setBackground(Color.RED);
        JLabel barraStatus = new JLabel("Data : 6 de Maio 17:04", JLabel.CENTER);
        janela.add(titulo,BorderLayout.NORTH);
        janela.add(barraStatus,BorderLayout.SOUTH);

        JPanel contentorBtn = new JPanel(new GridLayout(0,1));
        Dimension tmBtn = new Dimension(100,20);
        JButton sendBtn = new JButton("Enviar");
        sendBtn.setPreferredSize(tmBtn); // Definindo largura e altura para o botão "Enviar"

        JButton saveBtn = new JButton("Guardar");
        saveBtn.setPreferredSize(tmBtn); // Definindo largura e altura para o botão "Guardar"

        JButton resetBtn = new JButton("Reset");
        resetBtn.setPreferredSize(tmBtn); // Definindo largura e altura para o botão "Reset"

        JButton cancelBtn = new JButton("Cancelar");
        cancelBtn.setPreferredSize(tmBtn); // Definindo largura e altura para o botão "Cancelar"

        contentorBtn.add(sendBtn);
        contentorBtn.add(saveBtn);
        contentorBtn.add(resetBtn);
        contentorBtn.add(cancelBtn);
        janela.add(contentorBtn,BorderLayout.EAST);
        janela.setVisible(true);
    }
}
