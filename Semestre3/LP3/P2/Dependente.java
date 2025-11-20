public class Dependente{
    // atributos
    private String nome;
    private Cliente dependeDe; 

    // construtor que recebe um Cliente
    public Dependente(String nome, Cliente titular){
        this.nome = nome;
        this.dependeDe = titular;
    }

    // getters
    public String getNome() {
        return nome;
    }

    public Cliente getDependeDe() {
        return dependeDe;
    }
}