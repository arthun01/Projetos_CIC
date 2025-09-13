package Pessoa;

public class usaPessoa{
    public static void main(String[] args){
        Pessoa p1 = new Pessoa("Arthur", 19);
        Pessoa p2 = new Pessoa("Thales", 29);
        Pessoa p3 = new Pessoa();

        System.out.println(p1);
        System.out.println(p2);
        System.out.println(p3);
    }
}