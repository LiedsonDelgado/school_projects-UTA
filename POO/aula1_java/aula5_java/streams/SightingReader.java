import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Optional;
import java.util.function.Function;
import java.util.stream.Collectors;

/**
 * Classe para ler registos em formato CSV de relatórios de avistamentos de animais.
 * 
 * @author David J. Barnes e Michael Kölling
 * @version 2016.02.29
 */
public class SightingReader
{
    // Quantidade esperada de campos por linha.
    private static final int NUMBER_OF_FIELDS = 5;
    // Índices dos campos em cada registo.
    private static final int SPOTTER = 0,
                             ANIMAL = 1,
                             COUNT = 2,
                             AREA = 3,
                             PERIOD = 4;
    
    /**
     * Cria um leitor de observações (SightingReader).
     */
    public SightingReader()
    {
    }
    
    /**
     * Lê observações em formato CSV a partir do ficheiro indicado.
     * Devolve uma lista (ArrayList) de objetos Sighting criados com base
     * nas informações contidas no ficheiro.
     * 
     * @param filename O nome do ficheiro a ser lido — deve estar em formato CSV.
     * @return Uma lista de observações (Sightings).
     */
    public ArrayList<Sighting> getSightings(String filename)
    {
        // Cria uma instância de Sighting a partir de uma linha CSV.
        Function<String, Sighting> createSighting = 
            record -> {
                String[] parts = record.split(",");
                if(parts.length == NUMBER_OF_FIELDS) {
                    try {
                        int spotter = Integer.parseInt(parts[SPOTTER].trim());
                        String animal = parts[ANIMAL].trim();
                        int count = Integer.parseInt(parts[COUNT].trim());
                        int area = Integer.parseInt(parts[AREA].trim());
                        int period = Integer.parseInt(parts[PERIOD].trim());
                        return new Sighting(animal, spotter, count, area, period);
                    }
                    catch(NumberFormatException e) {
                        System.out.println("Registo de observação contém um número mal formatado: " + record);
                        return null;
                    }
                }
                else {
                    System.out.println("Registo de observação com número incorreto de campos: " + record);
                    return null;
                }
            };

        ArrayList<Sighting> sightings;
        try {
            sightings = Files.lines(Paths.get(filename))
                             .filter(record -> record.length() > 0 && record.charAt(0) != '#')
                             .map(createSighting)
                             .filter(sighting -> sighting != null)
                             .collect(Collectors.toCollection(ArrayList::new));
        }
        catch(IOException e) {
            System.out.println("Não foi possível abrir o ficheiro: " + filename);
            sightings = new ArrayList<>();
        }
        return sightings;
    }
}

