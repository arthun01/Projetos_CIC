package Pessoa;

public class Pessoa{
    // atributos privados
    private String nome;
    private int idade;

    // construtores
    public Pessoa(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }

    public Pessoa(){
        this.nome = "Indefinido";
        this.idade = 100;
    }

    // getters
    public String getNome(){
        return this.nome;
    }

    public int getIdade(){
        return this.idade;
    }

    // setters
    public void setNome(String novoNome){
        this.nome = novoNome;
    }

    public void setIdade(int novoIdade){
        this.idade = novoIdade;
    }

    // rescreevendo o toString
    @Override
    
    public String toString(){
        return("[Nome: " + this.nome + " | " + "Idade: " + this.idade + "]");
    }
}