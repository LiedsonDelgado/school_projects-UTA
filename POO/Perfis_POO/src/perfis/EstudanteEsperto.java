package perfis;

public class EstudanteEsperto extends PessoaUniversidade {
    public EstudanteEsperto(String nome) {
        super(nome);
    }

    public String realizarAtividade() {
        return nome + " está a resolver listas de exercícios por diversão.";
    }
}

