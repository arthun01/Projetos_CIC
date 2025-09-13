package Cliente;

public class usaCliente{
    public static void main(String[] args){
        Cliente cliente1 = new Cliente("Arthur", "123.456.677-12");

        System.out.println(cliente1.getNome() + cliente1.getCpf());
    }
}