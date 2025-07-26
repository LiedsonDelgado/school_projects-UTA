
public class LambdaDemo{
    public static void main(String[] args) {
        MyValue myVal;
        myVal = () -> 98.6;

        MyParamValue myPval;
        myPval = (n) -> 1.0/n;

        MyParamValue myParamValue;
        myParamValue = (x) -> Math.sqrt(x);

        System.out.println("O valor: " +myVal.getValue());
        System.out.println("Inverso de 4: " +myPval.getValue(4.0));
        System.out.println("Raiz Quadrada de " +myParamValue +":" +myParamValue.getValue(4.0));
    }
}