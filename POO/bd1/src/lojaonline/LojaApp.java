package lojaonline;

import lojaonline.dao.ConexaoBD;
import lojaonline.model.Cliente;
import lojaonline.service.LojaService;

import java.io.IOException;
import java.sql.SQLException;

public class LojaApp {
    public static void main(String[] args) {
        try {
            LojaService lojaService = new LojaService();

            // Exemplo de uso
            Cliente novoCliente = new Cliente();
            novoCliente.setNome("João Silva");
            novoCliente.setEndereco("Rua Exemplo, 123");
            novoCliente.setTelefone("(11) 99999-9999");

            lojaService.cadastrarCliente(novoCliente);
            System.out.println("Cliente cadastrado com sucesso!");

        } catch (SQLException e) {
            System.err.println("Erro na operação com o banco de dados:");
            e.printStackTrace();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            ConexaoBD.fecharConexao();
        }
    }
}