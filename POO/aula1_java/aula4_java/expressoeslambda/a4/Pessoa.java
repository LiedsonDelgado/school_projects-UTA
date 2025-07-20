public class Pessoa{
    private String nome;
    private String apelido;
    private int idade;

    public Pessoa(String nome, String apelido, int idade) {
        this.nome = nome;
        this.apelido = apelido;
        this.idade = idade;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getApelido() {
        return apelido;
    }

    public void setApelido(String apelido) {
        this.apelido = apelido;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

}