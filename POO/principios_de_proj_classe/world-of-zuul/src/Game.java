/**
 *  Esta classe é a classe principal da aplicação "Mundo de Zuul".
 *  "Mundo de Zuul" é um jogo de aventura textual muito simples. Os utilizadores
 *  podem caminhar por diversos cenários. É só isso. Deveria realmente ser ampliado
 *  para o tornar mais interessante!
 *
 *  Para jogar este jogo, crie uma instância desta classe e chame o método "jogar".
 *
 *  Esta classe principal cria e inicializa todas as outras: cria todas as
 *  salas, cria o analisador sintático (parser) e inicia o jogo. Também avalia e
 *  executa os comandos que o analisador sintático devolve.
 *
 * @author  Michael Kölling e David J. Barnes
 * @version 2016.02.29
 */

public class Game 
{
    private Parser parser;
    private Room currentRoom;
        
    /**
     * Criar o jogo e inicializar o seu mapa interno.
     */
    public Game() 
    {
        createRooms();
        parser = new Parser();
    }

    /**
     * Criar todas as salas e ligar as suas saídas entre si.
     */
    private void createRooms()
    {
        Room outside, theater, pub, lab, office;
      
        // criar as salas
        outside = new Room("à entrada principal da universidade");
        theater = new Room("num anfiteatro");
        pub = new Room("no bar do campus");
        lab = new Room("num laboratório de informática");
        office = new Room("no gabinete administrativo de informática");
        
        // inicializar as saídas
        outside.setExits(null, theater, lab, pub,null);
        theater.setExits(null, null, null, outside,null);
        pub.setExits(null, outside, null, null,null);
        lab.setExits(outside, office, null, null,outside);
        office.setExits(null, null, null, lab,null);

        currentRoom = outside;  // o jogo começa cá fora
    }

    /**
     * Rotina principal de jogo. Repete em ciclo até ao fim do jogo.
     */
    public void play() 
    {            
        printWelcome();
        
        // Entrar no ciclo principal de comandos. Aqui repetidamente lemos comandos e
        // executamo-los até o jogo terminar.
        boolean finished = false;
        while (!finished) {
            Command command = parser.getCommand();
            finished = processCommand(command);
        }
        System.out.println("Obrigado por jogar. Adeus.");
    }

    /**
     * Apresentar a mensagem inicial para o jogador.
     */
    private void printWelcome()
    {
        System.out.println();
        System.out.println("Bem-vindo ao Mundo de Zuul!");
        System.out.println("Mundo de Zuul é um novo jogo de aventura incrivelmente aborrecido.");
        System.out.println("Escreva 'ajuda' se precisar de ajuda.");
        System.out.println();

        printLocation();

        System.out.println();
    }

    /**
     * Dado um comando, processa (isto é: executa) o comando.
     * @param command O comando a ser processado.
     * @return true Se o comando terminar o jogo, false caso contrário.
     */
    private boolean processCommand(Command command) 
    {
        boolean wantToQuit = false;

        if(command.isUnknown()) {
            System.out.println("Não percebo o que quer dizer...");
            return false;
        }

        //String commandWord = command.getCommandWord();
        CommandWord commandWord = command.getCommandWord();
        
        switch(commandWord){
            case IR:
                goRoom(command);
                break;

            case VER:
                look();
                break;
            
            case SAIR:
                wantToQuit = quit(command);
                break;
            
            case AJUDA:
                printHelp();
                break;
            
            default:
                System.out.println("Comando Desconhecido!");
        }

        return wantToQuit;
    }

    /**
     * Apresenta algumas informações de ajuda.
     * Aqui imprimimos uma mensagem enigmática e uma lista das palavras de comando.
     */
    private void printHelp() 
    {
        System.out.println("Está perdido. Está sozinho. Vagueia");
        System.out.println("pela universidade.");
        System.out.println();
        System.out.println("As palavras de comando são:");
        System.out.println("   ir sair ajuda");
    }

    public void look(){
        System.out.println(currentRoom.getCompleteDescription());
    }

    private void goRoom(Command command) 
    {
        if(!command.hasSecondWord()) {
            // se não houver segunda palavra, não sabemos para onde ir...
            System.out.println("Ir para onde?");
            return;
        }

        String direction = command.getSecondWord();

        // Tentar sair da sala atual.
        Room nextRoom = currentRoom.getExit(direction);

        if (nextRoom == null) {
            System.out.println("Não há nenhuma porta!");
        }
        else {
            currentRoom = nextRoom;
            printLocation();
        }
    }

    private void printLocation(){
        System.out.println();
        System.out.println("Bem-vindo ao Mundo de Zuul!");
        System.out.println("Mundo de Zuul é um novo jogo de aventura incrivelmente aborrecido.");
        System.out.println("Escreva 'ajuda' se precisar de ajuda.");
        System.out.println();
        System.out.println("Está " + currentRoom.getDescription());
        System.out.print("Saídas: ");

        if(currentRoom.getExit("norte") != null) {
            System.out.print("norte ");
        }
        if(currentRoom.getExit("este") != null) {
            System.out.print("este ");
        }
        if(currentRoom.getExit("sul") != null) {
            System.out.print("sul ");
        }
        if(currentRoom.getExit("west") != null) {
            System.out.print("oeste ");
        }
        if(currentRoom.getExit("baixo") != null) {
            System.out.print("baixo");
        }
        System.out.println();
    }

    /**
     * O comando "sair" foi introduzido. Verificar se deve mesmo sair do jogo.
     * @return true, se este comando terminar o jogo, false caso contrário.
     */
    private boolean quit(Command command) 
    {
        if(command.hasSecondWord()) {
            System.out.println("Sair de quê?");
            return false;
        }
        else {
            return true;  // sinalizar que queremos sair
        }
    }
}
