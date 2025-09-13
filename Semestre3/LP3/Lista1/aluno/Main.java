public class Main{
    public static void main(String[] args) {
        System.out.println("-------------------------");

        // sem parametros (logo, ele vai ser o luiz)
        Aluno Aluno1 = new Aluno();
        System.out.println("Aluno: " + Aluno1);

        System.out.println("-------------------------");

        Aluno Aluno2 = new Aluno("Arthur", 18, 8.9f);
        System.out.println("Aluno: " + Aluno2);

        Aluno Aluno3 = new Aluno("Pedro", 19, 10.32f);
        System.out.println("Aluno: " + Aluno3);

        Aluno3.setIdade(19);
        System.out.println("Aluno: " + Aluno3);

        String nome_aleatorio = Aluno1.getNome();
        System.out.println(nome_aleatorio);

        Aluno1.setNome("Jonas Plaus");

        System.out.println("Aluno: " + Aluno1);
    }
}