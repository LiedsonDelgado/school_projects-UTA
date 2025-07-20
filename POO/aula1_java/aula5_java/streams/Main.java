public class Main{
    public static void main(String[] args){
        AnimalMonitor am = new AnimalMonitor();
        am.addSightings("sightings.csv");
        am.printList();
    }
}