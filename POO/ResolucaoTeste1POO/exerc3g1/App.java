public class App {
    public static void main ( String args []) {
        Teste b1 = new Teste (new C ());
        Teste b2 = new Teste (new PC (new Outro () ) );
        
        b1.open () ;
        b2.open () ;
    }
}