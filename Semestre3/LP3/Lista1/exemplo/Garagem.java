// Esta é a classe que contém o nosso programa principal (o método main).
public class Garagem {

    // A execução do programa SEMPRE começa aqui.
    public static void main(String[] args) {

        System.out.println("### Bem-vindo à Garagem! ###");

        // 1. CRIANDO OBJETOS (Instanciando a classe Carro)
        // Usamos a planta "Carro" para construir nosso primeiro carro.
        // `new Carro(...)` chama o CONSTRUTOR da classe Carro.
        Carro meuFusca = new Carro("Volkswagen", "Fusca");

        // Agora, vamos construir um segundo carro, usando a MESMA planta.
        Carro minhaFerrari = new Carro("Ferrari", "F8");
        
        System.out.println("\n--- Carros criados, mostrando estado inicial ---");
        meuFusca.exibirInformacoes();
        minhaFerrari.exibirInformacoes();


        System.out.println("\n--- Colocando os carros em ação! ---");
        
        // 2. INTERAGINDO COM OS OBJETOS
        // Vamos chamar os métodos de cada objeto.
        
        meuFusca.acelerar(50); // O Fusca acelera.
        minhaFerrari.acelerar(120); // A Ferrari acelera.
        
        meuFusca.frear(10); // O Fusca freia um pouco.

        System.out.println("\n--- Mostrando o estado final dos carros ---");
        meuFusca.exibirInformacoes();
        minhaFerrari.exibirInformacoes();

        System.out.println("------------------------------");
    }
}