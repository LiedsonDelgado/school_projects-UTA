import java.util.Scanner;

public class LerSequencia {
    public static void main(String[] args) {
        final int MAX = 1000; //TAMANHO MAXIMO DO VETOR(Constante Simbolica)

        int valores[] = new int[MAX];
            int i;

                for (i = 0; i < MAX; i++) {
                    System.out.println("Digite um numero: ");
                        valores[i] = new Scanner(System.in).nextInt();

                            if (valores[i] == -77) {
                            System.exit(0);
                            }
                }
    }
}