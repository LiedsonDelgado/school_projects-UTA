public class Outer{
    int numeros[];

    //Outer Constructor
    public Outer(int n[]){
        numeros = n;
    }

    //Methods
    public void detValores(){
        Inner inObj = new Inner();
        System.out.println("Maximo: " +inObj.valMax());
        System.out.println("Minimo: " +inObj.valMin());
        System.out.println("Media: " +inObj.valMid());
    }

    class Inner{
       int valMax(){
            int n = numeros[0];
            for(int i=1;i<numeros.length;i++){
                if(numeros[i] > n){
                    n = numeros[i];
                }
            }
                return n;
        }

        int valMin(){
            int n = numeros[0];
            for(int i=1;i<numeros.length;i++){
                if(numeros[i] < n){
                    n = numeros[i];
                }
            }
            return n;
        }

        double valMid(){
            int tam = numeros.length;
            double mid = 0;
            int soma = 0;

            for(int i=0;i<tam;i++){
                soma+=numeros[i];
            }
            mid = (double)(soma/tam);

            return mid;
        }
    }
}