public class Exemplo{
    public static void main(String[] args) {
        int v[] = {1,2,3,4,5};

        try{
            for(int i = 0;i < v.length+1;i++){
                System.out.println(v[i]);
            }
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Erro ao aceder indice invalido!");
        }
    }
}