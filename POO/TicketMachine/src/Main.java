import java.util.Scanner;

public class Main {

    private static void Menu(){
        System.out.println("1 - Inserir Dinheiro");
        System.out.println("2 - Print Ticket");
        System.out.println("3 - Total");
        System.out.println("4 - Sair");

            System.out.print("ESCOLHA UMA OPCAO: ");
    }

    public static void main(String[] args){

        TicketMachine ticket = new TicketMachine(1500);
            Scanner sc = new Scanner(System.in);
                int input;
                int opc;
     do {
         Menu();
         opc = sc.nextInt();
         switch (opc) {
             case 1:
                 System.out.print("Valor em Dinheiro a ser inserido: ");
                 input = sc.nextInt();

                 ticket.inserirDinheiro(input);
                 System.out.println("-Seu atual saldo e de " + ticket.getSaldo() + " CVE");

             case 2:
                 ticket.imprimirTicket();

             case 3:
                 ticket.getTotal();
         }
     }while(opc != 4);
    }
}
