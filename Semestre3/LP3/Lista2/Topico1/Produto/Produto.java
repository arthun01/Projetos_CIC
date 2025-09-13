package Produto;

public class Produto{
    // atributos
    private String nome;
    private float preco;

    // construtores
    public Produto(){
        System.out.println("Não foi declarado um nome nem o preço!");
        return ;
    }

    public Produto(String nome, float preco){
        this.nome = nome;
        this.preco = preco;
    }

    // getters
    public String getNome(){
        return this.nome;
    }

    public float getPreco(){
        return this.preco;
    }

    // setters
    public void setNome(String novoNome){
        this.nome = novoNome;
    }

    public void setPreco(float novoPreco){
        this.preco = novoPreco;
    }

    // métodos
    // método que aplica o desconto sobre o preço
    public void aplicar_desconto(int percentual){
        float percentual_decimal = percentual / 100f;
        this.preco = (this.preco - (this.preco * percentual_decimal));
    }

    // método que exibe o nome do produto e o seu preço atual
    public void exibir_preco(){
        System.out.printf("Produto: %s, Preço: %.2f\n", this.nome, this.preco);
    }
}