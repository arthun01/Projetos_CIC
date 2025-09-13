package Contato;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);

        String nome;
        String email;
        String telefone;
        boolean zap;

        nome = ler.nextLine();
        email = ler.nextLine();
        telefone = ler.nextLine();
        zap = ler.hasNextLine();

        Contato pessoa1 = new Contato(nome, email, telefone, zap);


        System.out.println(pessoa1);
    }   
}
