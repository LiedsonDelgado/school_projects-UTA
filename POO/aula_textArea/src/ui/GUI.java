package ui;

import javax.swing.*;
import java.awt.*;
import java.util.*;

public class GUI extends JFrame{
    private JLabel taskLabel;
    private JTextField textInput;
    private JList<String> activityArea;
    public DefaultListModel<String> aux;

    //GUI Constructor
    public GUI(){
        super("Gerenciadores de Tarefas Simples");
        taskLabel = new JLabel("Tarefa: ");
        textInput = new JTextField();
        aux = new DefaultListModel<>();
        activityArea = new JList<>(aux);

        setSize(800,600);
        setLayout(new BorderLayout(10,10));
        activityArea.setEnabled(true);
        activityArea.setBackground(new Color(0, 179, 124));

        JButton add = new JButton("Adicionar");
        add.addActionListener(e -> addTask());

        JButton remove = new JButton("Remover Selecionada");
        remove.addActionListener(e ->removeSelectedTask());

        JButton clear = new JButton("Limpar Tudo");
        clear.addActionListener(e ->clearAllTasks());

        JPanel buttonArea = new JPanel();
        buttonArea.add(add);
        buttonArea.add(remove);
        buttonArea.add(clear);

        JPanel enter = new JPanel(new BorderLayout());
        enter.add(taskLabel,BorderLayout.WEST);
        enter.add(textInput,BorderLayout.CENTER);

        add(buttonArea,BorderLayout.SOUTH);
        add(enter,BorderLayout.NORTH);
        add(activityArea,BorderLayout.CENTER);

        setVisible(true);
    }

    //Methods
    public void addTask(){
        String newTask = (String) textInput.getText();
        aux.addElement(newTask);
        activityArea.getModel();
        textInput.setText("");
    }

    public void removeSelectedTask(){
        String selected = activityArea.getSelectedValue();
        aux.removeElement(selected);
        activityArea.getModel();
    }

    public void clearAllTasks(){
        aux.removeAllElements();
    }
}