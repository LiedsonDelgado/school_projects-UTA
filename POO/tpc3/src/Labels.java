import javax.swing.*;
import java.awt.*;
public class Labels {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JLabel Examples");
        frame.setLayout(new FlowLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 150);
        JLabel basic = new JLabel("Default Label");
        frame.add(basic);
        frame.setVisible(true);
    }
}
