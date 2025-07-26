package simulacao.organismos;

public abstract class Cavala extends OrganismosMarinhos {
    public int consumoPorCiclo;

    public Cavala(String p_name,int populacaoInicial,float taxaReproducao,int p_consumoPorCiclo){
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

    public int consumir(Plancton plancton,int quantidade){
        return plancton.consumir(quantidade);
    }

    public void serPredado(int quantidade){
        if(quantidade > populacao){
            throw new IllegalArgumentException("O valor consumido de ser superior ou igual ao disponivel!\n");
        }
        this.populacao = populacao-quantidade;
    }

    public void atualizarEstados(){
        reproduzir();
    }
}
