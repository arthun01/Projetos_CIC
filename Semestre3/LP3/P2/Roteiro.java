public class Roteiro extends Evento{
    // construtor
    public Roteiro(String nome, double duracaoPrevista){
        super(nome, duracaoPrevista);
    }

    // reescrita do método abstract
    @Override
    public void descricao(){
        System.out.println("[Roteiro]: " + getNome() + " | Duração prevista: " + getDuracao() + " horas.");
    }
}