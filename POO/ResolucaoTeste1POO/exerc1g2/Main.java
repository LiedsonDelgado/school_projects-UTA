public class Main{
    public static void main(String[] args) {
        A a1,a2,a3,a4;

        a1 = new A();
        a2 = new B();
        a3 = new C();
        a4 = new D();

        a1.metd();
        a2.metd();
        a3.metd();
        a4.metd();

        System.out.println("a1.daVal() -> " +a1.daVal());
        System.out.println("a2.daVal() -> " +a2.daVal());
        System.out.println("a3.daVal() -> " +a3.daVal());
        System.out.println("a4.daVal() -> " +a4.daVal());
    }
}