public class Cumprimento implements Saudacao{

    @Override
    public void saudar(Saudacao s){
        b.saudar();
    }

    public static void main(String[] args) {
        Cumprimento c = new Cumprimento();
        c.saudar();
    }
}