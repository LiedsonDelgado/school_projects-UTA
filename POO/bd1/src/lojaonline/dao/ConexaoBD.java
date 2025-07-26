package lojaonline.dao;
import java.io.IOException;

import java.sql.*;
import java.util.Properties;
import java.io.InputStream;
import java.io.FileInputStream;

public class    ConexaoBD {
    private static Connection conexao = null;

    private ConexaoBD() {}

    public static Connection getConexao() throws SQLException, IOException {
        if (conexao == null || conexao.isClosed()) {
            try (InputStream input = new FileInputStream("src/resources/database.properties")) {
                Properties prop = new Properties();
                prop.load(input);

                String url = prop.getProperty("db.url");
                String user = prop.getProperty("db.user");
                String password = prop.getProperty("db.password");

                conexao = DriverManager.getConnection(url, user, password);
            }
        }
        return conexao;
    }

    public static void fecharConexao() {
        try {
            if (conexao != null && !conexao.isClosed()) {
                conexao.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
