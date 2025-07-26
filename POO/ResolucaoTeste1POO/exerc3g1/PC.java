public class PC extends Algo {
    Outro _else ;
    
    public PC (Outro ot){
        _else = ot ;
    }
    public String doIt(){
        return _else.doSomething();
    }
}