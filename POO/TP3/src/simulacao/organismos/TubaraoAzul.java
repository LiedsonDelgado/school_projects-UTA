package simulacao.organismos;

public abstract class TubaraoAzul extends OrganismosMarinhos {
    protected int taxaPredacao;

    public TubaraoAzul(String p_name,int p_populacao,float p_taxaReproducao,int p_taxaPredacao){
        super(p_name,p_populacao,p_taxaReproducao);
        this.taxaPredacao = p_taxaPredacao;
    }

    @Override
    public String getName(){
        return name;
    }

    @Override
    public int getPopulacao(){
        return populacao;
    }

    @Override
    public void reproduzir(){
        int newTaxaReproducao = Math.round(this.taxaReproducao);
        this.populacao = populacao +(populacao * newTaxaReproducao);
    }

    @Override
    public void setPopulacao(int newPopulation){
        this.populacao = newPopulation;
    }

    public int consumir(Cavala peixeAgulha,int quantidade){
        peixeAgulha.serPredado(quantidade);

        return quantidade;
    }

    public void atualizarEstados(){
        reproduzir();
    }
}
