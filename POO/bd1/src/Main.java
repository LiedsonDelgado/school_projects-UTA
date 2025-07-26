public class Main {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            System.out.println("Driver carregado!");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
