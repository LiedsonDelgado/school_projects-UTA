
import java.util.ArrayList;

public class MusicOrganizer {

    ArrayList<Music> playlist;

    //MusicOrganizer Constructor
    public MusicOrganizer() {
        playlist = new ArrayList<>();
    }

    //Methods
    public Music getMusicPath(String path) {
        for (Music music : playlist) { //percorre cada elemento do arraylist executa o bloco de codigo dentro do for(...)
            if (music.getMusicPath().equals(path)) {
                return music;
            }
        }
        return null;
    }

    //parametros recebe o: nome do artista[1]; o genero musical[2]; o nome da musica[3];o diretorio do ficheiro[4];duracao da musica[5]
    public void addMusic(String p_artist, String p_gender, String p_name, String p_path, double p_duration) {
        Music music = new Music(p_artist, p_gender, p_name, p_path, p_duration);
        playlist.add(music);
    }

    public void removeMusic(String p_music_name) {
        for (Music music : playlist) {
            if (music.getMusicName().equals(p_music_name)) {
                playlist.remove(p_music_name);
                break;
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();

        for (Music music : playlist) {
            int i = 1;
            String a = music.getArtist(); //armazena o artista
            String n = music.getMusicName(); //armazena o nome da musica
            String g = music.getGender(); //armazena o genero da musica
            double d = music.getDuration(); //armazena a duracao da musica

            string.append("Musica da").append(i).append("ª Posicao");

            string.append("Artista: ").append(a).append("\n");
            string.append("Nome da Musica: ").append(n).append("\n");
            string.append("Genero Musical: ").append(g).append("\n");
            string.append("Duracao: ").append(d).append("\n");

            string.append("\n");
            i++;
        }

        System.out.println(string.toString());

        return string.toString();
    }
}
