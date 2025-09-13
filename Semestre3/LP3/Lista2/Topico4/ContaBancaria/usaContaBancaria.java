package ContaBancaria;

public class usaContaBancaria{
    public static void main(String[] args){
        ContaBancaria conta1 = new ContaBancaria("Arthur", 125.89f);

        System.out.println(conta1);

        conta1.depositar(54.87f);

        System.out.println(conta1);

        conta1.sacar(10f);

        System.out.println(conta1);
    }
}