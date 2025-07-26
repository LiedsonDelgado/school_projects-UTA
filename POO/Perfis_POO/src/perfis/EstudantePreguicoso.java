package perfis;

public class EstudantePreguicoso extends PessoaUniversidade {
    public EstudantePreguicoso(String nome) {
        super(nome);
    }

    public String realizarAtividade() {
        return nome + " está a assistir às aulas no YouTube em velocidade 2x.";
    }
}
