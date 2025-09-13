package ContaBancaria;

public class ContaBancaria{
    // atributos
    private String nome;
    private float saldo;

    // construtores
    public ContaBancaria(String nome, float saldo){
        this.nome = nome;
        this.saldo = saldo;
    }

    // getters
    public String getNome(){
        return this.nome;
    }

    public float getSaldo(){
        return this.saldo;
    }

    // setters
    public void setNome(String novoNome){
        this.nome = novoNome;
    }

    public void setSaldo(float novoSaldo){
        this.saldo = novoSaldo;
    }

    // métodos
    public void depositar(float novoDeposito){
        setSaldo(this.saldo + novoDeposito);
    }

    public void sacar(float novoSaque){
        setSaldo(this.saldo - novoSaque);
    }

    // reescrevendo o metodo toString
    @Override
    public String toString(){
        return this.nome + ", saldo: " + this.saldo; 
    }
}