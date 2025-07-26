package simulacao.organismos;
import simulacao.interfaces.Consumidor;

public abstract class AveMarinha extends OrganismosMarinhos implements Consumidor<Cavala>{
    public int consumoPorCiclo;

    public AveMarinha(String p_name,int populacaoInicial,float taxaReproducao,int p_consumoPorCiclo){
        super(p_name,populacaoInicial,taxaReproducao);
        this.consumoPorCiclo = p_consumoPorCiclo;
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
