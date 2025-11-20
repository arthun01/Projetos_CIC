// package Biblioteca;

public class Biblioteca{
    private Livro livros[] = new Livro[10];
    private Membro membros[] = new Membro[10];
    private int vaziolivro = 0;
    private int vaziomembro = 0;

    public Biblioteca(){
        for(int i = 0; i < livros.length; i++){
            if(livros[i] == null){
                vaziolivro = i;
                break;
            }
        }

        for(int j = 0; j < membros.length; j++){
            if(membros[j] == null){
                vaziomembro = j;
                break;
            }
        }
    }

    // metodo para achar o indicec vazio se necessário
    public int getVazioLivro(){
        return vaziolivro;
    }

    public int getVazioMembro(){
        return vaziomembro;
    }

    public void adicionar_livro(String titulo, String autor, int ano_de_lancamento){
        Livro novo_livro = new Livro(titulo, autor, ano_de_lancamento);

        livros[getVazioLivro()] = novo_livro;

        System.out.printf("O livro '%s' foi adicionado com sucesso!!\n", novo_livro.getTitulo());

        this.vaziolivro += 1;
    }

    public void cadastrar_membro(String nome){
        Membro novo_membro = new Membro(nome);

        membros[getVazioMembro()] = novo_membro;

        System.out.printf("Membro '%s' cadastrado com sucesso!!\n", novo_membro.getNome());

        this.vaziomembro += 1;
    }

    // método para listar todos os livros do array
    public void listar_livros(){
        for(int i = 0; i < livros.length; i++){
            if(livros[i] != null){
                System.out.printf("Título: %s\nAutor: %s\nAno de Lançamento: %d\nDisponibilidade: %s\n", livros[i].getTitulo(), livros[i].getAutor(), livros[i].getAno(), livros[i].getDisponive());
                System.out.println("--------------------------------------------");
            }
        }
    }

    public void listar_membros(){
        for(int i = 0; i < membros.length; i++){
            if(membros[i] != null){
                System.out.printf("Membro: '%s' (ID: %d)\n", membros[i].getNome(), membros[i].getId());
                System.out.println("--------------------------------------------");
            }
        }
    }
}