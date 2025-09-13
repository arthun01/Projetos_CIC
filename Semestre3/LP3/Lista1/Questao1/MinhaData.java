public class MinhaData {
    // 1. ATRIBUTOS
    private byte dia;
    private byte mes;
    private short ano;

    // 2. MÉTODOS DE VALIDAÇÃO
    public static boolean dataValida(byte dia, byte mes, short ano) {
        if (ano < 1900 || ano > 2050) return false;
        if (mes < 1 || mes > 12) return false;
        int diasNoMes;
        if (mes == 2) {
            boolean bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
            diasNoMes = bissexto ? 29 : 28;
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            diasNoMes = 30;
        } else {
            diasNoMes = 31;
        }
        return dia >= 1 && dia <= diasNoMes;
    }

    private boolean dataValida() {
        return dataValida(this.dia, this.mes, this.ano);
    }

    // 3. CONSTRUTORES
    public MinhaData() {
        this.dia = 1; this.mes = 1; this.ano = 1970;
    }

    public MinhaData(byte dia, byte mes, short ano) {
        if (dataValida(dia, mes, ano)) {
            this.dia = dia; this.mes = mes; this.ano = ano;
        } else {
            this.dia = 1; this.mes = 1; this.ano = 1970;
        }
    }

    public MinhaData(MinhaData outraData) {
        this.dia = outraData.dia; this.mes = outraData.mes; this.ano = outraData.ano;
    }
    
    public MinhaData(MinhaData outraData, int intervalo) {
        this.dia = outraData.dia; this.mes = outraData.mes; this.ano = outraData.ano;
        for (int i = 0; i < intervalo; i++) {
            incrementaUmDia();
        }
    }

    // 4. MÉTODOS DE INICIALIZAÇÃO
    public void inicializaData() {
        this.dia = 1; this.mes = 1; this.ano = 1970;
    }

    public boolean inicializaData(byte dia, byte mes, short ano) {
        if (dataValida(dia, mes, ano)) {
            this.dia = dia; this.mes = mes; this.ano = ano;
            return true;
        }
        return false;
    }
    
    public void inicializaData(MinhaData outraData) {
        this.dia = outraData.dia; this.mes = outraData.mes; this.ano = outraData.ano;
    }

    public void inicializaData(MinhaData outraData, int intervalo) {
        this.dia = outraData.dia; this.mes = outraData.mes; this.ano = outraData.ano;
        for (int i = 0; i < intervalo; i++) {
            incrementaUmDia();
        }
    }
    
    // Método auxiliar privado para incrementar
    private void incrementaUmDia() {
        this.dia++;
        if (!dataValida()) {
            this.dia = 1; this.mes++;
            if (!dataValida()) {
                this.mes = 1; this.ano++;
            }
        }
    }

    // 5. GETTERS E SETTERS
    public byte getDia() { return this.dia; }
    public byte getMes() { return this.mes; }
    public short getAno() { return this.ano; }
    
    public boolean setDia(byte dia) {
        if (dataValida(dia, this.mes, this.ano)) { this.dia = dia; return true; }
        return false;
    }
    // ... outros setters ...

    // 6. MÉTODO toString()
    @Override
    public String toString() {
        String[] nomesMeses = {"", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
        return this.dia + " de " + nomesMeses[this.mes] + " de " + this.ano;
    }

    // 7. MÉTODOS DE COMPARAÇÃO
    public boolean igualA(MinhaData outraData) {
        return this.dia == outraData.dia && this.mes == outraData.mes && this.ano == outraData.ano;
    }
    
    public boolean diferenteDe(MinhaData outraData) { return !this.igualA(outraData); }

    public boolean anteriorA(MinhaData outraData) {
        if (this.ano < outraData.ano) return true;
        if (this.ano > outraData.ano) return false;
        if (this.mes < outraData.mes) return true;
        if (this.mes > outraData.mes) return false;
        return this.dia < outraData.dia;
    }

    public boolean posteriorA(MinhaData outraData) {
        return !this.anteriorA(outraData) && !this.igualA(outraData);
    }
    
    // 8. MÉTODOS DE INTERVALO
    public MinhaData[] intervaloDatas(MinhaData dataInicial, int quantidade) {
        MinhaData[] resultado = new MinhaData[quantidade];
        MinhaData dataCorrente = new MinhaData(dataInicial);
        for (int i = 0; i < quantidade; i++) {
            resultado[i] = new MinhaData(dataCorrente);
            dataCorrente.incrementaUmDia();
        }
        return resultado;
    }

    public MinhaData[] intervaloDatas(MinhaData dataInicial, int quantidade, int passo) {
        MinhaData[] resultado = new MinhaData[quantidade];
        MinhaData dataCorrente = new MinhaData(dataInicial);
        for (int i = 0; i < quantidade; i++) {
            resultado[i] = new MinhaData(dataCorrente);
            for (int j = 0; j < passo; j++) {
                dataCorrente.incrementaUmDia();
            }
        }
        return resultado;
    }
}