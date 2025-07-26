
import java.util.ArrayList;

public class Leilao {

    private ArrayList<Lote> lots;
    private int nextLot;

    public Leilao() {
        this.lots = new ArrayList<>();
        this.nextLot = 1;
    }

    public void addLot(String p_desc) {
        lots.add(new Lote(nextLot, p_desc));
        nextLot++;
    }

    public void listarLotes() {
        for (Lote lot : lots) {
            System.out.println(lot.toString());
        }
    }

    //(+)Implementar #1
    //->dar o resultado do leilao
    //->procurar na colecao para cada item e o computador
    //(+)Implementar #2
    //->Classes MusicPlayer & MusicOrganizer(Colecao de objetos: Player,Musica(artista,genero,nome ficheiro))
    //->usando a classe "javazoom.jl.player.advanced.AdvancedPlayer" (Pesquisar)
}
