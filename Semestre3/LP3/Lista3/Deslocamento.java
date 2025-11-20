public class Deslocamento extends Evento{
    public Deslocamento(String nome, double duracao){
        super(nome, duracao);
    }

    @Override
    public void exibirDetalhes(){
        System.out.println("-> Desclocamento: " + getNome() + " (" + getDuracaoPrevista() + "h)");
    }
}