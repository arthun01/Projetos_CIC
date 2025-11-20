// Arthur Ramos Vieira
// N° de matrícula: 202420022
public class UsaPolinomio{
    public static void main(String[] args){
        double[] cofs = {-1, 3, 2};

        Polinomio p1 = new Polinomio(cofs);

        System.out.println("P(0) = " + p1.avaliar(0));
        System.out.println("P(1) = " + p1.avaliar(1));
        System.out.println("P(2) = " + p1.avaliar(2));
        System.out.println("P(3) = " + p1.avaliar(3));

        p1.exibir();
        System.out.println("----------------");

        // -------------------

        Polinomio p2 = new Polinomio(5);
        
        System.out.println("P(0) = " + p2.avaliar(0));
        System.out.println("P(1) = " + p2.avaliar(1));
        System.out.println("P(2) = " + p2.avaliar(2));
        System.out.println("P(3) = " + p2.avaliar(3));

        p2.exibir();
        System.out.println("----------------");

        // --------------------

        double[] novos_cofs = {-10, 21, 54, 32, 12};

        Polinomio p3 = new Polinomio(novos_cofs);

        System.out.println("P(0) = " + p3.avaliar(0));
        System.out.println("P(1) = " + p3.avaliar(1));
        System.out.println("P(2) = " + p3.avaliar(2));
        System.out.println("P(3) = " + p3.avaliar(3));

        p3.exibir();
        System.out.println("----------------");

        System.out.printf("Total de Polinômios: %d\n", Polinomio.getTotalPolinomios());
    }
}