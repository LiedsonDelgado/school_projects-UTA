public class Teste {
    private Algo _thing ;
    
    public Teste ( Algo t ) {
    _thing =t;
    }
    public void open(){
        System.out.println(" Abriu a caixa e esta contém " +this) ;
    }
        public String toString () {
        return _thing.toString () ;
    }
}