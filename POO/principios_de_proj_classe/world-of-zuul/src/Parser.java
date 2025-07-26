import java.util.Scanner;

/**
 * Esta classe faz parte da aplicação "Mundo de Zuul".
 * "Mundo de Zuul" é um jogo de aventura textual muito simples.
 * 
 * Este analisador lê o input do utilizador e tenta interpretá-lo como um comando
 * do tipo "Aventura". Sempre que é chamado, lê uma linha do terminal e
 * tenta interpretá-la como um comando de duas palavras. Devolve o comando
 * como um objeto da classe Command.
 *
 * O analisador possui um conjunto de palavras de comando conhecidas. Verifica
 * o input do utilizador com base nessas palavras conhecidas e, se o input
 * não corresponder a nenhuma delas, devolve um objeto de comando marcado
 * como um comando desconhecido.
 * 
 * @author  Michael Kölling e David J. Barnes
 * @version 2016.02.29
 */
public class Parser 
{
    private CommandWords commands;  // guarda todas as palavras de comando válidas
    private Scanner reader;         // fonte do input de comandos

    /**
     * Cria um analisador para ler a partir da janela do terminal.
     */
    public Parser() 
    {
        commands = new CommandWords();
        reader = new Scanner(System.in);
    }

    /**
     * @return O próximo comando introduzido pelo utilizador.
     */
    public Command getCommand() 
    {
        String inputLine;   // irá conter a linha completa de input
        String palavra1 = null;
        String palavra2 = null;

        System.out.print("> ");     // mostrar prompt

        inputLine = reader.nextLine();

        // Encontrar até duas palavras na linha.
        Scanner tokenizer = new Scanner(inputLine);
        if(tokenizer.hasNext()) {
            palavra1 = tokenizer.next();      // obter a primeira palavra
            if(tokenizer.hasNext()) {
                palavra2 = tokenizer.next();  // obter a segunda palavra
                // nota: ignoramos o resto da linha de input.
            }
        }

        // Agora verificar se esta palavra é conhecida. Se for, criar um comando
        // com ela. Caso contrário, criar um comando "nulo" (para comando desconhecido).
        if(commands.isCommand(palavra1)) {
            return new Command(palavra1, palavra2);
        }
        else {
            return new Command(null, palavra2); 
        }
    }
}
