/**
 * Classe Room – uma sala num jogo de aventura.
 *
 * Esta classe faz parte da aplicação "Mundo de Zuul".
 * "Mundo de Zuul" é um jogo de aventura textual muito simples.
 *
 * Uma "Sala" representa um local no cenário do jogo.
 * Está ligada a outras salas através de saídas. As saídas estão
 * rotuladas como norte, este, sul e oeste. Para cada direção,
 * a sala guarda uma referência para a sala vizinha ou null,
 * se não houver saída nessa direção.
 * 
 * @author  Michael Kölling e David J. Barnes
 * @version 2016.02.29
 */

import java.util.*;

public class Room 
{
    private String description;
    private HashMap<String,Room> exits;

    /**
     * Cria uma sala com a descrição "description". Inicialmente,
     * não tem saídas. A "description" pode ser algo como
     * "uma cozinha" ou "um pátio aberto".
     * @param description A descrição da sala.
     */
    public Room(String description) 
    {
        this.description = description;
        exits = new HashMap();
    }

    public Room getExit(String direction){
        return exits.get(direction);
    }

    /**
     * Define as saídas desta sala. Cada direção leva a outra sala
     * ou é null (sem saída nessa direção).
     * @param north A saída a norte.
     * @param east A saída a este.
     * @param south A saída a sul.
     * @param west A saída a oeste.
     */
    public void setExits(String direction,Room exitKey) 
    {
       if(direction!=null){
            exits.put(direction,exitKey);
       }
    }

    /**
     * @return A descrição da sala.
     */
    public String getDescription()
    {
        return description;
    }

    public String getCompleteDescription(){
        return "Voce esta em: " +description +".\n" +getExitString();
    }

    public String getExitString(){
        String stringReturn = "Saidas: ";
        Set<String>chaves = exits.keySet();

        for(String saida : chaves){
            stringReturn += "" +saida;
        }
        return stringReturn;
    }

}
