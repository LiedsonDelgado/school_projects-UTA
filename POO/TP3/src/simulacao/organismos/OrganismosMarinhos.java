package simulacao.organismos;
import simulacao.base.ElementosSimulacao;

public abstract class OrganismosMarinhos extends ElementosSimulacao {
    protected int populacao;
    protected float taxaReproducao;

    public OrganismosMarinhos(String p_name, int populacaoInicial, float p_taxaReproducao){
        super(p_name);
        this.populacao = populacaoInicial;
        this.taxaReproducao = p_taxaReproducao;
    }

    public int getPopulacao(){
        return populacao;
    }

    public void reproduzir(){
        int newTaxaReproducao = Math.round(this.taxaReproducao);
        this.populacao = populacao +(populacao * newTaxaReproducao);
    }

    public void setPopulacao(int newPopulation){
        if(newPopulation > 0){
            this.populacao = newPopulation;
        }else{
            System.out.println("A populacao deve ser superior a 0\n");
        }
    }
}
