public class Triangulo extends FormaGeo{
    private int b; //base-b
    private int h; //altura-h

    //Triangle Constructor
    public Triangulo(String p_forma,int p_b,int p_h){
        super();
        this.b = p_b;
        this.h = p_h;
    }

    //Methods
    @Override
    public String getForma(){
        return forma;
    }

    public int getBase(){
        return b;
    }

    public int getAltura(){
        return h;
    }

    @Override
    public void setForma(String p_forma){
        this.forma = p_forma;
    }

    public void setBase(int p_b){
        this.b = p_b;
    }

    public void setAltura(int p_h){
        this.h = p_h;
    }

    public double calcularArea(int p_b,int p_h){
        double area = ();

        return area;
    }

    public double calcularPerimetro(){
        return 0;
    }
}