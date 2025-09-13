package Livro;

public class usaLivro{
    public static void main(String[] args){
        // declaração do array de 3 espaços
        Livro[] livros = new Livro[3];

        // instanciando as classes
        livros[0] = new Livro("Código Limpo: Habilidades Práticas do Agile Software", "Robert C. Martin", 2009);
        livros[1] = new Livro("Entendendo Algoritmos", "Aditya Y. Bhargava", 2017);
        livros[2] = new Livro("Treinamento em Linguagem C", "Victorine Viviane Mizrahi", 2015);

        // laço de repetição para saida dos títulos
        for(int i = 0; i < 3; i++){
            System.out.println("Livro " + (i + 1) + ": " + livros[i].getTitulo());
        }
    }
}