package Carro;

public class Carro{
    private String marca;
    private String modelo;
    private int ano;

    // construtores
    public Carro(){
        this.marca = "indef";
        this.modelo = "indef";
        this.ano = 0;
    }

    public Carro(String marca, String modelo, int ano){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
    }

    // getters
    public String getMarca(){
        return this.marca;
    }

    public String getModelo(){
        return this.modelo;
    }

    public int getAno(){
        return this.ano;
    }

    // setters
    public void setMarca(String novaMarca){
        if(novaMarca != null){
            this.marca = novaMarca;
        }
    }

    public void setModelo(String novoModelo){
        if(novoModelo != null){
            this.modelo = novoModelo;
        }
    }

    public void setAno(int novoAno){
        this.ano = novoAno;
    }

    // métodos

    // método para exibir informações
    public void exibir_info(){
        System.out.println("----------------");
        System.out.println("Marca: " + this.marca);
        System.out.println("Modelo: " + this.modelo);
        System.out.println("Ano: " + this.ano);
    }
}
