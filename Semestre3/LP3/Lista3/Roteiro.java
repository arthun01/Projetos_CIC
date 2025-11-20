public class Roteiro extends Evento{
    public Roteiro(String nome, double duracao){
        super(nome, duracao);
    }

    @Override
    public void exibirDetalhes(){
        System.out.println("[Roteiro] " + getNome() + " - Duração: " + getDuracaoPrevista() + "h");
        
    }
}