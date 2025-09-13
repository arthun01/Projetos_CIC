package Aluno;

public class usaAluno{
    public static void main(String[] args){
        Aluno aluno1 = new Aluno("Arthur Ramos Vieira", "202420022", 10f, 5.6f, 8.7f);

        aluno1.apresentar();

        float media = aluno1.getMedia();

        aluno1.apresentar();
        System.out.printf("Média: %.2f\n", media);
    }
}