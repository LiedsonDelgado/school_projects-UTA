import java.sql.*;

public class TesteConexao {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/sakila";
        String user = "root";
        String psswrd = "cisco@2020";

        try(Connection conn = DriverManager.getConnection(url,user,psswrd)){
            System.out.println("Conexao estabelelicada com sucesso!");
            Statement stmnt = conn.createStatement();
            ResultSet rslt = stmnt.executeQuery("select * from actor");
        }catch(SQLException error){
            System.out.println("Erro: " + error.getMessage());
        }
    }
}
