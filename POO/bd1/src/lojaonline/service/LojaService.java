package lojaonline.service;

import lojaonline.dao.*;
import lojaonline.model.*;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

public class LojaService {
    private ClienteDAO clienteDAO;
  //  private ProdutoDAO produtoDAO;
  //  private CarrinhoDAO carrinhoDAO;

    public LojaService() {
        this.clienteDAO = new ClienteDAO();
    //    this.produtoDAO = new ProdutoDAO();
    //    this.carrinhoDAO = new CarrinhoDAO();
    }

    public void cadastrarCliente(Cliente cliente) throws SQLException, IOException {
        clienteDAO.inserir(cliente);
    }

  /*  public List<Produto> listarProdutosDisponiveis() throws SQLException {
        return produtoDAO.listarDisponiveis();
    }

    public void adicionarAoCarrinho(int idCliente, int idProduto, int quantidade) throws SQLException {
        // Lógica para adicionar item ao carrinho
    }

    // Outros métodos de negócio */

}
