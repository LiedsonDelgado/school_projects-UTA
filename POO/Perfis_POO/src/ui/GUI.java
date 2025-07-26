package ui;
import perfis.*;

import javax.swing.*;
import java.awt.*;
import java.util.*;

public class GUI extends JFrame{
    private JList<PessoaUniversidade> listNPCs;
    ArrayList<PessoaUniversidade> filter_aux;
    private JComboBox<String> filter;
    private JTextArea activityArea;
    private DefaultListModel listModel;

    //GUI Constructor
    public GUI(){
        super("University Simulator");
        setSize(new Dimension(800,600));
        setLayout(new BorderLayout());

        listModel = new DefaultListModel<>();
        listNPCs = new JList<>(listModel);
        activityArea = new JTextArea();
        activityArea.setEnabled(false);
        filter_aux = new ArrayList<>();

        String[] opcoes = {"Todos","Professores","Estudantes"};
        filter = new JComboBox<>(opcoes);

        JScrollPane scrollBarList = new JScrollPane(listNPCs);
        JScrollPane scrollBarArea = new JScrollPane(activityArea);

        JButton addButton = new JButton("Adicionar Personagens");
        addButton.addActionListener(e -> addNPcs());

        JButton executeButton = new JButton("Executar");
        executeButton.addActionListener(e -> executeInfo());

        JButton cleanButton = new JButton("Limpar Saida");
        cleanButton.addActionListener(e -> clearInfos());

        filter.addActionListener(e -> Filter());

        JLabel filterText = new JLabel(" Filtro: ");

        JPanel buttonArea = new JPanel(); //Button Container
        buttonArea.add(addButton);
        buttonArea.add(executeButton);
        buttonArea.add(cleanButton);
        buttonArea.add(filterText);
        buttonArea.add(filter);

        add(scrollBarList,BorderLayout.WEST);
        add(scrollBarArea,BorderLayout.CENTER);
        add(buttonArea,BorderLayout.NORTH);

        setVisible(true);
    }

    private void executeInfo(){
        PessoaUniversidade selected = listNPCs.getSelectedValue();
            activityArea.setText(selected.realizarAtividade());
    }

    private void Filter(){
        String filterType = (String)filter.getSelectedItem();
        listModel.removeAllElements();

        for(PessoaUniversidade p : filter_aux){
            String className = p.getClass().getSimpleName();
            if(filterType.equals("Todos")
            || filterType.equals("Professores") && getClass().getSimpleName().startsWith("Professor")
            || filterType.equals("Estudantes") && getClass().getSimpleName().startsWith("Estudante")
            ){
                listModel.addElement(p);
            }
        }
    }



    private void clearInfos(){
        listModel.clear();
        //ou
        //listModel.removeAllElements();
        activityArea.setText("");
    }

    private void addNPcs(){
        listModel.addElement(new EstudanteEsperto("Liedson Delgado"));
        listModel.addElement(new EstudantePreguicoso("Joelner Monteiro"));
        listModel.addElement(new EstudanteFestas("Tiago Brito"));
        listModel.addElement(new ProfessorExigente("Sidnei Cruz"));

        filter_aux.add(new EstudanteEsperto("Liedson Delgado"));
        filter_aux.add(new EstudantePreguicoso("Joelner Monteiro"));
        filter_aux.add(new EstudanteFestas("Tiago Brito"));
        filter_aux.add(new ProfessorExigente("Sidnei Cruz"));
    }
}
