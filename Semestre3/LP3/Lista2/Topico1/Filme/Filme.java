package Filme;

public class Filme{
    // atributos
    private String titulo;
    private String diretor;
    private int duracao;

    // construtores
    public Filme(String titulo, String diretor, int duracao){
        this.titulo = titulo;
        this.diretor = diretor;
        this.duracao = duracao;
    }

    // getters - não recebe parametro e retorna atributos
    public String getTitulo(){
        return this.titulo;
    }

    public String getDiretor(){
        return this.diretor;
    }

    public int getDuracao(){
        return this.duracao;
    }

    // setters - recebe parametros para mudar os atributos
    public void setTitulo(String novoTitulo){
        this.titulo = novoTitulo;
    }

    public void setDiretor(String novoDiretor){
        this.diretor = novoDiretor;
    }

    public void setDuracao(int novaDuracao){
        this.duracao = novaDuracao;
    }
}