import javax.swing.*;
import java.awt.*;
public class ExemploTexto {
    public static void main(String args[]) {
        JFrame janela = new JFrame("Exemplo de Texto");
        janela.setLayout(new FlowLayout());
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setSize(800,600);
        JLabel nome = new JLabel("Nome: ");
        JLabel email = new JLabel("Email: ");
        JTextField campoNome = new JTextField(30);
        JTextField campoEmail = new JTextField(20);
        janela.add(nome);
        janela.add(campoNome);
        janela.add(email);
        janela.add(campoEmail);

        JLabel observa = new JLabel("Observações:");
        JTextArea descr = new JTextArea();
        descr.setLineWrap(true);
        descr.setWrapStyleWord(true);

        JScrollPane descrSroll = new JScrollPane(descr);
  //      descrSroll.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        descrSroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

        janela.add(observa);
        janela.add(descr);
        campoNome.requestFocus(true);
        janela.setVisible(true);
    }

}
