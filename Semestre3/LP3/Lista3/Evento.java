public abstract class Evento{
    private String nome;
    private double duracaoPrevista;
    private static int totalEventos = 0;

    public Evento(String nome, double duracaoPrevista){
        this.nome = nome;
        this.duracaoPrevista = duracaoPrevista;
        totalEventos++;
    }

    public double getDuracaoPrevista(){
        return this.duracaoPrevista;
    }

    public static int getTotalEventos(){
        return totalEventos;
    }

    public String getNome(){
        return this.nome;
    }

    // metodo abstract (o filho deve implementar)
    public abstract void exibirDetalhes();
}