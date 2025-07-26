public class Lance{
    private int value;
    private Pessoa person;

    public Lance(int p_value,Pessoa p_person){
        this.value = p_value;
        this.person = p_person;
    }

    //Getters
    public int getValue(){
        return value;
    }

    public Pessoa getLicitador(){
        return person;
    }

    //Setters
    public void setValue(int v){ //v-value parameter do setter
        this.value = v;
    }

    public void setLicitador(Pessoa p){ //p-person parameter do setter
        this.person = p;
    }
}