package Carro;

public class usaCarro{
    public static void main(String[] args){
        Carro carro1 = new Carro();
        Carro carro2 = new Carro("Fiat", "Uno", 1998);
        Carro carro3 = new Carro("Chevrolet", "Montana", 2025);

        carro1.exibir_info();
        carro2.exibir_info();
        carro3.exibir_info();
    }
}
