public abstract class Quadrado extends FormaGeo implements Forma3D{
    private int l; //l-lado do quadrado

    //Quadrado Constructor
    public Quadrado(String p_forma,int p_l){
        super();
        this.l = p_l;
    }

    //Methods
    @Override
    public String getForma(){
        return forma;
    }

    public int getLado(){
        return l;
    }

    @Override
    public void setForma(String p_forma){
        this.forma = p_forma;
    }

    public void setBase(int p_l){
        this.l = p_l;
    }

    public double calcularArea(int p_l){
        double area = (p_l*p_l);

        return area;
    }

    public double calcularPerimetro(int p_l){
        double perimetro = (4*p_l);
        return perimetro;
    }
}