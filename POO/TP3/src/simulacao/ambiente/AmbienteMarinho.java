package simulacao.ambiente;
import simulacao.base.ElementosSimulacao;

import java.util.ArrayList;
import java.util.List;

public class AmbienteMarinho extends Object{
    private List<simulacao.base.ElementosSimulacao>elementos;
    private int temperaturaAtual;
    private int temperaturaBase;

    public AmbienteMarinho(int p_temperaturaBase){
        elementos = new ArrayList<>();
        this.temperaturaBase = p_temperaturaBase;
        this.temperaturaAtual = p_temperaturaBase;
    }

    public void addElement(ElementosSimulacao newElement){
        elementos.add(newElement);
    }

    private void exibirEstado(){
        if(elementos == null){
            throw new IllegalArgumentException("A lista de elementos de simulacao esta vazia!\n");
        }

        for(ElementosSimulacao am : elementos){
            System.out.println(showEnviromentInfos());
        }
    }

    public String showEnviromentInfos(){
        StringBuilder msg = new StringBuilder();

        msg.append("--ESTADO AMBIENTAL--\n");
        msg.append("Temperatura Base: " +this.temperaturaBase +" C\n");
        msg.append("Temperatura Atual: " +this.temperaturaBase +" C");

        return msg.toString();
    }

    public void simularCiclo(){
        for(ElementosSimulacao am : elementos){
            am.atualizarEstados();
        }
    }
}
