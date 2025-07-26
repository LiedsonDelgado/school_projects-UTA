import java.util.ArrayList;
import java.util.Iterator;

/**
 * Monitoriza contagens de diferentes tipos de animais.
 * As observações são registadas por observadores.
 * 
 * @author David J. Barnes e Michael Kölling
 * @version 2016.02.29 (imperativo)
 */
public class AnimalMonitor 
{
    // Registos de todas as observações de animais.
    private ArrayList<Sighting> sightings;
    
    /**
     * Cria um monitor de animais.
     */
    public AnimalMonitor()
    {
        this.sightings = new ArrayList<>();
    }
    
    /**
     * Adiciona as observações registadas no ficheiro indicado à lista atual.
     * @param filename Um ficheiro CSV com registos de observações.
     */
    public void addSightings(String filename)
    {
        SightingReader reader = new SightingReader();
        sightings.addAll(reader.getSightings(filename));
    }
    
    /**
     * Imprime os detalhes de todas as observações.
     */
    public void printList()
    {
        /*for(Sighting record : sightings) {
            System.out.println(record.getDetails());
        }*/
        sightings.forEach((record) -> System.out.println(record.getDetails()));
    }
    
    /**
     * Imprime os detalhes de todas as observações do animal indicado.
     * @param animal O tipo de animal.
     */
    public void printSightingsOf(String animal)
    {
        /*for(Sighting record : sightings) {
            if(animal.equals(record.getAnimal())) {
                System.out.println(record.getDetails());
            }
        }*/

        sightings.stream().filter(a -> animal.equals(a.getAnimal())).forEach(s -> System.out.println(s.getDetails()));
    }
    
    /**
     * Imprime todas as observações feitas pelo observador indicado.
     * @param spotter O ID do observador.
     */
    public void printSightingsBy(int spotter)
    {
        /*for(Sighting record : sightings) {
            if(record.getSpotter() == spotter) {
                System.out.println(record.getDetails());
            }
        }*/

        sightings.stream().filter(b -> spotter == b.getSpotter()).forEach(s -> System.out.println(s.getDetails()));
    }
    
    public void printSightingDay(int dayID){
        /*for(Sighting record : sightings){
            if(record.getPeriod() == dayID){
                System.out.println(record.getDetails());
            }
        }*/
        sightings.stream().filter(c -> dayID == c.getPeriod()).forEach(s -> System.out.println(s.getPeriod()));
    }

    public void printSightingObs(int obs){
        sightings.stream().filter(s -> s.getCount() < obs).map(d -> obs > d.getCount());
    }

    /**
     * Imprime uma lista dos tipos de animais considerados em perigo.
     * @param animalNames Uma lista de nomes de animais.
     * @param dangerThreshold Contagens inferiores ou iguais a este valor
     *                        são consideradas perigosas.
     */
    public void printEndangered(ArrayList<String> animalNames, int dangerThreshold)
    {
        for(String animal : animalNames) {
            if(getCount(animal) <= dangerThreshold) {
                System.out.println(animal + " está em perigo.");
            }
        }
    }
    
    /**
     * Devolve o número total de observações do animal indicado.
     * @param animal O tipo de animal.
     * @return A contagem de observações do animal indicado.
     */
    public int getCount(String animal)
    {
        int total = 0;
        for(Sighting sighting : sightings) {
            if(animal.equals(sighting.getAnimal())) {
                total = total + sighting.getCount();
            }
        }
        return total;
    }
    
    /**
     * Remove da lista de observações todos os registos com
     * contagem igual a zero.
     */
    public void removeZeroCounts()
    {
        Iterator<Sighting> it = sightings.iterator();
        while(it.hasNext()) {
            Sighting record = it.next();
            if(record.getCount() == 0) {
                it.remove();
            }
        }
    }
    
    /**
     * Devolve uma lista de todas as observações do tipo de animal indicado
     * numa área específica.
     * @param animal O tipo de animal.
     * @param area O ID da área.
     * @return Uma lista de observações.
     */
    public ArrayList<Sighting> getSightingsInArea(String animal, int area)
    {
        ArrayList<Sighting> records = new ArrayList<>();
        for(Sighting record : sightings) {
            if(animal.equals(record.getAnimal())) {
                if(record.getArea() == area) {
                    records.add(record);
                }
            }
        }
        return records;
    }
    
    /**
     * Devolve uma lista de todas as observações do animal indicado.
     * @param animal O tipo de animal.
     * @return Uma lista de todas as observações do animal indicado.
     */
    public ArrayList<Sighting> getSightingsOf(String animal)
    {
        ArrayList<Sighting> filtered = new ArrayList<>();
        for(Sighting record : sightings) {
            if(animal.equals(record.getAnimal())) {
                filtered.add(record);
            }
        }
        return filtered;
    }
}

