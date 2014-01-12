package haikuvm.bench.from.darjeeling;

public class Darjeeling {

    public static void assertTrue(int i, boolean b) {
        if (b) {
            System.out.println("Darjeeling.assertTrue("+i/100+", "+i%100+") passed");
        } else {
            System.out.println("Darjeeling.assertTrue("+i/100+", "+i%100+") failed !!");
        }
    }

}
