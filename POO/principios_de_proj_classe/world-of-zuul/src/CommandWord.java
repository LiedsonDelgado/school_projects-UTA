public enum CommandWord{
    IR("ir"),SAIR("sair"),AJUDA("ajuda"),VER("ver");
    private String stringCommand;

    CommandWord(String p_stringCommand){
        this.stringCommand = p_stringCommand;
    }
}