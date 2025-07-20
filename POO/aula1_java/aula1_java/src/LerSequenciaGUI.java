import javax.swing.*;

public class LerSequenciaGUI{
    public static void main(String[] args) {
        final int MAX = 100;
        int valor   ;
        int sequencia[] = new int [MAX];
            int i;
        do {
            valor = JOptionPane.showInputDialog(null, "Digite um valor: ");
                    if (valor != -77) {
                        for(i=0;i<MAX;i++){
                            sequencia[i] = valor;
                        }
                    }else{
                        System.out(0);
                    }
        }while(valor != -77);
    }
}