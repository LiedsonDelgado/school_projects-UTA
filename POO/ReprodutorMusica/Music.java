
public class Music {

    protected String artist;
    protected String gender;
    protected String music_name;
    protected String music_path;
    protected double duration;

    public Music(String p_artist, String p_gender, String p_music_name, String p_path, double p_duration) {
        this.artist = p_artist;
        this.gender = p_gender;
        this.music_name = p_music_name;
        this.music_path = p_path;
        this.duration = p_duration;
    }

    //Getters
    public String getArtist() {
        return artist;
    }

    public String getGender() {
        return gender;
    }

    public String getMusicName() {
        return music_name;
    }

    public String getMusicPath() {
        return music_path;
    }

    public double getDuration() {
        return duration;
    }
}

//MusicOrganizer usa a classe Musica(contendo os seus objetos) de forma composta/agregada
//
