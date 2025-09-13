package Aluno;

public class Aluno{
    // atributos
    private String nome;
    private String matricula;

    // construtores
    public Aluno(String nome, String matricula){
        this.nome = nome;
        this.matricula = matricula;
    }

    // getters
    public String getNome(){
        return this.nome;
    }

    public String getMatricula(){
        return this.matricula;
    }

    // setters
    public void setNome(String novoNome){
        this.nome = novoNome;
    }

    public void setMatricula(String novaMatricula){
        this.matricula = novaMatricula;
    }

    // metodos
    public void apresentar(){
        System.out.printf("Aluno: %s - N° de Matrícula: %s\n", this.nome, this.matricula);
    }
}