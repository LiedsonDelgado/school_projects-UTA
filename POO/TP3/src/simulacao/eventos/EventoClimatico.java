package simulacao.eventos;
import simulacao.base.ElementosSimulacao;

public abstract class EventoClimatico extends ElementosSimulacao{
    public String tipo;
    public int duracao;
    public int impactoTemperatura;
    public int ciclos;

    public EventoClimatico(String p_name,String p_tipo,int p_duracao,int p_impactoTemperatura,int p_ciclos){
        super(p_name);
        this.tipo = p_tipo;
        this.duracao = p_duracao;
        this.impactoTemperatura = p_impactoTemperatura;
        this.ciclos = p_ciclos;
    }

    @Override
    public String getName(){
        return name;
    }
    public String getTipo(){
        return tipo;
    }

    public int getCiclosRestantes(){
        return ciclos;
    }

    public int getImpactoTemperatura(){
        if(estaAtivo()){
            return impactoTemperatura;
        }
        return 0;
    }

    @Override
    public void atualizarEstados(){
        if(ciclos <= 0){
            System.out.println("Os ciclos devem ser superiores que 0!");
        }
        this.ciclos--;
    }

    public boolean estaAtivo(){
        boolean status;
        if(getCiclosRestantes()>0){
            status = true;
        }else{
            status = false;
        }
        return status;
    }


}