package Retangulo;

public class usaRetangulo{
    public static void main(String[] args){
        Retangulo ret1 = new Retangulo(1.5f, 2.5f);
        Retangulo ret2 = new Retangulo();
        System.out.println("Área do retângulo é " + ret1.calcular_area());
        System.out.println("Área do retângulo é " + ret2.calcular_area());
    }
}