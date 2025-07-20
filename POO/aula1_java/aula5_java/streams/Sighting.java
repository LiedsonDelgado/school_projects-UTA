/**
 * Detalhes da observação de um tipo de animal por um determinado observador.
 * 
 * @author David J. Barnes e Michael Kölling
 * @version 2016.02.29
 */
public class Sighting
{
    // O animal avistado.
    private final String animal;
    // O ID do observador.
    private final int spotter;
    // Quantos foram avistados.
    private final int count;
    // O ID da área onde foram avistados.
    private final int area;
    // O período de registo.
    private final int period;
    
    /**
     * Cria um registo de uma observação de um determinado tipo de animal.
     * @param animal O animal avistado.
     * @param spotter O ID do observador.
     * @param count Quantidade avistada (>= 0).
     * @param area O ID da área onde foram avistados.
     * @param period O período de registo.
     */
    public Sighting(String animal, int spotter, int count, int area, int period)
    {
        this.animal = animal;
        this.spotter = spotter;
        this.count = count;
        this.area = area;
        this.period = period;
    }

    /**
     * Devolve o tipo de animal avistado.
     * @return O tipo de animal.
     */
    public String getAnimal() 
    {
        return animal;
    }

    /**
     * Devolve o ID do observador.
     * @return O ID do observador.
     */
    public int getSpotter() 
    {
        return spotter;
    }

    /**
     * Devolve quantos foram avistados.
     * @return A quantidade avistada.
     */
    public int getCount() 
    {
        return count;
    }

    /**
     * Devolve o ID da área onde foram avistados.
     * @return A área de avistamento.
     */
    public int getArea() 
    {
        return area;
    }

    /**
     * Devolve o período em que foram avistados.
     * @return O período de registo.
     */
    public int getPeriod() 
    {
        return period;
    }

    /**
     * Devolve uma string com os detalhes do animal, a quantidade avistada,
     * a área, o observador e o período.
     * @return Uma string com os detalhes da observação.
     */
    public String getDetails() 
    {
        return animal + 
               ", quantidade = " + count + 
               ", área = " + area + 
               ", observador = " + spotter + 
               ", período = " + period;
    }
}

