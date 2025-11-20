public class Pernoite extends Evento{
    // construtor
    public Pernoite(String nome, double duracaoPrevista){
        super(nome, duracaoPrevista);
    }

    // reescrita do método abstract
    @Override
    public void descricao(){
        int noites = (int) (getDuracao() / 24.0);
        System.out.println("[Pernoite]: " + getNome() + " | Noites: " + (int)noites + " (Total de horas: " + getDuracao() + ").");
    }
}