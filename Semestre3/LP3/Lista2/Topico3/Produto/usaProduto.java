package Produto;

public class usaProduto{
    public static void main(String[] args){
        Produto p1 = new Produto("Feijão", 4.56f);
        Produto p2 = new Produto("Arroz", 3.54f);

        p1.exibir_detalhes();
        p2.exibir_detalhes();
    }
}
