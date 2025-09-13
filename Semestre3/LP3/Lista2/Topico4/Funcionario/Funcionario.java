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

    public float getSalarioLiquido(){
        return this.salario - (this.salario * 0.15f);
    }

    // setters
    public void setNome(String novoNome){
        this.nome = novoNome;
    }

    public void setSalarioLiquido(float novoSalario){
        if(novoSalario > 0f){
            this.salario = novoSalario;
        }
    }

    // métodos
    public void aumentar_salario(float percentual){
        float salarioNovo = this.salario + (this.salario * (percentual / 100f));
        setSalarioLiquido(salarioNovo);
    }
}