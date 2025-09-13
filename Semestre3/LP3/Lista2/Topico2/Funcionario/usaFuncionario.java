package Funcionario;

public class usaFuncionario{
    public static void main(String[] args){
        Funcionario f1 = new Funcionario("Arthur Ramos Vieira", 1500.87f);

        System.out.printf("Nome: %s | Salário: %.2f\n", f1.getNome(), f1.getSalario());

        f1.aumentar_salario(32.5f);
        
        System.out.printf("Nome: %s | Salário: %.2f\n", f1.getNome(), f1.getSalario());
    }
}