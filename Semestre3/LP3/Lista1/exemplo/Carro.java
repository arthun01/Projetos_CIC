// public class Carro -> Define o início da nossa planta/molde chamado "Carro".
public class Carro {

    // 1. ATRIBUTOS (As características)
    // São as variáveis que cada objeto "Carro" terá.
    // Usamos 'private' para proteger os dados.
    private String marca;
    private String modelo;
    private int velocidadeAtual;

    // 2. CONSTRUTOR (A "linha de montagem")
    // É um método especial que é chamado quando criamos um novo carro.
    // Ele serve para inicializar os atributos.
    public Carro(String marcaDoCarro, String modeloDoCarro) {
        System.out.println("Construindo um carro novo!");
        this.marca = marcaDoCarro;   // 'this.marca' se refere ao atributo da classe.
        this.modelo = modeloDoCarro; // 'modeloDoCarro' é o valor que recebemos.
        this.velocidadeAtual = 0;    // Todo carro começa parado.
    }

    // 3. MÉTODOS (As ações que o carro pode fazer)

    // Um método para acelerar o carro.
    public void acelerar(int aumento) {
        this.velocidadeAtual = this.velocidadeAtual + aumento;
        System.out.println(this.modelo + " acelerou para " + this.velocidadeAtual + " km/h.");
    }

    // Um método para frear o carro.
    public void frear(int reducao) {
        this.velocidadeAtual = this.velocidadeAtual - reducao;
        System.out.println(this.modelo + " freou para " + this.velocidadeAtual + " km/h.");
    }

    // Um método para mostrar as informações atuais do carro.
    public void exibirInformacoes() {
        System.out.println("--- Carro: " + this.marca + " " + this.modelo + " ---");
        System.out.println("Velocidade Atual: " + this.velocidadeAtual + " km/h");
        System.out.println("-------------------------");
    }
}