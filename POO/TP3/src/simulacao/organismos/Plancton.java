package simulacao.organismos;
import simulacao.base.ElementosSimulacao;

public abstract class Plancton extends ElementosSimulacao {
    public int quantidadeInicial;
    public int taxaCrescimento;

    public Plancton(String p_name,int p_quantidadeInicial,int p_taxaCrescimento){
        super(p_name);
        this.quantidadeInicial = p_quantidadeInicial;
        this.taxaCrescimento = p_taxaCrescimento;
    }

    public int getQuantidade(){
        return quantidadeInicial;
    }

    public int consumir(int quantidadeConsumida){
        if(quantidadeConsumida > quantidadeInicial){
            throw new IllegalArgumentException("O valor consumido de ser >= ao disponivel");
        }
        return this.quantidadeInicial = quantidadeInicial-quantidadeConsumida;
    }

    public void crescer(){
        int newTaxaCrescimento = Math.round(this.taxaCrescimento);
        this.quantidadeInicial = quantidadeInicial +(quantidadeInicial * newTaxaCrescimento);
    }

    public void atualizarEstados(){
        crescer();
    }
}
