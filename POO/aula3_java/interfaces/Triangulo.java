public abstract class Triangulo extends FormaGeo implements Forma3D{
    private int a; //a-lado do triangulo
    private int b; //base-b & um dos lados do triangulo
    private int c; //c-lado do triangulo
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
        double area = (p_b*p_h)/2;

        return area;
    }

    public double calcularPerimetro(int p_a,int p_b,int p_c){
        double perimetro = (p_a+p_b+p_c);
        return perimetro;
    }
}