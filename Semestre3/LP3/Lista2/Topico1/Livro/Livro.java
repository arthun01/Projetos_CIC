package Livro;

public class Livro{
    // atributos
    private String titulo;
    private String autor;
    private int ano;

    // construtores
    public Livro(String titulo, String autor, int ano){
        if(titulo != null){
            this.titulo = titulo;
        }else{
            System.out.println("O título não pode ser nulo ou vazio.\n");
            return ;
        }

        if(autor != null){
            this.autor = autor;
        }else{
            System.out.println("O autor não pode ser nulo ou vazio.\n");
            return ;
        }

        if(ano >= 1900 || ano <= 2025){
            this.ano = ano;
        }else{
            System.out.println("O ano não pode ser menor que 1900 ou maior que 2025.\n");
            return ;
        }
    }

    public Livro(){
        this.titulo = "indef";
        this.autor = "autor indef";
        this.ano = 1900;
    }

    // getters
    public String getTitulo(){
        return this.titulo;
    }

    public String getAutor(){
        return this.autor;
    }

    public int getAno(){
        return this.ano;
    }

    // setters
    public void setTitulo(String novoTitulo){
        this.titulo = novoTitulo;
    }

    public void setAutor(String novoAutor){
        this.autor = novoAutor;
    }

    public void setAno(int novoAno){
        this.ano = novoAno;
    }

    // reescrevendo o toString
    @Override
    public String toString(){
        return "-------------\nTítulo: " + this.titulo + "\nAutor: " + this.autor + "\nAno: " + this.ano + ".\n-------------";
    }
}