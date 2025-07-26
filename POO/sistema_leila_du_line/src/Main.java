public class Main{
    public static void main(String[] args) {
        Leilao newLeilao = new Leilao();
        Pessoa newPerson = new Pessoa("Liedson","+238 9322743");

            newLeilao.addLot("ACER NITRO 5");
            newLeilao.addLot("iPhone 11 Pro");
            newLeilao.addLot("PS5 Pro");

            newLeilao.listarLotes();
            newPerson.getName();
            newPerson.getNumber();

    }
}