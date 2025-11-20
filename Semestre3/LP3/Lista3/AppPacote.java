public class AppPacote{
    public static void main(String[] args){
        PacoteTuristico pacoteParis = new PacoteTuristico("Paris Romântica");
        PacoteTuristico pacoteDisney = new PacoteTuristico("Disney Fun");

        Roteiro r1 = new Roteiro("Visita à Torre Eiffel", 3.5);
        Deslocamento d1 = new Deslocamento("Trem para Versalhes", 1.0);
        Pernoite p1 = new Pernoite("Hotel Central", 8.0);
        Roteiro r2 = new Roteiro("Palácio de Versalhes", 4.0);

        pacoteParis.adicionarEvento(r1);
        pacoteParis.adicionarEvento(d1);
        pacoteParis.adicionarEvento(p1);
        pacoteParis.adicionarEvento(r2);

        Roteiro r3 = new Roteiro("Visitar a casa do Mickey", 2.5);
        Deslocamento d2 = new Deslocamento("Carrinho de golf", 0.5);
        Pernoite p2 = new Pernoite("Hotel Lego", 8.0);
        Roteiro r4 = new Roteiro("Palácio das Princesas", 3.5);

        pacoteDisney.adicionarEvento(r3);
        pacoteDisney.adicionarEvento(d2);
        pacoteDisney.adicionarEvento(p2);
        pacoteDisney.adicionarEvento(r4);

        RoteiroPromocional rPromo = new RoteiroPromocional("Viagem a Cuba", 4.6, 20.0); 
        rPromo.exibirDetalhes();

        // --------------------------

        Cliente cli = new Cliente("Arthur Ramos Vieira", "107.992.985-14");

        cli.adicionarDependente("Thales");
        cli.adicionarDependente("Bernardo");

        cli.contratarPacote(pacoteParis);
        cli.contratarPacote(pacoteDisney);

        cli.listarPacotes();
        cli.listarDependentes();

        System.out.println("Total de Eventos: " + Evento.getTotalEventos());
    }
}