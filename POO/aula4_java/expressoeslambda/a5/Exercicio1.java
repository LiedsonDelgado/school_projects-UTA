import java.util.Arrays;
import java.util.List;

public class Exercicio1 {
    public static List<Pessoa> pessoas;
    public static void main(String[] args) {
        pessoas = Arrays.asList(
            new Pessoa("Liedson","Delgado",19),
            new Pessoa("James","Smith",49)
        );

        printCondicional((Pessoa s,String charc) -> s.getApelido().startsWith(charc));
        printCondicional((Pessoa s,int age) -> s.getIdade() > age);
    }

    /*ordenar lista pelo apelido usando expressoes lambda
    public static void ordenar(){
        Collections.sort(pessoas,(Pessoa p1,Pessoa p2) -> p1.getApelido().compareTo(p2.getApelido()));
    }
    */

    //ordenar a lista pelo nome,apelido,idade
    public static void showAll(){
        for(Pessoa s: pessoas){
            System.out.println("Nome: " +s.getNome());
            System.out.println("Apelido: " +s.getApelido());
            System.out.println("Idade: " +s.getIdade());
        }
    }

    //ordenar a lista pelo nome,apelido,idade que comecam com caracter especifico passado como argumento
    public static void showAllCharc(String charc){
        for(Pessoa s : pessoas){
            if(s.getApelido().startsWith(charc)){
                System.out.println("Nome: " +s.getNome());
                System.out.println("Apelido: " +s.getApelido());
                System.out.println("Idade: " +s.getIdade());
            }
        }
    }

    //ordenar a lista dado uma condicao
    public static void printCondicional(Condicao filtro){
        for(Pessoa s : pessoas){
            if(filtro.TestarIdade(s)){
                System.out.println("Nome: " +s.getNome());
                System.out.println("Apelido: " +s.getApelido());
                System.out.println("Idade: " +s.getIdade());
            }
        }
    }
}