package Produto;

public class Produto {
    private String nome;
    private float preco;

    public Produto(String nome, float preco){
        this.nome = nome;
        this.preco = preco;
    }

    public void exibir_detalhes(){
        System.out.printf(this.nome);
        System.out.println(": R$" + this.preco);
    }
}
