public class D extends C{
    private int d;

    public D(){
        d = 2;
    }

    @Override
    public int daVal(){
        return d;
    }

    @Override
    public void metd(){
        d = (d*10)+3;
    }
}