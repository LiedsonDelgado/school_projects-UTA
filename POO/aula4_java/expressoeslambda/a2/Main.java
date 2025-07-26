public class Main{
    public static void main(String[] args) {
        Cumprimento cump = new Cumprimento();

        Saudacao saudacaoLambda = () -> System.out.println("Bom dia!");
        Saudacao disciplina = () -> System.out.println("Aula POO");

        cump.saudar(saudacaoLambda);
        cump.saudar(disciplina);
    }
}