public class C extends B{
    private int c;

    public C(){
        c = 2;
    }

    @Override
    public int daVal(){
        return c;
    }

    @Override
    public void metd(){
        c += 30;
    }
}