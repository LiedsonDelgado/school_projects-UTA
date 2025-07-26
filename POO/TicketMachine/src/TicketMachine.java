public class TicketMachine {
    public int preco;
    public int saldo;
    public int total;

    public TicketMachine(int valor) {
        this.preco = valor;
        this.saldo = 0;
        this.total = 0;
    }

    public int getPreco() {
        return preco;
    }

    public int getSaldo() {
        return saldo;
    }

    public int getTotal() {
        return total;
    }

    public int devolverDinheiro(){
        int valordevolucao = saldo;
            saldo = 0;
                return valordevolucao;
    }

    public String toString() {
        return "[" +"preco =" +preco +"CVE" +", saldo=" +saldo +"CVE" +", total=" +total +"CVE" +"]";
    }

    //-----------------------------------------------------------------------------------------

    public void inserirDinheiro(int valor){
        if(valor > 0){
            saldo += valor;
        }else{
            System.out.println("O valor " +valor +" e invalido");
        }
    }

    public void imprimirTicket(){
        if(saldo >= preco){
            System.out.println("-------------------------");
            System.out.println("CV INTER ILHAS");
            System.out.println("TICKET");
            System.out.println("-"  +preco +" CVE");
            System.out.println("-------------------------");
            System.out.println(saldo);

           int troco = saldo - preco;

                if(troco > 0){
                    System.out.println("-O seu troco e de " + troco + " CVE");
                        total = (saldo+total)-troco;
                            saldo = 0;
                }

            }else{
                int restante = preco - saldo;
                System.out.println("-Ainda falta " +restante +" CVE");
             }
    }
}
