public abstract class Fruta{
    public String nome;
    public double precoBase;

    //Fruta Constructor
    public Fruta(){
        this.nome = null;
        this.precoBase = 0.0;
    }

    //Methods
    public String getNome(){
        return nome;
    }

    public double getPrecoBase(){
        return precoBase;
    }

    public void setNome(String p_nome){
        this.nome = p_nome;
    }

    public void setPrecoBase(double p_precoBase){
        this.precoBase = p_precoBase;
    }

    public abstract double aPagar();
    public abstract String toString();
    public abstract Fruta clone();
}