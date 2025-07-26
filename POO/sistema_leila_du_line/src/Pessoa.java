public class Pessoa{
    private String name;
    private String number;

    //Constructor Pessoa
    public Pessoa(String p_name,String p_number){
        this.name = p_name;
        this.number = p_number;
    }

    //Getters
    public String getName(){
        return name;
    }

    public String getNumber(){
        return number;
    }
}