// Arthur Ramos Vieira
// N° de matrícula: 202420022
public class UsaContaBancaria{
    public static void main(String[] args){
        // instanciando duas contas com saldos diferentes
        ContaBancaria c1 = new ContaBancaria("Arthur", 100);
        ContaBancaria c2 = new ContaBancaria("Pedro", 300);

        // saldos iniciais
        System.out.println("C1 saldo inicial: R$" + c1.getSaldo());
        System.out.println("C2 saldo inicial: R$" + c2.getSaldo());

        // operações conta 1
        c1.depositar(200);
        System.out.println("C1 saldo (deposito de 200): R$" + c1.getSaldo());
        c1.sacar(50);
        System.out.println("C1 saldo (saque de 50): R$" + c1.getSaldo());

        // saldo pos operacoes conta 1
        System.out.println("C1 saldo pós operações: R$" + c1.getSaldo());

        // operações conta 2
        c2.sacar(100);
        System.out.println("C2 saldo (saque de 100): R$" + c2.getSaldo());
        c2.depositar(300);
        System.out.println("C2 saldo (deposito de 300): R$" + c2.getSaldo());

        // saldo pos operações conta 2
        System.out.println("C2 saldo pós operações: R$" + c2.getSaldo());
    }
}