// Arthur Ramos Vieira, LP3 CIC 2025.2
// N° de Matrícula: 202420022
public class AppClienteDependente{
    public static void main(String[] args){
        
        // Criando um cliente titular
        Cliente titular = new Cliente("Arthur Ramos Vieira", "123.456.789-00");
        System.out.println("Titular Criado: " + titular.getNome() + " (CPF: " + titular.getCpf() + ")");
        
        // Criando dois dependentes
        Dependente dep1 = new Dependente("Kevin Nilton", titular);
        Dependente dep2 = new Dependente("Pedro Lucas", titular);
        
        System.out.println("\n=-= Dependentes Vinculados =-=");
        
        // Exibindo Dependente 1
        System.out.println("Dependente 1:");
        System.out.println("  Nome do Dependente: " + dep1.getNome());
        System.out.println("  Titular: " + dep1.getDependeDe().getNome());
        System.out.println("  CPF do Titular: " + dep1.getDependeDe().getCpf());
        
        System.out.println("\nDependente 2:");
        System.out.println("  Nome do Dependente: " + dep2.getNome());
        System.out.println("  Titular: " + dep2.getDependeDe().getNome());
        System.out.println("  CPF do Titular: " + dep2.getDependeDe().getCpf());
    }
}