public class Pessoa {
    public String nome;
    public String anoNascimento;
    public int idade;
    public double altura;
    public double peso;

    public Pessoa(String p_nome,String p_anoNascimento,int p_idade,double p_altura,double p_peso){
        this.nome = p_nome;
        this.anoNascimento = p_anoNascimento;
        this.idade = p_idade;
        this.altura = p_altura;
        this.peso = p_peso;
    }

    public String getNome(){
        return nome;
    }

    public String getAnoNascimento(){
        return anoNascimento;
    }

    public int getIdade(){
        return idade;
    }

    public double getAltura(){
        return altura;
    }

    public double getPeso(){
        return peso;
    }

    public void setNome(String p_nome){
        this.nome = p_nome;
    }

    public void setAnoNascimento(String p_anoNascimento){
        this.anoNascimento = p_anoNascimento;
    }

    public void setIdade(int p_idade){
        this.idade = p_idade;
    }

    public void setAltura(double p_altura){
        this.altura = p_altura;
    }

    public void setPeso(int p_peso){
        this.peso = p_peso;
    }
}
