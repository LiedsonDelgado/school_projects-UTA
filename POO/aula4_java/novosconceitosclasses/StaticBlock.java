public class StaticBlock{
    public static double f1;
    public static double f2;

    static{
        f1 = Math.sqrt(2.0);
        f2 = Math.sqrt(4.0);
    }

    public StaticBlock(String msg){
        System.out.println(msg);
        System.out.println(f1);
        System.out.println(f2);
    }
}