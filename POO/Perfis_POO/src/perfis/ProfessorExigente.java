package perfis;

public class ProfessorExigente extends PessoaUniversidade {
    public ProfessorExigente(String nome) {
        super(nome);
    }

    public String realizarAtividade() {
        return nome + " está a aplicar um teste surpresa com 10 questões dissertativas.";
    }
}

