//Super Classe das demais Classes(FrutaUnidade,FrutaPeso,FrutaVolume e CabazdeFruta)
public abstract class Fruta{
    public String nome;
    public double precoBase;

    //Fruta Constructor
    public Fruta(){
        this.nome = null;
        this.precoBase = 0.0;
    }

    //Methods
    //Getters
    public String getNome(){
        return nome;
    }

    public double getPrecoBase(){
        return precoBase;
    }

    //Setters
    public void setNome(String p_nome){
        this.nome = p_nome;
    }

    public void setPrecoBase(double p_precoBase){
        this.precoBase = p_precoBase;
    }

    public abstract double TotalaPagar();

    @Override
    public abstract String toString();

    @Override
    public abstract Fruta clone();
}