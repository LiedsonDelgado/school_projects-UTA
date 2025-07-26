public class B extends A{
    private int b;

    public B(){
        b = 2;
    }

    @Override
    public int daVal(){
        return b;
    }

    @Override
    public void metd(){
        b += 20;
    }
}