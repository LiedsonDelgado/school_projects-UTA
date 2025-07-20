import javax.swing.*;

public class In_Out_GUI {
    public static void main(String[] args) {
        String firstName;
        int idade;
        String readedValue;

            firstName = JOptionPane.showInputDialog(null,"Digite o seu primeiro nome: ");
                JOptionPane.showMessageDialog(null, "Ola, " +firstName +" como estas.\n");

            readedValue = JOptionPane.showInputDialog(null,"Digite a sua Idade: ");
                idade = Integer.parseInt(readedValue);

                    System.exit(0);
    }
}
