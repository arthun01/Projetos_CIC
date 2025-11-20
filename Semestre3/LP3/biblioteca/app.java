// package Biblioteca;
public class app {
    public static void main(String[] args){
        Biblioteca minha_Biblioteca = new Biblioteca();

        // testes fodas
        minha_Biblioteca.adicionar_livro("Harry Potter", "J.K. Rolling", 2001);
        minha_Biblioteca.adicionar_livro("Harry Potter 2", "J.K. Rolling", 2004);
        minha_Biblioteca.adicionar_livro("Harry Potter 3", "J.K. Rolling", 2006);
        System.out.println("------------");

        minha_Biblioteca.listar_livros();
        System.out.println("------------");

        minha_Biblioteca.cadastrar_membro("Arthur Ramos Vieira");
        minha_Biblioteca.cadastrar_membro("Thales Ramos Vieira");
        minha_Biblioteca.cadastrar_membro("José Vieira Santos");
        System.out.println("------------");
        minha_Biblioteca.listar_membros();
    }
}
