package Retangulo;

public class Retangulo{
    // atributos
    private float largura;
    private float altura;

    // construtores
    public Retangulo(float largura, float altura){
        this.largura = largura;
        this.altura = altura;
    }

    public Retangulo(){
        this.largura = 1f;
        this.altura = 1f;
    }

    // getters
    public float getLargura(){
        return this.largura;
    }

    public float getAltura(){
        return this.altura;
    }

    // setters
    public void setLargura(float novaLargura){
        this.largura = novaLargura;
    }

    public void setAltura(float novaAltura){
        this.altura = novaAltura;
    }

    public float calcular_area(){
        float area = (this.largura * this.altura);
        return area;
    }
}