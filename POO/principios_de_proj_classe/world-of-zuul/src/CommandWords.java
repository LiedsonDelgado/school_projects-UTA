
import java.util.HashMap;

/**
 * Esta classe faz parte da aplicação "Mundo de Zuul".
 * "Mundo de Zuul" é um jogo de aventura textual muito simples.
 * 
 * Esta classe guarda uma enumeração de todas as palavras de comando
 * conhecidas pelo jogo. É utilizada para reconhecer os comandos
 * introduzidos pelo utilizador.
 * 
 * @author  Michael Kölling e David J. Barnes
 * @version 2016.02.29
 */

public class CommandWords
{
    // um array constante que guarda todas as palavras de comando válidas
    private HashMap<String,CommandWord> validCommands;

    /**
     * Construtor – inicializa as palavras de comando.
     */
    public CommandWords()
    {
        validCommands = new HashMap<>();
        validCommands.put("ir",CommandWord.IR);
        validCommands.put("ver",CommandWord.VER);
        validCommands.put("ajuda",CommandWord.AJUDA);
        validCommands.put("sair",CommandWord.SAIR);
    }

    /**
     * Verifica se uma determinada String é uma palavra de comando válida.
     * @param aString A string a verificar.
     * @return true se a string for um comando válido,
     * false caso contrário.
     */
    public boolean isCommand(String aString)
    {
        return validCommands.containsKey(aString);
    }
}
