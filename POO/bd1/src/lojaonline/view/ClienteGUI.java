package lojaonline.view;


import lojaonline.dao.ClienteDAO;
import lojaonline.model.Cliente;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

public class ClienteGUI extends JFrame {
    private JTable tabelaClientes;
    private JButton btnCarregar;
    private JButton btnAdicionar;
    private JButton btnAtualizar;
    private JButton btnRemover;

    public ClienteGUI() {
        setTitle("Gestão de Clientes");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        initComponents();
        layoutComponents();
    }

    private void initComponents() {
        tabelaClientes = new JTable();
        btnCarregar = new JButton("Carregar Clientes");
        btnAdicionar = new JButton("Adicionar");
        btnAtualizar = new JButton("Atualizar");
        btnRemover = new JButton("Remover");

        // Configurar ações dos botões
        btnCarregar.addActionListener(e -> carregarClientes());
        btnAdicionar.addActionListener(e -> mostrarFormularioCliente(null));
        btnAtualizar.addActionListener(e -> {
            try {
                atualizarCliente();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });
        btnRemover.addActionListener(e -> {
            try {
                removerCliente();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });
    }

    private void layoutComponents() {
        JPanel painelBotoes = new JPanel();
        painelBotoes.add(btnCarregar);
        painelBotoes.add(btnAdicionar);
        painelBotoes.add(btnAtualizar);
        painelBotoes.add(btnRemover);

        JScrollPane scrollPane = new JScrollPane(tabelaClientes);

        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(painelBotoes, BorderLayout.NORTH);
        getContentPane().add(scrollPane, BorderLayout.CENTER);
    }

    private void carregarClientes() {
        try {
            ClienteDAO clienteDAO = new ClienteDAO();
            List<Cliente> clientes = clienteDAO.listarTodos();

            DefaultTableModel model = new DefaultTableModel();
            model.addColumn("ID");
            model.addColumn("Nome");
            model.addColumn("Email");
            model.addColumn("Telefone");
            model.addColumn("Endereço");

            for (Cliente cliente : clientes) {
                model.addRow(new Object[]{
                        cliente.getId(),
                        cliente.getNome(),
                        cliente.getEndereco(),
                        cliente.getTelefone()

                });
            }

            tabelaClientes.setModel(model);
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this,
                    "Erro ao carregar clientes: " + ex.getMessage(),
                    "Erro", JOptionPane.ERROR_MESSAGE);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private void mostrarFormularioCliente(Cliente cliente) {
        JDialog dialog = new JDialog(this, "Formulário de Cliente", true);
        dialog.setSize(400, 300);
        dialog.setLayout(new GridLayout(6, 2));

        JTextField txtNome = new JTextField();
        JTextField txtEmail = new JTextField();
        JTextField txtTelefone = new JTextField();
        JTextField txtEndereco = new JTextField();
        JTextField txtIdUtilizador = new JTextField();

        if (cliente != null) {
            txtNome.setText(cliente.getNome());
            txtEndereco.setText(cliente.getEndereco());
            txtTelefone.setText(cliente.getTelefone());
        }

        dialog.add(new JLabel("Nome:"));
        dialog.add(txtNome);
        dialog.add(new JLabel("Endereço:"));
        dialog.add(txtEndereco);
        dialog.add(new JLabel("Telefone:"));
        dialog.add(txtTelefone);


        JButton btnSalvar = new JButton("Salvar");
        btnSalvar.addActionListener(e -> {
            try {
                Cliente novoCliente = new Cliente();
                novoCliente.setNome(txtNome.getText());
                novoCliente.setEndereco(txtEndereco.getText());
                novoCliente.setTelefone(txtTelefone.getText());



                ClienteDAO clienteDAO = new ClienteDAO();
                if (cliente == null) {
                    clienteDAO.inserir(novoCliente);
                } else {
                    novoCliente.setId(cliente.getId());
                    // Implemente o método atualizar no DAO
                    // clienteDAO.atualizar(novoCliente);
                }

                carregarClientes();
                dialog.dispose();
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(dialog,
                        "Erro: " + ex.getMessage(),
                        "Erro", JOptionPane.ERROR_MESSAGE);
            }
        });

        dialog.add(btnSalvar);
        dialog.setVisible(true);
    }

    private void atualizarCliente() throws IOException {
        int linhaSelecionada = tabelaClientes.getSelectedRow();
        if (linhaSelecionada == -1) {
            JOptionPane.showMessageDialog(this,
                    "Selecione um cliente para atualizar",
                    "Aviso", JOptionPane.WARNING_MESSAGE);
            return;
        }

        int id = (int) tabelaClientes.getValueAt(linhaSelecionada, 0);
        try {
            ClienteDAO clienteDAO = new ClienteDAO();
            Cliente cliente = clienteDAO.buscarPorId(id);
            mostrarFormularioCliente(cliente);
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this,
                    "Erro ao buscar cliente: " + ex.getMessage(),
                    "Erro", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void removerCliente() throws IOException {
        int linhaSelecionada = tabelaClientes.getSelectedRow();
        if (linhaSelecionada == -1) {
            JOptionPane.showMessageDialog(this,
                    "Selecione um cliente para remover",
                    "Aviso", JOptionPane.WARNING_MESSAGE);
            return;
        }

        int confirmacao = JOptionPane.showConfirmDialog(this,
                "Tem certeza que deseja remover este cliente?",
                "Confirmar", JOptionPane.YES_NO_OPTION);

        if (confirmacao == JOptionPane.YES_OPTION) {
            int id = (int) tabelaClientes.getValueAt(linhaSelecionada, 0);
            try {
                ClienteDAO clienteDAO = new ClienteDAO();
                clienteDAO.remover(id);
                carregarClientes();
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(this,
                        "Erro ao remover cliente: " + ex.getMessage(),
                        "Erro", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            ClienteGUI gui = new ClienteGUI();
            gui.setVisible(true);
        });
    }
}