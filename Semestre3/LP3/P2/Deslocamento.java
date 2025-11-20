public class Deslocamento extends Evento{
    // construtor
    public Deslocamento(String nome, double duracaoPrevista){
        super(nome, duracaoPrevista);
    }

    // reescrita do método abstract
    @Override
    public void descricao(){
        System.out.println("[Deslocamento]: " + getNome() + " | Tempo de percurso: " + getDuracao() + " horas.");
    }
}