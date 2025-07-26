package perfis;

public class ProfessorZen extends PessoaUniversidade {
    public ProfessorZen(String nome) {
        super(nome);
    }

    public String realizarAtividade() {
        return nome + " está a dar uma aula tranquila com meditação e silêncio.";
    }
}

