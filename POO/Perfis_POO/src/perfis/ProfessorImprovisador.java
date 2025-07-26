package perfis;

public class ProfessorImprovisador extends PessoaUniversidade {
    public ProfessorImprovisador(String nome) {
        super(nome);
    }

    public String realizarAtividade() {
        return nome + " está a inventar o conteúdo da aula enquanto fala.";
    }
}





