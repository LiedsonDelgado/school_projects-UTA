import javax.swing.*;
import java.util.ArrayList;
import java.util.HashMap;

public class Main{
    public static void main(String[] args) {
        SwingUtilities.invokeLater(()->new gui());
        HashMap<String,String>carModel = new HashMap<>();
        carModel.put("Ford","Raptor");
        carModel.put("BMW","M3 GTR");
        carModel.put("Ferrari","F40");

        System.out.println(carModel);
        System.out.println(carModel.get("Ford"));
    }
}