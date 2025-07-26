import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;

public class JSliderExample extends JFrame {

    public JSliderExample() {
        setTitle("Exemplo de JSlider");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 200);

        // Cria um JSlider com valor mínimo de 0, máximo de 100 e valor inicial de 50
        JSlider slider = new JSlider(JSlider.HORIZONTAL, 0, 100, 50);
        slider.setMajorTickSpacing(20); // Define os intervalos maiores
        slider.setMinorTickSpacing(5); // Define os intervalos menores
        slider.setPaintTicks(true); // Mostra as marcações dos intervalos
        slider.setPaintLabels(true); // Mostra os valores dos intervalos
        slider.setFont(new Font("Arial", Font.PLAIN, 12));

        // Adiciona um ChangeListener para acompanhar as mudanças no valor do JSlider
        slider.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                JSlider source = (JSlider) e.getSource();
                int value = source.getValue();
                System.out.println("Valor atual do slider: " + value);
            }
        });

        // Adiciona o slider ao painel
        JPanel panel = new JPanel();
        panel.add(slider);

        // Adiciona o painel ao frame
        add(panel);

        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new JSliderExample();
            }
        });
    }
}

