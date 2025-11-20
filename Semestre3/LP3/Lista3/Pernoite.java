public class Pernoite extends Evento{
    public Pernoite(String nome, double duracao){
        super(nome, duracao);
    }

    @Override
    public void exibirDetalhes(){
        System.out.println("zzz Pernoite em: " + getNome() + " - Descanso de " + getDuracaoPrevista() + "h");
    }
}