package perfis;

public abstract class PessoaUniversidade {
    protected String nome;

    public PessoaUniversidade(String nome) {
        this.nome = nome;
    }

    public abstract String realizarAtividade();

    @Override
    public String toString() {
        return nome + " (" + this.getClass().getSimpleName() + ")";
    }
}