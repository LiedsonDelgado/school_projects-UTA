import javax.swing.*;

public class RaizQuadrada{
    public static void main(String[] args) {
        String readedValue;
        double n;
        double squareRoot;

        JOptionPane.showMessageDialog(null,"CALCULAR RAIZ QUADRADA\n");
        readedValue = JOptionPane.showInputDialog(null,"Numero: ");
            n = Double.parseDouble(readedValue);

    if(n > 0){
        squareRoot = Math.sqrt(n);
        JOptionPane.showMessageDialog(null,"Raiz Quadrada: "+String.format("%.1f",squareRoot));
    }else{
        JOptionPane.showMessageDialog(null,"Nao e possivel calcular raiz quadrada\n");
        }
    }
}
