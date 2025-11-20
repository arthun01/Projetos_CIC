public abstract class Evento{
    // atributos
    private String nome;
    private double duracaoPrevista;

    // construtor
    public Evento(String nome, double duracaoPrevista){
        this.nome = nome;
        this.duracaoPrevista = duracaoPrevista;
    }

    // getters
    public double getDuracao(){
        return this.duracaoPrevista;
    }

    public String getNome(){
        return nome;
    }

    // método abstract
    public abstract void descricao();
}