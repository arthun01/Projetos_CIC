package Funcionario;

public class Funcionario{
    // atributos
    private String nome;
    private float salario;
    
    // construtores
    public Funcionario(String nome, float salario){
        this.nome = nome;
        this.salario = salario;
    }

    // getters
    public String getNome(){
        return this.nome;
    }

    public float getSalario(){
        return this.salario;
    }

    // setters
    public void setNome(String novoNome){
        this.nome = novoNome;
    }

    public void setSalario(float novoSalario){
        this.salario = novoSalario;
    }

    // métodos
    public void aumentar_salario(float percentual){
        float salarioNovo = this.salario + (this.salario * (percentual / 100f));
        setSalario(salarioNovo);
    }
}