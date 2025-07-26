import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try{
            throw new Exception("Erro de Excecucao!\n"); //lanca uma excepcao
        }catch(Exception error){
            System.out.println("Ocorreu um erro de execucao!");
        }

        Scanner sc = new Scanner(System.in);
        System.out.print("Sua idade: ");
        int age = sc.nextInt();

        if(age <= 0){
            throw new IllegalArgumentException("A idade nao pode ser menor ou igual a 0");
        }
        System.out.println("OK!");
    }
}