public class Lote{
    private int n; //numero do lote
    private Lance highest_bid;
    private String description;

    public Lote(int p_n,String p_description){
        this.n = p_n;
        this.highest_bid = null;
        this.description = p_description;
    }

    //Getters
    public int getN(){ //getter do numero do lote
        return n;
    }

    public Lance getHighestBid(){
        return highest_bid;
    }

    public String getDescription(){
        return description;
    }

    //Setters
    public void setN(int p_n){ //setter do numero do lote & parameter n
        this.n = p_n;
    }

    public void setHighestBid(Lance p_h_b){ //setter do numero do lote & p_h_b-parameter highest bid
        this.highest_bid = p_h_b;
    }

    public void setDescription(String p_d){ //setter do numero do lote & p_d-parameter description
        this.description = description;
    }

    //Instance Methods
    public boolean makeHighestBid(Lance p_bid){
        if(highest_bid == null){
            highest_bid = p_bid;
            return true;
        }else if(p_bid.getValue() < highest_bid.getValue()){
            highest_bid = p_bid;
            return true;
        }else{
            return false;
        }
    }

    public String toString(){
        String details = n +": " +description;
        if(highest_bid != null){
            details += "  Lance: " +highest_bid.getValue();
        }else{
            details += "  Sem Lances Registrado";
        }
        return details;
    }
}