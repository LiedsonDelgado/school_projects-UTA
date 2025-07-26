import javax.swing.*;


public class Hello_World_GUI {
    public static void main(String[] args) {
        int number = 13;
        double media = 871.0 / 13.2;

        JOptionPane.showMessageDialog(null,"O valor do numero: " +number);
        JOptionPane.showMessageDialog(null,"O valor da media: " +String.format("%.2f",media));


            System.exit(0);
    }
}