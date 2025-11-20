public class ContaBancaria{
    private String titular;
    private double saldo;

    public ContaBancaria(String titular, double saldoInicial){
        this.titular = titular;
        this.saldo = saldoInicial;
    }

    public void depositar(double valor){
        if(valor > 0){
            saldo += valor;
        }
    }

    public void sacar(double valor){
        if(valor > 0 && valor <= saldo){
            saldo -= valor;
        }
    }

    public double getSaldo(){
        return this.saldo;
    }
}