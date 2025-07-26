//Sub Classe da Classe Fruta
public abstract class FrutaUnidade extends Fruta{
    public int unidade;

    //FrutaUnidade Constructor
    public FrutaUnidade(String p_nome,double p_precoBase,int p_unidade){
        super(p_nome,p_unidade  );
        this.unidade = p_unidade;
    }

    //Methods
    //Getters
    @Override
    public String getNome(){
        return nome;
    }

    @Override
    public double getPrecoBase(){
        return precoBase;
    }

    public int getUnidade(){
        return unidade;
    }

    //Setters
    @Override
    public double TotalaPagar(){
        double precoTotal = unidade * precoBase;
        return precoTotal;
    }
}