import java.util.Scanner;

public class InOutText {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
            String nome;
            int idade;
            float altura;

            System.out.print("Digite a sua Idade: ");
                idade = sc.nextInt();

            System.out.print("Digite a sua Altura: ");
                altura = sc.nextFloat();

            System.out.print("Digite a seu Nome: ");
                nome = sc.nextLine();

                System.out.printf("\nA sua Idade e: %d anos\n",idade);
                System.out.printf("A sua Altura e: %.2f cm\n",altura);
                System.out.printf("A sua Nome e: %s\n",nome);

    }
}
