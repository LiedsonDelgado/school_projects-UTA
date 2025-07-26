package simulacao.base;

public abstract class ElementosSimulacao{
    public String name;

    public ElementosSimulacao(String p_name){
        this.name = p_name;
    }

    public String getName(){
        return name;
    }

    public abstract void atualizarEstados();
}
