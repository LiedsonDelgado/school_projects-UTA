/**
 * Esta classe faz parte da aplicação "Mundo de Zuul".
 * "Mundo de Zuul" é um jogo de aventura textual muito simples.
 *
 * Esta classe guarda informação sobre um comando introduzido pelo utilizador.
 * Um comando consiste atualmente em duas palavras: uma palavra de comando e uma
 * segunda palavra (por exemplo, se o comando for "apanhar mapa", então as duas
 * palavras são "apanhar" e "mapa").
 * 
 * A utilização desta classe é a seguinte: os comandos já foram verificados quanto
 * à validade da palavra de comando. Se o utilizador introduziu um comando inválido
 * (ou seja, uma palavra que não é reconhecida), então a palavra de comando é <null>.
 *
 * Se o comando tiver apenas uma palavra, então a segunda palavra será <null>.
 * 
 * @author  Michael Kölling e David J. Barnes
 * @version 2016.02.29
 */

public class Command
{
    private CommandWord commandWord;
    private String secondWord;

    /**
     * Cria um objeto de comando. A primeira e segunda palavras devem ser fornecidas,
     * mas uma (ou ambas) podem ser nulas.
     * @param firstWord A primeira palavra do comando. Nula se o comando
     *                  não for reconhecido.
     * @param secondWord A segunda palavra do comando.
     */
    public Command(CommandWord firstWord, String secondWord)
    {
        commandWord = firstWord;
        this.secondWord = secondWord;
    }

    /**
     * Devolve a palavra de comando (a primeira palavra) deste comando.
     * Se o comando não for reconhecido, o resultado é null.
     * @return A palavra de comando.
     */
    public CommandWord getCommandWord()
    {
        return commandWord;
    }

    /**
     * @return A segunda palavra deste comando. Devolve null se não existir
     * segunda palavra.
     */
    public String getSecondWord()
    {
        return secondWord;
    }

    /**
     * @return true se este comando não for reconhecido.
     */
    public boolean isUnknown()
    {
        return (commandWord == null);
    }

    /**
     * @return true se o comando tiver uma segunda palavra.
     */
    public boolean hasSecondWord()
    {
        return (secondWord != null);
    }
}
