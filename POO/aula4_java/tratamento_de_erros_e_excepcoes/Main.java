import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner sc1 = new Scanner(System.in);
        String fileName;
        
        System.out.print("Digite o nome do ficheiro: ");
        fileName = sc1.next();

        try {
            readFile(fileName);
        }catch(FileNotFoundException e){
            throw new RuntimeException(e);
        }
    }

    private static void readFile(String fname) throws FileNotFoundException{
        File ficheiroInput = new File(fname);
        try{
            Scanner sc2 = new Scanner(ficheiroInput);
        }catch(FileNotFoundException e){
            throw new RuntimeException(e);
        }
    }
}