// Arthur Ramos Vieira, LP3 CIC 2025.2
// N° de Matrícula: 202420022
import java.util.ArrayList;
import java.util.List;

public class AppEventos{
    public static void main(String[] args) {
        // delcaração da lista de eventos
        List<Evento> pacoteEventos = new ArrayList<>();
        
        pacoteEventos.add(new Roteiro("Visita ao Cristo Redentor", 3.5));
        pacoteEventos.add(new Deslocamento("Voo Rio de Janeiro - Ilhéus", 4.0));
        pacoteEventos.add(new Pernoite("Hotel Farol da Barra", 48.0));

        System.out.println("=-= Relatório do Pacote de Eventos =-=\n");
        
        for (Evento evento : pacoteEventos) {
            evento.descricao(); 
        }
    }
}