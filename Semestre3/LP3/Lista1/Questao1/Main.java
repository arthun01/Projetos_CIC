public class Main {

    // Este é o ponto de entrada do programa. A execução sempre começa aqui.
    public static void main(String[] args) {

        System.out.println("--- Testando Construtores ---");
        
        // Usando o construtor padrão
        MinhaData dataPadrao = new MinhaData(); 
        System.out.println("Data Padrão: " + dataPadrao); // Usa o toString() automaticamente

        // Usando o construtor com uma data válida
        MinhaData meuAniversario = new MinhaData((byte)25, (byte)12, (short)2024);
        System.out.println("Meu Aniversário: " + meuAniversario);

        // Usando o construtor com uma data INVÁLIDA
        MinhaData dataInvalida = new MinhaData((byte)31, (byte)2, (short)2023);
        System.out.println("Data Inválida (virou padrão): " + dataInvalida);
        
        // Usando o construtor de cópia com incremento
        MinhaData diaSeguinteAoMeuNiver = new MinhaData(meuAniversario, 1);
        System.out.println("Dia seguinte ao meu niver: " + diaSeguinteAoMeuNiver);

        System.out.println("\n--- Testando Comparações ---");
        MinhaData outraData = new MinhaData((byte)25, (byte)12, (short)2024);
        
        System.out.println("Meu aniversário é igual a outraData? " + meuAniversario.igualA(outraData));
        System.out.println("Data padrão é anterior ao meu aniversário? " + dataPadrao.anteriorA(meuAniversario));
        System.out.println("Meu aniversário é posterior à data padrão? " + meuAniversario.posteriorA(dataPadrao));

        System.out.println("\n--- Testando Intervalo de Datas ---");
        MinhaData dataBase = new MinhaData((byte)28, (byte)2, (short)2024); // Fim de Fevereiro em ano bissexto
        
        // Gera 5 datas consecutivas a partir de dataBase
        MinhaData[] proximas5Datas = dataBase.intervaloDatas(dataBase, 5);
        
        System.out.println("Próximas 5 datas a partir de " + dataBase + ":");
        for (MinhaData data : proximas5Datas) {
            System.out.println(" -> " + data);
        }
    }
}