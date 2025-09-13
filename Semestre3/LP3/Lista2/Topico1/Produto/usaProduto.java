package Produto;

public class usaProduto{
    public static void main(String[] args){
        // duas instancia da classe Produto 
        Produto produto1 = new Produto();
        Produto produto2 = new Produto("Feijão", 5.76f);

        // exibindo os preços antes e depois do desconto
        produto1.exibir_preco();
        produto1.aplicar_desconto(10);
        produto1.exibir_preco();

        System.out.println("---------------");

        produto2.exibir_preco();
        produto2.aplicar_desconto(60);
        produto2.exibir_preco();
    }
}