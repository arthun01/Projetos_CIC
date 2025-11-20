import java.util.ArrayList;
import java.util.List;

public class PacoteTuristico{
    private String nomePacote;
    private List<Evento> eventos;

    public PacoteTuristico(String nomePacote){
        this.nomePacote = nomePacote;
        this.eventos = new ArrayList<>();
    }

    public void adicionarEvento(Evento e){
        eventos.add(e);
    }

    public double calcularDuracaoTotal(){
        double total = 0;

        for(Evento e : eventos){
            total += e.getDuracaoPrevista();
        }

        return total;
    }

    public void exibirSequenciaEventos(){
        System.out.println("=== Pacote: " + nomePacote + " ===");

        for(Evento e : eventos){
            e.exibirDetalhes();
        }
        System.out.println("------------------------");
        System.out.println("Duração Total: " + calcularDuracaoTotal() + " horas");
    }
}