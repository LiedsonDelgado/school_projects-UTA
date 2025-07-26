package perfis;

public class EstudanteFestas extends PessoaUniversidade {
    public EstudanteFestas(String nome) {
        super(nome);
    }

    public String realizarAtividade() {
        return nome + " está a preparar a próxima festa no dormitório.";
    }
}

