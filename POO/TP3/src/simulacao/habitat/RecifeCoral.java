package simulacao.habitat;
import simulacao.base.ElementosSimulacao;

public abstract class RecifeCoral extends ElementosSimulacao {
    public int saudeInicial;
    public int taxaRegeneracao;
    public int taxaDegradacao;

    public RecifeCoral(String p_name,int p_saudeInicial,int p_taxaRegeneracao,int p_taxaDegradacao){
        super(p_name);
        if(p_saudeInicial >= 0 || p_saudeInicial <= 100){
            this.saudeInicial = p_taxaRegeneracao;
        }else{
            System.out.println("A saude deve estar entre 0 a 100!");
        }
        this.taxaDegradacao = p_taxaDegradacao;
    }

    public int getSaude(){
        return saudeInicial;
    }

    public void degradar(){
        if(saudeInicial > 0) {
            this.saudeInicial -= taxaDegradacao;
        }else{
            System.out.println("O Recife ja esta degradado!");
        }
    }

    public boolean estaDegrado(){
        if(saudeInicial < 30){
            return true;
        }
        return false;
    }

    @Override
    public void atualizarEstados(){
        if(saudeInicial < 100){
            saudeInicial += taxaRegeneracao;
        }
    }
}
